#include <bits/stdc++.h>

using namespace std;

int n,solve[8010][8010],len=1;
char a[2000010];

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    memset(solve,0,sizeof(solve));
    scanf("%d%s",&n,&a);
    for(int i=0;;i++){
        if(i+len>=n){
            if(i==1)
                break;
            i=0; len+=2;
        }
        if(len==1&&a[i]==a[i+len]){
            solve[i][i+len]=1;
        }

    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(solve[j][i])
                ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
