#include<iostream>
using namespace std;
int main(){
    int n,d;
    double sum=0;
    int ans;
    int l=0;
    int v[100005],a[100005];
    cin>>n>>d;
    for(int i=0;i<n-1;i++){
        cin>>v[i];
        l+=v[i];
    }
    for(int i=0;i<n;i++)cin>>a[i];
    int i=0;
    sum=l/d;
    if(sum>int(sum))ans=int(sum)+1;
    else ans=int(sum);
    ans*=a[0];
    cout<<ans;
    return 0;
}
