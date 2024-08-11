#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int cnt;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    cin>>s;
    for(int i=0;i<n;i++){
        stack<char> st;
        for(int j=i;j<n;j++){
            if(!st.empty()&&st.top()==s[j]){
                st.pop();
            }else{
                st.push(s[j]);
            }
            if(st.empty()){
                cnt++;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}
