#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n,m=100005,ma;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(b<m){
            m=b;
            ma=a;
        }
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
    }
    cout<<ceil(ma/m);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
