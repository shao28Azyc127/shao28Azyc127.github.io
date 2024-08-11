#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int a[1010];
int b[1010];
int c[1010];
double u1,u2,q,p,derta;
int gcd(int x,int y)
{
    for(int i = max(x,y);i >= 1;i--)
    {
        if(x%i==0&&y&i==0)
        {
            return i;
        }
    }
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i = 1;i <= n;i++)
    {
        if(b[i]*b[i]-(4*a[i]*c[i])<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        derta=b[i]*b[i]-4*a[i]*c[i];
        u1=b[i]*-1+sqrt(derta);
        u1/=2*a[i];
        u2=b[i]*-1+sqrt(derta)*-1;
        u2/=2*a[i];
        if(u1==u2)
        {
            cout<<u2<<endl;
            continue;
        }
        else{
            cout<<max(u1,u2);
        }
    }
    fclose(stdin);
    fclose(stdout);
}
