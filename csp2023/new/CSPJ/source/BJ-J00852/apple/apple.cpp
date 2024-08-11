#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,i=0,r=0,t;
    cin>>n;
    while(n!=0){
        i++;
        if(n%3==0) n=n/3*2;
        else if(n%3==1&&r==1) n=n/3*2;
        else if(n%3==1&&r==0){
            n=n/3*2;
            t=i;
            r=1;
        }
        else if(n%3==2) n=n/3*2+1;
    }
    cout<<i<<" "<<t;
    return 0;
}
