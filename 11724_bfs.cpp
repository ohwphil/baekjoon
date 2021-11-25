#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool check[1001];
vector<int> a[1001];
queue<int> q;
void bfs(int i) {
	q.push(i);
	int curr;
	while (!q.empty()) {
		curr = q.front();//용어 주의!
		q.pop();
		for (int x : a[curr]) {
			if (check[x] == false) {//spelling 주의!
				check[x] = true;
				q.push(x);
			}
		}
	}
}
int n, m;
int u, v;
int main() {
	cin >> n >> m;
	while (m--) {
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	int components = 0;
	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			check[i] = true;
			bfs(i);
			components++;
		}
	}
	cout << components;
}
