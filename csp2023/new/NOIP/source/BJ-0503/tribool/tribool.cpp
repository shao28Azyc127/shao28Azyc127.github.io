#include<iostream>
using namespace std;
int c,t,n,m,aw[10],awsd=0;
struct order
{
    char v;
    int a;
    int b;
};
order o[100000];
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    bool unspr[100001];
    for(int i=0;i<=100000;i++)
    {
        unspr[i]=false;
    }
    for(int ertgte=0;ertgte<t;ertgte++)
    {
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            string ls;
            cin>>ls;
            o[i].v=ls[0];
            if(o[i].v!='+'&&o[i].v!='-')
            {
                o[i].a=ls[2];
            }
            else
            {
                o[i].a=ls[2];
                o[i].b=ls[4];
            }
        }
        if(c==1||c==2)
        {
            int d[10],ans=11,k[10];
            int aw[10],awsd=0;
            for(d[0]=0;d[0]<3;d[0]++)
            {
                k[0]=d[0];
                for(d[1]=0;d[1]<3;d[1]++)
                {
                    k[1]=d[1];
                    for(d[2]=0;d[2]<3;d[2]++)
                    {
                        k[2]=d[2];
                        for(d[3]=0;d[3]<3;d[3]++)
                        {
                            k[3]=d[3];
                            for(d[4]=0;d[4]<3;d[4]++)
                            {
                                k[4]=d[4];
                                for(d[5]=0;d[5]<3;d[5]++)
                                {
                                    k[5]=d[5];
                                    for(d[6]=0;d[6]<3;d[6]++)
                                    {
                                        k[6]=d[6];
                                        for(d[7]=0;d[7]<3;d[7]++)
                                        {
                                            k[7]=d[7];
                                            for(d[8]=0;d[8]<3;d[8]++)
                                            {
                                                k[8]=d[8];
                                                for(d[9]=0;d[9]<3;d[9]++)
                                                {
                                                    k[9]=d[9];
                                                    for(int i=0;i<m;i++)
                                                    {
                                                        if(o[i].v=='+')
                                                        {
                                                            d[o[i].a]=d[o[i].b];
                                                        }
                                                        else if(o[i].v=='-')
                                                        {
                                                            d[o[i].a]=2-d[o[i].b];
                                                        }
                                                        else if(o[i].v=='U')
                                                        {
                                                            d[o[i].a]=1;
                                                        }
                                                        else if(o[i].v=='F')
                                                        {
                                                            d[o[i].a]=0;
                                                        }
                                                        else if(o[i].v=='T')
                                                        {
                                                            d[o[i].a]=2;
                                                        }
                                                    }
                                                    bool pass=true;
                                                    for(int i=0;i<n;i++)
                                                    {
                                                        if(k[i]!=d[i])
                                                        {
                                                            pass=false;
                                                            d[i]=k[i];
                                                        }
                                                    }
                                                    if(!pass) continue;
                                                    int cnt=0;
                                                    for(int i=0;i<n;i++)
                                                    {
                                                        if(d[i]==1) cnt++;
                                                    }
                                                    if(ans>cnt) ans=cnt;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            aw[awsd]=ans;
            awsd++;
        }
        else if(c==3||c==4)
        {
            for(int i=0;i<m;i++)
            {
                if(o[i].v=='U')
                {
                    unspr[o[i].a]=true;
                }
                else
                {
                    unspr[o[i].a]=false;
                }
            }
            int cnt=0;
            for(int i=0;i<n;i++)
            {
                if(unspr[i]==true)
                {
                    cnt++;
                    unspr[i]=false;
                }
            }
            aw[awsd]=cnt;
            awsd++;
        }
        else if(c==5||c==6)
        {
            for(int i=0;i<m;i++)
            {
                if(o[i].v=='U')
                {
                    unspr[o[i].a]=true;
                }
                else
                {
                    unspr[o[i].a]=unspr[o[i].b];
                }
            }
            int cnt=0;
            for(int i=0;i<n;i++)
            {
                if(unspr[i]==true)
                {
                    cnt++;
                    unspr[i]=false;
                }
            }
            aw[awsd]=cnt;
            awsd++;
        }
    }
    for(int i=0;i<awsd;i++)
    {
        cout<<aw[i]<<endl;
    }
    return 0;
}