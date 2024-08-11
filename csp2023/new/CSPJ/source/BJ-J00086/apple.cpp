#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
freopen("apple.out","w",stdout);
    int n,m,k,flag=1;
    cin>>n;
    int i=0;
    while(n!=0){
        if(flag && n%3==1){
            k=i+1;
            flag=0;
        }
        n-=ceil(n/3.0);
        i++;

    }cout<<i<<" "<<k;
}
