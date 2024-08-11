#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int x,n,m,sum1=0,sum2=0;
    cin>>x;
    n=x;
    while(n!=0){
        sum1++;
        int t;
        if(n%3!=0){
            t=n/3+1;
        }else{
            t=n/3;
        }
        n-=t;
    }
    m=x;
    while(1){
        sum2++;
        int t;
        if(m%3==2){
            t=m/3+1;
        }else if(m%3==0){
            t=m/3;
        }else{
            break;
        }
        m-=t;
    }
    cout<<sum1<<" "<<sum2;

    return 0;
}
