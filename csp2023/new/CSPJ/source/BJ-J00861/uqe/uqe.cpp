#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

int gcd(int x,int y)
{
    if(y == 0) return x;
    return gcd(y,x%y);
}

void print(int a,int b)
{
    int k = gcd(abs(a),abs(b));
    a /= k;
    b /= k;
    if(b < 0)
    {
        a = -a;
        b = -b;
    }
    if(b == 1) cout << a;
    else if(b != 0) cout << a << "/" << b;
    else cout << a*2;

}

void work(int a,int b,int c)
{
    if(b*b-4*a*c < 0)
    {
        cout << "NO";
        return;
    }
    //cout q2*sqrt(b*b-4ac)
    int sum = b*b-4*a*c;
    if(int(sqrt(sum))*sqrt(sum) == sum)
    {
        if(2*a < 0) print(-b+sqrt(sum),2*a);
        else print(-b+sqrt(sum),2*a);
    }
    else
    {
        //cout << "_________";
        if(b != 0)
        {
            print(-b,2*a);
            cout << "+";
        }
        int nul = 1;
        //cout << sum << endl;
        for(int i = 2;i*i < sum;i++)
        {
            while(sum % (i*i) == 0)
            {
                sum /= i*i;
                nul *= i;
            }
            //cout << sum << " " << nul << endl;
        }
        a = abs(a);
        nul = abs(nul);
        a *= 2;
        //cout << nul << " " << a << endl;
        if(nul == a) cout << "sqrt(" << sum << ")";
        else if(abs(nul) % a == 0 && nul/a != 1) cout << nul/a << "*" << "sqrt(" << sum << ")";
        else if(nul == 1) cout << "sqrt(" << sum << ")" << "/" << a;
        else
        {
            int k = gcd(nul,a);
            nul /= k;
            a /= k;
            if(nul != 1) cout << nul << "*" << "sqrt(" << sum << ")" << "/" << a;
            else cout << "sqrt(" << sum << ")" << "/" << a;
        }
    }

}

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin >> t >> m;
    while(t--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        work(a,b,c);
        cout << endl;
    }
    return 0;
}
