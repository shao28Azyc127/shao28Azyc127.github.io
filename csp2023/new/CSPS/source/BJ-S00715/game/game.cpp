#include<bits/stdc++.h>
using namespace std;
char s[10000000];
bool xxl(int l,int r){
    stack<char> st;
    for(int i=l;i<=r;i++){
        if(st.empty()||st.top()!=s[i]){
            st.push(s[i]);
        }else{
            st.pop();
        }
    }
    if(st.empty()){
        return true;
    }
    return false;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n,ans=0;
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(xxl(i,j)){
                ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
