#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
int t;
int gcd(int a,int b)
{
    if (a<0)
    {
        a=-1*a;
    }
    if (b<0)
    {
        b=-1*b;
    }
    if (a<b)
    {
        t=a;
    }
    else{
        t=b;
    }
    for (int i=t;i>=1;i--)
    {

        if(a%i==0&&b%i==0)
        {
            return i;
        }
    }
}

double v(double n)
{
    for (double q=1;q<=100;q+=1 )
    {
        for (double p=-100;p<=100;p+=1)
        {
            if (n==(double)(p/q)&&gcd(p,q)==1)
            {
                //cout<<" "<<p<<" "<<q<<endl;
                return q;
            }
        }
    }
    return 101;
}



int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M,delta;
    cin>>T>>M;
    double x,p,q,q1,q2,sd1,sd2,flag=0,r;
    int a[101],b[101],c[101];
    for (int i=0;i<T;i++)
    {
        sd1=0;
        sd2=0;
        flag=0;
        cin>>a[i]>>b[i]>>c[i];
        delta =b[i]*b[i]-4*a[i]*c[i];
        for (int j=int(sqrt(delta));j>1;j--)
        {
            if (delta%(j*j)==0)
            {
                sd1=j;
                sd2=delta/(j*j);
                //cout<<"   "<<sd1<<" "<<sd2<<endl;;
                flag=1;
                break;
            }
        }
        if (flag==0)
        {


                sd1=1;
                sd2=delta;



        }
        if (delta==0)
            {

                sd1=0;
                sd2=0;
            }
        //cout<<" "<<sd1<<" "<<sd2<<endl;
        if (delta<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        //cout<<"    "<<b[i]<<" "<<sd1<<" "<<sd2<<" "<<a[i]<<endl;
        x=(-1*b[i]+sd1*sqrt(sd2))/(2*a[i]);
        p=x*v(x);
        q=v(x);
        //cout<<" "<<q<<endl;
        if (q!=101)
        {
            if (q==1)
            {
                cout<<p<<endl;
            }
            else
            {
                cout<<p<<"/"<<q<<endl;
            }
        }
        else
        {
            //cout<<"   "<<b[i]<<" "<<a[i]<<endl;
            q1=(double)(-1*b[i])/(2*a[i]);
            q2=sd1/(2*a[i]);
            r=sd2;
            //cout<<" "<<q1<<" "<<q2<<" "<<r<<endl;
            if (q1!=0)
            {
                  p=q1*v(q1);
            q=v(q1);
            if (q!=101)
            {
                if (q==1)
                {
                    cout<<p<<"+";
                }
                else
                {
                    cout<<p<<"/"<<q<<"+";
                }
            }
            }
            p=q2*v(q2);
            q=v(q2);

            if (q2==1)
            {
                cout<<"sqrt("<<r<<")"<<endl;
            }
            else if (q2>=1||q2<=-1)
            {
                if (q!=101)
            {
                if (q==1)
                {
                    cout<<q2<<"*"<<"sqrt("<<r<<")"<<endl;
                }
                else
                {
                    cout<<p<<"*"<<"sqrt("<<r<<")"<<"/"<<q<<endl;
                }
            }

            }
            else if (q2<1&&q2>-1)
            {

                cout<<"sqrt("<<r<<")"<<"/"<<(1/q2)<<endl;

            }
        }
    }
    return 0;
}
