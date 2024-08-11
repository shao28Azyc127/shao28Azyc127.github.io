#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n,d;
int a[N];
int b[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i = 1;i<=n-1;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 1;i<=n;i++){
        scanf("%d",&b[i]);
    }#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n,d;
int a[N];
int b[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i = 1;i<=n-1;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    long long res = 0;
    for(int i = 1;i<=n-1;i++){
        long long s = a[i];
        long long x = i+1;
        while(b[x]>b[i]){
            s+=a[x];
            a[x] = 0;
            x++;
        }
        int t = s/d;
        if(s%d!=0)t++;
        a[x]-=((d*t)-s);
        res+=(t*b[i]);
    }
    printf("%lld",res);

    return 0;
}

    long long res = 0;
    for(int i = 1;i<=n-1;i++){
        long long s = a[i];
        long long x = i+1;
        while(b[x]>b[i]){
            s+=a[x];
            a[x] = 0;
            x++;
        }
        int t = s/d;
        if(s%d!=0)t++;
        a[x]-=((d*t)-s);
        res+=(t*b[i]);
    }
    printf("%lld",res);

    return 0;
}
