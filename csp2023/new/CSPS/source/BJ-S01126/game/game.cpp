#include <cstdio>
#include <stack>
using namespace std;
int n;
char s[2000005],stk[2000005],top;
long long ans;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d %s",&n,s + 1);
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            if(stk[top] != s[j]){
                stk[++top] = s[j];
            }
            else{
                top--;
            }
            ans += !top;
        }
        top = 0;
    }
    printf("%lld",ans);
    return 0;
}
