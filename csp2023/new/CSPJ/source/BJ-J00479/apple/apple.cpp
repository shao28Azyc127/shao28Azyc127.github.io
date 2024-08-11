#include<bits/stdc++.h>
using namespace std;
int n, sum, idx, tim=0;
int ansn;
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin>>n;
    sum = idx = n;
    while(sum>0){
        tim++;
        sum -= (sum+2)/3;
        if((idx-1)%3==0 && ansn==0) ansn = tim;
        idx -= (idx+2)/3;
    }
    cout<<tim<<" "<<ansn;
    return 0;
}
