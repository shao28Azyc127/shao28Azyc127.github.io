#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,flag=0,cnt=0,ans=0;
    scanf("%d",&n);
    while(n>0)
    {
        cnt++;
        if(n%3==1&&flag==0)
            flag=1,ans=cnt,n=n-n/3-1;
        else
        {
            if(n<=3) n--;
            else
            {
                if(n%3==0) n=n-n/3;
                else n=n-n/3-1;
            }
        }
    }
    printf("%d %d",cnt,ans);
    return 0;
}
