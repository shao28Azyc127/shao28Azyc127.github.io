#include<bits/stdc++.h>
using namespace std;
#define N 3005
int n,m,a[N][N],mx[N][N],mn[N][N];
char c[N];
inline int chk(int x){
    for(int i=1,fl;i<=n;++i){
        if(i==x) continue;
        fl=0;
        for(int j=1;j<=m;++j){
            if(mn[x][j]!=mx[i][j]){
                if(mn[x][j]<mx[i][j]) fl=1;
                break;
            }
        }
        if(!fl) return 0;
    } return 1;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>c+1;
        for(int j=1;j<=m;++j) a[i][j]=c[j]-'a';
    }
    memcpy(mx,a,sizeof mx),memcpy(mn,a,sizeof mn);
    for(int i=1;i<=n;++i){
        sort(mx[i]+1,mx[i]+m+1,[&](const int &a,const int &b){return a>b;});
        sort(mn[i]+1,mn[i]+m+1,[&](const int &a,const int &b){return a<b;});
    }
    for(int i=1;i<=n;++i) cout<<chk(i);
}
