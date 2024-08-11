#include <iostream>
using namespace std;

int a[5005];
int b[5005];
int c[5005];
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    for(int i = 1;i <= t;i++)
    {
        cin >>a[i]>>b[i]>>c[i];
    }
    for(int i = 1;i <= t;i++)
    {#include <iostream>
using namespace std;

int a[5005];
int b[5005];
int c[5005];
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    for(int i = 1;i <= t;i++)
    {
        cin >>a[i]>>b[i]>>c[i];
    }
    for(int i = 1;i <= t;i++)
    {
        int d = b[i]*b[i]-4*a[i]*c[i];
        if(d < 0) cout <<"NO"<<endl;
        int x1 = (-b[i]+d)/2*a[i];
        int x2 = (-b[i]-d)/2*a[i];
        if(x2 == 1) cout <<"sqrt("<<x2<<")"<<endl;
        else cout <<x2<<"*sqrt("<<x1<<")"<<endl;
    }
    return 0;
}

        int d = b[i]*b[i]-4*a[i]*c[i];
        if(d < 0) cout <<"NO"<<endl;
        int x1 = (-b[i]+d)/2*a[i];
        int x2 = (-b[i]-d)/2*a[i];
        if(x2 == 1) cout <<"sqrt("<<x2<<")"<<endl;
        else cout <<x2<<"*sqrt("<<x1<<")"<<endl;
    }
    return 0;
}
