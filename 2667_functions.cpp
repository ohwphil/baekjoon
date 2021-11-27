void bfs(int x, int y, int cnt) {
	queue<pair<int, int>> q;
	group[x][y] = cnt;
	q.emplace(x, y);
	int nx, ny;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();//q.pop() 빼먹지 않기!!!
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if ((0 <= nx && nx < n) && (0 <= ny && ny < n)) {
				if (a[nx][ny] == 1 && group[nx][ny] == 0) {
					group[nx][ny] = cnt;
					q.emplace(nx, ny);
				}
			}
		}
	}
}
int bfs_write(int x, int y, int cnt) {
	queue<pair<int, int>> q;
	group[x][y] = cnt;
	q.emplace(x, y);
	int nx, ny;
	int ans = 1;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();//q.pop() 빼먹지 않기!!!
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if ((0 <= nx && nx < n) && (0 <= ny && ny < n)) {
				if (a[nx][ny] == 1 && group[nx][ny] == 0) {
					group[nx][ny] = cnt;
					q.emplace(nx, ny);
					++ans;
				}
			}
		}
	}
	return ans;
}
void dfs(int x, int y, int cnt) {
	if (a[x][y] == 1 && group[x][y] == 0) {//이것으로 둘러싸기
		group[x][y] = cnt;
		int nx, ny;
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if ((0 <= nx && nx < n) && (0 <= ny && ny < n)) {
				dfs(nx, ny, cnt);
			}
		}
	}

}
int dfs_write(int x, int y, int cnt) {
	if (a[x][y] == 1 && group[x][y] == 0) {//이것으로 둘러싸기
		group[x][y] = cnt;
		int nx, ny;
		int ans = 1;
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if ((0 <= nx && nx < n) && (0 <= ny && ny < n)) {
				ans+=dfs_write(nx, ny, cnt);
			}
		}
		return ans;
	}
	return 0;
}
