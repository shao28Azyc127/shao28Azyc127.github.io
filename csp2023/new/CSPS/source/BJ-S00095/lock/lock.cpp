#include<bits/stdc++.h>
using namespace std;
int n,nums[10][10],now[10],ans;
bool check(int id1){
    bool flag[10];int cnt=0;
    memset(flag,0,sizeof(flag));
    for(int i=1;i<=5;i++){
        if(nums[id1][i]!=now[i]){
            flag[i]=1;
            cnt++;
        }
    }//cout<<cnt<<'\n';
    if(cnt>=3||cnt==0){
        return 0;
    }else{
        if(cnt==2){
            for(int i=1;i<=4;i++){
                if(flag[i]&&flag[i+1]){
                    for(int j=0;j<=9;j++){
                        int x=now[i]+j,y=now[i+1]+j;x%=10,y%=10;
                        if((x==nums[id1][i])&&(y==nums[id1][i+1])){
                            return 1;
                        }
                    }
                }
            }return 0;
        }else{
            return 1;
        }
    }
}int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>nums[i][j];
        }
    }for(now[1]=0;now[1]<=9;now[1]++){
        for(now[2]=0;now[2]<=9;now[2]++){
            for(now[3]=0;now[3]<=9;now[3]++){
                for(now[4]=0;now[4]<=9;now[4]++){
                    for(now[5]=0;now[5]<=9;now[5]++){
                        bool flag=1;
                        for(int i=1;i<=n;i++){
                            flag&=check(i);
                        }if(flag){
                            ans++;
                        }
                    }
                }
            }
        }
    }cout<<ans<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}