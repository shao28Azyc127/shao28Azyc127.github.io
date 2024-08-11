#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n; scanf("%d",&n);
    int dayans = 0;
    int tmp = n;
    while(tmp){
        tmp = tmp - (int)ceil((double)tmp / 3.0);
        dayans++;
    }
    printf("%d ",dayans);
    dayans = 1;
    while(n){
        if(n % 3 == 1){
            printf("%d ",dayans);
            return 0;
        }
        n = n - (int)ceil((double)n / 3.0);
        dayans++;
    }
    return 0;
}
