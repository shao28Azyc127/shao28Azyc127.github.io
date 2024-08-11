#include<bits/stdc++.h>
using namespace std;
int n;
int ans,cnt;
bool b=1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    while(n>0){
        if(n%3==1&&b){
            cnt=ans+1;
            b=0;
        }
        n=(n-1)/3*2+(n%3+2)%3;
        ans++;
    }
    printf("%d %d",ans,cnt);
    return 0;
}
//1 2 3 4 5 6 7 8 9
//-     -     -
//1 2 3 4 5 6 7 8
//-     -     -
