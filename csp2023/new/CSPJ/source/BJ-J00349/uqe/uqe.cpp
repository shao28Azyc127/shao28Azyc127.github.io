#include<bits/stdc++.h>
using namespace std;
int t,m,a,b,c,delta;
bool flagg;
void outgen(int x)
{
    cout << "sqrt(" << x << ")";
    return ;
}
int zhishug(int x)
{
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
        return i;
    }
    return 0;
}
void yls(int p,int q)
{
    if(p==0)
    ;
    else
    {
        if(q==1)
        cout << p;
        else
        {
            if(p%q==0)
            cout << p/q;
            else
            {
                while(__gcd(p,q)!=1)
                {
                    int g=__gcd(p,q);
                    p/=g;
                    q/=g;
                }
                if(q<0)
                {
                    p=-p;
                    q=-q;
                }
                cout << p << "/" << q;
            }
        }
    }
}
bool pd(int numm,int p[])
{
    for(int i=0;i<numm;i++)
    {
        if(p[i]!=0)
        return 1;
    }
    return 0;
}
void mpsort(int numm,int p[])
{
    for(int i=0;i<numm-1;i++)
    {
        for(int j=0;j<numm-1;j++)
        {
            if(p[j]<p[j+1])
            swap(p[j],p[j+1]);
        }
    }
}
void genhao(int p)
{
    int num=0,ans1=1,ans2=1;
    int v[101];
    while(zhishug(p)!=0)
    {
        v[num++]=zhishug(p);
        p/=zhishug(p);
    }
    v[num++]=p;
    sort(v,v+num);
    int now=0;
    for(int i=0;i<num-1;i++)
    {
        if(v[i]!=0)
        {
            if(v[i]==v[i+1])
            {
                ans1*=v[i];
                v[i]=0;
                v[i+1]=0;
            }
        }
    }
    for(int i=0;i<num;i++)
    {
        if(v[i]!=0)
        ans2*=v[i];
    }
    if(ans1!=0)
    {
        if(__gcd(ans1,2*a)==1)
        cout << ans1 << '*' <<"sqrt(" << ans2 << ")";
        else
        {
            int op=2*a,ggcd;
            while(__gcd(ans1,op)!=1)
            {
                ggcd=__gcd(ans1,op);
                ans1/=ggcd;
                op/=ggcd;
            }
            if(ans1!=1)
            cout << ans1 << '*';
            cout <<"sqrt(" << ans2 << ")";
            if(op!=1)
            cout << '/' << op;
            cout << endl;
            flagg=1;
        }
    }
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ios::sync_with_stdio(0);
    cin >> t >> m;
    for(int i=0;i<t;i++)
    {
        flagg=0;
        cin >> a >> b >> c;
        delta=b*b-4*a*c;
        if(delta<0)
        cout << "NO\n";
        else if(delta==0)
        {
            yls(-b,2*a);
            cout << endl;
        }
        else if(delta>0)
        {
            int sq=sqrt(delta);
            if(sq*sq==delta)
            {
                if((-b+delta)%(2*a)==0)
                cout << (-b+sqrt(delta))/(2*a);
                else yls(-b+sqrt(delta),2*a);
                cout << endl;
            }
            else if(sq*sq!=delta)
            {
                yls(-b,2*a);
                if(-b!=0)
                cout << '+';
                if(zhishug(delta)==0)
                outgen(delta);
                else genhao(delta);
                if(flagg==0)
                cout << "/" << 2*a;
                else if(flagg==1)
                ;
                cout << endl;
            }
        }
    }
    return 0;
}
/*
9 1000
1 ©\1 0
©\1 ©\1 ©\1
1 ©\2 1
1 5 4
4 4 1
1 0 ©\432
1 ©\3 1
2 ©\4 1
1 7 1
*/
