#include<bits/stdc++.h>
using namespace std;
int c,n,m,q;

int a[500005],b[500005];

void check(){
    if(n==1&&m==1){
        cout<<1;
        return;
    }
    else if(n==1&&m==2){
        if(a[1]>b[2]&&a[1]>b[1]){
            cout<<1;
            return;
        }
        if(a[1]<b[2]&&a[1]<b[1]){
            cout<<1;
            return;
        }
        cout<<0;
        return;
    }
    else if(n==2&&m==1){
        if(a[1]>b[1]&&a[2]>b[1]){
            cout<<1;
            return;
        }
        if(a[1]<b[1]&&a[2]<b[1]){
            cout<<1;
            return;
        }

        cout<<0;
        return;
    }
    else if(n==2&&m==2){
        if(a[1]>b[1]&&a[2]>b[2]){
            cout<<1;
            return;
        }
        if(a[1]<b[1]&&a[2]<b[2]){
            cout<<1;
            return;
        }

        cout<<0;
        return;
    }
    else{
        int f=1;
        if(a[1]<b[1]) f=0;
        for(int i=1;i<=n;i++){
            for(int i=1;i<=n;i++){
                if(f==1&&a[i]<b[i]){
                    cout<<0;
                    return;
                }
                if(f==0&&a[i]>b[i]){
                    cout<<0;
                    return;
                }
                if(a[i]==b[i]){
                    cout<<0;
                    return;
                }
            }
        }
    }
}

int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    check();
    while(q--){
        int x,y;
        cin>>x>>y;
        while(x--){
            int u,v;
            cin>>u>>v;
            a[u]=v;
        }
        while(y--){
            int u,v;
            cin>>u>>v;
            b[u]=v;
        }
        check();
    }
    return 0;
}
