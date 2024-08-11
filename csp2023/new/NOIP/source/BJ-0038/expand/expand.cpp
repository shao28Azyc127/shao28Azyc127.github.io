#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,q;
int A[2300];
int B[2300];
int a[210],b[210];
int ta[210],tb[210];
bool f[210][210];
inline bool calc(){
    if(n==1||m==1)return 1;
    if((a[1]-b[1])*(a[n]-b[m])<=0)return 0;
    memset(f,0,sizeof(f));
    f[0][0]=1;
    bool sw=0;

    if(a[1]>b[1]){
        sw=1;
        swap(a,b);
        swap(n,m);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
             for(int k=i-1;k>=0;k--)
                if(a[k+1]>=b[j])break;
                else f[i][j]|=f[k][j-1];
            for(int k=j-1;k>=0;k--)
                if(a[i]>=b[k+1])break;
            else f[i][j]|=f[i-1][k];

        }
    bool r=f[n][m];
    if(sw)swap(n,m);
    return r;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++)cin>>A[i];
    for(int j=1;j<=m;j++)cin>>B[j];
    for(int i=1;i<=n;i++)
        a[i]=A[i];
    for(int i=1;i<=m;i++)
        b[i]=B[i];
    cout<<calc();
    while(q--){
        for(int i=1;i<=n;i++)
            a[i]=A[i];
        for(int i=1;i<=m;i++)
            b[i]=B[i];
        int ka,kb;
        cin>>ka>>kb;

        while(ka--){
            int x,y;
            cin>>x>>y;
            a[x]=y;
        }
        while(kb--){
            int x,y;
            cin>>x>>y;
            b[x]=y;
        }
        cout<<calc();
    }
    cout.flush();
    return 0;
}
