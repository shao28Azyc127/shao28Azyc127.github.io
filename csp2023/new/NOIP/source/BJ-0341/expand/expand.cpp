#include<bits/stdc++.h>
using namespace std;
const int maxn = 2005;
int c,n,m,on,om,q,a1[maxn],a2[maxn],oa1[maxn],oa2[maxn],ooa1[maxn],ooa2[maxn];
bool dp[maxn][maxn];
void findans() {
    n = on;
    m = om;
    for(int i = 0; i < n; i++) {
        a1[i] = oa1[i];
    }
    for(int i = 0; i < m; i++) {
        a2[i] = oa2[i];
    }
    if(a1[0] == a2[0]) {
        printf("0");
        return;
    }
    if(a1[0] < a2[0]) {
        swap(a1,a2);
        swap(n,m);
    }
    //for(int i = 0; i < n; i++) {
    //    printf("%d ",a1[i]);
    //}
    //printf("\n");
    //for(int i = 0; i < m; i++) {
    //    printf("%d ",a2[i]);
    //}
    //printf("\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dp[i][j] = false;
        }
    }
    dp[0][0] = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(dp[i][j] == true) {
                int tmp = min(m-1,j+1);
                if(i < n-1 && a1[i+1] > a2[tmp]) {
                    dp[i+1][tmp] = true;
                }
                tmp = min(n-1,i+1);
                if(j < m-1 && a1[tmp] > a2[j+1]) {
                    dp[tmp][j+1] = true;
                }
                if(j < m-1 && a1[i] > a2[j+1]) {
                    dp[i][j+1] = true;
                }
                if(i < n-1 && a1[i+1] > a2[j]) {
                    dp[i+1][j] = true;
                }
            }
        }
    }
    if(dp[n-1][m-1] == true) {
        printf("1");
        return;
    }
    else {
        printf("0");
        return;
    }
}
void cpy() {
    for(int i = 0; i < on; i++) {
        oa1[i] = ooa1[i];
    }
    for(int i = 0; i < om; i++) {
        oa2[i] = ooa2[i];
    }
}
int main () {
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&c,&on,&om,&q);
    for(int i = 0; i < on; i++) {
        scanf("%d",&ooa1[i]);
    }
    for(int i = 0; i < om; i++) {
        scanf("%d",&ooa2[i]);
    }
    cpy();
    findans();
    //printf("\n");
    while (q--) {
        cpy();
        int x,y;
        scanf("%d%d",&x,&y);
        for(int i = 0; i < x; i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            oa1[a-1] = b;
        }
        for(int i = 0; i < y; i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            oa2[a-1] = b;
        }
        findans();
        //printf("\n");
    }
    printf("\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
