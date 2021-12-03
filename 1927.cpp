#include <iostream>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;


int heap[100001];
int n;
int heapSize;
int pop() {
	if (heapSize == 0) return 0;
	int ret = heap[1];
	heap[1] = heap[heapSize];
	heap[heapSize--] = INT_MIN;
	for (int i = 1; i * 2 <= heapSize;) {
		if (heap[i] <= heap[2 * i] && heap[i] <= heap[2 * i + 1]) {
			break;
		}
		else if (heap[i * 2] < heap[i * 2 + 1]) {
			swap(heap[i], heap[i * 2]);
			i = i * 2;
		}
		else {
			swap(heap[i], heap[i * 2 + 1]);
			i = i * 2 + 1;
		}
	}
	return ret;
}
void push(int x) {
	heap[++heapSize] = x;
	for (int i = heapSize; i > 1; i /= 2) {
		if (heap[i / 2] > heap[i]) {
			swap(heap[i / 2], heap[i]);
		}
		else break;
	}
}
int main() {
	memset(heap, INT_MIN, sizeof(heap));
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		if (x == 0) {
			if (heapSize == 0) {
				cout << "0\n";
			}
			else {
				cout << pop() << '\n';
			}
		}
		else {
			push(x);
		}
	}
}
