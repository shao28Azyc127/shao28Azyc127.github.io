#include<cstdio>
using namespace std;

int a;

int checkmate(int x,int day)
{
    if(x%3==1&&a==0)
    {
        a=day;
    }
    if(x==1)
    {
        return day;
    }
    if(x%3==0)
    {
        return checkmate(x-(x/3),day+1);
    }
    else
    {
        return checkmate(x-(x/3+1),day+1);
    }
}

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    scanf("%d",&n);
    int t=checkmate(n,1);
    printf("%d %d",t,a);
    return 0;
}
