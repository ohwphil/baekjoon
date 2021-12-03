#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int indegree[10001];
int t[10001];
vector<int> adj[10001];
bool finished[10001];
int n;
int temp;
int tasks = 0;
int timeclock = 0;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];//시간 입력
		cin >> indegree[i];
		for (int j = 0; j < indegree[i]; j++) {
			cin >> temp;
			adj[temp].push_back(i);
		}
	}
	while (true) {
		for (int i = 1; i <= n; i++) {
			if (t[i] == 0 && !finished[i]) {
				++tasks;
				finished[i] = true;
				for (int j : adj[i]) {
					if(indegree[j]!=0)
						--indegree[j];
				}
					
			}
			if (tasks == n) {
				cout << timeclock;
				return 0;
			}
			if (indegree[i] == 0 && !finished[i]) {
				--t[i];
			}
		}
		++timeclock;
	}
}
