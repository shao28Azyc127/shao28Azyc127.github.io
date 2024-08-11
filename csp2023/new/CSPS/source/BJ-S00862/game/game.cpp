#include<bits/stdc++.h>
using namespace std;
#define int long long
struct st{
    int tj[29]={};
    int d;
    void operator=(const st dd){
        for(int i=0;i<29;i++){
            tj[i]=max(dd.tj[i],tj[i]);
        }
    }
}f[200009];
int n;
string s;
int ff[2000009];
int zz[2000009];
void _m1(){
    for(int i=0;i<200009;i++){
        for(int j=0;j<29;j++){
            f[i].tj[j]=-1;
        }
    }
    f[0].tj[s[0]-'a']=0;
    for(int i=1;i<s.size();i++){
        f[i].tj[s[i]-'a']=i;
        if(f[i-1].tj[s[i]-'a']!=-1){
            int fs;
            fs=f[i-1].tj[s[i]-'a'];
            f[i].d=1;
            if(fs>0){
                f[i].d+=f[fs-1].d;
                f[i]=f[fs-1];
                f[i].tj[s[i]-'a']=i;
            }
        }
    }
    int ans;
    ans=0;
    for(int i=1;i<n;i++){
        ans+=f[i].d;
    }
    cout<<ans;
}
void _m2(){
    memset(zz,-1,sizeof(zz));
    for(int i=0;i<s.size();i++){
        for(int j=i-1;j>=0;j=zz[j]){
            if(s[j]==s[i]){
                zz[i]=j-1;
                ff[i]++;
                if(j>0){
                    ff[i]+=ff[j-1];
                }
            }
            break;
        }
        if(!ff[i]){
            zz[i]=-1;
        }
    }
    int ans;
    ans=0;
    for(int i=1;i<n;i++){
        ans+=ff[i];
    }
    cout<<ans;
}
signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s;
    if(n<=200000){
        _m1();
    }else{
        _m2();
    }
    return 0;
}
