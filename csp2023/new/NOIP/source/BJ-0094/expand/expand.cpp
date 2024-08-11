#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 5;
int C,n,m,q;
int a[MAXN],b[MAXN];
int origa[MAXN],origb[MAXN];

bool dfs(int idx,int l){
    if (idx == n + 1 && l == m)
        return true;
    // start from l
    for (int r = l;r <= m;r ++){
        
        if (a[idx] <= b[r])break;
        if (dfs(idx + 1,r)){
            // printf("(%d,%d)\n",l,r);
            return true;
        }
    }
    // start from l+1
    if (idx == 1)return false;
    for (int r = l + 1;r <= m;r ++){
        if (a[idx] <= b[r])break;
        if (dfs(idx + 1,r)){
            // printf("(%d,%d)\n",l + 1,r);
            return true;
        }
    }
    return false;
}

int main(){
    #ifndef kevin
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    #endif
    scanf("%d%d%d%d",&C,&n,&m,&q);
    for (int i = 1;i <= n;i ++){
        scanf("%d",a + i);
        origa[i] = a[i];
    }
    for (int i = 1;i <= m;i ++){
        scanf("%d",b + i);
        origb[i] = b[i];
    }
    bool flag = false;
    if (a[1] < b[1]){
        swap(a,b);
        swap(n,m);
        flag = true;
    }
    printf("%d",dfs(1,1) ? 1 : 0);
    if (flag){
        swap(a,b);
        swap(n,m);
    }
    while (q --){
        memcpy(a,origa,sizeof(origa));
        memcpy(b,origb,sizeof(origb));
        int px,py;
        scanf("%d%d",&px,&py);
        while (px --){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x] = y;
        }
        while (py --){
            int x,y;
            scanf("%d%d",&x,&y);
            b[x] = y;
        }
        flag = false;
        if (a[1] < b[1]){
            swap(a,b);
            swap(n,m);
            flag = true;
        }
        #if 0
        printf("ARRAY a is:\n");
        for (int i = 1;i <= n;i ++)
            printf("%d ",a[i]);
        printf("\nARRAY b is:\n");
        for (int i = 1;i <= m;i ++)
            printf("%d ",b[i]);
        printf("\n");
        #endif
        printf("%d",dfs(1,1) ? 1 : 0);
        if (flag){
            swap(a,b);
            swap(n,m);
        }
    }
    return 0;
}