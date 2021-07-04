// [main.c]
// this template is provided for the 2D shooter game.

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <math.h>
#include <stdbool.h>

// If defined, logs will be shown on console and written to file.
// If commented out, logs will not be shown nor be saved.
#define LOG_ENABLED

/* Constants. */

// Frame rate (frame per second)
const int FPS = 60;
// Display (screen) width.
const int SCREEN_W = 1200;
// Display (screen) height.
const int SCREEN_H = 800;
// At most 4 audios can be played at a time.
const int RESERVE_SAMPLES = 4;
// Same as:
// const int SCENE_MENU = 1;
// const int SCENE_START = 2;
enum {
	MENU = 1,
	SETTING,
	STORY,
	SKY,
	CITY,
	MILKWAY,
	WALL,
	STOP_SKY,
	STOP_CITY,
	STOP_MILKWAY,
	STOP_WALL,
	WIN,
	LOSE
};

/* Input states */

// The active scene id.
int active_scene;
// Keyboard state, whether the key is down or not.
bool key_state[ALLEGRO_KEY_MAX];
// Mouse state, whether the key is down or not.
// 1 is for left, 2 is for right, 3 is for middle.
bool mouse_state[10001];
// Mouse position.
int mouse_x, mouse_y;
// TODO: More variables to store input states such as joysticks, ...
float vol = 0.8;
int gametimer = 0;
/* Variables for allegro basic routines. */

ALLEGRO_DISPLAY* game_display;
ALLEGRO_EVENT_QUEUE* game_event_queue;
ALLEGRO_TIMER* game_update_timer;

/* Shared resources*/

ALLEGRO_FONT* font_pirulen_32;
ALLEGRO_FONT* font_pirulen_24;
// TODO: More shared resources or data that needed to be accessed
// across different scenes.

/* Menu Scene resources*/
ALLEGRO_BITMAP *img_setting, *img_what, *menu_bg;
ALLEGRO_SAMPLE* menu_bgm;
ALLEGRO_SAMPLE_ID menu_bgm_id;

/*Story Scene*/
ALLEGRO_BITMAP *story_bg;
ALLEGRO_SAMPLE* story_bgm;
ALLEGRO_SAMPLE_ID story_bgm_id;

/* setting Scene resources*/
ALLEGRO_BITMAP* img_home_setting;
ALLEGRO_BITMAP* img_play_setting;
ALLEGRO_BITMAP* img_dir_l;
ALLEGRO_BITMAP* img_dir_r;

/*stop*/
ALLEGRO_BITMAP* bg_stop;

/*PLAYING scene*/
ALLEGRO_BITMAP* img_bg0;
ALLEGRO_BITMAP* img_bg1;
ALLEGRO_BITMAP* img_bg2;
ALLEGRO_BITMAP* img_bg3;
ALLEGRO_BITMAP* img_me0;
ALLEGRO_BITMAP* img_me01;
ALLEGRO_BITMAP* img_me1;
ALLEGRO_BITMAP* img_me11;
ALLEGRO_BITMAP* img_enemy0;
ALLEGRO_BITMAP* img_enemy1;
ALLEGRO_BITMAP* img_stop;
ALLEGRO_BITMAP* img_bullet;
ALLEGRO_BITMAP* img_heart;
ALLEGRO_BITMAP* img_sd;
ALLEGRO_BITMAP* img_power;
ALLEGRO_BITMAP* img_sauce;
ALLEGRO_BITMAP* img_cat;
ALLEGRO_BITMAP* img_home_play;
ALLEGRO_SAMPLE* play_bgm0;
ALLEGRO_SAMPLE* play_bgm1;
ALLEGRO_SAMPLE_ID play_bgm_id;
ALLEGRO_SAMPLE* atked_bgm;
ALLEGRO_SAMPLE_ID atked_bgm_id;

/*win/lose scene*/
ALLEGRO_BITMAP* img_home_res;
ALLEGRO_BITMAP* bg_win;
ALLEGRO_BITMAP* bg_gg;
ALLEGRO_SAMPLE* win_bgm;
ALLEGRO_SAMPLE_ID win_bgm_id;
ALLEGRO_SAMPLE* gg_bgm;
ALLEGRO_SAMPLE_ID gg_bgm_id;

typedef struct {
	float speed;//for chang speed
	// The center coordinate of the image.
	float x, y;
	// The width and height of the object.
	float w, h;
	// The velocity in x, y axes.
	float vx, vy;
	// Should we draw this object on the screen.
	bool hidden;
	ALLEGRO_BITMAP* img;
	ALLEGRO_BITMAP* img1;
	int life;
	int point;
	bool carriedorhitted = false;//me : carry?, enemy : hitted?(once->faster, twice->renew)
} MovableObject;
void draw_movable_object(MovableObject obj);
#define MAX_ENEMY 5
#define MAX_BULLET 20
#define MAXLIFE 3
#define INITSPEED 4.0
MovableObject chara;
MovableObject enemies[MAX_ENEMY];
MovableObject bullets[MAX_BULLET];
const float MAX_COOLDOWN = 2.5;
double last_shoot_timestamp = 0;
bool mask = false;

