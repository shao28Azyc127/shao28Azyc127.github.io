#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,q;
int x[N],y[N];
inline int solve(){
    if(x[1]==y[1]) return 0;
    if(n==1 && m==1){
        if(x[1]!=y[1]) return 0;
        return 1;
    }
    else if(n==2 && m==2){
        if(x[1]<y[1] && x[2]<y[2]){
            return 1;
        }
        if(x[1]>y[1] && x[2]>y[2]){
            return 1;
        }
        return 0;
    }
    else if(n==1 && m==2){
        if(x[1]>y[1] && x[1]>y[2]) return 1;
        if(x[1]<y[1] && x[1]<y[2]) return 1;
        return 0;
    }
    else if(n==2 && m==1){
        //cout<<"Yes"<<endl;
        if(y[1]>x[1] && y[1]>x[2]) return 1;
        if(y[1]<x[1] && y[1]<x[2]) return 1;
        return 0;
    }
    else{
       // cout<<"Yes";
        int l=1,r=0;
        for(int j=1;j<=m;j++){
            if(x[1]>y[j]) r++;
            else break;
        }
       // cout<<"here "<<l<<" "<<r<<endl;
        if(r!=0){
            for(int i=2;i<=n;i++){
                int mx=-1;
                for(int j=l;j<=min(m,r+1);j++){
                    if(x[i]>y[j])
                        mx=max(mx,j);
                }
                if(mx==-1) {
                    r=0;
                    break;
                }
                for(int j=mx;j<=m;++j){
                    if(x[i]>y[j]) r=j;
                    else break;
                }
            }
           // cout<<"here "<<l<<" "<<r<<endl;
            if(l==1 && r==m) return 1;
        } 
        l=1,r=0;
        for(int j=1;j<=n;j++){
            if(y[1]>x[j]) r++;
            else break;
        }
       // cout<<"here "<<l<<" "<<r<<" "<<y[1]<<" "x<<endl;
        if(r!=0){
            for(int i=2;i<=m;i++){
                int mx=-1;
                for(int j=l;j<=min(n,r+1);j++){
                    if(y[i]>x[j])
                        mx=max(mx,j);
                }
                if(mx==-1) {
                    r=0;
                    break;
                }
                for(int j=mx;j<=n;++j){
                    if(y[i]>x[j]) r=j;
                    else break;
                }
            }
            if(l==1 && r==n) return 1;
        }
        return 0;
    }
}
int a[N],b[N];
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;++i){
        scanf("%d",&x[i]);
        a[i]=x[i];
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&y[i]);
        b[i]=y[i];
    }
    //cout<<"here"<<endl;
   printf("%d",solve());
    int kx,ky;
    int tmp1,tmp2;
  //  int id=1;
    while(q--){
        scanf("%d%d",&kx,&ky);
        for(int i=1;i<=kx;i++){
            scanf("%d%d",&tmp1,&tmp2);
            x[tmp1]=tmp2;
        }
        for(int i=1;i<=ky;i++){
            scanf("%d%d",&tmp1,&tmp2);
            y[tmp1]=tmp2;
        }
        // for(int i=1;i<=n;i++){
        //     cout<<x[i]<<" ";
        // }
        // cout<<endl;
        // for(int j=1;j<=m;j++){
        //     cout<<y[j]<<" ";
        // }
        // cout<<endl;
        
        //cout<<"haha"<<id<<endl;
        //if(id==2)solve();
        printf("%d",solve());
        for(int i=1;i<=n;i++){
            x[i]=a[i];
        }
        for(int i=1;i<=m;i++){
            y[i]=b[i];
        }
    }
    return 0;
}