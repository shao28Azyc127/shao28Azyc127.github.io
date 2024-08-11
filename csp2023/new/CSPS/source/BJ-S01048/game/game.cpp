#include<bits/stdc++.h>

const int N =2e6+10;

using namespace std;

int n;
string a;
int ans;

string Fill(char c,string s,int sub){
    s.insert(sub-1,sub,c);
    return s;
}

void dfs(int n,string s){
    int cnt=0;
    for(int i=0;i<=s.length();i++){
        if(i>=1 && s[i]==s[i-1]){
            //char c = a[i];
            cnt++;
            s.erase(i-1,i);
            //dfs(n-2,s,step+1);
            //s = Fill(c,s,i);
        }
    }
    if(s.empty()){
        ans++;
        return ;
    }
    ans+=cnt;
    if(cnt==0)return ;
    dfs(n-cnt*2,s);
}

signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);

    scanf("%lld",&n);
    cin>>a;

    dfs(n-1,a);

    printf("%lld\n",ans);
    return 0;
}
