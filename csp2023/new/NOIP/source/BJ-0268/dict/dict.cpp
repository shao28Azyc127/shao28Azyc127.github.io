#include<bits/stdc++.h>
using namespace std;
const int N=3010;
struct Node{
    string s;int id;
}a[N];
int n,m,ans[N];char x[N];
inline bool cmp(Node x,Node y){return x.s<y.s;}
inline bool cmp1(char x,char y){return x<y;}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    if(n==1){cout<<1<<'\n';return 0;}
    for(int i=1;i<=n;i++) cin>>a[i].s,a[i].id=i;
    sort(a+1,a+n+1,cmp);
    ans[a[1].id]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++)x[j]=a[i].s[j-1];
        sort(x+1,x+m+1,cmp1);
        int cnt=0,flag=0;
        for(int j=1;j<=m;j++)
            if(x[j]<a[1].s[j-1]) {flag=1;break;}
        if(flag) ans[a[i].id]=1;
    }
    for(int i=1;i<=n;i++) cout<<ans[i];cout<<'\n';
    return 0;
}