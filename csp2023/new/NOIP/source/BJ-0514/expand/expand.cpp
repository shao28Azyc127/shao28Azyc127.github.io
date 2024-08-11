#include <bits/stdc++.h>
#include <stdint.h>
using namespace std;

int C,N,M,Q;

// T3
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);


    cin>>C>>N>>M>>Q;// line1
    vector<int> X;
    vector<int> Y;

    for(int i=0;i<N;i++){
        int x;
        cin>>x;// line2
        X.push_back(x);
    }
    for(int i=0;i<M;i++){
        int x;
        cin>>x;// line3
        Y.push_back(x);
    }

    // Spc Judge
    if(C==1){
        int ans = 1;
        if(X[0]==Y[0]){
            ans=0;
        }
        cout<<ans;
        for(int i=0;i<Q;i++){
            int kx,ky;
            cin>>kx>>ky;
            int nx=X[0];
            int ny=Y[0];
            for(int j=0;j<kx;j++){
                int px,vx;
                cin>>px>>vx;
                px--;// id to index
                nx=vx;
            }
            for(int j=0;j<ky;j++){
                int py,vy;
                cin>>py>>vy;
                py--;// id to index
                ny=vy;
            }
            ans = 1;
            if(nx==ny){
                ans=0;
            }
            cout<<ans;
        }
    }
    else if(C==2){
        int ans=1;
        X.push_back(X[0]);
        Y.push_back(Y[0]);
        int x1=X[0];
        int x2=X[1];
        int y1=Y[0];
        int y2=Y[1];
        if(x1==y1||x2==y2){
            ans=0;
        }
        if(x1>y1&& x2<y2){
            ans=0;
        }
        if(x1<y1&& x2>y2){
            ans=0;
        }
        cout<<ans;
        for(int i=0;i<Q;i++){
            int kx,ky;
            cin>>kx>>ky;
            int nx1=x1;
            int nx2=x1;
            int ny1=y1;
            int ny2=y1;
            for(int j=0;j<kx;j++){
                int px,vx;
                cin>>px>>vx;
                if(px==1){nx1=vx;
                if(N==1){
                    nx2=vx;
                }
                }
                if(px==2){nx2=vx;}
            }
            for(int j=0;j<ky;j++){
                int py,vy;
                cin>>py>>vy;
                if(py==1){ny1=vy;
                if(M==1){
                    ny2=vy;
                }
                }
                if(py==2){ny2=vy;}
            }
            ans = 1;
            //cout<<"x1="<<nx1<<" "<<"x2="<<nx2<<" "<<"y1="<<ny1<<" y2="<<ny2<<endl;
            if(nx1==ny1||nx2==ny2){
            ans=0;
        }
        if(nx1>ny1&& nx2<ny2){
            ans=0;
        }
        if(nx1<ny1&& nx2>ny2){
            ans=0;
        }
            cout<<ans;
        }
    }
    else{
        int ans = 0;
        if(X[0]==Y[0]){
            ans=1;
        }
        else{
            ans=0;
        }
        cout<<ans;
        for(int i=0;i<Q;i++){
            int kx,ky;
            cin>>kx>>ky;
            for(int j=0;j<kx;j++){
                int px,vx;
                cin>>px>>vx;
                px--;// id to index
                X[px]=vx;
            }
            for(int j=0;j<ky;j++){
                int py,vy;
                cin>>py>>vy;
                py--;// id to index
                Y[py] = vy;
            }
            ans = 0;
            if(X[0]==Y[0]){
                ans=1;
            }
            else{
                ans=0;
            }
            cout<<ans;
        }
    }
    cout<<endl;
    return 0;
}
