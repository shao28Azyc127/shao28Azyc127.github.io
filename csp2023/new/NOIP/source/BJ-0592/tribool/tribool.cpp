#include <bits/stdc++.h>
using namespace std;

#define T_ 10000000
#define F_ 10000001
#define U_ 10000002

int val[100005];
int a[100005];
bool book[100005];
set<int> bk;
/*
int search_(int n)
{
    int bkk=n;
    //bk.insert(n);

    while(a[n]!=bkk&&a[n]!=-bkk&&a[n]!=T_&&a[n]!=F_&&a[n]!=U_&&bk.find(a[n])==bk.end())
    {
        n=abs(a[n]);
        bk.insert(n);
    }
    bk.clear();

    if(a[n]==bkk)
    {
        return T_;
    }
    else if(a[n]==-bkk)
    {
        return U_;
    }
    else// if(a[n]==T_||a[n]==F_||a[n]==U_)
    {
        return a[n];
    }


    while(!book[n])
    {
        book[n]=true;
        n=a[n];
        if(bk.find(-bkk))
        {
            return U_;
        }
        else if(bk.find(n))
        {
            return T_;
        }
        else
        {
            bk.insert(n)
        }
    }
    return 0;
}*/

int search_(int n)
{
    int bkk=n;

    bk.insert(n);
    while(a[abs(n)]!=bkk&&a[abs(n)]!=-bkk&&a[abs(n)]!=T_&&a[abs(n)]!=F_&&a[abs(n)]!=U_&&bk.find(a[abs(n)])==bk.end())
    {
        if(n>0)
        {
            n=a[n];
        }
        else
        {
            n=-a[-n];
        }
        bk.insert(n);
    }
    bk.clear();

    if(a[n]==bkk)
    {
        return T_;
    }
    else if(a[n]==-bkk)
    {
        return U_;
    }
    else if(a[n]==T_||a[n]==F_||a[n]==U_)
    {
        return a[n];
    }
    else
    {
        return bkk;
    }
}

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);

    int t;
    scanf("%d%d",&t,&t);
    int n,m;

    char c;
    int ca,caa;
    int cnt;
    bool flag=true;

    while(t--)
    {
        scanf("%d%d",&n,&m);

        for(int i=1;i<=n;i++)
        {
            a[i]=i;
        }

        cnt=0;
        while(m--)
        {
            cin>>c;
            switch(c)
            {
                case 'T':
                {
                    scanf("%d",&ca);
                    val[ca]=T_;
                    break;
                }

                case 'F':
                {
                    scanf("%d",&ca);
                    a[ca]=F_;
                    break;
                }

                case 'U':
                {
                    scanf("%d",&ca);
                    a[ca]=U_;
                    break;
                }

                case '+':
                {
                    scanf("%d%d",&ca,&caa);
                    a[ca]=caa;
                    break;
                }

                case '-':
                {
                    scanf("%d%d",&ca,&caa);

                    if(caa<=n)
                    {
                        a[ca]=-caa;
                    }
                    else
                    {
                        if(caa==T_)
                        {
                            a[ca]=F_;
                        }
                        else if(caa==F_)
                        {
                            a[ca]=T_;
                        }
                        else if(caa==U_)
                        {
                            a[ca]=U_;
                        }
                    }

                    break;
                }

                default:
                {
                    break;
                }
            }
        }

        for(int i =1;i<=n;i++)
        {
            if(a[i]==i)
            {
                a[i]=T_;
            }
            else if(a[i]==-i)
            {
                a[i]=U_;
            }
        }

        //while(flag)
        {
            flag=false;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==T_||a[i]==F_||a[i]==U_)
                {
                    continue;
                }
                else
                {
                    flag=true;
                    a[i]=search_(i);
                }
            }
        }

        for(int i=1;i<=n;i++)
        {
            if(a[i]==U_)
                cnt++;
        }
        printf("%d\n",cnt);
    }

    return 0;
}
