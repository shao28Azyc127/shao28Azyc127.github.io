#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
struct Node
{
    int maxn;
    int m;
};
Node f;
Node a1[105];
vector<string> q;//struct
vector<string> q1;//weishu
vector<string> q2;
vector<int> q3;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    int i;
    int m=1;
    int h=0;
    int kong=0;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        int p=m;
        if(x==1)
        {
            h++;
            string s;
            int t;
            int maxn=0;
            cin>>s;
            cin>>t;
            q.push_back(s);
            q3.push_back(t);
            for(int i1=1;i1<=t;i1++)
            {
                string s1;
                string s2;
                cin>>s1>>s2;
                q2.push_back(s2);
                if(s1=="long")
                {
                    maxn=8;
                    if((m-1)%8==0)
                    {
                        m+=8;
                    }
                    else
                    {
                        int m1=m/8*8+9;
                        m=m1+8;
                    }
                }
                else if(s1=="int")
                {
                    maxn=max(maxn,4);
                    if((m-1)%4==0)
                    {
                        m+=4;
                    }
                    else
                    {
                        int m1=(m-1)/4*4+5;
                        m=m1+4;
                    }
                }
                else if(s1=="short")
                {
                    maxn=max(maxn,2);
                    if((m-1)%2==0)
                    {
                        m+=2;
                    }
                    else
                    {
                        int m1=m/2*2+3;
                        m=m1+2;
                    }
                }
                else if(s1=="byte")
                {
                    maxn=max(maxn,1);
                    m++;
                }
                else
                {
                    for(i=0;i<=h;i++)
                    {
                        if(q[i]==s1)
                        {
                            m+=a1[i].m;
                            maxn=max(maxn,a1[i].maxn);
                            break;
                        }
                    }
                }
            }
            cout<<m-p<<" "<<maxn<<endl;
            a1[h-1].maxn=maxn;
            a1[h-1].m=m-p;
        }
        if(x==2)
        {
            string s;
            string s2;
            cin>>s>>s2;
            cout<<kong<<endl;
            if(s=="long")
            {
                if((kong-1)%8==0)
                    {
                        for(i=kong+1;i<=kong+8;i++)
                        {
                            q1.push_back(s2);
                        }
                        kong+=8;
                    }
                    else
                    {
                        int kong1=kong/8*8+9;
                        for(i=kong+1;i<=kong1-1;i++)
                        {
                            q1.push_back("ERR");
                        }
                        for(i=kong1;i<=kong1+8;i++)
                        {
                            q1.push_back(s2);
                        }
                        kong=kong1+8;
                    }
            }
            else if(s=="int")
            {
                    if((kong-1)%4==0)
                    {
                        for(i=kong+1;i<=kong+4;i++)
                        {
                            q1.push_back(s2);
                        }
                        kong+=4;
                    }
                    else
                    {
                        int kong1=(kong-1)/4*4+5;
                        for(i=kong;i<=kong1-1;i++)
                        {
                            q1.push_back("ERR");
                        }
                        for(i=kong1;i<=kong1+4;i++)
                        {
                            q1.push_back(s2);
                        }
                        kong=kong1+4;
                    }
            }
            else if(s=="short")
            {
                if((kong-1)%2==0)
                    {
                        for(i=kong+1;i<=kong+2;i++)
                        {
                            q1.push_back(s2);
                        }
                        kong+=2;
                    }
                    else
                    {
                        int kong1=kong/2*2+3;
                        for(i=kong;i<=kong1-1;i++)
                        {
                            q1.push_back("ERR");
                        }
                        for(i=kong1;i<=kong1+2;i++)
                        {
                            q1.push_back(s2);
                        }
                        kong=kong1+2;
                    }
            }
            else if(s=="byte")
            {
                    kong++;
                    q1.push_back(s2);
            }
            else
            {
                for(i=0;i<=h;i++)
                {
                    if(s==q[i])
                    {
                        for(int j=0;i<q3[i];i++)
                        {
                            string s0;
                            s0=s+"."+q2[i*q3[j]];
                            q1.push_back(s0);
                        }
                    }
                }
            }

        }
        if(x==3)
        {
            string s;
            cin>>s;
            for(i=0;i<q1.size();i++)
            {
                if(q1[i]==s)
                {
                    cout<<i<<endl;
                    break;
                }
            }
        }
        if(x==4)
        {
            int add;
            cin>>add;
            cout<<q1[add]<<endl;
        }
    }

    return 0;
}
