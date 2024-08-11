#include<bits/stdc++.h>

using namespace std;
int n,a[16],ans;
int u[16],v[16],h[16];
int avl(int x,int y){
    if(x==y) return 0;
    int lst[10]={},cnt=0;
    for(int i=1;i<=5;i++){
        u[i]=x%10;
        v[i]=y%10;
        x/=10;
        y/=10;
        h[i]=v[i]-u[i];
        if(h[i]) lst[++cnt]=i;
    }
    if(cnt>2||cnt==0) return 0;
    if(cnt==1) return 1;
    return lst[1]+1==lst[2]&&
    (h[lst[1]]==h[lst[2]]||abs(h[lst[1]]-h[lst[2]])==10);
}
bool chk(int x){
    for(int i=1;i<=n;i++) if(!avl(a[i],x)) return 0;
    return 1;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++){
            int x;
            cin>>x;
            a[i]=a[i]*10+x;
        }
    for(int i=0;i<100000;i++) ans+=chk(i);
    cout<<ans;
    return 0;
}