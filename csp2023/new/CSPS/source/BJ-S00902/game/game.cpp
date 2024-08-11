#include <bits/stdc++.h>
using namespace std;
int n;
const int N=2e6+5;
char s[N];

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s+1;
    int ans=0;
    for(int l=1;l<=n;l++){
        stack<char> st;
        for(int r=l;r<=n;r++){
            st.push(s[r]);
            while(!st.empty()){
                char a=st.top();
                st.pop();
                if(st.empty()){
                    st.push(a);
                    break;
                }
                char b=st.top();
                st.pop();
                if(a!=b){
                    st.push(b),st.push(a);
                    break;
                }
            }
            if(st.empty()) ans++;
        }
    }
    cout<<ans;
}