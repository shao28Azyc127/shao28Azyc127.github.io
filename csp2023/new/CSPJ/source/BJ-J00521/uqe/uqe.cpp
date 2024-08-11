#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#include<time.h>
#include<cstdio>
#include<map>
#include<set>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,m,a,b,c,xid,gend;
ll cmpx,cmpy;
struct node
{
    ll beichu,chu,xi,gen;
    double shu1,shu2,shuzong;
    //x=beichu/chu+xi*sqrt(gen)/chu;
}x[110];
void cmp(ll x)
{
    gend=x;xid=1;
    for(int i=2;i*i<=gend;i++)
    {
        while(gend%(i*i)==0)
        {
            xid*=i;
            gend/=(i*i);
        }
    }
}
ll gcd(ll a,ll b)
{
    if(a==0||b==0) return 1;
    if(a%b==0) return b;
    else return gcd(b,a%b);
}
void put(ll x,ll y)
{
    ll s=gcd(x,y);
//    x[f].xi/=s,x[f].chu2/=s;
    cmpx=x/s,cmpy=y/s;
    if(cmpx*cmpy<0&&cmpx>0) cmpx=0-cmpx,cmpy=0-cmpy;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
//    cout<<gcd(t,m);
    while(t--)
    {
        cin>>a>>b>>c;
        ll dert=b*b-4*a*c;
//        cin>>dert;
        cmp(dert);
//        cout<<dert<<endl;
//        cout<<xid<<" "<<gend<<endl;
        if(dert<ll(0))
        {
            cout<<"NO"<<endl;
            continue;
        }
        x[1].beichu=-b;
        x[1].chu=2*a;
        x[1].gen=gend;
        x[1].xi=xid;
    //    put(1);put2(1);

        x[1].shu1=x[1].beichu*1.0/x[1].chu;
        x[1].shu2=x[1].xi*1.0*sqrt(x[1].gen*1.0)/x[1].chu;
        x[1].shuzong=x[1].shu1+x[1].shu2;


        x[2].beichu=-b;
        x[2].chu=2*a;
        x[2].gen=gend;
        x[2].xi=-xid;
   //     put(2);put2(2);

        x[2].shu1=x[2].beichu*1.0/x[2].chu;
        x[2].shu2=x[2].xi*1.0*sqrt(x[2].gen*1.0)/x[2].chu;
        x[2].shuzong=x[2].shu1+x[2].shu2;

        int big;
        if(x[1].shuzong>=x[2].shuzong) big=1;
        else big=2;

//        cout<<x[1].shuzong<<":"<<x[1].beichu<<"/"<<x[1].chu<<"+"<<x[1].xi<<"*sqrt("<<x[1].gen<<")/"<<x[1].chu<<endl;
//        cout<<x[2].shuzong<<":"<<x[2].beichu<<"/"<<x[2].chu<<"+"<<x[2].xi<<"*sqrt("<<x[2].gen<<")/"<<x[2].chu<<endl;
//        cout<<x[big].shuzong<<":"<<x[big].beichu<<"/"<<x[big].chu<<"+"<<x[big].xi<<"*sqrt("<<x[big].gen<<")/"<<x[big].chu<<endl;
    //    cout<<x[big].shu<<":"<<x[big].beichu<<"/"<<x[big].chu<<"+"<<x[big].xi<<"*sqrt("<<x[big].gen<<")/"<<x[2].chu2<<endl;

        if(x[big].gen==0)
        {
            if(x[big].beichu%x[big].chu==0)
            {
                cout<<x[big].beichu/x[big].chu<<endl;
                continue;
            }
            else
            {
                put(x[big].beichu,x[big].chu);
                cout<<cmpx<<"/"<<cmpy<<endl;
                continue;
            }
        }
        if(x[big].gen==1)
        {
            if((x[big].beichu+x[big].xi)%x[big].chu==0)
            {
                cout<<(x[big].beichu+x[big].xi)/x[big].chu<<endl;
                continue;
            }
            else
            {
                put(x[big].beichu+x[big].xi,x[big].chu);
                cout<<cmpx<<"/"<<cmpy<<endl;
                continue;
            }
        }

        put(x[big].beichu,x[big].chu);
        if(cmpx%cmpy==0&&cmpx!=0) cout<<cmpx<<"+";
        else if(cmpx!=0) cout<<cmpx<<"/"<<cmpy<<"+";

        put(x[big].xi,x[big].chu);
        if(cmpx==cmpy) cout<<"sqrt("<<x[big].gen<<")"<<endl;
        else if(cmpy==1) cout<<cmpx<<"*sqrt("<<x[big].gen<<")"<<endl;
        else if(cmpx==1) cout<<"sqrt("<<x[big].gen<<")/"<<cmpy<<endl;
        else cout<<cmpx<<"*sqrt("<<x[big].gen<<")/"<<cmpy<<endl;
    }
    return 0;
}
