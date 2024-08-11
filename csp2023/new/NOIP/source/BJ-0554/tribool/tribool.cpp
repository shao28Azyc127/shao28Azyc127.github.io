#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,a[100005];
int main(){
freopen("tribool.in","r",stdin);
freopen("tribool.out","w",stdout);
cin>>c>>t;
while(t--){
    int n,m;
    char v;
    for(int i=1;i<=n;i++)a[i]=i;
    cin>>n>>m;
    if(n>1500){
        int ans=0;
        if(c==4){
            for(int i=1;i<=n;i++){
                cin>>v;
                if(v=='U')ans++;
            }
        cout<<ans<<endl;
        continue;
        }
        else if(c==6){
            for(int i=1;i<=m;i++){
                cin>>v;
                if(v=='U'){
                    int x;
                    cin>>x;
                    a[x]=100005+3;
                }else{
                    int x,y;
                    cin>>x>>y;
                    a[x]=a[y];
                }
            }
            int ans=0;
            for(int i=1;i<=n;i++){
                if(a[i]==100005+3)ans++;
            }
            cout<<ans<<endl;
            continue;
        }
    }
    for(int i=1;i<=m;i++){
        cin>>v;
        if(v=='T'){
            int x;
            cin>>x;
            a[x]=100005+1;
        }
        else if( v=='F'){
            int x;
            cin>>x;
            a[x]=100005+2;
        }
        else if(v=='U'){
            int x;
            cin>>x;
            a[x]=100005+3;
        }
        else if(v=='-'){
            int x,y;
            cin>>x>>y;
            if(a[y]==100005+1)a[x]=100005+2;
            if(a[y]==100005+2)a[x]=100005+1;
            if(a[y]==100005+3)a[x]=100005+3;
            else {
                a[x]=-a[y];
            }
        }
        else{
            int x,y;
            cin>>x>>y;
            a[x]=a[y];
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]==i)a[i]=0;
        else if(a[i]==-i)a[i]=100005+3;
    }
    for(int j=1;j<=n;j++){
    for(int i=1;i<=n;i++){
        if(a[i]==100005+1 or a[i]==100005+2 or a[i]==100005+3)continue;
        else if(a[i]>0)a[i]=a[a[i]];
        else if(a[i]<0){
            if(a[-a[i]]==100005+1)a[i]=100005+2;
            else if(a[-a[i]]==100005+2)a[i]=100005+1;
            else if(a[-a[i]]==100005+3)a[i]=100005+3;
            else{
                a[i]=-a[-a[i]];
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]==i)a[i]=0;
        else if(a[i]==-i)a[i]=100005+3;
    }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]==100005+3)ans++;
    }
    cout<<ans<<endl;
}
return 0;
}
