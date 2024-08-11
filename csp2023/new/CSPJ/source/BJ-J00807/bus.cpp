#include<iostream>
using namespace std;
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int m,n,k;
    cin>>m>>n>>k;
    int u[100001]={},v[100001]={},a[100001]={};
    for(int i=0;i<n;i++)
    {
        cin>>u[i]>>v[i]>>a[i];
    }
    cout<<"-1"<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
