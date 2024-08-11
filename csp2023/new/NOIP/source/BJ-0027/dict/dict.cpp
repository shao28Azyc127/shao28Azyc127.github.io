#include<bits/stdc++.h>
#define For(i,l,r) for(register int i=(l);i<=(r);++i)
#define For_down(i,r,l) for(register int i=(r);i>=(l);--i)
using namespace std;
const int n_MAX=3000+5;
int n,m; char s[n_MAX]; vector<char> a[n_MAX],b[n_MAX],P[n_MAX],S[n_MAX];
void output(const vector<char> &a)
{
    For(i,0,m-1) cerr<<a[i];
    cerr<<'\n';
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    For(i,1,n) a[i].resize(m),b[i].resize(m);
    For(i,1,n) 
    {
        cin>>s;
        For(j,0,m-1) a[i][j]=s[j];
        sort(a[i].begin(),a[i].end());
        b[i]=a[i];
        reverse(b[i].begin(),b[i].end());
    }
    P[1]=b[1]; For(i,2,n) P[i]=min(P[i-1],b[i]);
    S[n]=b[n]; For_down(i,n-1,1) S[i]=min(S[i+1],b[i]);
    For(i,1,n)
    {
        bool Flag=true;
        if((i>=2)&&(a[i]>=P[i-1])) Flag=false;
        if((i<=(n-1))&&(a[i]>=S[i+1])) Flag=false;
        cout<<Flag;
    }
    cout<<'\n'; return 0;
}