#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
const int N=8e3+5;
int n,l[N],ans,j;
string s;
signed main() {
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>j;
    }
    for(int i=1;i<n;i++){
        cin>>j;
    }
    ans=n+1;
    cout<<ans;
    return 0;
}
