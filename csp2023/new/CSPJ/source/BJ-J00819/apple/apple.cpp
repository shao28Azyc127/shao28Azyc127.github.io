#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
int ans=0;
int getsum(int n,int now){
    if(n%3==1&&ans==0) ans=now;
    if(n==1) return 1;
    int tmp=n*2/3;
    return getsum(tmp,now+1)+1;
}
signed main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n=read();
    int sum=getsum(n,1);
    cout<<sum<<" "<<ans;
    return 0;
}
