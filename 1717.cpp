#include <cstdio>
int n, m;
int union_set[1000001];
int find(int x) {
    if (x == union_set[x]) return x;
    else {
        return union_set[x] = find(union_set[x]);
    }
}
void merge(int x, int y) {
    union_set[find(y)] = find(x);
}
int main() {
    int op, x, y;
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; i++)
        union_set[i] = i;//이걸 꼭!
    while (m--) {
        scanf("%d %d %d", &op, &x, &y);
        if (op == 0) merge(x, y);
        else printf((find(x) == find(y)) ? "YES\n" : "NO\n");
    }
}
