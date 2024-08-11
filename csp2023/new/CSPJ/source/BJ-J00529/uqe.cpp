#include <bits/stdc++.h>
using namespace std;
void ylh(int jie)
{
    double kfc=2;
    while(jie*kfc!=(int)jie*(int)kfc)
    {
        kfc+=1;
    }
    cout << jie*kfc << "/" << kfc << endl;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,m;
    while(n--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        double t=b*b-4*a*c;
        if(t<0)
        {
            cout << "NO" << endl;
            continue;
        }
        else if(t==0)
        {
            double sq=sqrt(t);
            if(sq==(int)sq)
            {
                double jie=(sq-b)/(2*a);
                if(jie-(int)jie==0)
                {
                    cout << jie << endl;
                }
                else
                {
                    ylh(jie);
                }
            }
            else
            {
                cout << "^_^" << endl;
            }
        }
        else
        {
            double sq=sqrt(t);
            if(sq==(int)sq)
            {
                double jie1=(sq-b)/(2*a);
                double jie2=((-1*sq)-b)/(2*a);
                int jie;
                if(jie1>=jie2)
                {
                    jie=jie1;
                }
                else
                {
                    jie=jie2;
                }
                if(jie1-(int)jie1==0)
                {
                    cout << jie << endl;
                }
                else
                {
                    ylh(jie);
                }
            }
            else
            {
                cout << "^_^" << endl;
            }
        }
    }
    return 0;
}
