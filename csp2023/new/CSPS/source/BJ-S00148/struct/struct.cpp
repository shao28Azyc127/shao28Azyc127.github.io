//play florr.io and tkk!
//written by a fan of Robert_Lewandovski
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,add=-1,tot,sz[110];
map<int,string> mp;
map<string,int> mp1;
map<string,int> str;
struct node{
    int lx;
    string nm;
}a[110][110];
signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int op;
        cin>>op;
        if(op==1){
            tot++;
            string s;
            int k;
            cin>>s>>k;
            sz[tot]=k;
            str[s]=tot;
            int mx=0;
            for(int j=1;j<=k;j++){
                string lx;
                cin>>lx>>a[tot][j].nm;
                if(lx[0]=='b') a[tot][j].lx=1;
                if(lx[0]=='s') a[tot][j].lx=2;
                if(lx[0]=='i') a[tot][j].lx=4;
                if(lx[0]=='l') a[tot][j].lx=8;
            }
        }else if(op==2){
            string s,nm;
            cin>>s>>nm;
            int cd=0;
            if(str[s]){
                int tt=str[s];
                int mx=0;
                int k=sz[tot];
                for(int j=1;j<=k;j++){
                    mx=max(a[tt][j].lx,mx);
                }
             //   cout<<mx<<endl;
                for(int j=1;j<=k;j++){
                    int hd=add+mx;
                    string tmp=nm;
                    tmp+='.';
                    tmp+=a[tt][j].nm;
                    mp1[tmp]=add+1;
                    for(int l=1;l<=a[tt][j].lx;l++){
                        mp[++add]=tmp;
                    }
                    for(int l=a[tt][j].lx+1;l<=mx;l++){
                        mp[++add]="ERR";
                    }
                }
                continue;
            }else if(s[0]=='b') cd=1;
            else if(s[0]=='s') cd=2;
            else if(s[0]=='l') cd=8;
            else if(s[0]=='i') cd=4;
            mp1[nm]=add+1;
            for(int i=1;i<=cd;i++){
                mp[++add]=nm;
            }
        }else if(op==3){
            string ss;
            cin>>ss;
            cout<<mp1[ss]<<endl;
        }else if(op==4){
            int x;
            cin>>x;
            if(x>add) cout<<"ERR"<<endl;
            else cout<<mp[x]<<endl;
        }
    }
    return 0;
}
