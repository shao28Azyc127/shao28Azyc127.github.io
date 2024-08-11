#include <bits/stdc++.h>
using namespace std;
string s;int sum;
bool check(){
    for(int i=1;i<s.size();i++)if(s[i]==s[i-1])return 0;
    return 1;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>sum>>s;sum=0;
    while(s.size()&&!check()){
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){s.erase(i-1,2);++sum;}
        }
    }
    if(s.empty())++sum;
    cout<<sum;
    return 0;
}
