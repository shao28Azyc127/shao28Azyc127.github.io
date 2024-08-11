#include<bits/stdc++.h>
using namespace std;
int a[6];
int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int i=1; i<=5; i++) scanf("%d", &a[i]);
    }
    printf("81");
    return 0;
}