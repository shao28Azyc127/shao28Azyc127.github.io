#include <stdio.h>
#include <math.h>
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int pw[9][7];
    int t[7];
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d%d%d",&pw[i][1],&pw[i][2],&pw[i][3],&pw[i][4],&pw[i][5]);
    }
    if(n==1)
    {
        printf("81");
        return 0;
    }
    int cnt=0;
    for(t[1]=0;t[1]<=9;t[1]++)
    {
        for(t[2]=0;t[2]<=9;t[2]++)
        {
            for(t[3]=0;t[3]<=9;t[3]++)
            {
                for(t[4]=0;t[4]<=9;t[4]++)
                {
                    for(t[5]=0;t[5]<=9;t[5]++)
                    {
                        int f=true;
                        for(int i=1;i<=n && f;i++)
                        {
                            f=false;
                            for(int j=1;j<=5;j++)
                            {
                                if(t[j]!=pw[i][j])
                                {
                                    if(f)
                                    {
                                        f=0;
                                        break;
                                    }
                                    if(t[j+1]!=pw[i][j+1] && (t[j]-t[j+1]==pw[i][j]-pw[i][j+1] || abs(t[j]-t[j+1]+pw[i][j+1]-pw[i][j])==10))
                                    {
                                        j++;
                                    }
                                    f=1;
                                }
                            }
                        }
                        if(f) cnt++;
                    }
                }
            }
        }
    }
    printf("%d\n",cnt);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
