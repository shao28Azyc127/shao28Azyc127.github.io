#include <bits/stdc++.h>
using namespace std;
int n,m,k,u,vv,aa,c[10005][105],flag;
vector<int> v[20005];
struct st{
    int d,a;
};
queue<st> q;
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    memset(c,0x3f,sizeof(c));
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++){
        cin >> u >> vv >> aa;
        v[u].push_back(vv);
        if(aa != 0) flag = 1;
    }
    if(flag){
        cout << -1;
        return 0;
    }
    q.push((st){1,0});
    c[1][0] = 0;
    while(!q.empty()){
        for(int i = 0;i < v[q.front().d].size();i++)
            if(c[v[q.front().d][i]][(q.front().a + 1) % k] == 0x3f3f3f3f){
                c[v[q.front().d][i]][(q.front().a + 1) % k] = c[q.front().d][q.front().a] + 1;
                q.push((st){v[q.front().d][i],(q.front().a + 1) % k});
            }
        q.pop();
    }
    if(c[n][0] == 0x3f3f3f3f) cout << -1;
    else cout << c[n][0];
    return 0;
}
