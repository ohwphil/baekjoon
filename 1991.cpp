#include <iostream>
using namespace std;
int a[50][2];
void preorder(int x){
    if(x!=-1){
        cout<<(char)(x+'A');
        preorder(a[x][0]);
        preorder(a[x][1]);
    }
}
void inorder(int x){
    if(x!=-1){
        inorder(a[x][0]);
        cout<<(char)(x+'A');
        inorder(a[x][1]);
    }
}
void postorder(int x){
    if(x!=-1){
        postorder(a[x][0]);
        postorder(a[x][1]);
        cout<<(char)(x+'A');
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char x, y, z;
        cin>>x>>y>>z;
        x=x-'A';
        if(y=='.') y=-1;
        else y-='A';
        if(z=='.') z=-1;
        else z-='A';
        a[x][0]=y;
        a[x][1]=z;
    }
    preorder(0);
    cout<<'\n';
    inorder(0);
    cout<<'\n';
    postorder(0);
    return 0;

}
