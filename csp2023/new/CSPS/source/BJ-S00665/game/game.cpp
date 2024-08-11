#include<bits/stdc++.h>
using namespace std;
#define int long long
string a;
int n,ans;
stack<char>st;
bool check(int l,int r){
    for(int i=l;i<=r;i++){
        if(!st.empty()&&st.top()==a[i]){
            st.pop();
        }
        else st.push(a[i]);
    }
    bool as=0;
    while(!st.empty()){
        st.pop();
        as=1;
    }
    return as;
}
signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%lld",&n);cin>>a;a='0'+a;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(!check(i,j))ans++;
        }
    }
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//zycakioi!!!
