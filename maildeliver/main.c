#include <stdio.h>
#define min(a,b) (a < b ? a : b)

int d[11][11];
int is[11], n, ans = 2147483647;

void DFS(int now, int pre, int dis){
	if(now == n){
		ans = min(ans, dis + d[pre][0]);
		return;
	}
	is[pre] = 1;
	for(int i = 0; i < n; i++){
		if(is[i]) continue;
		DFS(now + 1, i, dis + d[pre][i]);
	}
	is[pre] = 0;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &d[i][j]);
		}
	}
	DFS(1, 0, 0);
	printf("%d\n", ans);

	return 0;
}