// Initialize allegro5 library
void allegro5_init(void);
// Initialize variables and resources.
// Allows the game to perform any initialization it needs before
// starting to run.
void game_init(void);
// Process events inside the event queue using an infinity loop.
void game_start_event_loop(void);
// Run game logic such as updating the world, checking for collision,
// switching scenes and so on.
// This is called when the game should update its logic.
void game_update(void);
// Draw to display.
// This is called when the game should draw itself.
void game_draw(void);
// Release resources.
// Free the pointers we allocated.
void game_destroy(void);
// Function to change from one scene to another.
void game_change_scene(int next_scene);
// Load resized bitmap and check if failed.
ALLEGRO_BITMAP *load_bitmap_resized(const char *filename, int w, int h);
bool pnt_in_rect(int px, int py, int x, int y, int w, int h);

/* Event callbacks. */
void on_key_down(int keycode);

void on_mouse_down(int btn, int x, int y);

/* Declare function prototypes for debugging. */

// Display error message and exit the program, used like 'printf'.
// Write formatted output to stdout and file from the format string.
// If the program crashes unexpectedly, you can inspect "log.txt" for
// further information.
void game_abort(const char* format, ...);
// Log events for later debugging, used like 'printf'.
// Write formatted output to stdout and file from the format string.
// You can inspect "log.txt" for logs in the last run.
void game_log(const char* format, ...);
// Log using va_list.
void game_vlog(const char* format, va_list arg);

int main(int argc, char** argv) {
	// Set random seed for better random outcome.
	srand(time(NULL));
	allegro5_init();
	game_log("Allegro5 initialized");
	game_log("Game begin");
	// Initialize game variables.
	game_init();
	game_log("Game initialized");
	// Draw the first frame.
	game_draw();
	game_log("Game start event loop");
	// This call blocks until the game is finished.
	game_start_event_loop();
	game_log("Game end");
	game_destroy();
	return 0;
}

void allegro5_init(void) {
	if (!al_init())
		game_abort("failed to initialize allegro");

	// Initialize add-ons.
	if (!al_init_primitives_addon())
		game_abort("failed to initialize primitives add-on");
	if (!al_init_font_addon())
		game_abort("failed to initialize font add-on");
	if (!al_init_ttf_addon())
		game_abort("failed to initialize ttf add-on");
	if (!al_init_image_addon())
		game_abort("failed to initialize image add-on");
	if (!al_install_audio())
		game_abort("failed to initialize audio add-on");
	if (!al_init_acodec_addon())
		game_abort("failed to initialize audio codec add-on");
	if (!al_reserve_samples(RESERVE_SAMPLES))
		game_abort("failed to reserve samples");
	if (!al_install_keyboard())
		game_abort("failed to install keyboard");
	if (!al_install_mouse())
		game_abort("failed to install mouse");
	// TODO: Initialize other addons such as video, ...

	// Setup game display.
	game_display = al_create_display(SCREEN_W, SCREEN_H);
	if (!game_display)
		game_abort("failed to create display");
	al_set_window_title(game_display, "Final Project 108062224");

	// Setup update timer.
	game_update_timer = al_create_timer(1.0f / FPS);
	if (!game_update_timer)
		game_abort("failed to create timer");

	// Setup event queue.
	game_event_queue = al_create_event_queue();
	if (!game_event_queue)
		game_abort("failed to create event queue");

	// Malloc mouse buttons state according to button counts.
	const unsigned m_buttons = al_get_mouse_num_buttons();
	game_log("There are total %u supported mouse buttons", m_buttons);
	// mouse_state[0] will not be used.
	//mouse_state = malloc((m_buttons + 1) * sizeof(bool));
	memset(mouse_state, false, (m_buttons + 1) * sizeof(bool));

	// Register display, timer, keyboard, mouse events to the event queue.
	al_register_event_source(game_event_queue, al_get_display_event_source(game_display));
	al_register_event_source(game_event_queue, al_get_timer_event_source(game_update_timer));
	al_register_event_source(game_event_queue, al_get_keyboard_event_source());
	al_register_event_source(game_event_queue, al_get_mouse_event_source());
	// TODO: Register other event sources such as timer, video, ...

	// Start the timer to update and draw the game.
	al_start_timer(game_update_timer);
}

