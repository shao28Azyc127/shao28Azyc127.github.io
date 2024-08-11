#include<iostream>
#include<cstdio>
using namespace std;
struct MS
{
    MS *p;
    int n;
    MS()
    {
        p=this;
        n=0;
    }
    MS *head()
    {
        if(p==this)return this;
        MS *h=p->head();
        p=h;
        return h;
    }
    void merge(MS *a)
    {
        if(head()==a->head())return;
        if(head()->n<a->head()->n)head()->p=a->head();
        else if(head()->n==a->head()->n)
        {
            head()->p=a->head();
            a->head()->n++;
        }
        else a->head()->p=head();
    }
};
int va[100005];
MS *x[100005][2],*T,*F,*U;
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int tt=0;tt<t;tt++)
    {
        int n,m,u=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            va[i]=i;
            x[i][0]=new MS;
            x[i][1]=new MS;
        }
        for(int a=0;a<m;a++)
        {
            char v;
            int i,j;
            cin>>v>>i;
            switch(v)
            {
            case 'T':
                va[i]=1000000;
                break;
            case 'F':
                va[i]=-1000000;
                break;
            case 'U':
                va[i]=0;
                break;
            case '+':
                cin>>j;
                va[i]=va[j];
                break;
            case '-':
                cin>>j;
                va[i]=-va[j];
            }
        }
        T=new MS;
        F=new MS;
        U=new MS;
        for(int i=1;i<=n;i++)
        {
            if(va[i]==1000000)
            {
                x[i][0]->merge(T);
                x[i][1]->merge(F);
            }
            else if(va[i]==-1000000)
            {
                x[i][0]->merge(F);
                x[i][1]->merge(T);
            }
            else if(va[i]==0)
            {
                x[i][0]->merge(U);
                x[i][1]->merge(U);
            }
            else if(va[i]>0)
            {
                x[i][0]->merge(x[va[i]][0]);
                x[i][1]->merge(x[va[i]][1]);
            }
            else if(va[i]<0)
            {
                x[i][0]->merge(x[-va[i]][1]);
                x[i][1]->merge(x[-va[i]][0]);
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(x[i][0]->head()==x[i][1]->head()) u++;
        }
        cout<<u<<'\n';
    }
    return 0;
}
