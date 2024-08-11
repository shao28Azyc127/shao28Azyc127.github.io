#include<bits/stdc++.h>
using namespace std;

int n,applen,day;
long long a[100000000];

void ca(int m){
    while(a[1]!=0){
        for(int i=1;i<m;i+=3){
            if(a[i]=m) applen=day;
            for(int j=i;j<=m-1;j++){
                a[i]=a[i+1];
            }
        day++;
        }
    }
}

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) a[i]=i;
    for(int i=1;i<=n;i++) ca(n);
    cout<<day<<applen;

    return 0;
}
