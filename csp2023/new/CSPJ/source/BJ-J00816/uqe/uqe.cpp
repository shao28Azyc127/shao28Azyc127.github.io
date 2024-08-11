#include<bits/stdc++.h>
using namespace std;
long long _gcd(long long a,long long b)
{
    if(b==0)
    {
        return a;
    }
    _gcd(b,a%b);
}
int main()
{
    long long T,M;
    cin>>T>>M;
    while(T--)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        long long del=b*b-4*a*c;
        if(del<0)
        {
            cout<<"NO"<<endl;
        }
        if(del==0)
        {
            long long p,q;
            p=-b;
            q=2*a;
            p=p/_gcd(p,q);
            q=q/_gcd(p,q);
            if(p==0)
            {
                cout<<"0"<<endl;
            }else if(q==1)
            {
                cout<<p<<endl;
            }else{
                cout<<p<<"/"<<q<<endl;
            }
        }
        if(del>0)
        {
            long long p,q,qc=1;
            p=-b;
            q=2*a;
            for(long long i=2;i<del;i++)
            {
                long long c=0;
                while(del%i==0){
                    del/=i;
                    c++;
                }
                if(c==2){
                    del/=i;
                    qc=qc*i;
                }
            }
            if(del==1)
            {
                long long sn=p+qc;
                long long qs=q;
                sn=sn/_gcd(sn,qs);
                qs=qs/_gcd(sn,qs);
                if(sn==0)
                {
                    cou<<"0"<<endl;
                }else if(qs==1)
                {
                    cout<<sn<<endl;
                }else{
                    cout<<sn<<"/"<<qs<<endl;
                }
            }else{
                long long sum1=q;
                long long sum2=q;
                p=p/_gcd(sum1,p);
                sum1=sum1/_gcd(sum1,p);
                qc=qc/_gcd(qc,sum2);
                sum2=sum2/_gcd(qc,sum2);
                if(p==0)
                {
                    if(qc==1)
                    {
                        if(sum2==1)
                        {
                            cout<<"sqrt("<<del<<")"<<endl;
                        }else{
                            cout<<"sqrt("<<del<<")"<<"/"<<sum2<<endl;
                        }
                    }else{
                        if(sum2==1)
                        {
                            cout<<qc<<"*sqrt("<<del<<")"<<endl;
                        }else{
                            cout<<qc<<"*sqrt("<<del<<")"<<"/"<<sum2<<endl;
                        }
                    }
                }else if(p!=0&&sum1==1)
                {
                    if(qc==1)
                    {
                        if(sum2==1)
                        {
                            cout<<p<<"+"<<"sqrt("<<del<<")"<<endl;
                        }else{
                            cout<<p<<"+"<<"sqrt("<<del<<")"<<"/"<<sum2<<endl;
                        }
                    }else{
                        if(sum2==1)
                        {
                            cout<<p<<"+"<<qc<<"*sqrt("<<del<<")"<<endl;
                        }else{
                            cout<<p<<"+"<<qc<<"*sqrt("<<del<<")"<<"/"<<sum2<<endl;
                        }
                    }
                }else if(p!=0&&sum!=1)
                {
                    if(qc==1)
                    {
                        if(sum2==1)
                        {
                            cout<<p<<"/"<<sum1<<"+"<<"sqrt("<<del<<")"<<endl;
                        }else{
                            cout<<p<<"/"<<sum1<<"+"<<"sqrt("<<del<<")"<<"/"<<sum2<<endl;
                        }
                    }else{
                        if(sum2==1)
                        {
                            cout<<p<<"/"<<sum1<<"+"<<qc<<"*sqrt("<<del<<")"<<endl;
                        }else{
                            cout<<p<<"/"<<sum1<<"+"<<qc<<"*sqrt("<<del<<")"<<"/"<<sum2<<endl;
                        }
                    }
                }
            }
        }
    }
    return 0;
}