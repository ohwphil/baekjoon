#include <cstdio>
#include <vector>
using namespace std;
int n, m;
vector<int> graph[1001];
int number[1001];
void mark(int idx, int color){
        number[idx]=color;
        for(int x : graph[idx]){
            if(number[x]==0)
            mark(x, color);
        }
}
int main(){
    scanf("%d %d", &n, &m);
    int x, y;
    while(m--){
        scanf("%d %d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(number[i]==0)
            mark(i, ++ans);

    }
    printf("%d", ans);
}
