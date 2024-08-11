#include<bits/stdc++.h>
#include<iostream>
#include<list>
#include<vector>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<iomanip>
#include<deque>
using namespace std;
int n,ans;
int a[10][10],b[10],c[5][10];
bool check(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            c[1][j]=a[i][j]-b[j];
            c[2][j]=a[i][j]+10-b[j];
        }
        bool f=false;
        int cnt=0;
        for(int j=1;j<=5;j++){
            if(c[1][j]!=0&&c[2][j]!=0){
                cnt++;
                if(!f){
                    f=true;
                }else if(c[1][j-1]!=c[1][j]&&c[2][j-1]!=c[1][j]&&c[1][j-1]!=c[2][j]){
                    return false;
                }
            }

        }
        if(cnt>2){
            return false;
        }
        if(cnt==0){
            return false;
        }
    }
    return true;
}
void dfs(int x){
    if(x==6){
        if(check()){
            ans++;
        }
        return;
    }
    for(int i=0;i<=9;i++){
        b[x]=i;
        dfs(x+1);
    }
}
int main(){
    std::ios_base::sync_with_stdio(false);
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }
    dfs(1);
    cout<<ans;
    return 0;
}
