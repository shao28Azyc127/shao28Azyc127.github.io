#include<bits/stdc++.h>
using namespace std;
#define debug
const int MAXN=100;
int n, ans=0, key[MAXN][MAXN], now[MAXN];
inline int Add(int x, int y){
    return (x+y)%10;
}
inline int Turn(int x, int y){
    return (y+10-x)%10;
}
inline bool Cmp(int k){
    vector<int> tmp;
    for(int i=1; i<=5; i++){
        if(key[k][i]!=now[i]) tmp.push_back(i);
    }
    int cnt=tmp.size();
    if(cnt==1){
        return true;
    }
    else if(cnt==2){
        int t1=tmp[0], t2=tmp[1];
        if(t2-t1!=1) return false;
        return Add(now[t2], Turn(key[k][t1], now[t1])) == key[k][t2];
    }
    else return false;
}
inline void Dfs(int x){
    if(x==6){
        for(int i=1; i<=n; i++){
            if(!Cmp(i)) return;
        }
        ans++;
        return;
    }
    for(int i=0; i<=9; i++){
        now[x]=i;
        Dfs(x+1);
    }
}
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=5; j++){
            cin >> key[i][j];
        }
    }
    Dfs(1);
    cout << ans;
    return 0;
}