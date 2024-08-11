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
int n;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    read(n);
    printf("%d",n);
    return 0;
}
