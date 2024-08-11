#include <stdio.h>
using namespace std;
const int MAXN = 10;
int n;
int cnt;
int pass[MAXN][6];
int ans[6];

inline int df(int x,int y){
    return (y - x + 10) % 10;
}

bool check(){
    for (int i = 1;i <= n;i ++){
        int *a = pass[i];
        int cnt1 = 0,cnt2 = 0;
        for (int j = 1;j <= 5;j ++){
            if (j < 5 && ans[j] != a[j] && ans[j + 1] != a[j + 1] && df(ans[j],a[j]) == df(ans[j + 1],a[j + 1]))
                cnt2 ++;
            if (ans[j] != a[j])
                cnt1 ++;
        }
        if (!((cnt2 == 1 && cnt1 == 2) || (cnt2 == 0 && cnt1 == 1))){
            // for (int i = 1;i <= 5;i ++)
            //     printf("%d ",ans[i]);
            // printf("FAILED PASS in test %d\n",i);
            return false;
        }
        // printf("CNT1 %d CNT2 %d\n",cnt1,cnt2);
    }
    return true;
}

void dfs(int idx){
    if (idx >= 6){
        if (check()){
            cnt ++;
            // for (int i = 1;i <= 5;i ++)
            //     printf("%d ",ans[i]);
            // printf("\n");
        }
        return;
    }
    for (int i = 0;i <= 9;i ++){
        ans[idx] = i;
        dfs(idx + 1);
    }
}

int main(){
    #ifndef kevin
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    #endif
    scanf("%d",&n);
    for (int i = 1;i <= n;i ++)
        for (int j = 1;j <= 5;j ++)
            scanf("%d",&pass[i][j]);
    dfs(1);
    printf("%d",cnt);
    return 0;
}