#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
string s;
map<string,bool> mp;
bool check(string ss){
    int i=0;
    string x=ss;
    if(x.size()%2==1) return false;
    while(!x.empty()){
        if(mp[x]){
            mp[ss]=true;
            return true;
        }
        if(i>=x.size()-1) break;
        if(x[i]==x[x.size()-1]){
            x.erase(i,1);
            x.erase(x.size()-1,1);
            i=0;
        }
        else if(x[i]==x[i+1]){
            x.erase(i,2);
            i=0;
        }
        else ++i;
    }
    if(x.empty()){
        mp[ss]=true;
        return true;
    }
    return false;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    cin>>s;
    string ss;
    for(int i='a';i<='z';++i){
        ss=i;
        ss+=i;
        mp[ss]=true;
    }
    for(int i=0;i<n;++i){
        ss=s[i];
        for(int j=i+1;j<n;++j){
            ss+=s[j];
            if(check(ss)) ++ans;
        }
    }
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
