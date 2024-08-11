#include<bits/stdc++.h>
using namespace std;
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+(c-'0');
    x*=f;
}
const int N=2e6+10;
int n,top,ans;
string s;
char st[N];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    cin>>s;s=' '+s;
    //cout<<s;
    for(int l=1;l<n;++l){
        for(int r=l+1;r<=n;++r){
            if((r-l+1)%2==1) continue;
            top=0;
            for(int k=l;k<=r;++k){
                if(st[top]!=s[k]) st[++top]=s[k];
                else top--;
            }
            //cout<<l<<" "<<r<<" "<<top<<endl;
            if(top==0) ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
