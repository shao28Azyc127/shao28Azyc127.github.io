#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e6+10;
int cnt[maxn],a[maxn];
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        char c;
        cin>>c;
        a[i]=c-'a'+1;
    }
    stack<int> st;
    int ans=0;
    for (int i=1;i<=n;i++){
        while (!st.empty())st.pop();
        st.push(0);
        for (int j=i;j<=n;j++){
            if (a[st.top()]==a[j]){
                st.pop();
            }else st.push(j);
            if (st.top()==0)ans++;
        }
    }
    cout<<ans;
}