void game_init(void) {
	/* Shared resources*/
	font_pirulen_32 = al_load_font("./font/pirulen.ttf", 32, 0);
	if (!font_pirulen_32)
		game_abort("failed to load font: pirulen.ttf with size 32");

	font_pirulen_24 = al_load_font("./font/pirulen.ttf", 24, 0);
	if (!font_pirulen_24)
		game_abort("failed to load font: pirulen.ttf with size 24");

	/* Menu Scene resources*/
	menu_bg = load_bitmap_resized("./image/bg-menu.png", SCREEN_W, SCREEN_H);
	img_setting = load_bitmap_resized("./image/setting_blue.png",50,50);
	img_what = load_bitmap_resized("./image/what_blue.png",50,50);
	menu_bgm = al_load_sample("./sound/bgmsetmenu.ogg");
	if (!menu_bgm)
		game_abort("failed to load audio: menu ogg");

	/*story scene*/
	story_bg = load_bitmap_resized("./image/bg_story.png", SCREEN_W, SCREEN_H);
	story_bgm = al_load_sample("./sound/prowler.ogg");
	if (!story_bgm)
		game_abort("failed to load audio: story ogg");

	/*setting scene*/
	img_play_setting = load_bitmap_resized("./image/start_blue.png",150,150);
	img_home_setting = load_bitmap_resized("./image/home_blue.png",150,150);
	img_dir_l = load_bitmap_resized("./image/dir_l.png",50,50);
	img_dir_r = load_bitmap_resized("./image/dir_r.png",50,50);

	/*playing scene */
	img_bg0 = load_bitmap_resized("./image/bg_city.png",SCREEN_W,SCREEN_H);
	img_bg1 = load_bitmap_resized("./image/bg_woods.png",SCREEN_W,SCREEN_H);
	img_bg2 = load_bitmap_resized("./image/bg_space.png",SCREEN_W,SCREEN_H);
	img_bg3 = load_bitmap_resized("./image/bg_castle.png",SCREEN_W,SCREEN_H);

	img_enemy0 = load_bitmap_resized("./image/enemy0.png",50,50);
	img_enemy1 = load_bitmap_resized("./image/enemy0.png",50,50);

	img_me1 = load_bitmap_resized("./image/re0.png",50,70);
	img_me11 = load_bitmap_resized("./image/re1.png",50,70);
	img_me0 = load_bitmap_resized("./image/chara-egg.png",50,50);
	img_me01 = load_bitmap_resized("./image/chara-egg-full.png",50,50);

	img_stop = load_bitmap_resized("./image/stop_blue.png",30,30);
	img_home_play = load_bitmap_resized("./image/home_blue.png",30,30);
	img_heart = load_bitmap_resized("./image/heart32.png",32,32);
	img_power = load_bitmap_resized("./image/power.png",64,64);
	img_sd = load_bitmap_resized("./image/sd.png",64,64);
	img_sauce = load_bitmap_resized("./image/sauce.png",64,64);
	img_cat = load_bitmap_resized("./image/cat.png",64,64);


	play_bgm0 = al_load_sample("./sound/modern.ogg");
	if (!play_bgm0)
		game_abort("failed to load audio: modern.ogg");
    play_bgm1 = al_load_sample("./sound/bar.ogg");
	if (!play_bgm1)
		game_abort("failed to load audio: bar.ogg");
	atked_bgm = al_load_sample("./sound/boom.ogg");

	img_bullet =load_bitmap_resized("./image/heart.png",30,30);

    /*stop scene*/
	bg_stop = load_bitmap_resized("./image/bg_stop.png",SCREEN_W,SCREEN_H);

	/*win/gg resource*/

	bg_win = load_bitmap_resized("./image/bg_win.png",SCREEN_W,SCREEN_H);
	bg_gg = load_bitmap_resized("./image/bg_gg.png",SCREEN_W,SCREEN_H);
	img_home_res = load_bitmap_resized("./image/home_blue.png",50,50);
    win_bgm = al_load_sample("./sound/honor.ogg");
	if (!win_bgm)
		game_abort("failed to load audio: honor.ogg");
	gg_bgm = al_load_sample("./sound/oh.ogg");
	if (!gg_bgm)
		game_abort("failed to load audio: oh.ogg");

    //Change to first scene.
	game_change_scene(MENU);
}

void game_start_event_loop(void) {
	bool done = false;
	ALLEGRO_EVENT event;
	int redraws = 0;
	while (!done) {
		al_wait_for_event(game_event_queue, &event);
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			// Event for clicking the window close button.
			game_log("Window close button clicked");
			done = true;
		} else if (event.type == ALLEGRO_EVENT_TIMER) {
			// Event for redrawing the display.
			if (event.timer.source == game_update_timer)
				// The redraw timer has ticked.
				redraws++;
		} else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
			// Event for keyboard key down.
			game_log("Key with keycode %d down", event.keyboard.keycode);
			key_state[event.keyboard.keycode] = true;
			on_key_down(event.keyboard.keycode);
		} else if (event.type == ALLEGRO_EVENT_KEY_UP) {
			// Event for keyboard key up.
			game_log("Key with keycode %d up", event.keyboard.keycode);
			key_state[event.keyboard.keycode] = false;
		} else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			// Event for mouse key down.
			game_log("Mouse button %d down at (%d, %d)", event.mouse.button, event.mouse.x, event.mouse.y);
			mouse_state[event.mouse.button] = true;
			on_mouse_down(event.mouse.button, event.mouse.x, event.mouse.y);
		} else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			// Event for mouse key up.
			game_log("Mouse button %d up at (%d, %d)", event.mouse.button, event.mouse.x, event.mouse.y);
			mouse_state[event.mouse.button] = false;
		} else if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
			if (event.mouse.dx != 0 || event.mouse.dy != 0) {
				// Event for mouse move.
				game_log("Mouse move to (%d, %d)", event.mouse.x, event.mouse.y);
				mouse_x = event.mouse.x;
				mouse_y = event.mouse.y;
			} else if (event.mouse.dz != 0) {
				// Event for mouse scroll.
				game_log("Mouse scroll at (%d, %d) with delta %d", event.mouse.x, event.mouse.y, event.mouse.dz);
			}
		}
		// Redraw
		if (redraws > 0 && al_is_event_queue_empty(game_event_queue)) {
			// if (redraws > 1)
			// 	game_log("%d frame(s) dropped", redraws - 1);
			// Update and draw the next frame.
			game_update();
			game_draw();
			redraws = 0;
		}
	}
}

