#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,m;
int gcd(int x,int y)
{
    if(y==0)
        return x;
    return gcd(y,x%y);
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> t >> m;
    for(int i=1;i<=t;++i)
    {
        //cout << i << " ";
        int a,b,c;
        bool fa=0,fb=0,fc=0;
        cin >> a >> b >> c;
        if(a<0)
        {
            a = -a;
            b = -b;
            c = -c;
        }
        int delta = b*b-4*a*c;
        if(delta<0)
        {
            cout << "NO" << endl;
            continue;
        }
        //cout << "delta=" << delta << " ";
        int d = sqrt(delta);
        if(d*d==delta)
        {
            int q = int(sqrt(delta))-b;
            //cout << q << " ";
            if(q<0)
            {
                cout << '-';
                q = -q;
            }
            if(q%(a+a)==0)
                cout << q/2/a << endl;
            else
            {
                int g = gcd(q,a+a);
                cout << q/g << '/' << 2*a/g << endl;
            }
            continue;
        }
        if(b>0)
        {
            cout << '-';
        }
        if(b<0)
            b = -b;
        if(b!=0)
        {
            if(b%(2*a)==0)
            {
                cout << b/2/a;
            }
            else
            {
                int g = gcd(b,a+a);
                cout << b/g << '/' << 2*a/g;
            }
            cout << '+';
        }
        int ds = 1;
        for(int j=2;j*j<=delta;++j)
        {
            if(delta%(j*j)==0)
            {
                delta /= (j*j);
                ds *= j;
                //cout << "delta="<<delta<<" ";
                --j;
            }
        }
        //cout << "ds=" << ds << " ";
        int g = gcd(ds,a+a);
        //cout << "gcd=" <<gcd << " ";
        if(ds==a+a)
            cout << "sqrt(" << delta << ")" << endl;
        else if(ds%(a+a)==0)
            cout << ds/a/2 << "*sqrt(" << delta << ")" << endl;
        else if(ds==g)
            cout << "sqrt(" << delta << ")/" << a*2/g << endl;
        else
            cout << ds/g << "*sqrt(" << delta << ")/" << a*2/g << endl;
    }
    return 0;
}
