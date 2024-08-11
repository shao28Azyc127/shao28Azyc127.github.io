#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,d,e,f[10][10][10][10][10][10],s;
void lk(int ii,int aa,int bb,int cc,int dd,int ee)
{
    for(int i=1;i<=9;i++)
    {
        int aaa=aa+i,bbb=bb+i,ccc=cc+i,ddd=dd+i,eee=ee+i;
        if(aaa>=10)
            aaa=aaa-10;
        if(bbb>=10)
            bbb=bbb-10;
        if(ccc>=10)
            ccc=ccc-10;
        if(ddd>=10)
            ddd=ddd-10;
        if(eee>=10)
            eee=eee-10;
        f[ii][aaa][bbb][cc][dd][ee]=1;
        f[ii][aa][bbb][ccc][dd][ee]=1;
        f[ii][aa][bb][ccc][ddd][ee]=1;
        f[ii][aa][bb][cc][ddd][eee]=1;

        f[ii][aaa][bb][cc][dd][ee]=1;
        f[ii][aa][bbb][cc][dd][ee]=1;
        f[ii][aa][bb][ccc][dd][ee]=1;
        f[ii][aa][bb][cc][ddd][ee]=1;
        f[ii][aa][bb][cc][dd][eee]=1;
    }
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b>>c>>d>>e;
        lk(i,a,b,c,d,e);
    }

    for(int g=0;g<=9;g++)
    {
        for(int h=0;h<=9;h++)
        {
            for(int i=0;i<=9;i++)
            {
                for(int j=0;j<=9;j++)
                {
                    for(int k=0;k<=9;k++)
                    {
                        bool ff=true;
                        for(int l=1;l<=n;l++)
                        {
                            if(f[l][g][h][i][j][k]!=1)
                            {
                                ff=false;
                            }
                        }
                        if(ff) s++;
                    }
                }

            }

        }

    }
    cout<<s;
    return 0;
}
