#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n;
    long long a[1000000000];
    int x;
    cin >> n;
    a[0]=1;
    a[1]=2;
    for(int i=2;;i++){
        a[i]=a[i-1]+a[i-2];
        a[i-2]=a[i-1];
        a[i-1]=a[i];
        if((a[i]==n)||a[i+1]>n){
            x=a[i];
            cout << i+1 << " ";
        }
        for(int j=a[i-2];j<=x;j+=a[i-1]){
                if((n-j)%3==0) cout << i-1;
            }
    }
    return 0;
}
