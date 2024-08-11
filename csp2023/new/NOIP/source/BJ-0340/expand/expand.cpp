#include <bits/stdc++.h>
using namespace std;
int c,n,m,q;
int x[500005];
int y[500005];
int ans;
int max1,max2,min1,min2;

void re(){
    max1=0;
    max2=0;
    min1=(1<<30);
    max2=(1<<30);
    for(int i=1;i<=n;i++){
        max1=max(max1,x[i]);
        min1=max(min1,x[i]);
    }
    for(int i=1;i<=m;i++){
        max2=max(max2,y[i]);
        min2=max(min2,y[i]);
    }
    return ;
}

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
        cout<<(x[1]!=y[1]);
    }

    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        for(int i=1;i<=u;i++){
            int q1,q2;
            cin>>q1>>q2;
            x[q1]=q2;
        }
        for(int i=1;i<=v;i++){
            int q1,q2;
            cin>>q1>>q2;
            y[q1]=q2;
        }
        if(c==1){
            cout<<int(x[1]!=y[1]);
            continue;
        }

        bool ff=1;
        ff&=(x[1]>y[1]&&x[n]>y[m]||x[1]<y[1]&&x[n]<y[m]);

    }
    cout<<endl;
    return 0;
}
