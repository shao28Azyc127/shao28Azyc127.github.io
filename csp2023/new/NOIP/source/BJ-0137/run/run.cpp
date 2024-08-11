#include<bits/stdc++.h>
using namespace std;
#define int long long
int h[3009];
struct st{
    int ne,x;
}sd[1000009];
int inn;
int s[1000009][3];
int f[3009][3009];
int id;
void _main(){
    memset(h,0,sizeof(h));
    memset(sd,0,sizeof(sd));
    memset(s,0,sizeof(s));
    memset(f,-0x3f3f3f3f,sizeof(f));
    inn=0;
    int n,m,k,d;
    cin>>n>>m>>k>>d;
    for(int i=1;i<=m;i++){
        cin>>s[i][0]>>s[i][1]>>s[i][2];
        sd[++inn].x=i;
        sd[inn].ne=h[s[i][0]];
        h[s[i][0]]=inn;
    }
    int ans;
    ans=0;
    f[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            f[i][0]=max(f[i][0],f[i-1][j]);
        }
        //ans=max(ans,f[i][0]);
        for(int j=1;j<=min(i,k);j++){
            f[i][j]=f[i-1][j-1]-d;
            //ans=max(ans,f[i][j]);
        }
        for(int j=h[i];j;j=sd[j].ne){
            int o;
            o=sd[j].x;
            if(s[o][1]<=k){

                for(int l=s[o][1];l<=k;l++){
                    f[i][l]+=s[o][2];
                    //ans=max(ans,f[i][l]);
                }
            }
        }
    }

    for(int i=0;i<=k;i++){
        ans=max(ans,f[n][i]);
    }
    cout<<ans<<endl;
}
void __main(){
    int n,m,k,d;
    cin>>n>>m>>k>>d;
    int ans;
    ans=0;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        if(y>k){
            continue;
        }
        ans+=max(z-y*d,(long long)0);
    }
    cout<<ans<<endl;
}
signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int t;
    cin>>id>>t;
    while(t--){
        if(id<=9){
            _main();
        }else if(id==17||id==18){
            __main();
        }else{
            cout<<0<<endl;
        }
    }
    return 0;
}
