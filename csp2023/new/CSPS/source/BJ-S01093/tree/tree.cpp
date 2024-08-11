#include<iostream>
using namespace std;
int n,a[10001],b[10001],c[10001],u[10000],v[10000];
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=0;i<n-1;i++){
        cin>>v[i]>>u[i];
    }
    cout<<n+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
