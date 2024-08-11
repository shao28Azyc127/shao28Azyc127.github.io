#include <bits/stdc++.h>
using namespace std;
struct one
{
    int a,b,c,d,e;
};
one ind[10];

bool check(one aaa,one bbb)
{
    int sam=0;
    sam=(aaa.a==bbb.a)+(aaa.b==bbb.b)+(aaa.c==bbb.c)+(aaa.d==bbb.d)+(aaa.e==bbb.e);
    if(sam<3)
        return false;
    if(sam==5)
        return false;
    if(sam==4)
        return true;
    int i=0,tmp[10][2],tmp2[10];
    if(aaa.a!=bbb.a)
    {
        tmp[i][0]=aaa.a;
        tmp[i][1]=bbb.a;
        tmp2[i]=1;
        i++;
    }
    if(aaa.b!=bbb.b)
    {
        tmp[i][0]=aaa.b;
        tmp[i][1]=bbb.b;
        tmp2[i]=2;
        i++;
    }
    if(aaa.c!=bbb.c)
    {
        tmp[i][0]=aaa.c;
        tmp[i][1]=bbb.c;
        tmp2[i]=3;
        i++;
    }
    if(aaa.d!=bbb.d)
    {
        tmp[i][0]=aaa.d;
        tmp[i][1]=bbb.d;
        tmp2[i]=4;
        i++;
    }
    if(aaa.e!=bbb.e)
    {
        tmp[i][0]=aaa.e;
        tmp[i][1]=bbb.e;
        tmp2[i]=5;
        i++;
    }
    int k1=tmp[0][0]-tmp[0][1],k2=tmp[1][0]-tmp[1][1];
    if(k1<0) k1+=10;
    if(k2<0) k2+=10;
    if(k1!=k2) return false;
    else
    {
        if(tmp2[1]-tmp2[0]==1)
            return true;
        return false;
    }
}

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 1;i <=n;i++)
        cin>>ind[i].a>>ind[i].b>>ind[i].c>>ind[i].d>>ind[i].e;
    int cntans=0;
    for(int x1=0;x1<10;x1++)
        for(int x2=0;x2<10;x2++)
            for(int x3=0;x3<10;x3++)
                for(int x4=0;x4<10;x4++)
                    for(int x5=0;x5<10;x5++)
                    {
                        one aa;
                        aa.a=x1;aa.b=x2;aa.c=x3;aa.d=x4;aa.e=x5;
                        int yes=1;
                        for(int i = 1;i <=n;i++)
                            if(!check(ind[i],aa))
                            {
                                yes=0;
                                break;
                            }
                        if(yes==1)
                            cntans++;
                    }
    cout<<cntans;
    return 0;
}
