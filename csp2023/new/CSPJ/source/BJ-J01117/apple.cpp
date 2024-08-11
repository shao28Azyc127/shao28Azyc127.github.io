#include<cmath>
#include<iostream>
#include<vector>
using namespace std;

int solve(int n){
    if(n%3 == 1){
        return 1;
    }
    else{
        return solve((int)n*2/3)+1;
    }
}

int solve2(int n){
    if(n <= 3){
        return n;
    }
    return solve(n*2/3)+1;
}

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin >> n;
    cout << solve2(n) << " " << solve(n);

    return 0;
}
