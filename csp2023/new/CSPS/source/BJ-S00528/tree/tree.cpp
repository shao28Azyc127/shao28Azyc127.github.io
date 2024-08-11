#include<iostream>
using namespace std;
int n;
int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%d", &n);
    printf("%d", rand() % n + 1);
    return 0;
}
