#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d", &n);
    int a=n, cnt=0, ans;
    bool flag=true;
    while(a!=0){
        if(a%3==1&&flag==true){
            ans=cnt+1;
            flag=false;
        }
        int x=(a+2)/3;
        a-=x;
        cnt++;
    }
    printf("%d %d", cnt, ans);
    return 0;
}
