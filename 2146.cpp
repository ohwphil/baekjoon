/*

2146 다리 만들기

여러 섬으로 이루어진 나라가 있다. 이 나라의 대통령은 섬을 잇는 다리를 만들겠다는 공약으로 인기몰이를 해 당선될 수 있었다. 하지만 막상 대통령에 취임하자, 다리를 놓는다는 것이 아깝다는 생각을 하게 되었다. 그래서 그는, 생색내는 식으로 한 섬과 다른 섬을 잇는 다리 하나만을 만들기로 하였고, 그 또한 다리를 가장 짧게 하여 돈을 아끼려 하였다.

이 나라는 N×N크기의 이차원 평면상에 존재한다. 이 나라는 여러 섬으로 이루어져 있으며, 섬이란 동서남북으로 육지가 붙어있는 덩어리를 말한다. 다음은 세 개의 섬으로 이루어진 나라의 지도이다.



위의 그림에서 색이 있는 부분이 육지이고, 색이 없는 부분이 바다이다. 이 바다에 가장 짧은 다리를 놓아 두 대륙을 연결하고자 한다. 가장 짧은 다리란, 다리가 격자에서 차지하는 칸의 수가 가장 작은 다리를 말한다. 다음 그림에서 두 대륙을 연결하는 다리를 볼 수 있다.



물론 위의 방법 외에도 다리를 놓는 방법이 여러 가지 있으나, 위의 경우가 놓는 다리의 길이가 3으로 가장 짧다(물론 길이가 3인 다른 다리를 놓을 수 있는 방법도 몇 가지 있다).

지도가 주어질 때, 가장 짧은 다리 하나를 놓아 두 대륙을 연결하는 방법을 찾으시오.

입력
첫 줄에는 지도의 크기 N(100이하의 자연수)가 주어진다. 그 다음 N줄에는 N개의 숫자가 빈칸을 사이에 두고 주어지며, 0은 바다, 1은 육지를 나타낸다. 항상 두 개 이상의 섬이 있는 데이터만 입력으로 주어진다.

출력
첫째 줄에 가장 짧은 다리의 길이를 출력한다.

*/

//구현의 핵심 아이디어 : 토마토와 비슷하다! 한 섬의 모든 좌표를 push한 다음에, 가까운 육지를 만날 때까지 bfs를 진행한다.


#include <cstdio>
#include <algorithm>
#include <tuple>
#include <queue>
using namespace std;
int map[100][100];//바다이면 0, 섬의 번호에 따라서 1, 2, 3, ... 등을 가지는 배열
bool visited[100][100];
int n;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool isLand(int x, int y) {
    if (0 <= x && x < n && 0 <= y && y < n && map[x][y] != 0) return true;//육지인지 확인하는 함수
    return false;
}
void color(int x, int y, int c) {//섬을 번호에 따라서 색칠하는 함수
    if (c == 1) return;
    visited[x][y] = true;
    map[x][y] = c;
    for (int i = 0; i < 4; i++) {
        if (isLand(x + dx[i], y + dy[i]) && !visited[x + dx[i]][y + dy[i]]) color(x + dx[i], y + dy[i], c);//꼭 방문 확인해야 함!!!!!!!!
    }
}
int bfs(int c) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            visited[i][j] = false;
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (map[i][j] == c) {
                q.emplace(i, j, 0);
                visited[i][j] = true;
            }
    while (!q.empty()) {//꼭 괄호 붙이기
        tuple<int, int, int> t = q.front();//x좌표, y좌표, 거리를 담고 있는 큐
        q.pop();
        int x = get<0>(t);
        int y = get<1>(t);
        int z = get<2>(t);
        for (int i = 0; i < 4; i++) {
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= n) continue;
            if (visited[x1][y1]) continue;
            if (map[x1][y1] == 0 && !visited[x1][y1]) {
                visited[x1][y1] = true;
                q.emplace(x1, y1, z + 1);
            }
            else return z;
        }
    }
    return 100000;
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &map[i][j]);
    int num_colors = 0;
    for (int i = 0; i < n; i++)//for loop을 돌면서 색칠
        for (int j = 0; j < n; j++)
            if (!visited[i][j] && map[i][j] == 1) color(i, j, ++num_colors);
    int ans = 100000;
    for (int i = 1; i <= num_colors; i++) ans = min(ans, bfs(i));//매 섬마다 주변 육지와의 최단거리를 찾아서 기록 경신
    printf("%d", ans);
}
