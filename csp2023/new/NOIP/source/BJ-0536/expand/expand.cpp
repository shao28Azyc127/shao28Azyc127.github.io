#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long c,n,m,q,x[1000005],y[1000005],x2[1000005],y2[1000005];
/*void dfs(long long p,long long con){
    if(p>n){
        long long cnt=0;
        for(int i=1;i<=n;i++){
            if(r[i]){
                cnt-=r[i]*d;
            }
        }
        for(int i=1;i<=m;i++){
            if(rl[x[i]]>=y[i]){
                cnt+=v[i];
            }
            /*
            bool flag=1;
            for(int j=x[i];j>=x[i]-y[i]+1;j--){
                if(j<=0){
                    flag=0;
                    break;
                }
                if(!r[j]){
                    flag=0;
                    break;
                }
            }
            if(flag){
                cnt+=v[i];
            }* /
        }
        ans=max(cnt,ans);
        return;
    }
    if(con<k){
        r[p]=1;
        rl[p]=con+1;
        dfs(p+1,con+1);
    }
    r[p]=0;
    rl[p]=0;
    dfs(p+1,0);

}*/
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=m;i++){
        cin>>y[i];
    }
    if(c==1){
        if(x[1]==y[1]){
            cout<<1;
        }else{
            cout<<0;
        }
        for(int i=1;i<=n;i++){
            x2[i]=x[i];
        }
        for(int i=1;i<=m;i++){
            y2[i]=y[i];
        }
        for(int i=1;i<=q;i++){
            long long kx,ky;
            cin>>kx>>ky;
            for(int j=1;j<=kx;j++){
                long long px,vx;
                cin>>px>>vx;
                x2[px]=vx;
            }
            for(int j=1;j<=ky;j++){
                long long py,vy;
                cin>>py>>vy;
                y2[py]=vy;
            }
            if(x2[1]==y2[1]){
                cout<<1;
            }else {
                cout<<0;
            }
        }
    }
    else if(c==2){
        if(n==1&&m==1){
            if(x[1]==y[1]){
                cout<<1;
            }else{
                cout<<0;
            }
            for(int i=1;i<=n;i++){
                x2[i]=x[i];
            }
            for(int i=1;i<=m;i++){
                y2[i]=y[i];
            }
            for(int i=1;i<=q;i++){
                memset(x2,0,sizeof(x2));
                memset(y2,0,sizeof(y2));
                long long kx,ky;
                cin>>kx>>ky;
                for(int j=1;j<=kx;j++){
                    long long px,vx;
                    cin>>px>>vx;
                    x2[px]=vx;
                }
                for(int j=1;j<=ky;j++){
                    long long py,vy;
                    cin>>py>>vy;
                    y2[py]=vy;
                }
                if(x2[1]==y2[1]){
                    cout<<1;
                }else {
                    cout<<0;
                }
            }
        }else if(n==1&&m==2){
            if(x[1]==y[1]&&y[1]==y[2]){
                cout<<1;
            }else{
                cout<<0;
            }
            for(int i=1;i<=n;i++){
                x2[i]=x[i];
            }
            for(int i=1;i<=m;i++){
                y2[i]=y[i];
            }
            for(int i=1;i<=q;i++){
                memset(x2,0,sizeof(x2));
                memset(y2,0,sizeof(y2));
                long long kx,ky;
                cin>>kx>>ky;
                for(int j=1;j<=kx;j++){
                    long long px,vx;
                    cin>>px>>vx;
                    x2[px]=vx;
                }
                for(int j=1;j<=ky;j++){
                    long long py,vy;
                    cin>>py>>vy;
                    y2[py]=vy;
                }
                if(x2[1]==y2[1]&&y2[1]==y2[2]){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }
        }else if(n==2&&m==1){
            if(x[1]==y[1]&&x[1]==x[2]){
                cout<<1;
            }else{
                cout<<0;
            }
            for(int i=1;i<=n;i++){
                x2[i]=x[i];
            }
            for(int i=1;i<=m;i++){
                y2[i]=y[i];
            }
            for(int i=1;i<=q;i++){
                memset(x2,0,sizeof(x2));
                memset(y2,0,sizeof(y2));
                long long kx,ky;
                cin>>kx>>ky;
                for(int j=1;j<=kx;j++){
                    long long px,vx;
                    cin>>px>>vx;
                    x2[px]=vx;
                }
                for(int j=1;j<=ky;j++){
                    long long py,vy;
                    cin>>py>>vy;
                    y2[py]=vy;
                }
                if(x2[1]==y2[1]&&x2[1]==x2[2]){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }
        }else if(n==2&&m==2){
            if(x[1]==y[1]&&x[2]==y[2]){
                cout<<1;
            }else{
                cout<<0;
            }
            for(int i=1;i<=n;i++){
                x2[i]=x[i];
            }
            for(int i=1;i<=m;i++){
                y2[i]=y[i];
            }
            for(int i=1;i<=q;i++){
                memset(x2,0,sizeof(x2));
                memset(y2,0,sizeof(y2));
                long long kx,ky;
                cin>>kx>>ky;
                for(int j=1;j<=kx;j++){
                    long long px,vx;
                    cin>>px>>vx;
                    x2[px]=vx;
                }
                for(int j=1;j<=ky;j++){
                    long long py,vy;
                    cin>>py>>vy;
                    y2[py]=vy;
                }
                if(x[1]==y[1]&&x[2]==y[2]){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }
        }
    }
    return 0;
}
