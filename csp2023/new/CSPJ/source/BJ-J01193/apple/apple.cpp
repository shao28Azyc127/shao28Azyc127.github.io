#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n;
    cin>>n;
    int k=n/3+(n%3>0);
    int t2=n,t=0;
    while(t2>0&&k>=1){
        t2-=k;
        t++;
        k--;
    }
    cout<<t+max(t2,0)<<" ";
    if((n-1)%3==0) cout<<1;
    else if(n%(n/3+n%3)+1==0||n-((n/3+n%3)+1)==1){
        cout<<(n/3+n%3)+1;
    }else{
        cout<<
    }
    return 0;
}
