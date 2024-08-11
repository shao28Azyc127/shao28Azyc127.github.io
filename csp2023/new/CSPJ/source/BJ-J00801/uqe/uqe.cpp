#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int T,M;
int gcd(int a,int b)
{
    if(a == 0) return b;
    else return(gcd(b%a,a));
}

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);

    cin>>T>>M;
    int a,b,c,x1,y1,x2,y2,tmp,f1;
    while(T--)
    {
        x1 = x2 = y1 = y2 = f1 = 0;
        cin>>a>>b>>c;
        int delta = b*b-4*a*c;
        if(delta < 0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        int flag = 0;
        for(int i = 0;i*i <= delta;++i)
        {
            if(delta == i*i)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        {
            int ans1,ans2;
            x1 = sqrt(delta);
            ans1 = abs(x1-b);
            ans2 = abs(2*a);
            tmp = gcd(ans1,ans2);
            ans1 /= tmp,ans2 /= tmp;
            if(ans1 == 0)
            {
                cout<<0<<endl;
                continue;
            }
            if(((x1-b) < 0)^(2*a < 0))
            {
                if(ans2 == 1)
                {
                    cout<<-ans1<<endl;
                    continue;
                }
                else
                {
                    cout<<-ans1<<"/"<<ans2<<endl;
                    continue;
                }
            }
            else
            {
                if(ans2 == 1)
                {
                    cout<<ans1<<endl;
                    continue;
                }
                else
                {
                    cout<<ans1<<"/"<<ans2<<endl;
                    continue;
                }
            }

        }

        x2 = abs(b),y2 = abs(2*a);
        tmp = gcd(x2,y2);
        x2 /= tmp,y2 /= tmp;
        if(x2 != 0)
        {
            if((-b < 0)^(2*a < 0))
        {
            if(y2 == 1)
            {
                cout<<-x2<<"+";
            }
            else
            {
                cout<<-x2<<"/"<<y2<<"+";
            }
        }
        else
        {
            if(y2 == 1)
            {
                cout<<x2<<"+";
            }
            else
            {
                cout<<x2<<"/"<<y2<<"+";
            }
        }
        }


        y1 = abs(2*a);f1 = 1;

        x1 = delta;
        for(int i = 2;i*i <= x1;++i)
        {
            if(x1%(i*i) == 0)
            {
                f1 *= i;
                x1 /= (i*i);
            }
        }
        tmp = gcd(f1,y1);
        f1 /= tmp,y1 /= tmp;
        if(f1 == 1)
        {
            cout<<"sqrt("<<x1<<")";
        }
        else cout<<f1<<"*"<<"sqrt("<<x1<<")";
        if(y1 != 1)cout<<"/"<<y1;
        cout<<endl;
    }
    return 0;
}
