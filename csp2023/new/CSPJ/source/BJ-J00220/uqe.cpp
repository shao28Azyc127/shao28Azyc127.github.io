#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    return (b==0?a:gcd(b,a%b));
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,m;
    cin>>T>>m;
    while(T--){
        int a,b,c;
        cin>>a>>b>>c;
        int delta=b*b-4*a*c;
        if(delta<0){cout<<"NO\n";continue;}
        cout<<(-b+sqrt(delta))/(2*a)<<'\n';
    }
    return 0;
}
/*
1x^2+7x+1=0

delta=7*7+4*1*1=49-4=45

(-7+sqrt(45))/2=0
-7/2+sqrt(45)/2=0

x^2-1=0

delta=1-4*1*0=1

1+1/2=1
*/
