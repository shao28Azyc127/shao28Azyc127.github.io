#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e9+5;
int n,num,day,q;
bool flag[MAXN];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    while(num<n)
    {
        int s=0,s3=0;
        for(int i=1;i<=n;i++)
        {
            if(s3==0&&flag[i]==0)
            {
                if(i==n)
                {
                    q=day+1;
                }
                flag[i]=1;
                s3=1;
                num++;
            }
            if(flag[i]==0)
            {
                s++;
            }
            if(s==3)
            {
                if(i==n)
                {
                    q=day+1;
                }
                flag[i]=1;
                s=0;
                num++;
            }
            if(num>=n)break;
        }
        day++;
    }
    printf("%d",day);
    printf(" ");
    printf("%d",q);
    return 0;
}
