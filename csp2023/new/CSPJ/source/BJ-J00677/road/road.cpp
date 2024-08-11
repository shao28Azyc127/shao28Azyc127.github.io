#include<bits/stdc++.h>
using namespace std;
int n,d,a[60000],b[60000],y;
int main(){
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        int x=a[i]/d;
        if(a[i]%d!=0){x++;}
        y+=x*b[i];
    }
    cout<<y;
    return 0;
}
