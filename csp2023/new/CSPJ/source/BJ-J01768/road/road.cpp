#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d,l,s,v[100010],a[100010]={0x3f3f3f3f},mn=0x3f3f3f3f,mx;
int k(int a,int b){
    if(a%b==0) return a/b;
    else return a/b+1;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
    }for(int i=1;i<=n;i++){
        cin>>a[i];
    }int i=1;
    while(i<n){
        mn=min(a[i],mn);
        s+=k((v[i]-l),d)*mn;
        l=l+k((v[i]-l),d)*d-v[i];
        i++;
    }cout<<s;
    return 0;
}
