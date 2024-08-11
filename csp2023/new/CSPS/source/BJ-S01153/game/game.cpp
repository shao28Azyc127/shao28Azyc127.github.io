#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
int n,cont=0,lon;
char a[N];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%c",&a[i]);
    }
    for(int i=1;i<=n;i++){
        if(a[i]==a[i+1])
            cont++;
    }
    printf("%d",cont+2);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
