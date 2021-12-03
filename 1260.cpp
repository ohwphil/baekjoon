#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
vector<int> a[1001];
bool check[1001];
queue<int> q;
stack<int> s;
void bfs(int start) {
	memset(check, false, sizeof(check));
	q.push(start);
	check[start] = true;

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		printf("%d ", tmp);
		for (int i = 0; i < a[tmp].size(); i++) {

			// 방문하지 않았다면
			if (check[a[tmp][i]] == false) {
				// 큐에 넣어주고 방문했음을 표시한다.
				q.push(a[tmp][i]);
				check[a[tmp][i]] = true;
			}
		}
	}
}
void dfs(int start) {
	s.push(start);
	check[start] = true;
	printf("%d ", start);

	while (!s.empty()) {

		int current_node = s.top();
		s.pop();
		for (int i = 0; i < a[current_node].size(); i++) {

			int next_node = a[current_node][i];

			if (check[next_node] == false) {
				printf("%d ", next_node);
				check[next_node] = true;
				// pop()을 했었기 때문에 현재 current_node도 넣어줘야한다.
				s.push(current_node);
				s.push(next_node);
				break;
			}
		}
	}
}

int main() {
	int n, m, start;
	scanf("%d %d %d", &n, &m, &start);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}
	dfs(start);
	printf("\n");
	bfs(start);
	printf("\n");
	return 0;
}
