#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
stack <int> s;
int main(){
    long long i=0,ans=0,n;
    char a;
    bool k=0;
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        if(s.empty()!=1&&a==s.top()){
            s.pop();
            ans++;
        }else{
            s.push(a);
        }
        if(i!=n-1&&s.empty()==1){
            ans++;
        }
    }
    cout<<ans;
 return 0;
}
