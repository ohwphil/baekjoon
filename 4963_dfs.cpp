#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int a[50][50];//주의!!!!!!배열의 크기
int group[50][50];
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int ans[625];
int n, m;
void dfs(int x, int y, int cnt) {
	
	int nx, ny;
	if(a[x][y]==1 && group[x][y]==0) {
		group[x][y] = cnt;
		for (int i = 0; i < 8; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if ((0 <= nx && nx < m) && (0 <= ny && ny < n)) {
				dfs(nx, ny, cnt);//실수하지 않고 재귀함수를 넣어준다.
			}
		}
	}
}
int main() {
	while (true) {//이것과
		memset(a, 0, sizeof(a));
		memset(group, 0, sizeof(group));
		memset(ans, 0, sizeof(ans));
		cin >> n >> m;
		if (n == 0 && m == 0) break;//이것을 해야만 된다!
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 1 && group[i][j] == 0) {
					dfs(i, j, ++cnt);
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
