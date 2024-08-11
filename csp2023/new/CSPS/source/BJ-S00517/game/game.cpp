#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,cnt;
string s;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    for(int l=0;l<n;l++){
        for(int r=l;r<n;r++){
            // cout<<":"<<endl;
            // cout<<l<<";"<<r<<endl;
            if((r-l+1)%2==1) continue;
            stack<char> st;
            for(int i=l;i<=r;i++){
                if(i!=r && s[i]==s[i+1]) i++;
                else{
                    if(!st.empty() && st.top()==s[i]) st.pop();
                    else st.push(s[i]);
                }
            }
            if(st.empty()){
                cnt++;
                // cout<<cnt<<"|||"<<endl;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}