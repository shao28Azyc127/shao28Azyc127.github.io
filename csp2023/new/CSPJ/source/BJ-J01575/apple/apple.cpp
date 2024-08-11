#include<bits/stdc++.h>
using namespace std;
int n,day,ans;
bool flag=1;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    while(n){
        ++day;
        if(n%3==1&&flag)ans=day,flag=0;
        int qu=(n-1)/3+1;
        n-=qu;
    }
    return printf("%d %d",day,ans),0;
}