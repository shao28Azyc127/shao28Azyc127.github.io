#include<bits/stdc++.h>
using namespace std;
int n;
int ans1,ans2,x;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    x = n;
    while(x){
        ans1++;
        x--;
        x = x-x/3;
    }
    x = n;
    while(x){
        ans2++;
        if(n%3 == 1){
            break;
        }
        x--;
        x = x-x/3;
    }
    cout<<ans1<<' '<<ans2;
    return 0;
}
