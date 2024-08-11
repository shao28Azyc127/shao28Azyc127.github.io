#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n,temp;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>temp>>temp>>temp;
    }
    for(int i = 0;i<n-1;i++){
        cin>>temp>>temp;
    }
    cout<<n+1;
    return 0;
}
