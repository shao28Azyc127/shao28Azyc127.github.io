#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e5+7;
int n;
int f[Nmax];
int vis[Nmax];
int ans;
int ret(int q,int p,int qq,int pp,int qp){
    return q*10000+p*1000+qq*100+pp*10+qp;
}
int main(){
    freopen("lock.in","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        vis[ret(a,b,c,d,e)]=1;
        int a1=a,b1=b,c1=c,d1=d,e1=e;
        for(int j=1;j<=9;j++){
            int a2=(a-j+10)%10,b2=(b-j+10)%10,c2=(c-j+10)%10,d2=(d-j+10)%10,e2=(e-j+10)%10;
            f[ret(a2,b2,c,d,e)]+=1;
            f[ret(a,b2,c2,d,e)]+=1;
            f[ret(a,b,c2,d2,e)]+=1;
            f[ret(a,b,c,d2,e2)]+=1;
        }
        while(a-1>=0){
            f[ret(a-1,b,c,d,e)]+=1;
            a--;
        }a=a1;b=b1;c=c1;d=d1;e=e1;
        while(b-1>=0){
            f[ret(a,b-1,c,d,e)]+=1;
            b--;
        }a=a1;b=b1;c=c1;d=d1;e=e1;
        while(c-1>=0){
            f[ret(a,b,c-1,d,e)]+=1;
            c--;
        }a=a1;b=b1;c=c1;d=d1;e=e1;
        while(d-1>=0){
            f[ret(a,b,c,d-1,e)]+=1;
            d--;
        }a=a1;b=b1;c=c1;d=d1;e=e1;
        while(e-1>=0){
            f[ret(a,b,c,d,e-1)]+=1;
            e--;
        }a=a1;b=b1;c=c1;d=d1;e=e1;
        while(a+1<=9){
            f[ret(a+1,b,c,d,e)]+=1;a++;
        }a=a1;b=b1;c=c1;d=d1;e=e1;
        while(b+1<=9){
            f[ret(a,b+1,c,d,e)]+=1;b++;
        }a=a1;b=b1;c=c1;d=d1;e=e1;
        while(c+1<=9){
            f[ret(a,b,c+1,d,e)]+=1;c++;
        }a=a1;b=b1;c=c1;d=d1;e=e1;
        while(d+1<=9){
            f[ret(a,b,c,d+1,e)]+=1;d++;
        }a=a1;b=b1;c=c1;d=d1;e=e1;
        while(e+1<=9){
            f[ret(a,b,c,d,e+1)]+=1;e++;
        }a=a1;b=b1;c=c1;d=d1;e=e1;
    }
    for(int i=0;i<=99999;i++){
        if(f[i]>=n&&vis[i]!=1)ans++;
    }
    freopen("lock.out","w",stdout);
    cout<<ans;
    return 0;
}
