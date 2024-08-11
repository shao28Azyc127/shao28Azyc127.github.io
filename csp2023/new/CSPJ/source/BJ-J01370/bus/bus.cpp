#include<bits/stdc++.h>
using namespace std;
vector <long long> s[10005];
struct node{
    long long v,t;
};
queue <node> q;
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    long long n,m,k,flag = 0;
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++){
        long long a,b,c;
        cin >> a >> b >> c;
        if(c) flag = 1;
        s[b].push_back(a);
    }
    if(flag)cout << -1;
    else{
        q.push(node{n,0});
        while(q.size()){
            for(int i = 0;i < s[q.front().v].size();i++){
                q.push(node{s[q.front().v][i],q.front().t + 1});
                cout << s[q.front().v][i] << " ";
                if(s[q.front().v][i] == 1 && (q.front().t + 1) % k == 0){
                    cout << q.front().t + 1;
                    flag = 1;
                    break;
                }
            }
            q.pop();
        }
        if(!flag) cout << -1;
    }
    return 0;
}
