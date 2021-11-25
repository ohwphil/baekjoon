#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int k, v, e;
int x, y;
vector<int> a[20001];
queue<int> q;
int color[20001];
void bfs(int i, int c) {
	color[i] = c;
	q.push(i);
	int curr;
	while (!q.empty()) {
		curr = q.front();
		q.pop();
		for (int z : a[curr]) {
			if (color[z] == 0) {
				color[z] = 3 - color[curr];
				q.push(z);
			}
		}
	}
}
int main() {
	cin >> k;
	while (k--) {
		memset(color, 0, sizeof(color));
		//이 코드 주의!
		for (vector<int>& v : a) {
			v.clear();
		}
		cin >> v >> e;
		while (e--) {
			cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		for (int i = 1; i <= v; i++) {
			if (color[i] == 0) {
				bfs(i, 1);
			}
		}
		bool ok = true;
		for (int i = 1; i <= v; i++) {
			for (int z : a[i]) {
				if (color[i] == color[z])
					ok = false;
			}
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
}
