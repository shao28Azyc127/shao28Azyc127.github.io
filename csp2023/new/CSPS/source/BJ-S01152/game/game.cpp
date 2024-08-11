#include<bits/stdc++.h>
using namespace std;
long long ans;
int n;
string s;
stack<char> q;

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s;
    for(int i = 0;i < n;i++){
        while(!q.empty()){
            q.pop();
        }
        for(int j = i;j < n;j++){
            if(q.empty()){
                q.push(s[j]);
            }else{
                if(s[j] == q.top()){
                    q.pop();
                }else{
                    q.push(s[j]);
                }
                if(q.empty()){
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
