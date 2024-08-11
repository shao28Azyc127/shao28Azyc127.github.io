#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int a[500005],b[500005];
int a2[500005],b2[500005];
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,n,m,q;
    cin>>c>>n>>m>>q;
    if(n==1&&m==1)
        c=1;
    if(c==1){
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=m;i++)
            cin>>b[i];
        if(a[1]!=b[1])
            cout<<1;
        else cout<<0;
        for(int i=1;i<=q;i++){
            int k1,k2;
            cin>>k1>>k2;
            int na,nb;
            for(int j=1;j<=k1;j++){
                int x,v;
                cin>>x>>v;
                na=v;
            }
            for(int j=1;j<=k2;j++){
                int x,v;
                cin>>x>>v;
                nb=v;
            }
            if(na!=nb){
                cout<<1;
                continue;
            }
        }
    }
    if(c==2){
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=m;i++)
            cin>>b[i];
        if(n==m&&n==2){
            if((a[1]<b[1]&&a[2]<b[2])||(a[1]>b[1]&&a[2]>b[2]))
                cout<<1;
            else{
                cout<<0;
            }
            for(int i=1;i<=q;i++){
                int k1,k2;
                cin>>k1>>k2;
                for(int j=1;j<=n;j++)
                    a2[j]=a[j];
                for(int j=1;j<=m;j++)
                    b2[j]=a[j];
                for(int j=1;j<=k1;j++){
                    int x,v;
                    cin>>x>>v;
                    a2[x]=v;
                }
                for(int j=1;j<=k2;j++){
                    int x,v;
                    cin>>x>>v;
                    b2[x]=v;
                }
                if((a[1]<b[1]&&a[2]<b[2])||(a[1]>b[1]&&a[2]>b[2]))
                    cout<<1;
                else
                    cout<<0;
            }
        }else{
            if(n==1){
                if((a[1]<b[1]&&a[1]<b[2])||(a[1]>b[1]&&a[1]>b[2]))
                    cout<<1;
                else cout<<0;
                for(int i=1;i<=q;i++){
                    int k1,k2;
                    cin>>k1>>k2;
                    for(int j=1;j<=n;j++)
                        a2[j]=a[j];
                    for(int j=1;j<=m;j++)
                        b2[j]=a[j];
                    for(int j=1;j<=k1;j++){
                        int x,v;
                        cin>>x>>v;
                        a2[x]=v;
                    }
                    for(int j=1;j<=k2;j++){
                        int x,v;
                        cin>>x>>v;
                        b2[x]=v;
                    }
                    if((a[1]<b[1]&&a[1]<b[2])||(a[1]>b[1]&&a[1]>b[2]))
                        cout<<1;
                    else cout<<0;
                }
            }
            if(m==1){
                if((a[1]<b[1]&&a[2]<b[1])||(a[1]>b[1]&&a[2]>b[1]))
                    cout<<1;
                else cout<<0;
                for(int i=1;i<=q;i++){
                    int k1,k2;
                    cin>>k1>>k2;
                    for(int j=1;j<=n;j++)
                        a2[j]=a[j];
                    for(int j=1;j<=m;j++)
                        b2[j]=a[j];
                    for(int j=1;j<=k1;j++){
                        int x,v;
                        cin>>x>>v;
                        a2[x]=v;
                    }
                    for(int j=1;j<=k2;j++){
                        int x,v;
                        cin>>x>>v;
                        b2[x]=v;
                    }
                    if((a[1]<b[1]&&a[2]<b[1])||(a[1]>b[1]&&a[2]>b[1]))
                        cout<<1;
                    else cout<<0;
                }
            }

        }
    }
    return 0;
}
