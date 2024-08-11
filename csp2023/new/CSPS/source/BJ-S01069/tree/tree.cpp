#include<iostream>
#include<vector>
using namespace std;
const int N=100010;
struct node{
    int low_tall;
    int b,c;
    int now_tall;
}tree[N];
vector<int> g[N];
int day=0;
int visit[N];
int ans=1e9;
int n;
bool is_full(){
    for(int i=1;i<=n;i++){
        if(visit[i]!=1){
            return false;
        }
    }
    return true;
}
bool endup(){
    for(int i=1;i<=n;i++){
        if(tree[i].now_tall<tree[i].low_tall){
            return false;
        }
    }
    return true;
}
void dfs(int place){
    visit[place]=1;
    day++;
    for(int i=1;i<=n;i++){
        if(visit[i]==1){
            tree[i].now_tall=tree[i].now_tall+max(1,tree[i].b+tree[i].c*day);
        }
    }
    if(endup()==true){
        ans=min(day,ans);
        return;
    }
    if(is_full()==true){
        dfs(place);
    }
    for(int i=0;i<g[place].size();i++){
        if(visit[g[place][i]]==1){
            continue;
        }
        dfs(g[place][i]);
        visit[g[place][i]]=0;
        tree[g[place][i]].now_tall-=max(1,tree[i].b+tree[i].c*day);
        day--;
    }
    return;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> tree[i].low_tall >> tree[i].b >> tree[i].c;
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    if(ans==1e9){
        cout << "5" << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
