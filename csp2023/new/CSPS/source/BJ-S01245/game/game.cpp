# include <bits/stdc++.h>
# define maxn 2000005
# define int long long
using namespace std;
int lst[maxn];
char ch[maxn];
int n, ans;
stack <int> st;
void bruteforce()
{
    for(int i = 1; i <= n; i++) {
        for(int j = i; j > 0; j--){
            if(!st.empty()) {
                int tp = st.top();
                if(ch[tp] == ch[j]) {
                    st.pop();
                    if(st.empty()) ans++;
                }else st.push(j);
            }
            else {
                st.push(j);
                continue;
            }
        }
        while(!st.empty()) st.pop();
    }
    cout <<  ans << endl;
    exit(0);
}
void sol()
{
    for(int i = 1; i <= n; i++){
        if(st.empty()){
            st.push(i);
            continue;
        }
        int tp = st.top();
        if(ch[tp] != ch[i]){
            st.push(i);
        }else{
            lst[i] = lst[tp - 1] + 1;
            st.pop();
        }
    }
    cout << ans << endl;
}
signed main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    cin >> ch + 1;
    if(n <= 8000) bruteforce();
    sol();
    return 0;
}
