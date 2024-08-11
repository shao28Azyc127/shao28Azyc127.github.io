#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define rep0(i,n) for(int i=0;i<n;i++)
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    int step=0,day,flag=1;
    cin>>n;
    while(n>=1){
        step++;
        if(n%3==1 && flag==1) day=step,flag=0;
        double m=n;
        int take=ceil(m/3);
        n-=take;
    }
    cout<<step<<" "<<day;
    return 0;
    }
