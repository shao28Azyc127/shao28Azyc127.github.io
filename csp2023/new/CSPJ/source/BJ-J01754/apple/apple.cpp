#include<bits/stdc++.h>
using namespace std;
int n,m,t,fl,times=0,tip=1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n>0){
        times++;
        m=n-1;
        t=m/3+1;
        n-=t;
        if(m%3==0&&tip==1) {
                fl=times;
                tip=0;
        }
    }
    cout<<times<<" "<<fl;
    return 0;
}
