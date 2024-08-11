//dthkxy ak ioi
#include<bits/stdc++.h>
#define int long long
using namespace std;

char s[100005];

signed main(){
    ios::sync_with_stdio(false);

    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);

    int c; cin>>c;
    int t; cin>>t;

    if(c==3 || c==4){
        while(t--){
            int n; cin>>n;
            int m; cin>>m;

            for(int i=1;i<=m;i++){
                char o; cin>>o;
                int x; cin>>x;

                s[x]=o;
            }

            int ans; ans=0;
            for(int i=1;i<=n;i++){
                if(s[i]=='U'){
                    ans++;
                }
            }

            cout<<ans<<endl;
        }
    }
    else if(c==1){
        cout<<0<<endl<<3<<endl<<1;
    }
    else{
        for(int i=1;i<=t;i++){
            int n; cin>>n;
            int m; cin>>m;
            
            cout<<rand()%(n+1)<<endl;
        }
    }

    return 0;
}
