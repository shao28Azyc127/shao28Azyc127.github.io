#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,x;
char ch,a[100005];
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        int ans=0;
        for(int i=1;i<=m;i++){
            cin>>ch>>x;
            if(a[x]=='U')ans--;
            a[x]=ch;
            if(ch=='U')ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
