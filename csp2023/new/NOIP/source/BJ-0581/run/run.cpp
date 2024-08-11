#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

inline void fio(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
}
int c,t;
signed main(){
    fio();
    int ans=-1;
    scanf("%d %d",&c,&t);
    while(t--){
        int n,m,k,d;
        scanf("%d %d %d %d",&n,&m,&k,&d);
        for(int i=1;i<=m;i++){
            int x,y,v;
            scanf("%d %d %d",&x,&y,&v);
            if(k<=y) ans=max(ans,(v-d*y));
        }
        printf("%d\n",ans);
    }

    return 0;
}
