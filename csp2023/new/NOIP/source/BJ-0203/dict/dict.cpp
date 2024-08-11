#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
const int N=3005;
int n,m,a[N][30],mn[N],mx[N];
char c[N];
const ll mod=998244353,bas=131;
ll has(int l,int r,int id) {

}
bool cmp(int x,int y) {
    return x>y;
}
int main() {
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    rep(i,1,n) mn[i]=1e9,mx[i]=-1e9;
    rep(i,1,n) {
        cin>>c+1;
        rep(j,1,m) a[i][c[j]-'a'+1]++,mn[i]=min(mn[i],c[j]-'a'+1),mx[i]=max(mx[i],c[j]-'a'+1);
    }
    if(n==1) {
        cout<<1;
        return 0;
    }
    rep(i,1,n) {
        bool ok=1;
        rep(j,1,n) {
            if(i==j) continue;
            if(mx[j]<=mn[i]) {
                ok=0;
                break;
            }
        }
        cout<<ok;
    }
    return 0;
}
