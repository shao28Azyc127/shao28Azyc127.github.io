#include<bits/stdc++.h>
using namespace std;
bool flag[105][10005][105];
int n,m,k,ans = INT_MAX;
vector<int> way[10005],a[10005];
struct st{
    int tim,x,maxx;
    bool operator <(const st tmp) const{
        return tim + maxx < tmp.tim + tmp.maxx;
    }
};
int read(){
    int x = 0;
    char ch = getchar();
    while(!isdigit(ch)){
        ch = getchar();
    }
    while(isdigit(ch)){
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
    return x;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    n = read();
    m = read();
    k = read();
    for(int i = 1;i <= m;i++){
        int u = read(),v = read(),t = read();
        way[u].push_back(v);
        a[u].push_back(t);
    }
    priority_queue<st> q;
    q.push(st{0,1,0});
    while(!q.empty()){
        st now = q.top();
        //cout << now.x << " " << now.maxx << now.tim << '\n';
        q.pop();
        if(now.x == m && now.tim % k == 0){
            cout << now.tim + (now.maxx + k - 1) / k * k;
            return 0;
        }
        int siz = way[now.x].size();
        for(int i = 0;i < siz;i++){
            int x = way[now.x][i];
            if(!flag[(now.tim + 1) % k][x][max(now.maxx,a[now.x][i] - now.tim)]){
                q.push(st{now.tim + 1,x,max(now.maxx,a[now.x][i] - now.tim)});
                flag[(now.tim + 1) % k][x][max(now.maxx,a[now.x][i] - now.tim)] = 1;
            }
        }
    }
    return 0;
}
