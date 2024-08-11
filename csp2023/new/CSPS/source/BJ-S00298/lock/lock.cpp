#include <fstream>
using namespace std;
ifstream cin ("lock.in");
ofstream cout ("lock.out");
int dis (int x,int y)
{
    if (y>=x)
    {
        return y-x;
    }
    else
    {
        return 10+y-x;
    }
}
int main ()
{
    int n;
    cin>>n;
    int a[10][6];
    for (int j=1;j<=n;j++)
    {
        for (int i=1;i<=5;i++)
        {
            cin>>a[j][i];
        }
    }
    int i[6];
    int ans=0;
    for (i[1]=0;i[1]<10;i[1]++)
    {
        for (i[2]=0;i[2]<10;i[2]++)
        {
            for (i[3]=0;i[3]<10;i[3]++)
            {
                for (i[4]=0;i[4]<10;i[4]++)
                {
                    for (i[5]=0;i[5]<10;i[5]++)
                    {
                        int tmp=0;
                        for (int k=1;k<=n;k++)
                        {
                            int cnt=0;
                            int f=10,l=0;
                            for (int j=1;j<=5;j++)
                            {
                                if (i[j]!=a[k][j])
                                {
                                    cnt++;
                                    f=min(f,j);
                                    l=max(l,j);
                                }
                            }
                            if (cnt==0 or cnt>=3)
                            {
                                continue;
                            }
                            if (cnt==1)
                            {
                                tmp++;
                            }
                            if (cnt==2)
                            {
                                if(l==f+1 and dis(i[f],a[k][f])==dis(i[l],a[k][l]))
                                {
                                    tmp++;
                                }
                            }
                        }
                        if (tmp==n)
                        {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}