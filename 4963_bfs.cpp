#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int a[50][50];
int group[50][50];
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int ans[625];
int n, m;
void bfs(int x, int y, int cnt) {
	queue<pair<int, int>> q;
	group[x][y] = cnt;
	q.emplace(x, y);
	int nx, ny;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if ((0 <= nx && nx < m) && (0 <= ny && ny < n)) {
				if (a[nx][ny] == 1 && group[nx][ny] == 0) {
					group[nx][ny] = cnt;
					q.emplace(nx, ny);
				}
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
					bfs(i, j, ++cnt);
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
