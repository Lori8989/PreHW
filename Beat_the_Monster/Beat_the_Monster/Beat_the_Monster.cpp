#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

struct State {
    int lv, hp, mhp;
    int cur;

    State(int lv, int hp, int mhp, int cur = 0)
        :lv(lv), hp(hp), mhp(mhp), cur(cur){}
};

bool happened[20][310][410];

int main(){
    int maxlv, hp, mhp, mdmg;
    cin >> maxlv >> hp >> mhp >> mdmg;

    int hl[20], dmg[20];
    for (int i = 1; i <= maxlv; i++) {
        cin >> dmg[i] >> hl[i];
    }

    queue<State> que;
    que.push(State(1, hp, mhp));

    while (!que.empty()) {
        auto s = que.front();
        if (s.mhp <= 0)
            break;
        que.pop();

        //attack
        if (dmg[s.lv] > s.mhp || s.hp > mdmg) {
            State nxt(s.lv, s.hp - mdmg, mdmg - dmg[s.lv]);

            if (!happened[nxt.lv][nxt.hp][nxt.mhp])
                happened[nxt.lv][nxt.hp][nxt.mhp] = true;
            else
                break;

            que.push(nxt);
        }

    }
    return 0;
}

/*
10 10 5 1
1 1
2 2
3 3
4 3
5 5
4 4
7 7
8 9
9 7
10 10
*/



/*

struct State {
    int lv, hp, mhp;
    int cur;//count of rounds

    State(int lv, int hp, int mhp, int cur = 0)//set the format
        :lv(lv), hp(hp), mhp(mhp), cur(cur){}
};

bool situation[20][310][410];//level, hp, mhp

int main()
{
    int maxlv, hp, mhp, mdmg;
    int dmg[16], hl[16];//damage and heal in each level
    cin >> maxlv >> hp >> mhp >> mdmg;

    for (int i = 1; i <= maxlv; i++) {
        cin >> dmg[i] >> hl[i];
    }

    queue<State> p;
    p.push(State(1, hp, mhp));

    while (!p.empty()) {
        State s = p.front();
        if (s.mhp <= 0)
            break;
        p.pop();

        //attack : dmg > mhp || hp >mdmg
        if (dmg[s.lv] - s.mhp >= 0|| s.hp > mdmg) {//can do attack
            State nxt(s.lv, s.hp - mdmg,max(0, s.mhp - dmg[s.lv]), s.cur+1);
           // cout << "atk, cur: " << s.cur << endl;
           // cout << "next: " << nxt.cur << endl;

            if (!situation[nxt.lv][nxt.hp][nxt.mhp]) {
                situation[nxt.lv][nxt.hp][nxt.mhp] = true;
                p.push(nxt);
            }
        }

        //heal : hl[s,lv] > mdmg
        if (hl[s.lv] > mdmg) {
            State nxt(s.lv, min(s.hp + hl[s.lv],hp) - mdmg,s.mhp, s.cur+1);
           // cout << "heal, cur: " << s.cur << endl;
           // cout << "next: " << nxt.cur << endl;
            if (!situation[nxt.lv][nxt.hp][nxt.mhp]) {
                situation[nxt.lv][nxt.hp][nxt.mhp] = true;
                p.push(nxt);
            }
        }

        //level up : hp > mdmg && s.lv < maxlv
        if (s.hp > mdmg && s.lv < maxlv) {
            State nxt(s.lv + 1, s.hp - mdmg, s.mhp, s.cur + 1);
            //cout << "lv up, cur: " << s.cur << endl;
            //cout << "next: " << nxt.cur << endl;
            if (!situation[nxt.lv][nxt.hp][nxt.mhp]) {
                situation[nxt.lv][nxt.hp][nxt.mhp] = true;
                p.push(nxt);
            }
        }
    }

    if (p.empty())
        cout << -1 << endl;
    else
        cout << p.front().cur << endl;
*/