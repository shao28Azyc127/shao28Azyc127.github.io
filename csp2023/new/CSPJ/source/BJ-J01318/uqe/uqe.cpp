#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
struct abc
{
    int a;
    int b;
    int c;
};
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    string f[10000];
    cin>>t>>m;
    abc l[10000];
    for(int i=0;i<t;i++)
    {
        cin>>l[i].a>>l[i].b>>l[i].c;
        int g=(l[i].b*l[i].b)-(4*l[i].a*l[i].c);
        string h;
        if(g<0)
        {
            f[i]="NO";
        }
        else
        {
            int d=(0-l[i].b+sqrt(g))/2*l[i].a;
            h+=d%10+48;
            for(int j=h.size()-1;j>=0;j--)
            {
                f[i]+=h[j];
            }
        }
    }
    for(int i=0;i<t;i++)
    {
        cout<<f[i]<<endl;
    }
}
