#include<iostream>
using namespace std;
int rh(int l,int r,int rl[])
{
    int zl = 0;
    for(int i = l;i < r;i++)
    {
        zl = zl + rl[i];
    }
    return zl;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int syl = 0;
    int n,d;
    cin>>n>>d;
    int rl[n-1];
    int yj[n];
    for(int i = 0;i < n-1;i++)
    {
        cin>>rl[i];
    }
    for(int i = 0;i < n;i++)
    {
        cin>>yj[i];
    }
    int a = 0;
    int ans = 0;
    while(a != n-1)
    {
        for(int i = a;i < n;i++)
        {
            if(yj[i] < yj[a])
            {
                int yl = rh(a,i,rl);
                if(syl != 0)
                {
                    if((yl-syl) % d == 0)
                    {
                        yl = (yl-syl) / d;
                        syl = 0;
                    }
                    else
                    {
                        int fj = 0;
                        bool ok = false;
                        while((yl-syl+fj) % d != 0 && fj <= syl)
                        {
                            fj++;
                            if((yl-syl+fj) % d == 0)
                            {
                                ok = true;
                            }
                        }
                        if(ok == true)
                        {
                            syl = syl-(syl-fj);
                            yl = (yl-syl+fj) / d;
                        }
                        else
                        {
                            syl = d;
                            yl = yl / d;
                        }
                    }
                    ans = ans + yl*yj[a];
                    a = i;
                    break;
                }
                else
                {
                    if(yl % d == 0)
                    {
                        yl = yl / d;
                    }
                    else
                    {
                        syl = syl + d - (yl % d);
                        yl = yl / d + 1;
                    }
                    ans = ans + yl*yj[a];
                    a = i;
                    break;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}