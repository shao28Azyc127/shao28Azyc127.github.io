#include<bits/stdc++.h>
using namespace std;
long long n,flag,flag2,cnt,c=2555;
long long a[10][7];
int ans[100050];
int main()
{
    freopen("lock2.in","r",stdin);
    freopen("lock2.out","w",stdout);
    cin>>n;
    cout<<cnt;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin>>a[i][j];
        }
    }
    if(n==1)
    {
        cout<<"81";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    else
    {
        for(int i=1;i<=9;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<5;k++)
                {
                    flag=0;
                    flag2=10000;
                    for(int m=0;m<5;m++)
                    {
                        if(m==k)
                        {
                            if(a[j][k]+i>=10)
                            {
                                flag+=flag2*(a[j][k]+i-10);
                            }
                            else
                            {
                                flag+=flag2*(a[j][k]+i);
                            }
                        }
                        else
                        {
                            flag+=flag2*a[j][m];
                        }
                        flag2/=10;
                    }
                    ans[flag]++;
                }
            }
        }
        for(int i=1;i<=9;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                for(int k=0;k<4;k++)
                {
                    flag=0;
                    flag2=10000;
                    for(int m=0;m<5;m++)
                    {
                        if(m==k||m==k+1)
                        {
                            if(a[j][k]+i>=10)
                            {
                                flag+=flag2*(a[j][m]+i-10);
                            }
                            else
                            {
                                flag+=flag2*(a[j][m]+i);
                            }
                        }
                        else
                        {
                            flag+=flag2*a[j][m];
                        }
                        flag2/=10;
                    }
                    ans[flag]++;
                }
            }
        }
        for(int i=0;i<100050;i++)
        {
            if(ans[i]==5)
            {
                cnt++;
            }
        }
        cout<<cnt;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
