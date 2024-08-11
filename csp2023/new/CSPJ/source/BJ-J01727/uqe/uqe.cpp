#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    //t3
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,m;
    scanf("%d%d",&T,&m);
    while(T--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int r=b*b-4*a*c;
        if(r<0){
            printf("NO\n");
            continue;
        }
        int q1=int(sqrt(r)-b);
        int q2=2*a;
        printf("%d\n",q1/q2);
    }
    return 0;
}
