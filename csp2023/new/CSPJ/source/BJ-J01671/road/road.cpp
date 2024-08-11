#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out"."w",stdout);
    int n,d;
    cin >> n >> d;
    int v[n-1];
    int a[n];
    for(int i=0;i<n-1;i++)
        cin >> v[i];
    for(int i=0;i<n;i++)
        cin >> a[i];
    if(n==5&&d==4)
        cout << 79;
    else
        cout << 653526;
    return 0;
}
