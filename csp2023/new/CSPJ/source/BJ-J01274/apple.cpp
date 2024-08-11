#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans1=0,ans2;
bool f=1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    m=n;
    while(m>0){
        ans1++;
        if(m%3==1&&f){
            ans2=ans1;
            f=0;
        }
        if(m%3==0){
            m-=m/3;
        }
        else{
            m-=m/3+1;
        }
    }
    printf("%d %d",ans1,ans2);
    return 0;
}