void game_update(void) {
	if (active_scene >= 4 && active_scene < 8) {//in game and not stop
	    gametimer++;
	    int shining = gametimer / 10;
	    if(shining > 300){
            chara.speed += 0.05;
            for(int idx = 0; idx < MAX_ENEMY; idx++){
                enemies[idx].speed += 0.005;
            }
            if(shining % 5 == 0){
                mask = true;
            }
            else
                mask = false;
	    }
		int sec = gametimer / 60;
		//printf("now is %dsec\n",sec);
		if(sec >= 60){
			printf("time out\n");
			game_change_scene(WIN);
		}
		chara.vx = chara.vy = 0;
		if (key_state[ALLEGRO_KEY_UP] || key_state[ALLEGRO_KEY_W])
			chara.vy -= 1;
		if (key_state[ALLEGRO_KEY_DOWN] || key_state[ALLEGRO_KEY_S])
			chara.vy += 1;
		if (key_state[ALLEGRO_KEY_LEFT] || key_state[ALLEGRO_KEY_A])
			chara.vx -= 1;
		if (key_state[ALLEGRO_KEY_RIGHT] || key_state[ALLEGRO_KEY_D])
			chara.vx += 1;
		// 0.71 is (1/sqrt(2)).
		chara.y += chara.vy * chara.speed * (chara.vx ? 0.71f : 1);
		chara.x += chara.vx * chara.speed * (chara.vy ? 0.71f : 1);
		// Limit the plane's collision box inside the frame.
		if (chara.x  < 25)
			chara.x = 25;
		else if (chara.x + 25 > SCREEN_W)
			chara.x = SCREEN_W - 25;
		if (chara.y  < 25)
			chara.y = 25;
		else if (chara.y + 25  > SCREEN_H)
			chara.y = SCREEN_H - 25;

		if(chara.x >= 1090 && chara.y <= 124 && chara.carriedorhitted){
			printf("uncarry----\n");
			chara.point += 100;
			chara.speed *= 1.5;
			chara.carriedorhitted = false;
		}
		else if(chara.x <= 100 && chara.y >= 700 && !chara.carriedorhitted){
			printf("carry----\n");
			chara.speed *= 0.5;
			chara.carriedorhitted = true;
		}
		srand(time(NULL));
		for(int idx = 0; idx < MAX_ENEMY; idx++){//;
			if(enemies[idx].hidden) continue;//died
			//direc is random
			int dir = rand() % 5;
			if(dir == 0 && enemies[idx].x < 1170){
				enemies[idx].x += (rand() % (int)enemies[idx].speed) * 2;
				//enemies[idx].y += (rand() % (int)enemies[idx].speed);
			}
			else if(dir == 1 && enemies[idx].y < 770){
				//enemies[idx].x -= (rand() % (int)enemies[idx].speed);
				enemies[idx].y += (rand() % (int)enemies[idx].speed) * 2;
			}
			else if(dir == 2 && enemies[idx].x > 30){
				enemies[idx].x -= (rand() % (int)enemies[idx].speed) * 2;
				//enemies[idx].y -= (rand() % (int)enemies[idx].speed);
			}
			else if(dir == 3 && enemies[idx].y > 50){
				//enemies[idx].x += (rand() % (int)enemies[idx].speed);
				enemies[idx].y -= (rand() % (int)enemies[idx].speed) * 2;
			}

			//touch?
			if(pnt_in_rect(enemies[idx].x,enemies[idx].y,chara.x,chara.y,enemies[idx].w / 2,enemies[idx].h / 2)){
				al_play_sample(atked_bgm, vol, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &atked_bgm_id);
				//printf("hit\n");
				if(chara.carriedorhitted){
					chara.carriedorhitted = false;
					chara.speed = INITSPEED;
				}
				else{
					chara.life--;
				}
				if(chara.life == 0)
				    game_change_scene(LOSE);

				enemies[idx].hidden = true;

				//printf("finish hit\n");
			}
		}
		// bullet
		int i;//printf("bullet\n");
		for (i=0 ;i + 4 < MAX_BULLET; i += 4) {
			if (!bullets[i].hidden){
				bullets[i].y += bullets[i].vy;
				if (bullets[i].y > SCREEN_H)
					bullets[i].hidden = true;
			}

			if (!bullets[i + 1].hidden){
				bullets[i + 1].x += bullets[i + 1].vx;
				if (bullets[i + 1].x > SCREEN_W)
					bullets[i + 1].hidden = true;
			}

			if (!bullets[i + 2].hidden){
				bullets[i + 2].y -= bullets[i + 2].vy;
				if (bullets[i + 2].y < 0)
					bullets[i + 2].hidden = true;
			}

			if (!bullets[i + 3].hidden){
				bullets[i + 3].x -= bullets[i + 3].vx;
				if (bullets[i + 3].x < 0)
					bullets[i + 3].hidden = true;
			}
			if(pnt_in_rect(chara.x,chara.y,bullets[i].x,bullets[i].y,16,16)
                        || pnt_in_rect(chara.x,chara.y,bullets[i + 1].x,bullets[i + 1].y,16,16)
                           || pnt_in_rect(chara.x,chara.y,bullets[i + 2].x,bullets[i + 2].y,16,16)
                              || pnt_in_rect(chara.x,chara.y,bullets[i + 3].x,bullets[i + 3].y,16,16)){
                                al_play_sample(atked_bgm, vol, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &atked_bgm_id);
                                chara.point -= 10;
                                if(chara.point < 0){
                                    game_change_scene(LOSE);
                                }
                              }

		}//printf("done bullet\n");
        double now = al_get_time();//printf("timer\n");
		if (now - last_shoot_timestamp >= MAX_COOLDOWN) {
            /*for (i = 0;i<MAX_BULLET; i++) {
		        if (bullets[i].hidden){
                    printf("hide ");
		        }
		        else
                    printf("appear ");
		    }
		    printf("\n");*/
			for (i = 0;i + 4 < MAX_BULLET; i += 4) {
		        if (bullets[i].hidden && bullets[i + 2].hidden)
		            break;
		    }
		    if (i < MAX_BULLET) {
				int enemyCanShoot = (MAX_BULLET - i) / 4;
		        last_shoot_timestamp = now;
				for(int e = 0; e < enemyCanShoot; e++){
					if(e >= MAX_ENEMY || i + 4 >= MAX_BULLET)//no more alive can shoot
					    break;
					if(enemies[e].hidden){//this died already
						enemyCanShoot++;
						continue;
					}
					//last e are can shoot
					bullets[i].hidden = false;
		            bullets[i].x = enemies[e].x - enemies[e].w/2;
		            bullets[i].y = enemies[e].y - enemies[e].h/2;
					bullets[i + 1].hidden = false;
		            bullets[i + 1].x = enemies[e].x - enemies[e].w/2;
		            bullets[i + 1].y = enemies[e].y - enemies[e].h/2;
					bullets[i + 2].hidden = false;
		            bullets[i + 2].x = enemies[e].x - enemies[e].w/2;
		            bullets[i + 2].y = enemies[e].y - enemies[e].h/2;
					bullets[i + 3].hidden = false;
		            bullets[i + 3].x = enemies[e].x - enemies[e].w/2;
		            bullets[i + 3].y = enemies[e].y - enemies[e].h/2;

				}
		    }
		}//printf("end\n");
	}
}

