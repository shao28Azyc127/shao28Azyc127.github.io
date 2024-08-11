#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    bool f=0;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int der=b*b-4*a*c;
        if(der<0)puts("NO");
        else{
            int x1=(-b+sqrt(der))/2*a,x2=(-b-sqrt(der))/2*a;
            printf("%d\n",max(x1,x2));
        }
    }
    return 0;
}
