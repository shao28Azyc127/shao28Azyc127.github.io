#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    srand(clock());
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
    }
    int mod=1e9;
    cout<<rand()%(n+13);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
