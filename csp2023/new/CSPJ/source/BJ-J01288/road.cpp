#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],s[100005],z;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<n;i++){
        int l=a[i];
        int k=i;
        for(int j=1;i+j<n;j++){
            if(s[i]<s[i+j])l+=a[i+j];
            else {
                i+=j;
                break;
            }
        }z+=l/a[k];
    }cout<<z;
    return 0;
}
