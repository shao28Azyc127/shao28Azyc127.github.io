#include<bits/stdc++.h>
using namespace std;
int a[100005], v[100005], n, d, s, m, w;
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d", &n, &d);
    for(int i=1;i<n;i++){int t;scanf("%d", &t);v[i]=v[i-1]+t;}
    for(int i=0;i<n;i++)scanf("%d", &a[i]);
    while(s<v[n-1]){
        int next=n-1;
        for(int i=w;i<n;i++){
            if(a[i]<a[w]){next=i;break;}
        }
        while(s<v[next]){
            s+=d;
            m+=a[w];
        }
        w=next;
    }
    printf("%d", m);
    return 0;
}
