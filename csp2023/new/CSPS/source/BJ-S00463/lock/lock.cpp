#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
int n;
int num[10][10];
int ans[10],sum=0;
int c[10][2];
bool ff[10];
bool check(){
    memset(ff,0,sizeof(ff));
    for(int i=1;i<=n;i++){
        memset(c,0,sizeof(c));
        int nm=0;
        for(int j=1;j<=5;j++){
            if(ans[j]==num[i][j])nm++;
        }
        if(nm==4){
            for(int j=1;j<=5;j++)if(ans[j]!=num[i][j])ff[j]=1;
        }else if(nm==3){
            bool f=0;
            for(int j=1;j<=4;j++){
                int c1=ans[j]-num[i][j],c2=ans[j+1]-num[i][j+1];
                if(c1<0)c1+=10;
                if(c2<0)c2+=10;
                if(c1==c2&&c1!=0){
                    f=1;
                    ff[c1]=ff[c2]=1;
                    break;
                }
            }
            if(f==0)return 0;
        }else return 0;
    }
    int ss=0;
    for(int i=1;i<=5;i++)if(ff[i])ss++;
    if(ss==1)return 1;
    else if(ss==2){
            for(int i=1;i<=4;i++)if(ff[i]&&ff[i+1])return 1;
        return 0;
    }
    return 0;
}
void dfs(int x){
    if(x>=5){
        if(check()){
            sum++;
        }
        return;
    }
    for(int i=0;i<10;i++){
        ans[x+1]=i;
        dfs(x+1);
    }
}
signed main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)for(int j=1;j<=5;j++)cin>>num[i][j];
    dfs(0);
    cout<<sum<<endl;
}
