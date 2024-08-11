#include<bits/stdc++.h>
using namespace std;
int n,a[100010],b1,b,m;
void z(int x){
    for(int j=x;j<=n;j++){
        a[j]=a[j+1];
    }
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int n2=n;
    for(int i=1;i<=n;i++) a[i]=i;
    while(n){
        b1++;
        m=n;
        for(int i=1;i<=m;i++){
            if(i%2==1){
                z(i);
                if(a[i]==n2) b=b1;
                n--;
            }
        }
    }
    cout<<b1+1<<" "<<b+1;
    return 0;
}
