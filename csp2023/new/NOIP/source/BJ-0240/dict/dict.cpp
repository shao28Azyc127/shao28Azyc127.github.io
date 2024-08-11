#include<bits/stdc++.h>
using namespace std;
char a[3001][3001],b[3001][3001];
bool cmp(char x,char y)
{
    return x>y;
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        sort(a[i],a[i]+m,cmp);
        strcpy(b[i],a[i]);
        sort(a[i],a[i]+m);
    }
    int flag;
    for(int i=1;i<=n;i++)
    {
        flag=1;
        for(int j=1;j<=n;j++)
        {
            if(j==i)
                continue;
            if(strcmp(a[i],b[j])>0)
            {
                flag=0;
                break;
            }
        }
        cout<<flag;
    }
    return 0;
}
