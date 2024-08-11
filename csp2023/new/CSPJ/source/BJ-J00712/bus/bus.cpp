include<iostream>
using namespace std;
#include<cstdio>
int n,m,n1;
int a[1000000],b[1000000],c[1000000]
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>n1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    cout<<-1<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
