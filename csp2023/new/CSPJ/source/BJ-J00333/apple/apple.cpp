#include <bits/stdc++.h>
using namespace std;
int n,d,cnt,ans=1;
bool f;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    while(n>0){
        cnt++;
        if(n%3==1&&!f){
            ans=cnt;
            f=true;
        }
        if((n%3==2||n%3==1)&&n>3){
            n-=(n/3+1);
        }else{
            if(n<3){
                n-=1;
            }else{
                n-=(n/3);
            }
        }

    }
    printf("%d %d",cnt,ans);
    return 0;
}
