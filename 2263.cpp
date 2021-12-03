#include <stdio.h>

int inorder[100001], postorder[100001], index[100001];

int n;
void solve(int in_start, int in_end, int post_start, int post_end){
    if(in_start>in_end || post_start>post_end) return;
    int root = postorder[post_end];
    int pivot = index[root];
    int left = pivot-in_start;
    printf("%d ", root);
    solve(in_start, pivot-1, post_start, post_start+left-1);
    solve(pivot+1, in_end, post_start+left, post_end-1);
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", inorder+i);
    }
    for(int i=0;i<n;i++){
        scanf("%d", postorder+i);
    }
    for(int i=0;i<n;i++){
        index[inorder[i]]=i;
    }
    solve(0, n-1, 0, n-1);
}
