#include<bits/stdc++.h>
using namespace std;
struct IO{
    IO(){
        freopen("lock.in","r",stdin);
        freopen("lock.out","w",stdout);
    }
    ~IO(){
        fclose(stdin);
        fclose(stdout);
    }
}io;
int n,pm[10][10],ans=0,v[10];
inline bool chk(int x,int y,int z,int p,int q){
    v[1]=x,v[2]=y,v[3]=z,v[4]=p,v[5]=q;
    bool flg=true;
    for(int i=1;i<=n;i++){
        int cnt=0,pos1=0,pos2=0;
        for(int j=1;j<=5;j++){
            if(v[j]!=pm[i][j]&&pos1==0){
                cnt++;
                pos1=j;
            }else if(v[j]!=pm[i][j]){
                cnt++;
                pos2=j;
            }
        }
        if(cnt==1){
            continue;
        }
        if(cnt>2||cnt==0){
            flg=false;
        }
        bool yellowduck=false;
        for(int j=1;j<=9;j++){
            if(((v[pos1]+j)%10)==pm[i][pos1]&&((v[pos2]+j)%10)==pm[i][pos2]){
                yellowduck=true;
            }
        }
        if(!yellowduck||!flg||(cnt==2&&pos1!=pos2-1)){
            return false;
        }
    }
    return true;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>pm[i][j];
        }
    }
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                for(int l=0;l<=9;l++){
                    for(int m=0;m<=9;m++){
                        if(chk(i,j,k,l,m)){
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}
