#include<bits/stdc++.h>
using namespace std;
int n,lo[10][10],sum;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    if(n==1)
    {
        cout<<81;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>lo[i][j];
        }
    }
    for(int a=0;a<=9;a++)
    {
        for(int b=0;b<=9;b++)
        {
            for(int c=0;c<=9;c++)
            {
                for(int d=0;d<=9;d++)
                {
                    for(int e=0;e<=9;e++)
                    {
                        bool l=true;
                        for(int i=1;i<=n;i++)
                        {
                            int _a,_b,_c,_d,_e;
                            _a=lo[i][1]-a;
                            _b=lo[i][2]-b;
                            _c=lo[i][3]-c;
                            _d=lo[i][4]-d;
                            _e=lo[i][5]-e;
                            if((!(_a==0 && _b==0 && _c==0 && _d==0)))
                                if((!(_a==0 && _b==0 && _c==0 && _e==0)))
                                    if((!(_a==0 && _b==0 && _d==0 && _e==0)))
                                        if((!(_a==0 && _c==0 && _d==0 && _e==0)))
                                            if((!(_b==0 && _c==0 && _d==0 && _e==0)))
                                                if((!(_a==0 && _b==0 && _c==0 && _d==_e)))
                                                    if((!(_a==0 && _b==0 && _e==0 && _c==_d)))
                                                        if((!(_a==0 && _d==0 && _e==0 && _b==_c)))
                                                            if((!(_c==0 && _d==0 && _e==0 && _a==_b)))
                                                                l=false;
                        }
                        if(l)
                        {
                            cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;
                            sum++;
                        }
                    }
                }
            }
        }
    }
    cout<<sum;
    return 0;
}
