#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,cnt,day,flag=0;
signed main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int k=n;
    while(k){
        ++cnt;
        if(k%3==1&&!flag){
            day=cnt;
            flag=1;
        }
        int num=k/3;
        if(k%3) ++num;
        k-=num;
    }
    cout<<cnt<<" "<<day;
    return 0;
}
