#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,m,i=0;
    bool flag=0;
    cin>>n;
    while(n>0){
        i++;
        if((n-1)%3==0&&flag==0)
            m=i,flag=1;
        n--;
        n-=n/3;
    }
    cout<<i<<" "<<m;
    return 0;
}
