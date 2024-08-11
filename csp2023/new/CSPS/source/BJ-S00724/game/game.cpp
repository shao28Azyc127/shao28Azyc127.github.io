#include<bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define ull unsigned long long
using namespace std;
int n;
ll ans;
string s;
int xiao(string str){
    if(str.size()%2==1)return 0;
    if(str=="")return 1;
    for(int i=0;i<str.size()-1;i++){
        if(str[i]==str[i+1])return xiao(str.substr(0,i)+str.substr(i+2,str.size()-i-2));
    }
    return 0;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>s;
    for(int i=0;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j+=2){
            if(xiao(s.substr(i,j-i+1))==1)ans++;
        }
    }
    cout<<ans;
    return 0;
}