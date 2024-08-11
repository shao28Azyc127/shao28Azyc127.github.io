#include <bits/stdc++.h>
using namespace std;
const int N=2e6+9;
inline int read(){
    char c=getchar();int s=0,f=1;
    while(c<'0'||c>'9'){if(c=='-'){f=-1;}c=getchar();}
    while(isdigit(c)){s=(s<<3)+(s<<1)+(c^48);c=getchar();}
    return s*f;
}
string s;int ans=0;
int x[N];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n=read();
    cin>>s;int ans=0;
    for(int i=0;i<n;i++){
        x[i+1]=s[i]-'a'+1;
    }
    stack<int>p;
    for(int i=1;i<=n;i++){
        if(p.empty()){p.push(x[i]);continue;}
        if(p.top()==x[i]){ans++;p.pop();}
        else{p.push(x[i]);}
    }
    cout<<ans;
    return 0;
}
