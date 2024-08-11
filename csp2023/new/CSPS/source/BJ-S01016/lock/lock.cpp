#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int n,a[N],b[N],c[N],d[N],e[N];
int cnt,ha[N][N][N][N][N];
int h1[]={0,0,1,1,1,-1,-1,-1};
int h2[]={1,-1,0,1,-1,0,1,-1};

int p(int x,int y)
{
    if(x+y==-1) return 9;
    else if(x+y==10) return 0;
    else return x+y;
}

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i]>>d[i]>>e[i];
    }

    for(int i=1;i<=n;i++)
    {
        int a1=a[i],b1=b[i],c1=c[i],d1=d[i],e1=e[i];
        for(int j=1;j<=9;j++)
        {
            if(ha[p(a1,h[j])])
            {
                cnt++;
            }
            if()
            {
                cnt++;

            }
            if()
            {
                cnt++;
                ha[a1][b1]
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
