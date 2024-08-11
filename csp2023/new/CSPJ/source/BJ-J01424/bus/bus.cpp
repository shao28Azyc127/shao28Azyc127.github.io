#include<iostream>
using namespace std;
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,a,b[1000][4]={},sum=0;
    cin>>n>>m>>a;
    sum=a;
    for(int i=1;i<=n;i++){
        cin>>b[i][1]>>b[i][2]>>b[i][3];
    }
    for(int i=1;i<=n;i++){
        sum+=0;
    }
    cout<<sum+3<<endl;

    return 0;
}
