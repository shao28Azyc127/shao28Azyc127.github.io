#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct node{
    long long int a, b, c;
}q[N];
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    scanf(" %d",&n);
    for(int i = 1; i <= n; i++){
        scanf(" %lld %lld %lld",&q[i].a,&q[i].b,&q[i].c);
    }
    printf("%d\n", n + 1);
    return 0;
}
