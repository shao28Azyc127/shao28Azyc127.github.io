#include <bits/stdc++.h>
using namespace std;
const int N=1e9;
inline int read(){
    char c=getchar();int s=0,f=1;
    while(c<'0'||c>'9'){if(c=='-'){f=-1;}c=getchar();}
    while(isdigit(c)){s=(s<<3)+(s<<1)+(c^48);c=getchar();}
    return s*f;
}
int n,m;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    n=read();
    int ans=0,tim=0;
    bool flag=1;
    while(n>3){
        ans++;
        if(n%3==1&&flag){tim=ans;flag=!flag;}
        n=n-((n-1)/3+1);
    }
    ans+=n;
    !flag?cout<<ans<<" "<<tim:cout<<ans<<" "<<ans;
    return 0;
}