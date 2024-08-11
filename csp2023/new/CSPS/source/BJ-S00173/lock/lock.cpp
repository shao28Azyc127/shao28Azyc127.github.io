#include<bits/stdc++.h>
#define For(i,l,r) for(register int i=(l);i<=(r);++i)
#define For_down(i,r,l) for(register int i=(r);i>=(l);--i)
using namespace std;
const int n_MAX=100+5;
int n,trans[10][10];
array<int,5> a[n_MAX],b[n_MAX],c[n_MAX][n_MAX];
void DFS(const array<int,5> a,array<int,5> b[])
{
    int m=0;
    For(i,0,4) For(x,1,9) ++m,b[m]=a,b[m][i]=trans[b[m][i]][x];
    For(i,0,3) For(x,1,9) ++m,b[m]=a,b[m][i]=trans[b[m][i]][x],b[m][i+1]=trans[b[m][i+1]][x];
}
set<array<int,5>> S;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    const int m=81;
    For(i,0,9) For(j,0,9) trans[i][j]=((i+j)%10);
    For(i,1,n) For(j,0,4) cin>>a[i][j];
    DFS(a[1],b);
    For(i,1,m) DFS(b[i],c[i]);
    int ans=0;
    For(i,1,m)
    {
        S.clear();
        For(j,1,m) S.insert(c[i][j]);
        bool Flag=true;
        For(j,1,n) if(S.find(a[j])==S.end()){Flag=false;break;}
        if(Flag) ++ans;
    }
    cout<<ans<<'\n'; return 0;
}