#include <bits/stdc++.h>
#define ll long long
#define db double
#define MAXN 100000
#define P 998244353

using namespace std;

int c,t;
int n,m;
int d[MAXN+5];
int ans;

int main(){

    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);

    scanf("%d%d",&c,&t);
    if(c==3||c==4){
        while(t--){
            scanf("%d%d",&n,&m);
            ans=0;
            for(int i=1;i<=n;i++) d[i]=1;
            for(int i=1;i<=m;i++){
                char v;
                int x;
                cin>>v>>x;
                if(d[x]!=0&&v=='U') ans++,d[x]=0;
                if(d[x]==0&&v!='U') ans--,d[x]=1;
            }
            printf("%d\n",ans);
        }
    }

    return 0;
}
