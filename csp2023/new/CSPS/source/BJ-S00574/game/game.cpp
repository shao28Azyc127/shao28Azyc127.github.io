//dthkxy ak ioi
#include<bits/stdc++.h>
#define int long long
using namespace std;

bool check(string s){
    stack <char> stk1;
    stack <char> stk2;

    int len; len=s.size();
    for(int i=0;i<len;i++){
        stk1.push(s[i]);
    }

    while(!stk1.empty()){
        if(stk2.empty()){
            stk2.push(stk1.top());
            stk1.pop();
        }

        if(stk1.top()==stk2.top()){
            stk1.pop();
            stk2.pop();
        }
        else{
            stk2.push(stk1.top());
            stk1.pop();
        }
    }

    if(stk2.empty()){
        return 1;
    }
    else{
        return 0;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);

    int n; cin>>n;
    string s; cin>>s;

    int ans; ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j+=2){
            string t;
            for(int k=i;k<=j;k++){
                t+=s[k];
            }

            if(check(t)){
                ans++;
            }
        }
    }

    cout<<ans;
    return 0;
}
