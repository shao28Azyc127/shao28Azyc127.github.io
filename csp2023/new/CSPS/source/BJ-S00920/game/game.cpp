#include<iostream>
#include<cstdio>
#include<stack>
#include<string>
using namespace std;
int n,ans;
string s;
stack<char> a;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    for(int i=0;i<n;i++){
        for(int k=i;k<n;k++){
            if(!a.empty() and a.top()==s[k]){
                a.pop();
            }else{
                a.push(s[k]);
            }
            if(a.empty()){
                ans++;
            }
        }
        while(!a.empty()){
            a.pop();
        }
    }
    cout<<ans<<endl;
    return 0;
}