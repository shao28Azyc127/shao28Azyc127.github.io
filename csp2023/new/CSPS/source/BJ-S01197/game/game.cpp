#include<bits/stdc++.h>
using namespace std;
const int NN=1e6;
int n;
char a[NN];
stack<char> stk;
int ans;
int main(){

    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cin>>a;
    int i=0;

    while(i<n){

        if(!stk.empty()){
            char s=stk.top();
            if(s==a[i]){
                stk.pop();
                ans++;
            }else{
                stk.push(a[i]);
            }
        }else{
            stk.push(a[i]);
        }
        i++;

    }
    if(stk.empty()){
        ans++;
    }else{
        while(!stk.empty()){
           ans++;
            stk.pop();
        }

    }
    cout<<ans;
    return 0;
}
