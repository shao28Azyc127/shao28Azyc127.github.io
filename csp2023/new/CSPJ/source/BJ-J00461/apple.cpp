#include<bits/stdc++.h>
using namespace std;

int n;
bool a[100005];
int hav;
int ans[100005];
int tot;
int l;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    hav=n;
    for (int i=1;i<=n;i++)
    {
        a[i]=1;
    }
    while(hav)
    {
        l++;
        int tmp=0;
        for (int i=1;i<=n;i++)
        {
            if(a[i])
            {
                //printf("%d",i);
                if (!tmp)
                {
                    a[i]=0;
                    hav--;
                    //printf("%d ",i);
                    ans[i]=l;
                }
                //printf("  ");
                tmp=(tmp+1)%3;
            }
        }
        //printf("\n");
    }
    for (int i=1;i<=n;i++)
    {
        tot=max(ans[i],tot);
    }
    printf("%d %d",tot, ans[n]);
    return 0;
}
