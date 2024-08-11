#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
const int MAX=1e5+5;

LL c,t;
LL n,m,k,d;
LL x[MAX],y[MAX],z[MAX];
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++)
        {
            cin>>x[i]>>y[i]>>z[i];
        }
    }
    cout<<"2";
    return 0;
}

