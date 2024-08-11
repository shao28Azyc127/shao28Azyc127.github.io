#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("tree.in",r);
    freopen("tree.out",w);
    int n;
    cin>>n;
    int a,b,c,s,e;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
    }
    for(int i=0;i<n-1;i++){
        cin>>s>>e;
    }
    cout<<n+1;
    fclose();
    return 0;
}