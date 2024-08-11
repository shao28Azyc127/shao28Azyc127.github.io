#include<bits/stdc++.h>
using namespace std;
vector<int> roads[20010];
int bfs(int n,int m,int k){
    queue<vector<int> > q({vector<int>()});
    int t=k;
    while(1){
        vector<int> x = q.front();
        q.pop();
        q.push(vector<int>());
        for(int s:x){
            for(int u=0;u<roads[s].size();u+=2){
                if(t >= roads[s][u+1]){
                    q.back().push_back(x[u]);
                }
            }
        }
        for(int i=0;i<q.front().size();i++){
            if(q.front()[i] == n) return int(ceil(t / double(k))*k);
        }
        t++;
    }
}
int main(void){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k,x1,x2,x3;
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        cin >> x1 >> x2 >> x3;
        roads[x1].push_back(x2);
        roads[x1].push_back(x3);
    }
    cout << bfs(n,m,k);
    return 0;
}
