# include <stack>
# include <cstdio>
# include <iostream>
typedef long long ll;
using namespace std;

stack <char> st;
int flag[2000001];
//? removed block

int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    cin >> n;
    char f;
    cin >> f;
    st.push(f);
    ll ans = 0;
    int cnt = 0;
    bool rem = false;
    for (int i = 2; i <= n; i++){
        char c = getchar();
        if (!st.empty() && c == st.top()){
            st.pop();
            ans++, cnt++;
            rem = true;
        }
        else{
            if (rem){
                flag[st.size()]++;
                ans += flag[st.size()];
                rem = false;
            }
            st.push(c);
            cnt = 0;
        }
    }
    cout << ans << endl;
    return 0;
}