#include<bits/stdc++.h>
#define ll long long
const int N=500010;
int a[N],b[N];
int c,nn,mm,q;
int com[4010][4010],cnt[5010];
bool dp[4010][4010];
int maxn[4010],minn[4010];
int s[4010],d[4010];
using namespace std;
void solve(){
    int flag=0;
    if(s[1]>d[1]&&s[nn]>d[mm]) flag=1;
    if(s[1]<d[1]&&s[nn]<d[mm]) flag=2;
    if(!flag){
        cout<<0;
        return;
    }
    int n=nn,m=mm;
    for(int i=1;i<=n;i++)
        a[i]=s[i];
    for(int i=1;i<=m;i++)
        b[i]=d[i];
    if(flag==2){
        swap(n,m);
        swap(a,b);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]>b[j]){
                cnt[i]++;
                com[i][cnt[i]]=j;
            }
        }
    }
    memset(maxn,0,sizeof maxn);
    memset(minn,0,sizeof minn);
    for(int i=1;i<=n;i++){
        for(int j=max(minn[i-1],1);j<=maxn[i-1]+1&&j<=m;j++){
            if(a[i]>b[j]){
                minn[i]=j;
                break;
            }
        }
        if(minn[i]==0){
            cout<<0;
            return;
        }
        if(a[i]>b[maxn[i-1]])
        for(int j=maxn[i-1];j<=m;j++){
            if(a[i]<=b[j])
                break;
            maxn[i]=j;
        }
        else
        for(int j=maxn[i-1]-1;j>=0;j--){
            if(a[i]>b[j]){
                maxn[i]=j;
            break;
            }
        }
        //cout<<minn[i]<<maxn[i]<<endl;
    }
    if(maxn[n]==m)
        cout<<1;
    else cout<<0;
    return;
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>nn>>mm>>q;
    for(int i=1;i<=nn;i++)
        cin>>s[i];
    for(int i=1;i<=mm;i++)
        cin>>d[i];
    solve();
    for(int i=1;i<=q;i++){
        int x,y,p,v;
        cin>>x>>y;
        int p1[4010],v1[4010],p2[4010],v2[4010];
        for(int j=1;j<=x;j++){
            cin>>p>>v;
            p1[j]=p;
            v1[j]=s[p];
            s[p]=v;
        }
        for(int j=1;j<=y;j++){
            cin>>p>>v;
            p2[j]=p;
            v2[j]=d[p];
            d[p]=v;
        }
        solve();
        for(int j=1;j<=x;j++){
            s[p1[j]]=v1[j];
        }
        for(int j=1;j<=y;j++){
            d[p2[j]]=v2[j];
        }
    }
    return 0;
}//3 3 3 3 8 6 9 1 7 4
