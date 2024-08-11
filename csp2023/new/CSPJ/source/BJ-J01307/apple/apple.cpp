#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt,day,n1,tmp;
signed main(){
    ios::sync_with_stdio(false);
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    n1=n;
    int n2=n;
    if(n==1){
        cout<<1<<" "<<1;
        return 0;
    }
    if(n==2){
        cout<<2<<" "<<2;
        return 0;
    }
    if(n==3){
        cout<<3<<" "<<3;
        return 0;
    }
    while(n1>3){
        cnt++;
        n1=n1-(n1+1)/3;
        //cout<<cnt<<" "<<n1<<endl;
    }
    cnt+=n1;
    if(n%3!=0) cnt--;
    cout<<cnt<<" ";
    while((n2-1)%3!=0&&n2>3){
        day++;
        n2=n2-(n2+1)/3;
        //cout<<day<<" "<<n2<<endl;
    }
    day+=n2%3;
    if(n2%3==0) day+=3;
    if(n%3==1) cout<<1;
    else cout<<day;
    return 0;
}
