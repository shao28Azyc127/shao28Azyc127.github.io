#include<bits/stdc++.h>
using namespace std;
int n,tot,ans;
string a;
bool pd(string x){
    queue<char>q;
    for(int i=0;i<x.length();++i){
        q.push(x[i]);
    }
    int t=x.length();
    int jl=0,hh,tt=0;
    bool ls=false;
    while(!q.empty()){
        if(tt>300)return false;
        tt++;
        char a=q.front();
        q.pop();
        char b=q.front();
        if(a==b){
            hh+=2;
            jl+=2;
            ls=true;
            q.pop();
            continue;
        }
        else{
            q.push(a);
            jl++;
        }
    }
    return true;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>a;
    for(int i=2;i<=a.length();i+=2){
        for(int j=0;j<=a.length()-i;++j){
            string x=a.substr(j,i);
            if(pd(x)){
                //cout<<x<<endl;
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
