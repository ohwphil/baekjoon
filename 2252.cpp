#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int indegree[32001];
vector<int> adj[32001];
queue<int> q;
int n, m, x, y;
int main() {
	cin >> n >> m;
	while (m--) {
		cin >> x >> y;
		++indegree[y];
		adj[x].push_back(y);
	}
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		cout << curr << ' ';
		for (int i : adj[curr]) {
			if (--indegree[i] == 0) q.push(i);
		}
	}
}
