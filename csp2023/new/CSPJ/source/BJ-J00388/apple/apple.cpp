#include <cstdio>
using namespace std;
int n;
int a[1000050];
bool check()
{
    for(int i=1; i<=n; i++)
    {
        if(a[i]==0)
        {
            return 0;
        }
    }
    return 1;
}
void apple()
{
    int day,ans=0;
    for(int i=0;; i++)
    {
        if(ans==0)
        {
            if(a[n]==1)
            {
                ans=i;
                a[n]=-1;
            }
        }

        if(check()==1)
        {
            day=i;
            break;
        }
        int f=2;
        for(int j=1; j<=n; j++)
        {
            if(a[j]==1)
            {
                continue;
            }
            if(f==2)
            {
                a[j]=1;
                f=0;
                continue;
            }
            f++;
        }
    }
    printf("%d %d",day,ans);
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    apple();
    return 0;
}
