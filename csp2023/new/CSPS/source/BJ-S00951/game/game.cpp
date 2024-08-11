#include<bits/stdc++.h>
using namespace std;
char s[2000005];
vector <long long> st[2000005];
long long en[2000005];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    long long n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> s[i];
    }
    for(int i = 1;i < n;i++){
        int l = i,r = i + 1;
        while(l >= 1 && r <= n && s[l] == s[r]){
            st[l].push_back(r);
            en[r]++;
            l--;
            r++;
        }
    }
    long long ans = 0;
    for(int i = 1;i <= n;i++){
        ans += en[i];
        if(en[i] == 0) continue;
        for(int j = 0;j < st[i + 1].size();j++){
            en[st[i + 1][j]] += en[i];
        }
    }
    cout << ans;
    return 0;
}
