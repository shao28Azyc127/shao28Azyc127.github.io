#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int i,nres;
    int num = n;
    i = 0;
    nres = -1;
    while(num>=1){
        i++;
        if(n % 3 == 1&&nres==-1){
            nres=i;
        }
        int t = 1+(num-1)/3;
        num-=t;
        if(nres == -1){
            n -= t;
        }
    }
    cout<<i<<' '<<nres;
    return 0;
}
