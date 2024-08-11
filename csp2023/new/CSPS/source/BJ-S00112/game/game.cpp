#include <bits/stdc++.h>
using namespace std;
int n,cnt=0;
string s;
vector<stack> st;
void check(int len){
    for(int l=0;l<=n-len;l++){
            for(int i=l;i<=l+len-1;i++){
                if(i!=l){
            if(s[i]==st.top())
                st.pop();
            else st.push(s[i]);
            }
          else st.push(s[i]);
        }
        if(st.empty()) cnt++;
        else while(!st.empty()) st.pop();
    }

}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s;
    for(int i=2;i<=n;i+=2){
        check(i);
    }
    cout<<cnt;
return 0;
}
