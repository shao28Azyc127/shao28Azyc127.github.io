#include<iostream>
#include<map>
#include<vector>
using namespace std;
const int maxn=2e6+100;
int n,ans;
string s;
map<pair<int,int>,bool> vis;
int rgt[maxn];
void solve(int l,int r){
    if(vis[make_pair(l,r)] or s[l]!=s[r]) return;
    ans++;
    if(l>0) ans+=rgt[l-1];
    if(r<n-1) rgt[r]+=rgt[l-1]+1;
    if(l>0 and r<n-1) solve(l-1,r+1);
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n;
    cin >> s;
    for(int i = 0;i < s.size()-1;i++){
        if(s[i]==s[i+1]) solve(i,i+1);
    }
    cout << ans;
    cout << endl;
    // for(int i = 1;i <= n;i++) cout << rgt[i] << ' ';
    return 0;
}