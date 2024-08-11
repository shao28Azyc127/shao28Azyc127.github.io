#include<bits/stdc++.h>
using namespace std;
int n,m;


int dt(int a,int b,int c)
{
    int res;
    res=b*b-4*a*c;
    return res;
}

int r(int a,int b,int c,int dtt)
{

    return max((-b+sqrt(dtt))/2*a,(-b-sqrt(dtt))/2*a);
}

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {

        int a,b,c;
        cin>>a>>b>>c;
        if(dt(a,b,c)<0)
        {

            cout<<"NO"<<endl;
        }
        else
        {
            cout<<r(a,b,c,dt(a,b,c))<<endl;
        }
    }
    return 0;
}
