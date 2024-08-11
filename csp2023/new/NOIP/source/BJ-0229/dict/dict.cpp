#include <bits/stdc++.h>
using namespace std;
__int128 read(){
    __int128 c = 0,f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        c = (c << 3) + (c << 1) + (ch ^ 48);
        ch = getchar();
    }
    return c * f;
}
void print(__int128 x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x >= 10) print(x / 10);
    putchar(x % 10 + 48);
}
int n,m;
int maxn[3005],minn[3005];
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++){
        maxn[i] = -1,minn[i] = 27;
        for(int j = 1; j <= m; j++){
            char tmp; cin >> tmp;
            int tmpa = tmp - 'a';
            maxn[i] = max(maxn[i],tmpa);
            minn[i] = min(minn[i],tmpa);
        }
    }
    for(int i = 1; i <= n; i++){
        bool flag = 1;
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            if(minn[i] >= maxn[j]){
                flag = 0; break;
            }
        }
        if(flag) printf("1");
        else printf("0");
    }
    printf("\n");
    return 0;
}
