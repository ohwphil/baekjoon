/*
입력 : 
0 1 0 0 1
1 0 1 1 0
0 1 0 1 0
0 1 1 0 1
1 0 0 1 0

출력 : 1
*/

#include <cstdio>
#include <queue>
using namespace std;
int adj_mat[6][6];
bool visited[6];
int dist[6];
int shortest_path_bfs(int start, int end) {
	queue<int> q;
	int curr;
	q.emplace(start);
	visited[start] = true;
	while (!q.empty()) {
		curr = q.front();
		q.pop();
		if (curr == end) return visited[end];
		for (int i = 1; i <= 5; i++) {
			if (adj_mat[curr][i] == 1) {
				visited[i] = true;
				dist[i] = dist[curr] + 1;
				q.push(i);
			}
		}
	}
	return 100000;
}
int main() {
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			scanf_s("%d", &adj_mat[i][j]);
		}
	}
	printf("%d", shortest_path_bfs(1, 5));
}
