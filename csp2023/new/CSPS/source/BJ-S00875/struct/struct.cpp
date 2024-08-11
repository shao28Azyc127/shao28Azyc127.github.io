#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int M=1e6+5;
const int INF=2e9+5;
template<typename T>
inline void read(T &x) {
    x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
template<typename T>
void write(T x) {
    if(x>=10)write(x/10);
    putchar(x%10+'0');
}
int n,tot=0;
map<string,ll>mp;
map<ll,string>mpp;
int main() {
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) {
        int op;
        string leixing,name;
        cin>>op;
        if(op==2) {
            cin>>leixing>>name;
            mp[name]=tot;
            mpp[tot]=name;
            tot+=8;
        }
        if(op==3) {
            cin>>name;
            cout<<mp[name]<<endl;
        }
        if(op==4) {
            ll x;
            cin>>x;
            cout<<mpp[x]<<endl;
        }
    }
    return 0;
}
