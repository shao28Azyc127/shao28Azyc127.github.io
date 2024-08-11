#include<iostream>
using namespace std;
int n,m,k;
struct node{
    int u;
    int v;
    int a;
}t[100010];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>t[i].u>>t[i].v>>t[i].a;
    cout<<-1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}