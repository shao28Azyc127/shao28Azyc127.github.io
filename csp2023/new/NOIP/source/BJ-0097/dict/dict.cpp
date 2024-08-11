#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,ans[3005];
char t[3005];
struct node{
    char s[3005];
    int id;
}a[3005];
bool operator<(node x,node y){
    return strcmp(x.s,y.s) < 0;
}
bool cmp1(char x,char y){
    return x > y;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf(" %s",a[i].s);
        a[i].id = i;
        sort(a[i].s,a[i].s + m,cmp1);
    }
    sort(a + 1,a + 1 + n);
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < m;j++){
            t[j] = a[i].s[m - j - 1];
        }
        if((i == 1 && (n == 1 || strcmp(t,a[2].s) < 0)) || (i > 1 && strcmp(t,a[1].s) < 0)){
            ans[a[i].id] = 1;
        }
        else{
            ans[a[i].id] = 0;
        }
    }
    for(int i = 1;i <= n;i++){
        printf("%d",ans[i]);
    }
    return 0;
}
