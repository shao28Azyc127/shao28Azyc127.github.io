#include<bits/stdc++.h>
using namespace std;
int n,a[6],b[6],c[6],ans=0,d[6],e[6];
int main(){
    freopen("lock.in","in",stdin);
    fprintf(stdout,"lock.out");
    cin>>n;
    if(n==1){
        for(int i=1;i<=5;i++) cin>>a[i];
        cout<<"81";
    }
    else if(n==2){
        for(int i=1;i<=5;i++) cin>>a[i];
        for(int i=1;i<=5;i++) cin>>b[i];
        int tt=0;
        for(int i=1;i<=5;i++){
            if(a[i]!=b[i]){
                tt++;
                if(a[i-1]!=b[i-1] && a[i-1]==a[i] && b[i-1]==b[i]) tt--;
            }
        }
        cout<<tt*10;
    }
    else{
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i]>>d[i]>>e[i];
        }
        for(int i=1;i<=5;i++) if(a[i]!=a[1]) ans+=10;
        for(int i=1;i<=5;i++) if(b[i]!=b[1]) ans+=10;
        for(int i=1;i<=5;i++) if(b[i]!=b[1]) ans+=10;
        for(int i=1;i<=5;i++) if(b[i]!=b[1]) ans+=10;
        for(int i=1;i<=5;i++) if(b[i]!=b[1]) ans+=10;
        cout<<ans;
    }
    return 0;
}
