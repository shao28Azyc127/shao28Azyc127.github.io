#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int a,b,c;
    cin>>a;
    b=0;
    c=0;
    while (a>0)
    {
        b++;
        if (a%3==1&&c==0) c=b;
        a-=ceil((double)a/3);
    }
    cout<<b<<" "<<c;
    return 0;
}
