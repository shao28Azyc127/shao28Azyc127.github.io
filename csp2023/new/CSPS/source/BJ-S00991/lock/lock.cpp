#include<iostream>
using namespace std;

int n,state[9][6],pass[6],ans,c1cnt;

void printpass(){
            for(int i=1;i<=5;i++)cout<<pass[i];
            cout<<endl;
 
}
int diff(int a,int b){
    if(a>=b)return a-b;
    return a-b+10;
}
bool check(){
    for(int i=1;i<=n;i++){
        int df,dc=0,dp;
        for(int j=1;j<=5;j++)if(pass[j]!=state[i][j]){
            if(dc==0)df=diff(pass[j],state[i][j]),dc++,dp=j;
            else if(df!=diff(pass[j],state[i][j]))return false;
            else if(dc==2)return false;
            else if(dp!=j-1)return false;
            else dc++;
        }
        if(dc!=1&&dc!=2)return false;
    }
    return true;
}
void dfs(int dep){
    if(dep==6){
        ans+=check();
        return;
    }
    for(int i=0;i<10;i++)pass[dep]=i,dfs(dep+1);
}

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)for(int j=1;j<=5;j++)cin>>state[i][j];
    dfs(1);
    cout<<ans<<endl;
}