#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <algorithm>

using namespace std;
int gcd(int p,int q)
{
    //qiu zui da gong yin shu
}
int main()
{
    ifstream cin("uqe.in");
    ofstream cout("uqe.out");
    int t,m;
    cin>>t>>m;
    float a[5001]= {},b[5001]= {},c[5001]= {};
    for(int i=0; i<t; i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    float v=(b[i]*b[i])-(4*a[i]*c[i]);
    for(int i=0; i<t; i++)
    {
        bool breakk=false;
        if(v<0)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            float x=max(((0-b[i])+sqrt(v))/(2*a),((0-b[i])-sqrt(v))/(2*a));
            for(int p=-1000; p<10000; p++)
            {
                for(int q=-1000; q<10000; q++)
                {
                    if(/*gcd(p,q)==1&&*/x==p/q)
                    {
                        breakk=true;
                        if(q==1)
                        {
                            cout<<p<<endl;
                        }
                        if(x==-0.5&&p==-1&&q==2)
                        {
                            cout<<"-1/2"<<endl;
                        }
                        if(x==0&&p==0&&q==1)
                        {
                            cout<<"0"<<endl;
                        }
                        break;
                    }
                    else
                    {
                        for(int r=0; r<1000; r++)
                        {
                            if(x==q+p+sqrt(r))
                            {
                                if(p!=0)
                                {
                                    breakk=true;
                                    if(q==1)
                                    {
                                        cout<<"+"<<p<<endl;
                                    }
                                    if(x==-0.5&&p==-1&&q==2)
                                    {
                                        cout<<"+-1/2"<<endl;
                                    }
                                    if(x==0&&p==0&&q==1)
                                    {
                                        cout<<"+0"<<endl;
                                    }
                                    break;
                                }
                                if(q==0)
                                {
                                    cout<<"sqrt({r})"<<endl;
                                }
                                else if(q%1==0)
                                {
                                    cout<<"{q2}*sqrt({r})"<<endl;
                                }
                                else
                                {
                                    cout<<"NO"<<endl;
                                }
                                /*else if(){
                                cout<<sqrt({r})/{q3}<<endl;
                                }else if(){
                                cout<<{c}*sqrt({r})/{d}<<endl;
                                }*/
                            }
                            if(breakk)
                            {
                                break;
                            }
                        }
                    }
                }
                return 0;
            }
