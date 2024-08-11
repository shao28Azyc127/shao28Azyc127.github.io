#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[100007];
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        int n,m,k,d;
        cin>>n>>m>>k>>d;
        int c[n+1];
        int v[n+1];
        for(int j=1;j<=m;j++){
            int x,y,z;
            cin>>x>>y>>z;
            c[j]=x;
            v[j]=z-(y*d);
        }
        cout<<v[1]<<endl;
    }
    return 0;
}
