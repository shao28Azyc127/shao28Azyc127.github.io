#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N=2e6+10;

stack <char> s;
int n,ans;
char a[N];

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>a;
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n;j++){
                if(!s.empty()&&s.top()==a[j]) s.pop();
                else s.push(a[j]);
                if(s.empty()) ans++;
        }
        while(!s.empty()) s.pop();
    }
    cout<<ans;
    return 0;
}
