#include <bits/stdc++.h>
using namespace std;

bool cmp(char a,char b)
{
    if(a>b)
        return true;
    return false;
}
char a[3000][3000];

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);

    int n,m;
    bool flag=true;
    scanf("%d%d",&n,&m);

    if(n==1)
    {
        printf("1");
        return 0;
    }

    //vector<string> a(n);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<n;i++)
    {
        sort(a[i],a[i]+m,cmp);
    }

    for(int i=0;i<n;i++)
    {
        reverse(a[i],a[i]+m);
        for(int j=0;j<n;j++)
        {
            if(i==j)continue;
            if(strncmp(a[i],a[j],m)>=0)
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            printf("1");
        }
        else
        {
            printf("0");
            flag=true;
        }
        reverse(a[i],a[i]+m);
    }

    return 0;
}
