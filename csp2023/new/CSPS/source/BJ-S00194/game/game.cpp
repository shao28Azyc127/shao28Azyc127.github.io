#include<bits/stdc++.h>
using namespace std;
int n;
string s;
stack<char> z;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    s=' '+s;
    int ans=0;
    for(int i=1;i<=n;i++){
        while(!z.empty())z.pop();
        for(int j=i;j<=n;j++){
            if(z.empty())z.push(s[j]);
            else{
                if(z.top()==s[j])z.pop();
                else z.push(s[j]);
            }
            if(z.empty())ans++;
        }
    }
    cout<<ans;
    return 0;
}
