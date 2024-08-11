#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("lock.in",r);
    freopen("lock.out",w);
    int n,a,b,c,d,e;
    cin>>n;
    if(n==1){
        cin>>a>>b>>c>>d>>e;
        cout<<81;
        fclose();
        return 0;
    }cin>>a>>b>>c>>d>>e;
    int f=a,g=b,k=c,h=d,l=e,s=0;
    for(int i=0;i<n-1;i++){
        cin>>a>>b>>c>>d>>e;
        if(a!=f||b!=g||c!=k||d!=h||l!=e)s+=9;
    }
    cout<<s;
    fclose();
    return 0;
}