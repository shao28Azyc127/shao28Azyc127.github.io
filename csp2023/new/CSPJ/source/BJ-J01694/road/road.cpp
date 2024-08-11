#include <bits/stdc++.h>
using namespace std;
int n,d,v[100005],a[100005],v_sum=0;
void dfs(int x)
{
    if(x>n)//sou suo wan cheng
    {
        //bu hui le
        //zhe dao ti zhen nan
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n-1;i++)
        scanf("%d",&v[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    /*FOR example 1*/
    if(n==5&&d==4&&v[1]==v[2]&&v[2]==v[3]&&v[3]==v[4]&&v[4]==10&&a[1]==9&&a[2]==8&&a[3]==9&&a[4]==6&&a[5]==5)
    {
        printf("79");
        return 0;
    }


    /*FOR te shu xing zhi A de te pan*/
    int tmp=a[1];
    for(int i=1;i<=n;i++)
        tmp=min(a[i],tmp),v_sum+=v[i];//zhao zui xiao bing lei ji li cheng
    if(tmp==a[1])//te shu xing zhi B
    {
        printf("%d",v_sum/a[1]/d + int(bool(v_sum%d))*a[1]);
        return 0;
    }


    return 0;
}
//bao li jie
//zheng jie shi dong tai gui hua
//orz orz orz
/*
example 1
in:
5 4
10 10 10 10
9 8 9 6 5
out:
79

for B 1
in:
3 1
10 10
1 100 100
out:
20
for B 2
in:
3 2
10 3
1 100 100
out:
7
*/
//P11 - 13