void game_draw(void) {
	if (active_scene == MENU) {
		al_draw_bitmap(menu_bg, 0, 0, 0);
		al_draw_text(font_pirulen_24, al_map_rgb(250,250, 250), 20, SCREEN_H - 50, 0, "Choose stage or press key to start ");

		if (pnt_in_rect(mouse_x, mouse_y, SCREEN_W - 78, 20, 50, 50))
			al_draw_bitmap(img_setting, SCREEN_W - 78, 20, 0);
		else
			al_draw_bitmap(img_setting, SCREEN_W - 78, 20, 0);
	    if (pnt_in_rect(mouse_x, mouse_y, SCREEN_W - 78, 90, 50, 50))
			al_draw_bitmap(img_what, SCREEN_W - 78, 90, 0);
		else
			al_draw_bitmap(img_what, SCREEN_W - 78, 90, 0);

		//scene choose
		al_draw_rectangle(40,650,290,685,al_map_rgb(36,123,252),0);
		al_draw_text(font_pirulen_32, al_map_rgb(36,123,252), 105, 650, 0, "SCENE0");

		al_draw_rectangle(330,650,580,685,al_map_rgb(161,144,63),0);
		al_draw_text(font_pirulen_32, al_map_rgb(161,144,63), 395, 650, 0, "SCENE1");

		al_draw_rectangle(620,650,870,685,al_map_rgb(162,25,253),0);
		al_draw_text(font_pirulen_32, al_map_rgb(162,25,253), 685, 650, 0, "SCENE2");

		al_draw_rectangle(910,650,1160,685,al_map_rgb(26,151,34),0);
		al_draw_text(font_pirulen_32, al_map_rgb(26,151,34), 975, 650, 0, "SCENE3");
	}
	else if(active_scene == STORY){
		al_draw_bitmap(story_bg,0,0,0);
	}
	else if(active_scene == SETTING){
        al_clear_to_color(al_map_rgb(180,180,180));
		al_draw_bitmap(img_play_setting,900,250,0);
		al_draw_bitmap(img_home_setting,900,450,0);
		al_draw_textf(font_pirulen_32, al_map_rgb(200,200,200), 170, 500, 0, "vol:%.0f",vol * 10);
		al_draw_bitmap(img_dir_l,150,550,0);
		al_draw_bitmap(img_dir_r,250,550,0);
	}
	else if (active_scene > 3 && active_scene < 8) {
		int i;
		if(active_scene == 4){
		    al_draw_bitmap(img_bg0, 0, 0, 0);
			al_draw_bitmap(img_cat,1100,50,0);
			al_draw_bitmap(img_sauce,15,720,0);
		}
		else if(active_scene == 5){
		    al_draw_bitmap(img_bg1, 0, 0, 0);
			al_draw_bitmap(img_cat,1100,50,0);
			al_draw_bitmap(img_sauce,15,720,0);
		}
		else if(active_scene == 6){
		    al_draw_bitmap(img_bg2, 0, 0, 0);
			al_draw_bitmap(img_cat,1100,50,0);
			al_draw_bitmap(img_sauce,15,720,0);
		}
		else if(active_scene == 7){
		    al_draw_bitmap(img_bg3, 0, 0, 0);
			al_draw_bitmap(img_power,1100,50,0);
			al_draw_bitmap(img_sd,15,720,0);
		}

		al_draw_text(font_pirulen_32, al_map_rgb(255,152,235), 15, 15, 0, "Life: ");
		for(int life = 0; life < chara.life; life++){
		    al_draw_bitmap(img_heart,120 + 35 * life, 25,0);
		}
		al_draw_textf(font_pirulen_32, al_map_rgb(200,200,200), 15, 50, 0, "Points: %5d",chara.point);

		al_draw_bitmap(img_home_play,1100,15,0);
		al_draw_bitmap(img_stop,1150,15,0);

		for (i = 0; i < MAX_BULLET; i++){
			draw_movable_object(bullets[i]);
	    }

		draw_movable_object(chara);

		for (i = 0; i < MAX_ENEMY; i++)
			draw_movable_object(enemies[i]);
        if(mask){
            al_clear_to_color(al_map_rgb(154,154,154));
        }
        al_draw_textf(font_pirulen_32, al_map_rgb(200,200,200), 900, 50, 0, "TIME: %3d",60 - gametimer / 60);

	}
	else if (active_scene < 12){
		al_draw_bitmap(bg_stop,0,0,0);
	}
	else if (active_scene == WIN) {
        al_draw_bitmap(bg_win, 0, 0, 0);
		al_draw_textf(font_pirulen_32, al_map_rgb(162,25,253), 660, 650, 0, "Total points: %d!",chara.point + 50 * chara.life);
	}
	else if (active_scene == LOSE) {
        al_draw_bitmap(bg_gg, 0, 0, 0);
	}
	al_flip_display();
}

