#include<bits/stdc++.h>
using namespace std;
int a[100001],v[100001];
int len=0;
int n,d;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for(int i=0;i<n-1;i++){
        cin >> v[i];
        len+=v[i];
    }
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    if(len%d!=0) cout << (len/d+1)*a[0];
    else cout << len/d*a[0];

    return 0;
}
