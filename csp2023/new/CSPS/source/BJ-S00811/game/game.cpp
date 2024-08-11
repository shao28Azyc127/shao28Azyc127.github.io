#include<bits/stdc++.h>
using namespace std;
char c[2000005];
stack<char>st;
bool check(int x,int y){
    while(!st.empty()){
        st.pop();
    }
    st.push(c[x]);
    for(int i=x+1;i<=y;i++){
        if(!st.empty() && c[i]==st.top()){
            st.pop();
        }
        else{
            st.push(c[i]);
        }
    }
    if(st.size()!=0){
        return false;
    }
    else{
        return true;
    }

}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    int cnt=0;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(check(i,j)){
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
