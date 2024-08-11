#include<bits/stdc++.h>
#define PII pair<int,int>
#define fir first
#define sec second
using namespace std;
const int N=1e6+10;
int C,n,m,q;
int a[N],b[N],ans[N],tt;
int c[N],d[N];
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&C,&n,&m,&q);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    for(int i=1;i<=n;i++) c[i]=a[i];
    for(int i=1;i<=m;i++) d[i]=b[i];
    int mxa=max(c[1],c[n]),mna=min(c[1],c[n]);
        int mxb=max(d[1],d[m]),mnb=min(d[1],d[m]);
        if(c[1]==d[1]||c[n]==d[m]) cout<<0;
        else if((c[1]<d[1]&&c[n]>d[m])||(c[1]>d[1]&&c[n]<d[m])) cout<<0;
        else if(c[1]>d[1]){
            cout<< (mxa>mxb&&mna>mnb);
        }
        else{
            cout<< (mxa<mxb&&mna<mnb);
        }
    if(n<=2&&m<=2){
        while(q--){
            int kx,ky;
            scanf("%d%d",&kx,&ky);
            for(int i=1;i<=n;i++) c[i]=a[i];
            for(int i=1;i<=m;i++) d[i]=b[i];
            while(kx--){
                int x,y;
                scanf("%d%d",&x,&y);
                c[x]=y;
            }
            while(ky--){
                int x,y;
                scanf("%d%d",&x,&y);
                d[x]=y;
            }
            int mxa=max(c[1],c[n]),mna=min(c[1],c[n]);
            int mxb=max(d[1],d[m]),mnb=min(d[1],d[m]);
            if(c[1]==d[1]||c[n]==d[m]) cout<<0;
            else if((c[1]<d[1]&&c[n]>d[m])||(c[1]>d[1]&&c[n]<d[m])) cout<<0;
            else if(c[1]>d[1]){
                cout<< (mxa>mxb&&mna>mnb);
            }
            else{
                cout<< (mxa<mxb&&mna<mnb);
            }
        }
    }
    return 0;
}
