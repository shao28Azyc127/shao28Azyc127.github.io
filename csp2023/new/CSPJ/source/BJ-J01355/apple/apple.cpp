#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=1e9+5;
bool vis[N];
ll n,t;
int f(int x)
{
    if(x<=3) return x;
    return f(x-round(((double)(x+1))/3.0))+1;
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    t=f(n);
    if(n<=3) cout<<n<<" ";
    if(n==4) cout<<3<<" ";
    if(n>4) cout<<t<<" ";
    if(n%3==2)
    {
        cout<<t;
    }
    if(n%3==1)
    {
        cout<<1;
    }
    if(n%3==0)
    {
        cout<<2;
    }
    return 0;
}
