#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int n, d, sum;

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d", &n, &d);
    int t;
    for(int i = 1; i < n; i++){
        scanf("%d", &t);
        sum += t;
    }
    int val;
    scanf("%d", &val);
    t = ceil(1.0*sum/d);
    printf("%d", t*val);

    return 0;
}
