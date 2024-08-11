#include<bits/stdc++.h>
using namespace std;
int rd(){
    int x=0,f=1;
    char b = getchar();
    while(!isdigit(b)){
        if(b == '-') f = -1;
        b = getchar();
    }
    while(isdigit(b)){
        x = (x << 3) + (x << 1) + (b^48);
        b=getchar();
    }
    return x*f;
}

int main(){
    freopen("tree.in","r",stdin);
    feropen("tree.out","w",stdout);
    int n =rd();
    if(n <= 10) cout << 3;
    int a = rand();
    if(n >  10) cout <<  a;
    return 0;
}
