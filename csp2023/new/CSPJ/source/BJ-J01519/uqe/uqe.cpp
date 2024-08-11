#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int main ()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin >> t >> m;
    while(t--)
    {
        int a,b,c;
        cin >>a >> b >>c;
        int r=b*b-4*a*c;
        if(r<0)cout << "NO" << endl;
        else{
            int p=0-b+sqrt(r);
            int q=2*a;
            if(p%q==0)
            {
                q=1;
                p=p/q;
                cout << p/2;
            }
            else{
                if(q%p==0)
                {
                    p=1;
                    q=q/p;
                }
                cout << p << '/' << q << endl;
            }
        }
    }
    return 0;
}
