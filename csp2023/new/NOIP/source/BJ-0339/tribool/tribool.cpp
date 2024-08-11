#include<bits/stdc++.h>
using namespace std;
const int MXN=1e5+10,MXM=1e5+10;
int n,m,c,t;
int val[MXN],lx[MXM],ly[MXM],p3[20];
char lv[MXM];
int qf(int ln){
    if(ln==0) return 1;
    if(ln==1) return 0;
    return ln;
}
int get_num(int ln,int lnum){
    return ln/p3[lnum]%3;
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>t;
    p3[0]=1;
    for(int i=1;i<=15;i++){
        p3[i]=p3[i-1]*3;
    }
    if(c==1||c==2){
        while(t--){
            cin>>n>>m;
            for(int i=1;i<=m;i++){
                cin>>lv[i];
                if(lv[i]!='+'&&lv[i]!='-'){
                    cin>>lx[i];
                    lx[i]--;
                }else{
                    cin>>lx[i]>>ly[i];
                    lx[i]--,ly[i]--;
                }
            }
            int lim=p3[n]-1,ans=INT_MAX;
            for(int i=0;i<=lim;i++){
                int lnum=i;
                for(int j=1;j<=m;j++){
                    if(lv[j]=='T') lnum=lnum-get_num(lnum,lx[j])*p3[lx[j]]+1*p3[lx[j]];
                    if(lv[j]=='F') lnum=lnum-get_num(lnum,lx[j])*p3[lx[j]]+0*p3[lx[j]];
                    if(lv[j]=='U') lnum=lnum-get_num(lnum,lx[j])*p3[lx[j]]+2*p3[lx[j]];
                    if(lv[j]=='-') lnum=lnum-get_num(lnum,lx[j])*p3[lx[j]]+qf(get_num(lnum,ly[j]))*p3[lx[j]];
                    if(lv[j]=='+') lnum=lnum-get_num(lnum,lx[j])*p3[lx[j]]+get_num(lnum,ly[j])*p3[lx[j]];
                }
                if(lnum==i){
                    int ret=0;
                    for(int i=0;i<n;i++){
                        if(get_num(lnum,i)==2) ret++;
                    }
                    ans=min(ans,ret);
                }
            }
            cout<<ans<<'\n';
        }
    }else if(c==3||c==4){
        while(t--){
            cin>>n>>m;
            char v;
            int x,y;
            for(int i=1;i<=m;i++){
                cin>>v>>x;
                if(v=='T') val[x]=1;
                else if(v=='F') val[x]=2;
                else if(v=='U') val[x]=3;
            }
            int ans=0;
            for(int i=1;i<=n;i++){
                if(val[i]==3) ans++;
                val[i]=0;
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
