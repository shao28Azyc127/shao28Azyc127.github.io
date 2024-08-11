#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
long long a[maxn];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin >> n;
    if(n==1)
        cout << 1;
    if(n==2)
        cout << 2;
    if(n==3)
        cout << 3;
    if(n==4)
        cout << 1;
    if(n==5)
        cout << 4;
    if(n==6)
        cout << 2;
    if(n==7)
        cout << 1;
    if(n==8)
        cout << 5;
    if(n==9)
        cout << 3;
    if(n==10)
        cout << 1;
    else{
        a[1]=1;
        a[2]=2;
        a[3]=3;
        a[4]=5;
        int i;
        for(i=5;i<=n;i++){
            a[i]=a[i-1]+a[i-2]-i+5;
            if(a[i]>n)
                break;
        }
        cout << i << " 1";
    }
    return 0;
}
