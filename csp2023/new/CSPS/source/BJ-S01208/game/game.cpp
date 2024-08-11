#include<bits/stdc++.h>
using namespace std;
const int Nmax=2e6+7;
int n;
stack<int> s;
int ans;
char r[Nmax];
int main(){
    freopen("game.in","r",stdin);
    cin>>n;
    cin>>r;
    for(int i=0;i<=n-1;i++){
        int c;
        c=r[i];
        //cout<<c<<endl;
        if(!s.empty()&&c==s.top()){
            ans++;
            s.pop();
        }
        else{
            s.push(c);
        }
    }
    if(s.empty())ans++;
    freopen("game.out","w",stdout);
    cout<<ans;
    return 0;
}