void game_destroy(void) {
	// Destroy shared resources.
	al_destroy_font(font_pirulen_32);
	al_destroy_font(font_pirulen_24);

	/* Menu Scene resources*/
	al_destroy_bitmap(menu_bg);
	al_destroy_sample(menu_bgm);
	al_destroy_bitmap(img_setting);
	al_destroy_bitmap(img_what);

	/*story scene*/
	al_destroy_bitmap(story_bg);
	al_destroy_sample(story_bgm);

	/*setting scene*/
	al_destroy_bitmap(img_play_setting);
	al_destroy_bitmap(img_home_setting);
	al_destroy_bitmap(img_dir_l);
	al_destroy_bitmap(img_dir_r);

	/*stop*/
	al_destroy_bitmap(bg_stop);

	/* Start Scene resources*/
	al_destroy_bitmap(img_bg0);
	al_destroy_bitmap(img_bg1);
	al_destroy_bitmap(img_bg2);
	al_destroy_bitmap(img_bg3);
	al_destroy_bitmap(img_me0);
	al_destroy_bitmap(img_me1);
	al_destroy_bitmap(img_me01);
	al_destroy_bitmap(img_me11);
	al_destroy_bitmap(img_enemy0);
	al_destroy_bitmap(img_enemy1);
	al_destroy_bitmap(img_stop);
	al_destroy_bitmap(img_home_play);
	al_destroy_sample(play_bgm0);
	al_destroy_sample(play_bgm1);
	al_destroy_sample(atked_bgm);
	al_destroy_bitmap(img_bullet);
	al_destroy_bitmap(img_heart);
	al_destroy_bitmap(img_power);
	al_destroy_bitmap(img_sd);
	al_destroy_bitmap(img_cat);
	al_destroy_bitmap(img_sauce);

	/*res scene*/
	al_destroy_sample(win_bgm);
	al_destroy_sample(gg_bgm);
	al_destroy_bitmap(img_home_res);
	al_destroy_bitmap(bg_win);
	al_destroy_bitmap(bg_gg);

	al_destroy_timer(game_update_timer);
	al_destroy_event_queue(game_event_queue);
	al_destroy_display(game_display);
	free(mouse_state);
}

