#include<bits/stdc++.h>
using namespace std;
string lk[11];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<5;j++)
        {
            int a;
            cin>>a;
            char c=a+'0';
            lk[i]+=c;
        }
    //枚举可能的正确密码
    //10*10*10*10*10=100000种可能性
    int ans=0;
    for(char a='0';a<='9';a++)
        for(char b='0';b<='9';b++)
            for(char c='0';c<='9';c++)
                for(char d='0';d<='9';d++)
                    for(char e='0';e<='9';e++)
                    {
                        bool flag=true;
                        string now="";
                        now+=a;now+=b;now+=c;now+=d;now+=e;
                        for(int i=0;i<n;i++)
                        {
                            if(now==lk[i])
                            {
                                flag=false;
                                break;
                            }
                            int ret=0;
                            for(int j=0;j<5;j++)
                                if(now[j]!=lk[i][j])
                                    ret++;
                            if(ret>2)
                            {
                                flag=false;
                                break;
                            }
                            if(ret==2)
                            {
                                int w=-1,v=-1;
                                for(int j=0;j<5;j++)
                                    if(now[j]!=lk[i][j])
                                    {
                                        if(w==-1)
                                            w=j;
                                        else
                                            v=j;
                                    }
                                if(v-w!=1)
                                {
                                    flag=false;
                                    break;
                                }
                                if((lk[i][v]-now[v]+10)%10 != (lk[i][w]-now[w]+10)%10)
                                {
                                    flag=false;
                                    break;
                                }
                            }
                        }
                        if(flag)
                            ans++;
                    }
    cout<<ans;
    return 0;
}
