#include<iostream>
#include<cstdio>
using namespace std;
struct fc{
    long long u;
    long long v;
    long long a;
}t[6024];
int mian(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>t[i].u>>t[i].v>>t[i].a;
    }
    long long time;
    cout<<2*m;
    fclose(stdin);
    fclose(stdout);
    
}

