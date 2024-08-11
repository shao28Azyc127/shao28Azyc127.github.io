#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int x = n, cnt = 0, ans, flag = 0;
    while(x){
        cnt++;
        if (x%3==1&&!flag){
            ans = cnt;
            flag = 1;
        }
        x-=x%3?x/3+1:x/3;
    }
    cout<<cnt<<" "<<ans;
    return 0;
}