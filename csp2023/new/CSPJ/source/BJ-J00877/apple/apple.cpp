#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int sum = 1,x = n;
    while(n!=0){
        if(n%3 == 1){
            x = min(x,sum);
        }
        sum++;
        if(n%3){
            n-=(n%3+1);
        }else{
            n-=n%3;
        }
    }
    cout<<sum-1<<' '<<x;
    return 0;
}
