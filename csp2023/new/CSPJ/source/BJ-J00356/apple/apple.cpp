#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,day=0,sn=-1;
    cin>>n;
    while(n>0){
        day++;
        if((n-1)%3==0&&sn==-1) sn=day;
        n-=(n-1)/3+1;
    }
    cout<<day<<" "<<sn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
