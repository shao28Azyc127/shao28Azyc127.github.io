#include <bits/stdc++.h>
using namespace std;
const int N=1e3+9;
inline int read(){
    char c=getchar();int s=0,f=1;
    while(c<'0'||c>'9'){if(c=='-'){f=-1;}c=getchar();}
    while(isdigit(c)){s=(s<<3)+(s<<1)+(c^48);c=getchar();}
    return s*f;
}
int t,m;
int poww(int x){return x*x;}

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    t=read();m=read();
    while(t--){
        int a=read(),b=read(),c=read();
        int t=b;
        int del=(poww(b)-4*a*c);
        if(del<0){cout<<"NO"<<endl;continue;}
        else{cout<<(sqrt(del)-t)/(2*a)<<endl;}
    }
    return 0;
}
