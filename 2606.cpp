#include <cstdio>
int n, m;
int union_set[101];
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
    int x, y;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        union_set[i] = i;//이걸 꼭!
    while (m--) {
        scanf("%d %d", &x, &y);
        merge(x, y);
    }
    int ans = 0;
    for (int i = 2; i <= n; i++)
        if (find(i) == find(1)) ++ans;//이것도 고려
    printf("%d", ans);
}
