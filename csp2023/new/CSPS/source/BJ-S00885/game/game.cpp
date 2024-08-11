#include<bits/stdc++.h>
using namespace std;
bool bb[200003];
int aa[200003];
bool dfs(int a,int b){
    memset(bb,0,sizeof(bb));
    int nn=b-a+1;
    while(nn!=0){
        int tp=-1,ttp,ct=0,fg=0;
        for(int i=a; i<=b; i++){
            if(bb[i]==0){
                if(aa[i]!=tp||ct==2){
                    tp=aa[i];
                    ttp=i;
                    ct=1;
                }else if(aa[i]==tp&&ct==1){
                    ct++;
                    bb[ttp]=1;
                    bb[i]=1;
                    nn-=2;
                    fg=1;
                    tp=-1;
                }
            }
        }if(fg==0)break;
    }if(nn==0)return 1;
    return 0;
}int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n,cnt=0;
    char c;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>c;
        aa[i]=c-'a';
    }for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(dfs(i,j)){
                cnt++;
            }
        }
    }cout<<cnt;
    return 0;
}
