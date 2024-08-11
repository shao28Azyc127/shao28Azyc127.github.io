/*
    ---  ---  ---
    |    |    |__
    |    |    |
    ---  ---  |
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
int a[10][10],b[10];
vector<int> v;
bool check(){
    for(int i=1;i<=n;i++){
        int flag = 0;
        v.clear();
        for(int j=1;j<=5;j++){
            if(a[i][j]!=b[j]){
                flag++;
                v.push_back(j);
            }
        }
        if(flag<=1){
            continue;
        }
        else if(flag==2){
            if(v[0]+1==v[1] && a[i][v[0]]==a[i][v[1]]){
                continue;
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
    }
    return 1;
}
void dfs(int x){
    if(x==6){
        if(check()){
            ans++;
        }
        return;
    }
    for(int i=1;i<=9;i++){
        b[x] = i;
        dfs(x+1);
        b[x] = 0;
    }
}
signed main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin >> a[i][j];
        }
    }
    dfs(1);
    cout << ans;
    return 0;
}
