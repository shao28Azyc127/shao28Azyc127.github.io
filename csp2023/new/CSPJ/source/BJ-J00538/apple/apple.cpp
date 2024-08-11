#include <bits/stdc++.h>
using namespace std;
int n;



int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int n2 = n;
    int cnt = 0;
    while(1){
        n-=3;
        ++cnt;
        if(n == 2 || n == 3 || n == 4){
            break;
        }

    }int ans = 3+cnt;
    cout<<ans<<" ";



    if(n2 % 3 == 1){
        cout<<1;
        return 0;
    }else if(n2%3 == 0){
        cout<<n2/3;
    }else{
        cout<<ans;
    }




    return 0;
}
