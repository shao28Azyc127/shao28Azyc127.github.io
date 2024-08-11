#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> que;
vector<int> cnt;

int gcd(int x,int y){
    if(y==0){
        return x;
    }
    else{
        return gcd(y,x%y);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,c=0,tmp=0,ans,ns=0,os=0;
    cin>>n;
    que.resize(n+1);
    cnt.resize(n+1);
    int i=1;
    os=que.size();
    while(!que.empty()){
        if(ns!=os) c++;
        i++;
        if((i-1)%3==0){
            if((i-1)%n+1==n){
                ans=tmp;
            }
            que.erase(que.begin(),que.begin()+1);
        }
        else{
            que.push_back(que.front());
            que.erase(que.begin(),que.begin()+1);
        }
        tmp++;
        ns=que.size();
    }
    int g=gcd(c,ans);
    cout<<c/g<<" "<<g;
    return 0;
}
