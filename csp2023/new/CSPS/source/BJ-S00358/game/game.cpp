#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=2e6+50;
ll n, ans=0, cnt[30];
char a[MAXN];
struct Node{
    int pst, nxt;
}st[MAXN];
inline void Delete(int l, int r){
    st[st[l].pst].nxt=st[r].nxt;
    st[st[r].nxt].pst=st[l].pst;
}
inline bool Search(int head){
    bool flag=false;
    while(st[head].nxt){
        head=st[head].nxt;
        if(st[head].nxt && a[head]==a[st[head].nxt]){
            Delete(head, st[head].nxt);
            head=st[head].nxt;
            flag=true;
        }
    }
    return flag;
}
inline bool Check(int l, int r){
    memset(cnt, 0, sizeof(cnt));
    int head=MAXN-5;
    for(int i=l; i<=r; i++){
        if(i<r) st[i+1].pst=i;
        if(i>l) st[i-1].nxt=i;
        cnt[a[i]-'a']++;
    }
    st[r].nxt=0;
    st[l].pst=head;
    st[head].nxt=l;
    for(int i=0; i<='z'-'a'; i++){
        if(cnt[i]%2) return false;
    }
    while(st[head].nxt){
        if(!Search(head)) return false;
    }
    return true;
}
int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(Check(i, j)) ans++;
        }
    }
    cout << ans;
    return 0;
}