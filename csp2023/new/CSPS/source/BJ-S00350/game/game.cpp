#include<bits/stdc++.h>
using namespace std;
struct node{
    int lef, righ;
};
queue<node> q;
int n, ans, xuans, P = 99991;
bool v[1000000];
string s;
vector<int> lef[200010];
vector<int> righ[200010];
int hashh(int x, int y){
    long long res = 0, wei = 1;
    for(int i=x;i<=y;i++){
        res += ((s[i] - 'a') * wei) % P;
        wei = (wei * 26) % P;
    }
    return res%P;
}
int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin>>n;
    cin>>s;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            ans++;
            q.push(node{i, i+1});
            lef[i].push_back(i+1);
            righ[i+1].push_back(i);
            //a[ans][0] = i, a[ans][1] = i + 1;
        }
    }
    while(!q.empty()){
        node now = q.front();
        q.pop();
        int x = 1;
        int left = now.lef, right = now.righ;
        while(left-x>=0 && right+x<n && s[left-x] == s[right+x]){
            if(v[hashh(left-x, right+x)]){
                x++;
                continue;
            }
            ans++;
            q.push(node{left-x, right+x});
            lef[left-x].push_back(right+x);
            righ[right+x].push_back(left-x);
            v[hashh(left-x, right+x)] = 1;
            x++;
        }
        for(int i=0;i<righ[left-1].size();i++){
            if(v[hashh(righ[left-1][i], right)]) continue;
            ans++;
            q.push(node{righ[left-1][i], right});
            lef[righ[left-1][i]].push_back(right);
            righ[right].push_back(righ[left-1][i]);
            v[hashh(righ[left-1][i], right)] = 1;
        }
        for(int i=0;i<lef[right+1].size();i++){
            if(v[hashh(left, lef[right+1][i])]) continue;
            ans++;
            q.push(node{left, lef[right+1][i]});
            lef[left].push_back(lef[right+1][i]);
            righ[lef[right+1][i]].push_back(left);
            v[hashh(left, lef[right+1][i])] = 1;
        }
    }
    //cout<<xuans<<" "<<ans<<endl;
    cout<<ans<<endl;
    return 0;
}
