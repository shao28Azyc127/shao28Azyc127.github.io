#include<bits/stdc++.h>
using namespace std;
int n;
int lk[10][6];
int now[6];
long long ans;
int t;
int ab(int x)
{
    if(x<0)return -x;
    return x;
}
int check(int y){
    int temp = 0;
    int id1 = -50;
    int id2 = -50;
    for(int i = 1; i <= 5; i++){
        if(now[i]!=lk[y][i])
        {
            temp++;
            if(id1==-50)id1 = i;
            else id2 = i;
        }
    }
    if(temp==0)return 0;
    if(temp>2)return 0;
    if(temp==1)return 1;
    if(ab(id1-id2)>1)return 0;
    for(int k = 1; k <= 10; k++){
        if((now[id1]+k)%10==lk[y][id1]&&(now[id2]+k)%10==lk[y][id2])
        {return 1;}
    }
    return 0;
}
int judge()
{
    for(int i = 1; i <= n; i++){
        if(check(i)==0)return 0;
    }
    return 1;

}
void dfs(int x)
{
    if(x==5)
    {
        if(judge()){
            ans++;
        }
        return;
    }
    for(int i = 0; i <= 9; i++){
        now[x+1] = i;
        dfs(x+1);
    }
    return;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 5; j++){
            scanf("%d",&lk[i][j]);
        }
    }
    dfs(0);
    cout<<ans;
    return 0;
}
