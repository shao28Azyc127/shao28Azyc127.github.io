#include <bits/stdc++.h>
using namespace std;
int day(int apple){
    if(apple <= 3){
        return apple;
    }else{
        return 1+day(apple-apple/3-1);
    }
}

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin >> n;
    cout << day(n) << " ";
    int k=n,d=1,f=1;
    while(f){
        if(k%3==1){
            cout << d << endl;
            f=0;
        }else if(k%3==0){
            k -= k/3;
        }else{
            k -= k/3+1;
        }
        ++d;
    }
    return 0;
}
