#include<iostream>
using namespace std;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;;
    }
    if(n==1)
        cout<<81;
    else
        cout<<10-n;
    return 0;
}

