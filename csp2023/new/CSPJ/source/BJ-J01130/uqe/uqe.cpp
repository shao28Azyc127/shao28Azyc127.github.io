#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int mysqrt(long long x) {
    long long p=sqrt(x);
    long long q=max(p-10,(long long)0);
    for(long long i=q;i*i<=x;i++) {
        if(i*i==x) {
            return i;
        }
    }
    return -1;
}
int mygcd(long long x,long long y) {
    return x%y==0?y:mygcd(y,x%y);
}
int main() {
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,t;
    cin>>n>>t;
    while(n--) {
        long long a,b,c;
        cin>>a>>b>>c;
        long long temp1=b*b-4*a*c;
        if(temp1<0) {
            cout<<"NO\n";continue;
        }
        long long temp2=mysqrt(temp1);
        long long temp3=temp2-b;
        long long temp4=0-temp2-b;
        long long temp5=max(temp3,temp4);
        bool digit5=0,digit6=0;
        if(temp5<0) temp5=0-temp5,digit5=1;
        long long temp6=2*a;
        if(temp6<0) temp6=0-temp6,digit6=1;
        long long temp7=mygcd(temp5,temp6);
        long long temp8=temp5/temp7;
        long long temp9=temp6/temp7;
        bool digit9=digit5^digit6;
        if(digit9==1) cout<<'-';
        if(temp9==1) {
            cout<<temp8<<endl;continue;
        }
        cout<<temp8<<"/";
        cout<<temp9<<endl;
    }
    return 0;
}
