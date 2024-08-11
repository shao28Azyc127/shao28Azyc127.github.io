#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n,d;
int u[N],a[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i = 1;i<=n-1;++i){
        scanf("%d",&u[i]);
    }
    for(int i = 1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    int longn = 0;
    for(int i = 1;i<=n-1;++i){
        longn+=u[i];
    }
    if(longn%d==0)
        printf("%d",(longn/d)*a[1]);
    else
        printf("%d",(longn/d+1)*a[1]);
    fcloseall();

    return 0;
}
