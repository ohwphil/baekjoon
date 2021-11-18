/*
* 
* 허프만 코드의 구현 방식
* 
* ① 문자와 빈도를 산출한다.
* ② 빈도를 기준으로 정렬하는 Min Heap에 문자들을 삽입한다.
* ③ 가장 빈도가 적은 두 개의 노드를 자식으로 가지는 새로운 노드를 만든다.(이 노드의 빈도는 두 자식 노드의 빈도를 합한 것으로 정의한다.)
* ④ 아무 노드도 남지 않을 때까지 반복한다. 이 때 루트 노드만 남는데, 이 노드의 하위에 트리가 구성된다.
* ⑤ 이 트리의 자식들 중에는 문자인 것도 있고, 아닌 것도 있다. 문자의 인코딩을 붙여 주려면 트리 순회를 통해 찾는데, 왼쪽으로 한 번 갈 때마다 0을 붙이고 오른쪽으로 갈 때마다 1을 붙인다.
*/

#include <queue>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
class Node {
public:
	int freq;//빈도
	char data;//널문자면 자식 노드로 문자를 가지는 것이다.
	Node* left;
	Node* right;
	Node(int f, char d = '\0', Node* l = nullptr, Node* r = nullptr) : freq(f), data(d), left(l), right(r) {}
};
class Compare {
public:
	bool operator () (Node* a, Node* b) {//나열을 위한 연산자
		if (a->freq != b->freq) return a->freq > b->freq;
		else return a->data > b->data;
	}
};
void traverse_tree(Node* curr, string s) {//왼쪽 노드로 갈 때에는 0, 오른쪽 노드로 갈 때에는 1를 인코딩에 추가해 준다. Preorder 방식
	if (curr == nullptr) return;
	//cout << "data" << (int)curr->data << endl;
	if (curr->data != '\0') cout << curr->data << ", Frequency : " << curr->freq << ", Encoding : " << s << endl;
	string t, r;
	t = s;
	t.append(1, '0');
	r = s;
	r.append(1, '1');
	traverse_tree(curr->left, t);
	traverse_tree(curr->right, r);
}
priority_queue<Node*, vector<Node*>, Compare> pq;
int freq_count[26];//빈도수 세기
int main() {
	string s;
	cin >> s;
	for (char c : s) {
		if (c >= 'A' && c <= 'Z') ++freq_count[c - 'A'];//1. 문자 빈도 산출
	}
	for (int i = 0; i < 26; i++) {
		if (freq_count[i] != 0) pq.push(new Node(freq_count[i], i + 'A'));//2. min heap에 삽입
	}
	while (pq.size() > 1) {//3, 4. 계속 새 노드 생성
		Node* first = pq.top();
		pq.pop();
		Node* second = pq.top();
		pq.pop();
		pq.push(new Node(first->freq + second->freq, '\0', first, second));
	}
	Node* root = pq.top();
	traverse_tree(root, "");//5. 트리 순회
}
