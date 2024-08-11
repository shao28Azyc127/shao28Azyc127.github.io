#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
string s;
char c[maxn];
int n;
long long ans;
bool check(string str){
    if(str.size()&1) return 0;
    bool flag=1;
    while(flag){
        flag=0;
        for(int i=0;i<(int)str.size()-1;i++){
            if(str[i]==str[i+1]){
                string ns=str.substr(0,i);
                if(i+2<str.size()) ns+=str.substr(i+2);
                flag=1;
                str=ns;
                break;
            }
        }
    }
    return str.size()==0;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    s=" "+s;
    for(int i=1;i<=n;i++){
        string ns="";ns+=s[i];
        for(int j=i+1;j<=n;j++){
            ns+=s[j];
            if(check(ns)) ans++;
        }
    }
    cout<<ans<<endl;
}
