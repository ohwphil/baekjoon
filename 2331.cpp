#include <cstdio>
int order[500000];
int power(int num, int pow){
    if(num==0) return 0;
    int ans=1;
    for(int i=0;i<pow;i++)
        ans*=num;
    return ans;
}
int manipulate(int x, int pow){
    int answer=0;
    while(x!=0){
        answer+=power(x%10, pow);
        x/=10;
    }
    return answer;
}
int main(){
    int a, p;
    scanf("%d %d", &a, &p);
    int mark=1;
    while(true){
        if(order[a]==0)
            order[a]=mark++;
        else break;
        a=manipulate(a, p);
    }
    printf("%d", order[a]-1);//mark 말고
}
