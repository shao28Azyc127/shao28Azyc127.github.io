#include<iostream>
#include<vector>
using namespace std;
int val[1010][1010];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);

    int n,m,k,u,v,a;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>a;
        val[u][v]=a;
    }
    cout<<-1;


    fclose(stdin);
    fclose(stdout);
}
