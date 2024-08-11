#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
typedef long long ll;
using namespace std;
const ll maxn=2e6+5;
string s;
ll n,cnt2;
ll ans;
stack<char> st;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s;
    ll cnt=0;
    for(ll i=0;i<=n-1;i++){
        char ch=s[i];
        if(!st.empty() && st.top()==ch){
            st.pop();
            cnt++;
        }
        else st.push(ch);
        if(st.empty()){
            ans+=cnt;
            cnt=0;
            cnt2++;
        }
    }
    cout<<ans+cnt2*(cnt2-1)/2<<endl;
    return 0;
}
