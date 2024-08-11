#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    if(n%2) cout<<n/2+1;
    else cout<<n/2;
    return 0;
}
