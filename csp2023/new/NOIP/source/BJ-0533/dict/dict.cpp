#include<iostream>
#include<string>
#include<algorithm>
#define MAXN 1010
using namespace std;
struct node{
    int id;
    int num;
}a[MAXN*2];
int b[MAXN];
int n,m;
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        a[i].num=(int)c;
    }
    for(int i=1;i<=n;i++)
    {
        a[i].id=i;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            b[j]=a[i].num;
        }
        sort(b+1,b+m+1);
        for(int j=1;j<=m;j++)
        {
            a[i].num=b[j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i==a[i].id) cout<<1;
        else cout<<0;
    }
    return 0;
}
