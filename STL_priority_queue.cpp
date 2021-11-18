//STL의 priority_queue 이용

#include <cstdio>
#include <queue>
using namespace std;
int main() {
	priority_queue<int> pq;
	pq.push(10);
	pq.push(5);
	pq.push(30);
	pq.push(8);
	pq.push(9);
	pq.push(3);
	pq.push(7);
	
	while (!pq.empty()) {
		printf("%d ", pq.top());
		pq.pop();
	}
}
