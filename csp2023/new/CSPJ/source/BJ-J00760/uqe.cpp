#include<bits/stdc++.h>
using namespace std;
const int N=1e4+1;
int T,m,sq[N],cnt=0;
int gcd(int a,int b)
{
    return !b?a:gcd(b,a%b);
}
inline bool prime(int x)
{
    for(int i=2;i*i<=x;i++)
        if(!(x%i))
            return false;
    return true;
}
inline void Init()
{
    for(int i=2;true;i++)
    {
        if(i*i<=100000)
            sq[++cnt]=i*i;
        else break;
    }
    return;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Init();
    cin >> T >> m;
    while(T--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        int delta=b*b-4.0*a*c;
        if(delta<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else if(!delta)
        {
            int up=-b,down=2*a;
            int Gcd=abs(gcd(up,down));
            if(Gcd!=1)up/=Gcd,down/=Gcd;
            if(up==down)
                cout<<"1"<<endl;
            else cout<<up<<"/"<<down<<endl;
        }
        else
        {
            int SQ=sqrtl(delta);
            if(SQ*SQ==delta)//C
            {
                int up,down=2*a;
                if(down<0)up=-b-SQ;
                else up=-b+SQ;
                if(!up)
                {
                    cout<<0<<endl;
                    continue;
                }
                int Gcd=gcd(up,down);
                if(Gcd!=1)up/=Gcd,down/=Gcd;
                if(down==1)cout<<up<<endl;
                else cout<<up<<"/"<<down<<endl;
            }
            else
            {
                int q2=1;
                if(!prime(delta))
                {
                    for(int i=1;i<=cnt;i++)
                    {
                        if(sq[i]<=delta)
                        {
                            if(!(delta%sq[i]))
                                q2=abs(sqrtl(sq[i]));
                        }
                        else break;
                    }
                }
                delta/=q2*q2;
                if(!b)
                {
                    int up=q2,down=2*a;
                    if(down>0)up=abs(up);
                    else
                        if(up>0)up=-up;
                    int Gcd=gcd(up,down);
                    if(Gcd!=1)up/=Gcd,down/=Gcd;
                    if(q2!=1)
                        cout<<up<<"*";
                    if(down==1)
                        cout<<"sqrt("<<delta<<")"<<endl;
                    else cout<<"sqrt("<<delta<<")/"<<down<<endl;
                }
                else if(!c)
                {
                    int up,down=2*a;
                    if(down<0)up=-b-SQ;
                    else up=-b+SQ;
                    if(!up)
                    {
                        cout<<"0"<<endl;
                        continue;
                    }
                    int Gcd=gcd(up,down);
                    if(Gcd!=1)up/=Gcd,down/=Gcd;
                    if(down==1)cout<<up<<endl;
                    else cout<<up<<"/"<<down<<endl;
                }
                else
                {
                    int q1=-b/2*a,down=a*2;
                    if(q1)
                    {
                        if(-b==2*a)
                            cout<<"1+";
                        else cout<<-b<<"/"<<2*a<<"+";
                    }
                    if(q2==a*2)
                        cout<<"sqrt("<<delta<<")"<<endl;
                    else if(!(q2%(2*a)))
                        cout<<q2/(2*a)<<"*"<<"sqrt("<<delta<<")"<<endl;
                    else if(!((2*a)%q2))
                        cout<<"sqrt("<<delta<<")/"<<(2*a)/q2<<endl;
                    else cout<<q2<<"*sqrt("<<delta<<")/"<<2*a<<endl;
                }
            }
        }
    }
    return 0;
}