#include <iostream>
#include <algorithm>
using namespace std;
int a[100001],b[100001];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for (int i=1;i<n;i++)cin>>a[i];
    for (int i=1;i<=n;i++)cin>>b[i];
    int now=1,last=0,value=0;
    for (int i=1;i<n;i++){
        int k=a[i]-last;
        last+=(k/d)*d;
        value+=k/d*b[now];
        if (k%d!=0){
            last+=d;
            value+=b[now];
        }

        last-=a[i];
        if (b[i+1]<=b[now])now=i+1;
    }
    cout<<value;
}
