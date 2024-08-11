#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,w=1;
    char ch=0;
    while(ch<'0'||'9'<ch)
    {
        if(ch=='-')w=-1;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9')
    {
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    return x*w;
}
int n;
int s[10][6];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=5;++j)
        {
            cin>>s[i][j];
        }
    }
    int ans=0,cnt1=0,cnt2=0;
    for(int a=0;a<=9;++a)
    {
        for(int b=0;b<=9;++b)
        {
            for(int c=0;c<=9;++c)
            {
                for(int d=0;d<=9;++d)
                {
                    for(int e=0;e<=9;++e)
                    {
                        bool flag=1;
                        for(int i=1;i<=n;++i)
                        {
                            if(!flag)break;
                            int tmp[6];
                            int cnt=0;
                            tmp[1]=(a-s[i][1]+10)%10;
                            tmp[2]=(b-s[i][2]+10)%10;
                            tmp[3]=(c-s[i][3]+10)%10;
                            tmp[4]=(d-s[i][4]+10)%10;
                            tmp[5]=(e-s[i][5]+10)%10;
                            for(int j=1;j<=5;++j)
                            {
                                if(tmp[j]==0)
                                {
                                    cnt++;
                                }
                            }
                            if(cnt==4)
                            {
                                cnt1++;
                                continue;
                            }
                            else if(cnt==3)
                            {
                                for(int j=1;j<=4;++j)
                                {
                                    if(tmp[j]!=0)
                                    {
                                        if(tmp[j]==tmp[j+1])
                                        {
                                            cnt2++;
                                            break;
                                        }
                                        else
                                        {
                                            flag=0;
                                            break;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                flag=0;
                            }
                        }
                        if(flag)
                        {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
