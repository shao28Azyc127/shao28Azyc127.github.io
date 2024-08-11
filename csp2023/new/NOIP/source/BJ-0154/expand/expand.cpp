#include<bits/stdc++.h>
using namespace std;

int c,n,m,q;
int a[500001],b[500001];
int x[500001],y[500001],xl,yl;

bool dfs(int xn,int yn){
    if(xn == xl){
        for(int i = yn+1;i <= yl;i++){
            if(x[xl] <= y[i]){
                return false;
            }
        }
        if(x[xl] <= y[yl]){
            return false;
        }
        return true;
    }
    for(int i = yn;i <= yl;i++){
        if(x[xn] > y[i]){
            if(dfs(xn+1,i)){
                return true;
            }
        }else{
            break;
        }
    }
    return false;
}

int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    for(int i = 1;i <= m;i++){
        cin>>b[i];
    }
    xl = n;
    yl = m;
    if(a[1] == b[1]){
        cout<<0;
    }else if(a[1] < b[1]){
        swap(xl,yl);
        for(int i = 1;i <= max(n,m);i++){
            x[i] = b[i];
            y[i] = a[i];
        }
    }else{
        for(int i = 1;i <= max(n,m);i++){
            x[i] = a[i];
            y[i] = b[i];
        }
    }
    if(dfs(1,1)){
        cout<<1;
    }else{
        cout<<0;
    }
    int kx,ky,p,v;
    while(q--){
        for(int i = 1;i <= max(n,m);i++){
            x[i] = a[i];
            y[i] = b[i];
        }
        xl = n;
        yl = m;
        cin>>kx>>ky;
        while(kx--){
            cin>>p>>v;
            x[p] = v;
        }
        while(ky--){
            cin>>p>>v;
            y[p] = v;
        }
        if(x[1] == y[1]){
            cout<<0;
            continue;
        }else if(x[1] < y[1]){
            swap(xl,yl);
            for(int i = 1;i <= max(n,m);i++){
                swap(x[i],y[i]);
            }
        }
        if(dfs(1,1)){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    return 0;
}
