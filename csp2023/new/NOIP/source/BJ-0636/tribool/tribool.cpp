#include<bits/stdc++.h>
using namespace std;
int c,t,m,n,x,y,z;
char op,a[100005];
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    if(c==3||c==4){
        for(int g=1;g<=t;g++){
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            cin>>op;
            cin>>z;
            a[z]=op;

        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]=='U') cnt++;
        }
        cout<<cnt;
        }
    }

return 0;
}
