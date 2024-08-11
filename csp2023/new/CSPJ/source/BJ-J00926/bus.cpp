#include<bits/stdc++.h>
using namespace std;

int n,m,k;
struct a{
    int next,to,w;
}num[40004];
int head[20004];
int nume;
int vis[20004];
void add(int from,int to,int x){
    nume++;
    num[nume].to = to;
    num[nume].w = x;
    num[nume].next = head[from];
    head[from] = nume;
}

int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m >> k;
    int ma = 0;
    for(int i = 1;i <= m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
        ma = max(ma,c);
    }
    queue<pair<int,int> >q;
    if(n <= 10){
        for(int ii = 0;ii <= ma;ii += k){
            q.push({ii,1});
            while(!q.empty()){
                int x = q.front().second;
                int y = q.front().first;
                q.pop();
                if(x == n && y%k==0){
                    cout << y;
                    return 0;
                }
                for(int i = head[x];i;i = num[i].next){
                    if(y >= num[i].w && vis[i] < n){
                        q.push({y+1,num[i].to});
                        vis[i]++;
                    }
                }
            }
        }
        cout << -1;
        return 0;
    }
    else{
        q.push({0,1});
        while(!q.empty()){
            int x = q.front().second;
            int y = q.front().first;
            q.pop();
            if(x == n && y%k==0){
                cout << y;
                return 0;
            }
            for(int i = head[x];i;i = num[i].next){
                if(y >= num[i].w && vis[i] < n){
                    q.push({y+1,num[i].to});
                    vis[i]++;
                }
            }
        }
        cout << -1;
    }

}
