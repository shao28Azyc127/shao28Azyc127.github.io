#include<iostream>
#include<cstdio>
using namespace std;
int main() {
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n;
    cin>>n;
    long long ans=0,sum=0;
    long long t=n;
    bool flag=false;
    while(t!=0) {
        long long m;
        if(t%3==1&&flag==false) {
            m=t/3+1;
            ans=sum+1;
            flag=true;
        }
        else if(t%3==0) m=t/3;
        else m=t/3+1;
        t-=m;
        sum++;
    }
    cout<<sum<<" "<<ans;
    return 0;
}
