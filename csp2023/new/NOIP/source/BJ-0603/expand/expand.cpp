#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int c;
int n,m,q;
int arra[500005],arrb[500005];
int maxa=INT_MIN,maxb=INT_MIN,mina=INT_MAX,minb=INT_MAX;
pair <int,int> changex[500005],changey[500005];

void proccess()
{
    if(arra[n]-arrb[m]==0)
    {
        cout<<0;
        return ;
    }
    if((arra[1]-arrb[1])>0)
    {
        bool flag=false;
        if(mina-minb<0 || mina-minb==0)
        {
            cout<<0;
            return ;
        }
        else
        {
            int cur_p=1;
            for(int i=1;i<=m;i++)
            {
                while(arra[cur_p+1]>arrb[i] && cur_p<n)
                {
                    //cout<<i;
                    cur_p++;
                    //cout<<endl<<cur_p<<"t"<<endl;
                }
                if(arra[cur_p]<=arrb[i])
                {
                    flag=false;
                    for(int j=cur_p;j>=1;j--)
                    {
                        if(arra[j]>arrb[i])
                        {
                            cur_p = j;
                            flag=true;
                            break;
                        }
                    }
                    if(flag==false)
                    {
                        cout<<0;
                        return;
                    }
                    else
                    {
                        flag=false;
                    }
                }
            }
            if(cur_p == n)
            {
//                cout<<endl;
//
//                        for(int i=1;i<=n;i++)
//        {
//            cout<<arra[i]<<" ";
//        }
//        cout<<endl;
//        for(int i=1;i<=m;i++)
//        {
//            cout<<arrb[i]<<" ";
//        }
//        cout<<endl;

                cout<<1;

            }
            else
            {
                cout<<0;
            }
            return ;
        }
    }
    else if((arra[1]-arrb[1])<0)
    {
        bool flag=false;
        if(maxa-maxb>0 || maxa-maxb==0)
        {
            cout<<0;
            return ;
        }
        else
        {
            int cur_p=1;
            for(int i=1;i<=m;i++)
            {
                while(arra[cur_p+1]<arrb[i] && cur_p<n)
                {
                    //cout<<i;
                    cur_p++;
                    //cout<<endl<<n<<" "<<cur_p<<endl;
                }
                if(arra[cur_p]>=arrb[i])
                {
                    flag=false;
                    for(int j=cur_p;j>=1;j--)
                    {
                        if(arra[j]<arrb[i])
                        {
                            cur_p = j;
                            flag=true;
                            break;
                        }
                    }
                    if(flag==false)
                    {
                        cout<<0;
                        return;
                    }
                    else
                    {
                        flag=false;
                    }
                }
            }
            //cout<<cur_p;
            if(cur_p == n)
            {
                cout<<1;

            }
            else
            {
                cout<<0;
            }
            return ;
        }
    }
    else if((arra[1]-arrb[1])==0)
    {
        cout<<0;
        return ;
    }
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arra[i]);
        maxa=max(maxa,arra[i]);
        mina = min(mina,arra[i]);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&arrb[i]);
        maxb=max(maxb,arrb[i]);
        minb = min(minb,arrb[i]);
    }
    proccess();
    int kx,ky;
    int p,v;

    while(q--)
    {
        scanf("%d%d",&kx,&ky);

        maxa=INT_MIN,maxb=INT_MIN,mina=INT_MAX,minb=INT_MAX;
        for(int i=1;i<=kx;i++)
        {
            scanf("%d%d",&p,&v);
            changex[i].first = p;
            changex[i].second = arra[p];
            maxa = max(maxa,v);
            mina = min(mina,v);
            arra[p]=v;
        }
        for(int i=1;i<=ky;i++)
        {
            scanf("%d%d",&p,&v);
            changey[i].first = p;
            changey[i].second = arrb[p];
            maxb = max(maxb,v);
            minb = min(minb,v);
            arrb[p]=v;
        }
//        for(int i=1;i<=n;i++)
//        {
//            cout<<arra[i]<<" ";
//        }
//        cout<<endl;
//        for(int i=1;i<=m;i++)
//        {
//            cout<<arrb[i]<<" ";
//        }
//        cout<<endl;
        proccess();
        for(int i=1;i<=kx;i++)
        {
            arra[changex[i].first] = changex[i].second;
            maxa = max(maxa,arra[changex[i].first]);
            mina = min(mina,arra[changex[i].first]);
        }
        for(int i=1;i<=ky;i++)
        {
            arrb[changey[i].first] = changey[i].second;
            maxb = max(maxb,arrb[changey[i].first]);
            minb = min(minb,arrb[changey[i].first]);
        }
    }
    return 0;
}
