#include <bits/stdc++.h>
#define int long long
using namespace std;
struct zhan{
    vector<char>s;
    void push(char x){s.push_back(x);}
    void pop(){s.pop_back();}
    void clear(){s.clear();}
    int size(){return s.size();}
    char top(){return s.back();}
    bool empty(){return s.empty();}
}st;
bitset<30>tong;
signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    s=" "+s;
    int ans=0;
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            st.clear();
            tong.reset();
            for(int k=i;k<=j;++k){
                if(tong[s[k]-'a']&&st.top()==s[k])st.pop();
                else st.push(s[k]);
                tong[s[k]-'a']=!tong[s[k]-'a'];
            }
            if(st.empty())ans++;
        }
    }
    cout<<ans;
    return 0;
}
