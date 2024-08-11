#include<bits/stdc++.h>
#include<iostream>
#include<list>
#include<vector>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<iomanip>
#include<deque>
using namespace std;
int n,ans;
string s;
bool check(int l,int r){
    int t['z'+10]={0};
    deque<char> q1,q2;
    for(int i=l;i<=r;i++){
        t[s[i]]++;
        q1.push_back(s[i]);
    }
    for(int i='a';i<='z';i++){
        if(t[i]%2!=0){
            return false;
        }
    }
    bool f=true;
    while(f){
        f=false;
        while(q1.empty()){
            char c=q1.front();
            q1.pop_front();
            if(q2.back()==c){
                q2.pop_back();
                f=true;
            }else{
                q2.push_back(c);
            }
        }
        q1=q2;
        q2.clear();
    }
    if(!q1.empty()){
        return false;
    }else{
        return true;
    }
}
int main(){
    std::ios_base::sync_with_stdio(false);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j+=2){
            if(check(i,j)){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
