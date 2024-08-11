#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    scanf("%d",&n);
    int left=n;
    bool a[n]={};
    int i=0;
    int t=0,tmp=0,ans=0;
    int ans2;
    while (left>0)
    {
        t=0,tmp=0;
        while (t<=2)
        {
            if (a[i+t]==0)
            {
                t++;
            }
            tmp++;
        }
        if (tmp+i>n-1)
        {
            ans++;
            i=0;
            continue;
        }
        a[tmp+i]=1;
        i=tmp+i;
        if (i=n-1)
        {
            ans2=ans+1;
            ans++;
        }
        left--;
    }
    printf("%d %d",ans,ans2);
    return 0;
}
