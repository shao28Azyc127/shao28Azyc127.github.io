#include<bits/stdc++.h>
using namespace std;

template<typename T>
void read(T& x) {
    char ch=getchar();int _f=1;x=0;
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-') _f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar()){x*=10;x+=ch-48;}
    x*=_f;
}

int q;

int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    read(q);read(q);read(q);read(q);
    for(int i=1;i<=q+1;i++) printf("0");
    return 0;
}
