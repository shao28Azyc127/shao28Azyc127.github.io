#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int N = 1e5+5;
#define int long long
int t,m;
int a,b,c;
signed main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--)
    {
        cin>>a>>b>>c;
        int delt = b*b-4*a*c;
        if(delt<0) cout << "NO\n";
        else
        {
            double t1 = 1.0*(-b+sqrt(delt))/(2*a);
            double t2 = 1.0*(-b-sqrt(delt))/(2*a);
            cout << max(t1,t2) << endl;
        }
    }
    return 0;
}