void game_change_scene(int next_scene) {
	game_log("Change scene from %d to %d", active_scene, next_scene);
	//bgms.
	if (active_scene == MENU) {//to story, setting or playing
		al_stop_sample(&menu_bgm_id);
		game_log("stop audio (bgm)");

		//renew the chara
		chara.speed = INITSPEED;
		chara.life = MAXLIFE;
		chara.point = 0;
		chara.carriedorhitted = false;
		gametimer = 0;
		mask = false;
		for (int i = 0; i < MAX_ENEMY; i++) {
			enemies[i].speed = 3;
		}
	}
    else if(active_scene == SETTING && next_scene > 3){
        al_stop_sample(&menu_bgm_id);
		game_log("stop audio (bgm)");
    }
	else if (active_scene > 3 && active_scene < 8) {//to stop or home
		al_stop_sample(&play_bgm_id);
		game_log("stop audio (playing bgm)");
	} else if (active_scene == WIN) {//win to menu
		al_stop_sample(&win_bgm_id);
		game_log("stop audio (win)");
	} else if (active_scene == LOSE) {//gg to menu
		al_stop_sample(&gg_bgm_id);
		game_log("stop audio (gg)");
	}
	active_scene = next_scene;
	// Allocate resources before entering scene.
	if (active_scene == MENU) {
		if (!al_play_sample(menu_bgm, vol, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &menu_bgm_id))
			game_abort("*failed to play audio (bgm)");
	} else if (active_scene < 7) {
		int i;
		chara.img = img_me0;
		chara.img1 = img_me01;
		chara.x = 400;
		chara.y = 500;
		chara.w = al_get_bitmap_width(chara.img);
        chara.h = al_get_bitmap_height(chara.img);
		for (i = 0; i < MAX_ENEMY; i++) {
			enemies[i].img = img_enemy0;
			enemies[i].w = al_get_bitmap_width(img_enemy0);
			enemies[i].h = al_get_bitmap_height(img_enemy0);
			enemies[i].x = enemies[i].w / 2 + (float)(rand() % 400) + 100;
			enemies[i].y = enemies[i].h / 2 + (float)(rand() % 900) + 100;
		}
		for (i=0;i<MAX_BULLET; i++) {
			bullets[i].w = al_get_bitmap_width(img_bullet);
			bullets[i].h = al_get_bitmap_height(img_bullet);
			bullets[i].img = img_bullet;
			bullets[i].vx = 3;
			bullets[i].vy = 3;
			bullets[i].hidden = true;
		}
		if (!al_play_sample(play_bgm0, vol, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &play_bgm_id))
			game_abort("*failed to play audio (play bgm)");
	}else if (active_scene == 7) {
		int i;
		chara.img = img_me1;
		chara.img1 = img_me11;
		chara.x = 400;
		chara.y = 500;
		chara.w = al_get_bitmap_width(chara.img);
        chara.h = al_get_bitmap_height(chara.img);
		for (i = 0; i < MAX_ENEMY; i++) {
			enemies[i].img = img_enemy1;
			enemies[i].w = al_get_bitmap_width(img_enemy1);
			enemies[i].h = al_get_bitmap_height(img_enemy1);
			enemies[i].x = enemies[i].w / 2 + (float)(rand() % 700) + 30;
			enemies[i].y = enemies[i].h / 2 + (float)(rand() % 1100) + 30;
		}
		for (i=0;i<MAX_BULLET; i++) {
			bullets[i].w = al_get_bitmap_width(img_bullet);
			bullets[i].h = al_get_bitmap_height(img_bullet);
			bullets[i].img = img_bullet;
			bullets[i].vx = 3;
			bullets[i].vy = 3;
			bullets[i].hidden = true;
		}
		if (!al_play_sample(play_bgm1, vol, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &play_bgm_id))
			game_abort("*failed to play audio (play bgm)");
	}
	else if(active_scene == WIN){
		if (!al_play_sample(win_bgm, vol, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &win_bgm_id))
			game_abort("*failed to play audio (win bgm)");
	}
	else if(active_scene == LOSE){
		if (!al_play_sample(gg_bgm, 1, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &gg_bgm_id))
			game_abort("*failed to play audio (gg bgm)");
	}
}

void on_key_down(int keycode) {
	if (active_scene == MENU) {
		if (keycode == ALLEGRO_KEY_ENTER)
			game_change_scene(SKY);
	}
}

