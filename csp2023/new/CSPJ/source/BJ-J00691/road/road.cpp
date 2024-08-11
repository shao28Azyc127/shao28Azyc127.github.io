#include <iostream>
#include <cstdio>
using namespace std;
int a[100001],b[100001];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    long long s=0;
    scanf("%d %d",&n,&d);
    for(int i=1;i<=d;i++){
        scanf("%d",&a[i]);
        s+=a[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    s*=b[1];
    cout<<s;

    return 0;
}

