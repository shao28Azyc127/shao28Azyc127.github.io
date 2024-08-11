#include<cstdio>
char c[2000005];
int n,ans;
bool check(int l,int r){
    int lft = l,rht = l + 1;
    if((r - l) % 2 == 1) return 0;
    if(r == rht) return c[l] == c[r];
    while(c[lft] != c[rht] && rht < r + 3) rht++;
    if(rht > r + 1) return 0;
    return check(l + 1,rht - 1) && check(rht + 1,r);
}
int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++) scanf(" %c ",&c[i]);
    for(int l = 0;l < n;l++){
        for(int r = l;r < n;r++){
            if(check(l,r)) ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
