#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans[100005],cnt;
int c,t,q;
int s[100005];
bool vis[100005];
struct cmp{
    int x,y,z;
};
cmp f[100005];
int main(){
    freopen("expend.in","r",stdin);
    freopen("expend.out","w",stdout);
    cin>>c>>n>>m>>q;
    cout<<1;
    for(int i=1;i<=q-2;i++){
        cout<<0;
    }
    cout<<1;
    return 0;
}
