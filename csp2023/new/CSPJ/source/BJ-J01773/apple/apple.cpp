#include<bits/stdc++.h>
using namespace std;
int n,a,m,f=1,t,z;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;m=n;
    while(m){
        t++;
        m--;
        if(f&&(m%3==0||m==1)){
            f=0;
            z=t;
        }
        m-=m/3;
    }
    cout<<t<<" "<<z<<endl;
    return 0;
}
