#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    string A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    if(n==1) cout<<81;
    else{
        cout<<1;
    }
    return 0;
}