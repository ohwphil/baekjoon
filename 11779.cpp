#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
int n, m;
struct Edge {
	int cost;
	int to;
	Edge(int c, int t) : cost(c), to(t) {}
};
vector<Edge> adj[1001];
vector<int> path;
stack<int> st;
int dist[1001];
bool check[1001];
int predecessor[1001];
int main() {
	memset(dist, 1000000, sizeof(dist));
	cin >> n;
	cin >> m;
	int x, y, c;
	while (m--) {
		cin >> x >> y >> c;
		adj[x].push_back(Edge(c, y));
	}
	cin >> x >> y;
	check[x] = true;
	dist[x] = 0;
	int curr = x;
	while (curr != y) {
		for (Edge& e : adj[curr]) {
			if (!check[e.to] && dist[e.to]>dist[curr]+e.cost) {
				predecessor[e.to] = curr;
				dist[e.to] = min(dist[e.to], dist[curr] + e.cost);//min 주의!
				
			}
		}
		int minIndex = 0;
		for (int i = 1; i <= n; i++) {
			if (!check[i] && (dist[i] < dist[minIndex])) {
				minIndex = i;
			}
		}
		curr = minIndex;
		check[curr] = true;
	}
	cout << dist[y] << '\n';
	while (curr != x) {
		st.push(curr);
		curr = predecessor[curr];
	}
	st.push(x);
	cout << st.size() << '\n';
	while (!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}
}
