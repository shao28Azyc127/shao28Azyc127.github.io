#include<bits/stdc++.h>
using namespace std;
long long n,ans;string s;
bool b[200001];
bool xiao(int x,int y){
    int T=0;
    while(1){
        int H=0,l=-29;
        for(int i=x;i<=y;i++){
            if(b[i]==1)continue;
            if(l!=-29){
                if(s[i]==s[l]){
                    ++H;
                    b[i]=1,b[l]=1;
                    l=-29;
                }else l=i;
            }else if(l==-29)l=i;
        }
        T+=H;
        if(H==0)for(int i=x;i<=y;i++)b[i]=0;
        if(H==0&&T*2==y-x+1)return 1;
        else if(H==0)return 0;
    }
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%lld",&n);cin>>s;
    for(register int i=0;i<n;i++){
        for(register int j=i+1;j<=n;j+=2){
            bool lzp=xiao(i,j);
            if(lzp==1)++ans;
        }
    }
    printf("%lld",ans);
    return 0;
}