void on_mouse_down(int btn, int x, int y) {
	if (active_scene == MENU) {
		if (btn == 1) {
			if (pnt_in_rect(x, y, SCREEN_W-78, 20, 50, 50))//click at setting
				game_change_scene(SETTING);
			else if(pnt_in_rect(x, y, SCREEN_W-78,90,50,50))
			    game_change_scene(STORY);
			else if(pnt_in_rect(x, y, 40,650,150,35))
			    game_change_scene(4);
			else if(pnt_in_rect(x, y, 330,650,150,35))
			    game_change_scene(5);
			else if(pnt_in_rect(x, y, 620,650,150,35))
			    game_change_scene(6);
			else if(pnt_in_rect(x, y, 910,650,150,35))
			    game_change_scene(7);
		}
	}
	else if(active_scene == SETTING){
		//the vol and home or play
		if(btn == 1){
			if(pnt_in_rect(x,y,900,250,150,150)){
				game_change_scene(4);
			}
			else if(pnt_in_rect(x,y,900,450,150,150)){
				game_change_scene(MENU);
			}
			else if (pnt_in_rect(x, y, 150,550, 50, 50) && vol > 0)//click at setting
			{
				vol -= 0.2;
				//vol up
			}
			else if (pnt_in_rect(x, y, 250, 550, 50, 50) && vol < 5)//click at setting
			{
				vol += 0.2;
			}
		}
	}
	else if(active_scene == STORY){
		if(btn == 1){
			game_change_scene(MENU);
		}
	}
	else if(active_scene < 8){
		if(btn == 1){
			if (pnt_in_rect(x, y, 1100,15, 30, 30))//click at home
				game_change_scene(MENU);
			else if(pnt_in_rect(x, y, 1150,15,30,30))//click stop
			    game_change_scene(active_scene + 4);
		}
	}
	else if(active_scene < 11){
		if(btn == 1){
			game_change_scene(active_scene - 4);
		}
	}
	else{
		if(btn == 1){
			//if (pnt_in_rect(x, y, SCREEN_W-48, 10, 38, 38))//click at home
			game_change_scene(MENU);
		}
	}
}

void draw_movable_object(MovableObject obj) {
	if (obj.hidden)
		return;
	if(obj.carriedorhitted)
	al_draw_bitmap(obj.img1, round(obj.x - obj.w / 2), round(obj.y - obj.h / 2), 0);
	else
	al_draw_bitmap(obj.img, round(obj.x - obj.w / 2), round(obj.y - obj.h / 2), 0);
}

ALLEGRO_BITMAP *load_bitmap_resized(const char *filename, int w, int h) {
	ALLEGRO_BITMAP* loaded_bmp = al_load_bitmap(filename);
	if (!loaded_bmp)
		game_abort("failed to load image: %s", filename);
	ALLEGRO_BITMAP *resized_bmp = al_create_bitmap(w, h);
	ALLEGRO_BITMAP *prev_target = al_get_target_bitmap();

	if (!resized_bmp)
		game_abort("failed to create bitmap when creating resized image: %s", filename);
	al_set_target_bitmap(resized_bmp);
	al_draw_scaled_bitmap(loaded_bmp, 0, 0,
		al_get_bitmap_width(loaded_bmp),
		al_get_bitmap_height(loaded_bmp),
		0, 0, w, h, 0);
	al_set_target_bitmap(prev_target);
	al_destroy_bitmap(loaded_bmp);

	game_log("resized image: %s", filename);

	return resized_bmp;
}

// [HACKATHON 3-3] done
// TODO: Define bool pnt_in_rect(int px, int py, int x, int y, int w, int h)
// Uncomment and fill in the code below.
bool pnt_in_rect(int px, int py, int x, int y, int w, int h) {
	if(x > px || px > x + w || y > py || py > y + h )
        return 0;
	else
        return 1;

}


// +=================================================================+
// | Code below is for debugging purpose, it's fine to remove it.    |
// | Deleting the code below and removing all calls to the functions |
// | doesn't affect the game.                                        |
// +=================================================================+

void game_abort(const char* format, ...) {
	va_list arg;
	va_start(arg, format);
	game_vlog(format, arg);
	va_end(arg);
	fprintf(stderr, "error occured, exiting after 2 secs");
	// Wait 2 secs before exiting.
	al_rest(2);
	// Force exit program.
	exit(1);
}

void game_log(const char* format, ...) {
#ifdef LOG_ENABLED
	va_list arg;
	va_start(arg, format);
	game_vlog(format, arg);
	va_end(arg);
#endif
}

void game_vlog(const char* format, va_list arg) {
#ifdef LOG_ENABLED
	static bool clear_file = true;
	vprintf(format, arg);
	printf("\n");
	// Write log to file for later debugging.
	FILE* pFile = fopen("log.txt", clear_file ? "w" : "a");
	if (pFile) {
		vfprintf(pFile, format, arg);
		fprintf(pFile, "\n");
		fclose(pFile);
	}
	clear_file = false;
#endif
}
