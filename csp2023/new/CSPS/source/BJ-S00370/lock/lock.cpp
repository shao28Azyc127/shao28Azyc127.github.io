#include<iostream>
using namespace std;
const int MAXN=20;
int a[MAXN][MAXN];
int n,m=5;
bool flag[MAXN][MAXN][MAXN][MAXN];
inline void Work1(){
    cout<<81;
}
void Turn(int x,int y){
    for(int i=0;i<=10;i++){
        flag[x][y][(x+i)%10][(y+i)%10]=1;
    }
}
inline void Init(){
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            Turn(i,j);
            flag[i][j][i][j]=0;
        }
    }
}
int b[MAXN];
int cnt=0;
int tot[MAXN];
bool Check(){
    for(int i=1;i<=n;i++){
        if(tot[i]==0) return false;
    }
    /*cout<<tot[1]<<":";
    for(int i=1;i<=5;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;*/
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            if(a[i][j]!=b[j]&&tot[i]==1) continue;
            if(a[i][j]!=b[j]&&tot[i]==2){
                if(flag[a[i][j]][a[i][j+1]][b[j]][b[j+1]]) break;
                else return false;
            }
        }
    }
    /*for(int i=1;i<=5;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;*/
    //cout<<":::"<<tot[1]<<endl;
    return true;
}
void Dfs(int x){
    if(x>5){
        cnt+=Check();
        return;
    }
    for(int i=0;i<=9;i++){
        b[x]=i;
        bool flag=1;
        for(int j=1;j<=n;j++){
            if(a[j][x]!=b[x]){
                tot[j]++;
                if(tot[j]>2) flag=0;
                if(tot[j]==2&&a[j][x-1]==b[x-1]) flag=0;
            }
        }
        if(flag) Dfs(x+1);
        for(int j=1;j<=n;j++){
            if(a[j][x]!=b[x]){
                tot[j]--;
            }
        }
        b[x]=0;
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin>>a[i][j];
    }
    if(n==1) return Work1(),0;
    Init();
    /*for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                for(int l=0;l<10;l++){
                    if(flag[i][j][k][l]){
                        cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
                    }
                }
            }
        }
    }*/
    Dfs(1);
    cout<<cnt;
    return 0;
}