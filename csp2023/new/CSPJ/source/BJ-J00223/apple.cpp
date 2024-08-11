#include<bits/stdc++.h>
using namespace std;
int n,i,k,t=0,p=0,s=0,maxn=1e10;
long long a[100000000];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    k=n;
    for(int i=1;i<=n;i++)
        a[i]=i;
    while(a[1]!=maxn){
        t++;
        for(int i=1;i<=k;i+=3){
            if(a[i]==n)
                s=t;
            a[i]=maxn;
            p++;
        }
        sort(a,a+k+1);
        k-=p;
        p=0;
    }
    printf("%d %d",t,s);
    return 0;
}