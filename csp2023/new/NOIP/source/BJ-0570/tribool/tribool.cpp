#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==3||c==4){
        for(int k=0;k<t;k++){
            int n,m;
            cin>>n>>m;
            int cnt = 0;
            int a[n+1];
            for(int i=1;i<=n;i++) a[i] = 0;
            int b[m+1];
            char d[m+1];
            for(int i=1;i<=m;i++){
                cin>>d[i]>>b[i];
            }
            for(int i=m;i>0;i--){
                if(d[i]=='U'&&a[b[i]]==0){
                    cnt++;
                }
                a[b[i]] = 1;
            }
            cout<<cnt<<endl;
        }
    }
    return 0;
}