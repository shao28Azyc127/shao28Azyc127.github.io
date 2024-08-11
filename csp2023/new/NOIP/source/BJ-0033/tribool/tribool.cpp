#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
using namespace std;
long long read(){
    long long x=0,k=1;
    char c=getchar();
    for(;c!='-'&&(c>'9'||c<'0');c=getchar());
    if(c=='-') k=-1,c=getchar();
    for(;'0'<=c&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
    return x*k;
}
int n,m;
int a[200005],fa[200005];
int get_fa(int x){
    if(x<2) return x;
    if(fa[x]==x) return fa[x];
    return fa[x]=get_fa(fa[x]);
}
void merge(int x,int y){
    x=get_fa(x),y=get_fa(y);
    if(x==y) return;
    if(x<y) swap(x,y);
    // if(x<2) cout<<x<<" "<<y<<endl;
    fa[x]=y;
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int C=read(),T=read();
    int T2=0;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++) fa[i*2]=a[i*2]=i*2,fa[i*2+1]=a[i*2+1]=i*2+1;
        while(m--){
            char c=getchar();
            for(;c!='+'&&c!='-'&&c!='T'&&c!='F'&&c!='U';c=getchar());
            if(c=='+'){
                int x=read(),y=read();
                // cout<<c<<" "<<x<<" "<<y<<endl;
                a[x*2]=a[y*2],a[x*2+1]=a[y*2+1];
            }
            else if(c=='-'){
                int x=read(),y=read();
                // cout<<c<<" "<<x<<" "<<y<<endl;
                // cout<<x<<" "<<y<<endl;
                a[x*2]=a[y*2+1],a[x*2+1]=a[y*2];
            }
            else{
                int x=read();
                // cout<<c<<" "<<x<<endl;
                if(c=='U') a[x*2]=a[x*2+1]=0;
                else if(c=='T') a[x*2]=1,a[x*2+1]=-1;
                else a[x*2]=-1,a[x*2+1]=1;
            }
            // for(int i=1;i<=n;i++) cout<<a[i*2]<<"/"<<a[i*2+1]<<" "; puts("");
        }
        T2++;
        for(int i=1;i<=n;i++){
            merge(i*2,a[i*2]),merge(i*2+1,a[i*2+1]);
            // if(T2==3)
            // cout<<a[i*2]<<" "<<a[i*2+1]<<endl;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            // if(T2==3)
            // cout<<get_fa(i*2)<<" "<<get_fa(i*2+1)<<endl;
            ans+=get_fa(i*2)==get_fa(i*2+1);
        }
        cout<<ans<<endl;
    }
    return 0;
}