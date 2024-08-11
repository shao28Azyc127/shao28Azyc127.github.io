#include<bits/stdc++.h>
#define int long long
using namespace std;

bool check(string s){
    if(s.length()<=1||s.length()%2==1){
        return false;
    }
    bool flag=true;
    while(flag){
        flag=false;
        for(int i=1;i<s.length();i++){
            if(s[i-1]==s[i]){
                flag=true;
                s.erase(i-1,1);
                s.erase(i-1,1);
                i--;
            }
        }
    }
    if(s.length()!=0){
        return false;
    }
    return true;
}

int n,ans;
string s;

signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    cin>>s;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            string ns=s.substr(j,i-j+1);
            if(check(ns)){
                ans++;
            }
        }
    }
    cout<<ans;

    return 0;
}
