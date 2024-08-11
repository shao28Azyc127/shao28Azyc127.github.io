#include<bits/stdc++.h>
using namespace std;

int n,ans;
int a[10][10],s[10];

void dfs(int x)
{
    if(x>5)
    {
        bool flag=1;

        for(int i=1;i<=n;i++)
        {
            int cnt=0;
            int last1,last2;
            int num;
            for(int j=1;j<=5;j++)
            {
                if(a[i][j]!=s[j])
                {
                    cnt++;
                    if(cnt>2)
                    {
                        flag=0;
                        break;
                    }
                    int d1,d2;
                    if(a[i][j]>s[j])
                    {
                        d1=a[i][j]-s[j];
                        d2=-(10-d1);
                    }
                    else
                    {
                        d2=a[i][j]-s[j];
                        d1=10+d2;
                    }
                    if(cnt==1)
                    {
                        last1=d1;
                        last2=d2;
                        num=j;
                    }
                    else
                    {
                        if((d1!=last1&&d2!=last2)||j!=num+1)
                        {
                            flag=0;
                            break;
                        }
                    }
                }
            }
            if(cnt==0)
            {
                flag=0;
                break;
            }
            if(!flag)
                break;
        }
        if(flag)
            ans++;
        return;
    }
    for(int i=0;i<=9;i++)
    {
        s[x]=i;
        dfs(x+1);
    }
}

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n ;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
            cin >> a[i][j] ;
    dfs(1);
    cout << ans << endl ;
    return 0 ;
}
