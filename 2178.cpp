#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int a[100][100];//주의!!!!!!배열의 크기
int dist[100][100];
bool check[100][100];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int m, n;
void bfs(int x, int y) {
	check[x][y] = true;
	queue<pair<int, int>> q;
	dist[x][y] = 1;
	q.emplace(x, y);
	int nx, ny;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if ((0 <= nx && nx <= m) && (0 <= ny && ny < n)) {
				if (check[nx][ny] == false && a[nx][ny] == 1) {
					check[nx][ny] = true;
					dist[nx][ny] = dist[x][y] + 1;
					q.emplace(nx, ny);
				}
			}
		}
	}
}
int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	bfs(0, 0);
	cout << dist[m - 1][n - 1];
}
