#include<iostream>
#include<cstdio>
using namespace std;
int c,t;
char x[100005];
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            char v;
            int t;
            cin>>v>>t;
            x[t]=v;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(x[i]=='U'){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}