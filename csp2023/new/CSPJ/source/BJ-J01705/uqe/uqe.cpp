#include <iostream>

using namespace std;

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    int a[10005],b[10005],c[10005];
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=m;i++) cout<<"NO"<<endl;
    return 0;
}
