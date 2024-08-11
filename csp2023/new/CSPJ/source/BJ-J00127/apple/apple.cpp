#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,cnt,idx=0;


int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    idx=0;
    cnt=0;
    int day=0;
    while(n>0){
        day++;
        if(n%3==1&&idx==0) idx=day;
        cnt++;
        n=n*2/3;
    }
    if(idx==0) idx=cnt;
    cout<<cnt<<' '<<idx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
