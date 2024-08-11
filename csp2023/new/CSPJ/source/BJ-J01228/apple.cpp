#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int x = n;
    int a = 0;
    int b = 0;
    for(int i = 1;i<=1000000005;i++){
        if(n == 0){
            break;
        }
        if(n % 3==0){
            n = n - n/3;

        }
        else{
            n = n - n/3 - 1;
        }
        a++;
    }
    for(int i = 1;i<=a;i++){
        if(x % 3==0){
            x = x - x/3;

        }
        else if(x%3 == 1){
            x = x-x/3-1;
            b = i;
            break;
        }
        else{
            x = x - x/3 -1;
        }
    }

    cout<<a<<" "<<b;
}