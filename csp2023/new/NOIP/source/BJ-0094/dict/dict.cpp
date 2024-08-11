#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3005;
int n,m;
char str[MAXN][MAXN];
char l[MAXN][MAXN];
char min_r[MAXN];

inline bool cmp(char a,char b){
    return a > b;
}

int main(){
    #ifndef kevin
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    #endif
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n;i ++)
        scanf("%s",str[i] + 1);
    memset(min_r,'z',sizeof(min_r));
    for (int i = 1;i <= n;i ++){
        sort(str[i] + 1,str[i] + m + 1);
        strcpy(l[i] + 1,str[i] + 1);
        sort(str[i] + 1,str[i] + m + 1,cmp);
        if (strcmp(str[i] + 1,min_r + 1) < 0)
            strcpy(min_r + 1,str[i] + 1);
    }
    for (int i = 1;i <= n;i ++)
        if (strcmp(l[i] + 1,min_r + 1) > 0)
            printf("0");
        else
            printf("1");
    return 0;
}