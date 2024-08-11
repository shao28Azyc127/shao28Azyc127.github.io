#include<bits/stdc++.h>
using namespace std;
bool ifok(string t,int x){
    int y=0;
    while(y!=x){
        if(x==0) return true;
        y=x;
        for(int i=0;i<x-1;i++){
            if(t[i]==t[i+1]){
                for(int j=i;j<x-2;j++){
                    t[j]=t[j+2];
                }
                x-=2;
            }
        }
    }
    return false;
}
int main(){
    freopen("game.in","r","stdin");
    freopen("game.out","w","stdout");
    int n,ans=0;
    cin>>n;
    string s;
    cin>>s;
    for(int i=2;i<=n;i+=2){
        for(int j=0;j<n-i+1;j++){
            if(ifok(s.substr(j,i),i))ans++;
        }
    }
    cout<<ans;
    return 0;
}