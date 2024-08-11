#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
using namespace std;
int n,f[2000005],match[2000005],ans;
string s;
stack<pair<char,int> > st;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s; s=' '+s;
    for(int i=2;i<=n;i++){
        if(s[i-1]==s[i]) {
            match[i]=i-1; continue;
        }
        int tmp=i-1;
        while(tmp>0){
            tmp=match[tmp]-1;
            if(tmp<=0) break;
            if(s[tmp]==s[i]) {match[i]=tmp; break;}
        }
    }
    for(int i=1;i<=n;i++){
        if(match[i]!=0) f[i]=f[match[i]-1]+1;
        ans+=f[i];
    }
    cout<<ans<<endl;
    return 0;
}
