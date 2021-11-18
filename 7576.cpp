/*

7576 토마토

철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 토마토는 아래의 그림과 같이 격자 모양 상자의 칸에 하나씩 넣어서 창고에 보관한다. 



창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다. 대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.

토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.

입력
첫 줄에는 상자의 크기를 나타내는 두 정수 M,N이 주어진다. M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다. 단, 2 ≤ M,N ≤ 1,000 이다. 둘째 줄부터는 하나의 상자에 저장된 토마토들의 정보가 주어진다. 즉, 둘째 줄부터 N개의 줄에는 상자에 담긴 토마토의 정보가 주어진다. 하나의 줄에는 상자 가로줄에 들어있는 토마토의 상태가 M개의 정수로 주어진다. 정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다.

토마토가 하나 이상 있는 경우만 입력으로 주어진다.

출력
여러분은 토마토가 모두 익을 때까지의 최소 날짜를 출력해야 한다. 만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.
*/


#include <cstdio>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;
int tomatoes[1000][1000];//토마토의 정보(0 : 익지 않음, 1 : 익음)
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int m, n;
bool isNew(int i, int j) {
    if ((0 <= i && i < m) && (0 <= j && j < n) && tomatoes[i][j] == 0) return true;//익지 않은 토마토인지 확인하는 함수
    return false;
}
int bfs() {
    int x, y, z;
    queue<tuple<int, int, int>> q;//x좌표, y좌표, 거리를 가지는 튜플으로 bfs
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (tomatoes[i][j] == 1) q.emplace(i, j, 1);
    int ans = 0;
    while (!q.empty()) {
        tuple<int, int, int> curr = q.front();
        q.pop();
        x = get<0>(curr);
        y = get<1>(curr);
        z = get<2>(curr);
        if ((tomatoes[x][y] != 0) && (tomatoes[x][y] != 1)) continue;
        tomatoes[x][y] = z;
        for (int i = 0; i < 4; i++) {//인접한 토마토가 익지 않은 토마토이면 큐에 삽입(거리 정보를 1 늘려서)
            if (isNew(x + dx[i], y + dy[i])) q.emplace(x + dx[i], y + dy[i], z + 1);
        }
        ans = max(ans, z - 1);//정답 경신
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (tomatoes[i][j] == 0) return -1;//만약 이 과정을 거쳤는데도 익지 않은 토마토가 있다면 -1
        }
            
    return ans;
}
int main() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++)//n, m 바꿔줘야 제대로 입력됨
        for (int j = 0; j < m; j++) {
            scanf("%d", &tomatoes[j][i]);
        }
        

    printf("%d", bfs());
}
