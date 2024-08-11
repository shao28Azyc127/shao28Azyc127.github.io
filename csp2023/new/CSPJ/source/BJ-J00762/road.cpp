#include <bits/stdc++.h>

using namespace std;
int n,m;
struct man
{
    int c=0;
    int r=0;
    int place=0;
};
man mass;
int s[100000];
int q[100021];
void buy(int qqq)
{
    int ssa;
    for(int i=mass.place;i<qqq+mass.place;i++)
    {
        ssa=ssa+s[i];
    }
    if(mass.r<ssa)
    {
        int k=0;
        while(m*k<ssa)
        {
            k++;
        }
        mass.c=mass.c+(q[n]*k);
    }
}
int maxt(int ss)
{
    int sqa=0;
    for(int i=ss;i<n;i++)
    {
        sqa+=s[i];
        if(mass.r/sqa<0)
        {
            return i-1;
        }
    }
}
int road(int s)
{
    int ss=99999999;
    for(int i=s;i<maxt(s);i++)
    {
        ss=min(ss,q[i]);
    }
    for(int i=s;i<maxt(s);i++)
    {
        if(ss==q[i])
        {
            return i;
        }
    }
}
int distence()
{
    if(mass.place==0)
    {
        buy(1);
    }
    for(int i=0;i<n;i++)
    {
        buy(road(i));
        mass.r-=s[i];
        mass.place++;
        if(mass.place==n)
        {
            return mass.c;
        }
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n-1;i++)
    {
        cin>>s[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>q[i];
    }
    cout<<distence()<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
