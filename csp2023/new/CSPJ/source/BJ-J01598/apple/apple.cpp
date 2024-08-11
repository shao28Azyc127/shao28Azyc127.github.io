#include<iostream>
#include<cstdio>
using namespace std;
int n,ans;
int k;
bool flag;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    if(n%3==1)
    while(n > 3){
        if(!flag)ans++;
        if(n%3==1)flag=1;
        k++;
        n-=(n-1)/3;
        printf("k=%d,n=%d\n",k,n);
    }
    cout << k <<' '<< ans << endl;
    return 0;
}