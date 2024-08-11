#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T>
inline void read(T &x){
    x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+(c-'0');
    x*=f;
}
template<typename T>
inline void write(T x){
    if(x>=10) write(x/10);
    putchar(x%10+48);
}
int n,ans,ans2;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    read(n);
    while(n){
        if((n-1)%3==0 && ans2==0){
            ans2=ans+1;
        }
        n-=((n-1)/3)+1;
        ans++;
    }
    write(ans);printf(" ");
    write(ans2);
    return 0;
}
