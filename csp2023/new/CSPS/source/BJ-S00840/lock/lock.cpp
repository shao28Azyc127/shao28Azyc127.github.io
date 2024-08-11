#include <bits/stdc++.h>

using namespace std;

const int N=10;
int b[N][6],a[N];
int n,cnt;

bool check()
{
    int cnt=0,last=0;
    for(int i=1;i<=n;i++){
        cnt=0,last=0;
        for(int j=1;j<=5;j++){
            if(b[i][j]!=a[j]){
                last++;
                if(j>1 && b[i][j-1]!=a[j-1] && last<=2){
                    int ori_1=b[i][j]-a[j],ori_2=b[i][j-1]-a[j-1];
                    int tmp_1=(b[i][j]-a[j]+10)%10,tmp_2=(b[i][j-1]-a[j-1]+10)%10;
                    if(ori_1==ori_2 || (ori_1*ori_2<0 && tmp_1==tmp_2)) continue;
                    return false;
                }
                else if(cnt || last>2){
                    return false;
                }
                else cnt++;
            }
        }
        if(!cnt) return false;
    }/*
    for(int i=1;i<=5;i++)
        printf("%d ",a[i]);
    printf("\n");*/
    return true;
}

void dfs(int step)
{
    if(step==6)
        cnt+=check();
    else{
        for(int i=0;i<10;i++){
            a[step]=i;
            dfs(step+1);
        }
    }
}

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++)
            scanf("%d",&b[i][j]);
    }
    dfs(1);
    printf("%d\n",cnt);
    return 0;
}
