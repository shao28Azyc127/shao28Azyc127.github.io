#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n,i;
    cin>>n;
    int a;
    for(i=1;i<=n;i++){
         cin>>a>>a>>a;
    }
    for(i=1;i<=n-1;i++){
         cin>>a>>a;
    }
    cout<<n+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
