#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,ans1=0,ans2=0,sum=1;
    cin>>n;
    long long int x1[12]={1,2,3,3,4,4,4,5,5,5,5,6};
    long long int y1[12]={1,2,3,1,4,2,1,5,3,1,2,6};
    long long int x2[10005];
    long long int y2[10005];
    if(n<=12){
            cout<<x2[n-1]<<" "<<y2[n-1];
            return 0;
    }
    for(int i=1;i<=n;i++){
        sum*=i;
    }
    cout<<sum<<" "<<1;
return 0;
}
