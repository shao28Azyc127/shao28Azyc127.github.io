#include<bits/stdc++.h>
using namespace std;
const int N=3e3+10;
int n,m;
string s[N];
int minn[N],maxx[N];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    memset(minn,0x3f,sizeof(minn));
    memset(maxx,-1,sizeof(maxx));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        cin>>s[i];
        for(int j=0;j<m;j++) minn[i]=min(minn[i],s[i][j]-'a'+1),maxx[i]=max(maxx[i],s[i][j]-'a'+1);
    }
    for(int i=1;i<=n;i++){
        bool flag=false;
        for(int j=1;j<=n;j++){
            if(j==i) continue;
            if(minn[i]>maxx[j]){
                cout<<0;
                flag=true;
                break;
            }
            if(minn[i]==maxx[j]&&maxx[i]!=minn[j]){
                cout<<0;
                flag=true;
                break;
            }
        }
        if(!flag) cout<<1;
    }
    //puts("");
    return 0;
}