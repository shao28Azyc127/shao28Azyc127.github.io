#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a[100000001];
int find_next(int st){
    st++;
    while(a[st]) st++;
    return st;
}
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    scanf("%d", &n);
    int days = 0;
    int x = n;
    while(x){
        x -= int(ceil(x / 3.0));
        days++;
    }
    int day = 1, ind = 1;
    while(!a[n]){
        ind = find_next(0);
        a[ind] = 1;
        while(ind < n){
            a[ind = find_next(find_next(find_next(ind)))] = 1;
        }
        day++;
    }
    printf("%d %d\n", days, day - 1);
    return 0;
}

