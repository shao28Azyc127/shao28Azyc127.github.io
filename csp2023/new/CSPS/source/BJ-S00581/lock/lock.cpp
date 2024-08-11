#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 10;

int g[N][10],n,cnt = 0,nw[10];
int modify(int a,int b)
{
    int ret = a+b;
    if(ret < 0) ret = 10+ret;
    if(ret > 9) ret %= 10;
    return ret;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= 5;++j) cin>>g[i][j];
    for(int a = 0;a <= 9;++a)
        for(int b = 0;b <= 9;++b)
            for(int c = 0;c <= 9;++c)
                for(int d = 0;d <= 9;++d)
                    for(int e = 0;e <= 9;++e)
                    {
                        nw[1] = a,nw[2] = b,nw[3] = c,nw[4] = d,nw[5] = e;
                        int fl1 = 1;
                        for(int i = 1;i <= n;++i)
                        {
                            int fl2 = 0,dif = 0,sa = 0;
                            for(int j = 1;j <= 5;++j)
                            {
                                if(j != 5)
                                {
                                    if(g[i][j] != nw[j])
                                    {
                                        int tmp = nw[j]-g[i][j],tmp2 = 0;
                                        if(tmp < 0)
                                        {
                                            tmp2 = 10+tmp;
                                            if(modify(g[i][j+1],tmp) == nw[j+1]) ++sa;
                                            else if(modify(g[i][j+1],tmp) == nw[j+1]) ++sa;
                                        }
                                        else if(tmp > 0)
                                        {
                                            tmp2 = -(10-tmp);
                                            if(modify(g[i][j+1],tmp) == nw[j+1]) ++sa;
                                            else if(modify(g[i][j+1],tmp) == nw[j+1]) ++sa;
                                        }
                                    }
                                }
                                if(nw[j] != g[i][j]) ++dif;
                            }
                            if(dif == 1||((dif == 2)&&(sa == 1))) fl2 = 1;
                            if(fl2 == 0) fl1 = 0;
                        }

                        if(fl1)
                        {
                            ++cnt;

                        }
                    }
    cout<<cnt<<endl;
    return 0;
}
