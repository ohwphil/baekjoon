#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// 최대 정점의 수
#define MAX 10001
// 그래프 방문표시 배열
bool check[MAX] = {false,};
// 그래프의 인접 리스트(연결된 정점 번호, 간선 가중치)쌍
vector<pair<int,int>> mArr[MAX];

void prim(){
    check[1] = true; //1번부터 시작

// 우선순위 큐
    priority_queue<pair<int,int>> q;
// 1번 정점을 시작으로 트리에 가장 먼저 추가
// second : -가중치 값
    for(auto p: mArr[1]){
        q.push(make_pair(-p.second, p.first));
    }
//MST 최소의 합 저장 변수
    int answer = 0;

while(!q.empty()){
    pair<int,int> p = q.top();
    q.pop();
//끝점이 방문된 점이 있지 않은 경우
    if(!check[p.second]){
        //방문표시
        check[p.second] = true;
//최소값의 합 덧셈
        answer+= -p.first;

        int x = p.second;
        for(pair<int,int> p : mArr[x]){
            q.push(make_pair(-p.second, p.first));
        }
    }
}
    cout<<answer<<'\n';
}

int main(){
    int n=0, m=0;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int a=0, b=0, c=0;
        cin>>a>>b>>c;
        mArr[a].push_back(make_pair(b,c));
        mArr[b].push_back(make_pair(a,c));
    }
    prim();
    return 0;
}
