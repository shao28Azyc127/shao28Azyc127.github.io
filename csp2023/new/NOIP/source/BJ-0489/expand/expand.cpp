#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=500010;
int c,n,m,Q,ra[N],rb[N],a[N],b[N],kx,ky,X[N],Y[N];
queue<pii> q;
void check(){
    while(!q.empty())q.pop();
    bool flag;
    if(a[1]==b[1]){
        cout<<0;
        return ;
    }
    if(a[1]<b[1])flag=0;
    else flag=1;
    q.push({1,1});
    while(!q.empty()){
        int i=q.front().fi;
        int j=q.front().se;
        q.pop();
        //printf("i=%d j=%d\n",i,j);
        if(i<n){
            if(j<m){
                if(flag&&a[i+1]>b[j])q.push({i+1,j});
                if(flag&&a[i]>b[j+1])q.push({i,j+1});
                if(!flag&&a[i+1]<b[j])q.push({i+1,j});
                if(!flag&&a[i]<b[j+1])q.push({i,j+1});
            }else{
                if(flag&&a[i+1]>b[j])q.push({i+1,j});
                if(!flag&&a[i+1]<b[j])q.push({i+1,j});
            }
        }else if(j<m){
            if(flag&&a[i]>b[j+1])q.push({i,j+1});
            if(!flag&&a[i]<b[j+1])q.push({i,j+1});
        }else{
            cout<<1;
            return ;
        }
    }
    cout<<0;
    return ;
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>Q;
    //if(c<=4){
        for(int i=1;i<=n;i++){
            cin>>ra[i];
            a[i]=ra[i];
        }
        for(int i=1;i<=m;i++){
            cin>>rb[i];
            b[i]=rb[i];
        }
        check();
        int pos;
        while(Q--){
            cin>>kx>>ky;
            for(int i=1;i<=kx;i++){
                cin>>X[i]>>pos;
                a[X[i]]=pos;
            }
            for(int i=1;i<=ky;i++){
                cin>>Y[i]>>pos;
                b[Y[i]]=pos;
            }
            check();
            for(int i=1;i<=kx;i++){
                a[X[i]]=ra[X[i]];
            }
            for(int i=1;i<=ky;i++){
                b[Y[i]]=rb[Y[i]];
            }
        }
    //}
    cout<<endl;
    return 0;
}

