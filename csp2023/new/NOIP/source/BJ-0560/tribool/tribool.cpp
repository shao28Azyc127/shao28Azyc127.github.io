#include<bits/stdc++.h>
using namespace std;
int c,t,n,m;
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>m;
        int a[1000000];
        char v;
        int x;
        for(int j=1;j<=m;j++){
            cin>>v;
            cin>>x;
            if(v=='T') a[x]=2;
            else if(v=='F') a[x]=0;
            else if(v=='U') a[x]=1;
        }
        int cnt=0;
        for(int j=1;j<=n;j++) {
            if(a[j]==1) cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
