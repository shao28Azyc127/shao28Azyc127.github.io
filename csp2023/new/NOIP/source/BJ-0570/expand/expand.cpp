#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,m,n,q;
    cin>>c>>m>>n>>q;
    int a[m],b[n];
    int x[m],y[n];
    int ans[q+1];
    for(int i=0;i<m;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int p,v,o1,o2;
    int i;
    for(int k=0;k<=q;k++){
        p = 0;
        v = 0;
        if(c==1||c==2){
            if(c==1){
                x[0] = a[0];
                y[0] = b[0];
            }
            if(c==2){
                x[0] = a[0];
                x[1] = a[1];
                y[0] = b[0];
                y[1] = b[1];
            }
            if(k!=0){
                cin>>o1>>o2;
                for(int h=0;h<o1;h++){
                    cin>>p>>v;
                    x[p-1] = v;
                }
                for(int h=0;h<o2;h++){
                    cin>>p>>v;
                    y[p-1] = v;
                }
            }
            if(x[0]!=y[0]&&c==1) ans[k] = 1;
            else ans[k] = 0;
            if(c==2){
                if(n==2&&m==2){
                    if((x[0]-y[0])*(x[1]-y[1])>0) ans[k] = 1;
                }
                else if(n==2&&m==1){
                    if((x[0]-y[0])*(x[1]-y[0])>0) ans[k] = 1;
                }
                else if(n==1&&m==2){
                    if((x[0]-y[0])*(x[0]-y[1])>0) ans[k] = 1;
                }
                else ans[k] = 0;
            }
        }
        else{
            for(i=0;i<n;i++) x[i] = a[i];
            for(i=0;i<m;i++) y[i] = b[i];
            if(k!=0){
                cin>>o1>>o2;
                for(int h=0;h<o1;h++){
                    cin>>p>>v;
                    x[p-1] = v;
                }
                for(int h=0;h<o2;h++){
                    cin>>p>>v;
                    y[p-1] = v;
                }
            }
            if((x[0]>y[0]&&x[n-1]<y[n-1])||(x[0]<y[0]&&x[n-1]<y[n-1])||x[0]==y[0]||x[n-1]==y[n-1]) ans[k] = 0;
            else{
                int yes = 1;
                if(x[0]>y[0]){
                    yes = 1;
                    for(i=0;i<n&&yes == 1;i++){
                        yes = 0;
                        for(int j=0;j<m&&yes==0;j++){
                            if(x[j]>y[i]) yes = 1;
                        }
                    }
                    if(i>=n-2) ans[k] = 1;
                    else ans[k] = 0;
                }
                else if(x[0]<y[0]){
                    yes = 1;
                    for(i=0;i<n&&yes == 1;i++){
                        yes = 0;
                        for(int j=0;j<m&&yes==0;j++){
                            if(x[j]<y[i]) yes = 1;
                        }
                    }
                    if(i>=n-2) ans[k] = 1;
                    else ans[k] = 0;
                }
            }
        }
    }
    for(i=0;i<q+1;i++) cout<<ans[i];
    return 0;
}