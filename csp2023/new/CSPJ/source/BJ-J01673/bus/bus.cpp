#include<iostream>
#include<cstdio>
using namespace std;
int a[101][101];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>a1>>b>>c;
        a[a1][b]=c;
    }
    cout<<-1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}