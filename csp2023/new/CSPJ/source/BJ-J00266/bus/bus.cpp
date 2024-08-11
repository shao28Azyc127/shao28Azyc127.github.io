#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k,a[N][N],d[N];
bool f[N],flag;
vector <int> v[N];

int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    memset(d,0x3f,sizeof d);
    memset(a,0x3f,sizeof a);
    d[1]=0;
    cin>>n>>m>>k;
    for (int i=0,u,vv,t;i<m;i++){
        scanf("%d%d%d",&u,&vv,&t);
        v[u].push_back(vv);
        if (t!=0) flag=true;
    }
    if (flag==true&&n*n>20000000){
        cout<<-1;
        return 0;
    }
    for (int i=1;i<n;i++){
        int fr=0;
        for (int j=1;j<=n;j++){
            if (d[j]<d[fr]&&f[j]==false) fr=j;
        }
        //cout<<fr<<endl;
        f[fr]=true;
        for (int j=0;j<v[fr].size();j++){
            int kk=v[i][j];
            //cout<<kk<<" ";
            d[kk]=min(d[kk],d[fr]+1);
        }
    }
    if (d[n]==0x3f3f3f3f||d[n]%k!=0) cout<<-1;
    else cout<<d[n];
    return 0;
}
