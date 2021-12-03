#include <iostream>
#include <cstring>
using namespace std;
int a[1001];
bool check[1001];
void dfs(int x) {
    if (check[x]) return;
    check[x] = true;
    dfs(a[x]);
}
int t, n;
int main() {
    cin >> t;
    while (t--) {
        memset(a, 0, sizeof(a));
        memset(check, false, sizeof(check));
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int components = 0;
        for (int i = 1; i <= n; i++) {
            if (check[i] == false) {
                dfs(i);
                ++components;
            }
        }
        cout << components << '\n';
    }
}
