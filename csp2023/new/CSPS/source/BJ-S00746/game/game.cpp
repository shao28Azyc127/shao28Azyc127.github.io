#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,cnt;
string s;
bool check(string t){
    if(t.size()==0)return true;
    int l=t.size();
    if(l%2==1)return false;
    if(l==2)return t[0]==t[1];
    string to;
    for(int i=0;i<t.size();){
        if(i!=t.size()-1&&t[i]==t[i+1])i+=2;
        else{
            to.push_back(t[i]);i++;
        }
    }
    if(to.size()==t.size())return false;
    return check(to);
}
bool check2(int l,int r){
    string to;
    for(int i=l;i<=r;){
        if(i!=s.size()-1&&s[i]==s[i+1])i+=2;
        else{
            to.push_back(s[i]);i++;
        }
    }
    return check(to);
}
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j+=2)
            if(check2(i,j))cnt++;
    printf("%lld",cnt);
    return 0;
}
