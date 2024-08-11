#include <bits/stdc++.h>
using namespace std;
int lo[10][10],n,ans,c,an[20][10],id[6],fid[6],s;
bool mark[20],po[6];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    if(n==1)
    {
        cin>>lo[1][1]>>lo[1][2]>>lo[1][3]>>lo[1][4]>>lo[1][5];
        cout<<81<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
        cin>>lo[i][1]>>lo[i][2]>>lo[i][3]>>lo[i][4]>>lo[i][5];
    for(int i=1;i<=5;i++)
        if(lo[1][i]!=lo[2][i])
        {
            po[i]=1;
            c++;
            id[c]=i;
        }
        else
            fid[++s]=i;
    if(c==5)
    {
        cout<<0<<endl;
        return 0;
    }
    if(c==4)
    {
        if(!po[2]||!po[4])
        {
            cout<<0<<endl;
            return 0;
        }
        if((lo[1][id[1]]-lo[1][id[2]])!=(lo[2][id[1]]-lo[2][id[2]])||(lo[1][id[3]]-lo[1][id[4]])!=(lo[2][id[3]]-lo[2][id[4]]))
        {
            cout<<0<<endl;
            return 0;
        }
        ans=2;
        mark[1]=mark[2]=1,an[1][fid[1]]=an[2][fid[1]]=lo[1][fid[1]];
        an[1][id[1]]=lo[1][id[1]],an[1][id[2]]=lo[1][id[2]],an[1][id[3]]=lo[2][id[3]],an[1][id[4]]=lo[2][id[4]];
        an[2][id[1]]=lo[2][id[1]],an[2][id[2]]=lo[2][id[2]],an[2][id[3]]=lo[1][id[3]],an[2][id[4]]=lo[1][id[4]];
    }
    if(c==3)
    {
        if(!po[2]&&!po[4])
        {
            cout<<0<<endl;
            return 0;
        }
        if(lo[1][id[1]]-lo[1][id[2]]!=lo[2][id[1]]-lo[2][id[2]]&&lo[1][id[3]]-lo[1][id[2]]!=lo[2][id[3]]-lo[2][id[2]])
        {
            cout<<0<<endl;
            return 0;
        }
        if((lo[1][id[1]]-lo[1][id[2]]==lo[2][id[1]]-lo[2][id[2]])&&id[1]+1==id[2])
        {
            mark[1]=mark[2]=1,an[1][fid[1]]=an[2][fid[1]]=lo[1][fid[1]],an[1][fid[2]]=an[2][fid[2]]=lo[1][fid[2]];
            an[1][id[1]]=lo[1][id[1]],an[1][id[2]]=lo[1][id[2]],an[1][id[3]]=lo[2][id[3]];
            an[2][id[1]]=lo[2][id[1]],an[2][id[2]]=lo[2][id[2]],an[2][id[3]]=lo[1][id[3]];
            ans+=2;
        }
        if((lo[1][id[3]]-lo[1][id[2]]==lo[2][id[3]]-lo[2][id[2]])&&id[2]+1==id[3])
        {
            mark[ans+1]=mark[ans+2]=1,an[ans+1][fid[1]]=an[ans+2][fid[1]]=lo[1][fid[1]],an[ans+1][fid[2]]=an[ans+2][fid[2]]=lo[1][fid[2]];
            an[ans+1][id[3]]=lo[1][id[3]],an[ans+1][id[2]]=lo[1][id[2]],an[ans+1][id[1]]=lo[2][id[1]];
            an[ans+2][id[3]]=lo[2][id[3]],an[ans+2][id[2]]=lo[2][id[2]],an[ans+2][id[1]]=lo[1][id[1]];
            ans+=2;
        }
    }
    if(c==2)
    {
        ans=2;
        mark[1]=mark[2]=1,an[1][fid[1]]=an[2][fid[1]]=lo[1][fid[1]],an[1][fid[2]]=an[2][fid[2]]=lo[1][fid[2]],an[1][fid[3]]=an[2][fid[3]]=lo[1][fid[3]];
        an[1][id[1]]=lo[1][id[1]],an[1][id[2]]=lo[2][id[2]];
        an[2][id[1]]=lo[2][id[1]],an[2][id[2]]=lo[1][id[2]];
        if(id[1]+1==id[2])
        {
            if(lo[1][id[1]]-lo[1][id[2]]==lo[2][id[1]]-lo[2][id[2]])
            {
                int x=lo[1][id[1]]-lo[1][id[2]];
                for(int i=0;i<=9;i++)
                {
                    if(i==lo[1][id[1]]||i==lo[2][id[1]])
                        continue;
                    ans++,mark[ans]=1;
                    an[ans][fid[1]]=lo[1][fid[1]],an[ans][fid[2]]=lo[1][fid[2]],an[ans][fid[3]]=lo[1][fid[3]];
                    an[ans][id[1]]=i,an[ans][id[2]]=(i-x+10)%10;
                }
            }
            else
            {
                mark[ans+1]=mark[ans+2]=mark[ans+3]=mark[ans+4]=1;
                an[ans+1][fid[1]]=an[ans+2][fid[1]]=an[ans+3][fid[1]]=an[ans+4][fid[1]]=lo[1][fid[1]];
                an[ans+1][fid[2]]=an[ans+2][fid[2]]=an[ans+3][fid[2]]=an[ans+4][fid[2]]=lo[1][fid[2]];
                an[ans+1][fid[3]]=an[ans+2][fid[3]]=an[ans+3][fid[3]]=an[ans+4][fid[3]]=lo[1][fid[3]];
                an[ans+1][id[1]]=lo[1][id[1]],an[ans+1][id[2]]=(lo[1][id[1]]+(lo[2][id[2]]-lo[2][id[1]])+10)%10;
                an[ans+2][id[1]]=lo[2][id[1]],an[ans+2][id[2]]=(lo[2][id[1]]+(lo[1][id[2]]-lo[1][id[1]])+10)%10;
                an[ans+3][id[2]]=lo[1][id[2]],an[ans+3][id[1]]=(lo[1][id[2]]+(lo[2][id[1]]-lo[2][id[2]])+10)%10;
                an[ans+4][id[2]]=lo[2][id[2]],an[ans+4][id[1]]=(lo[2][id[2]]+(lo[1][id[1]]-lo[1][id[2]])+10)%10;
                ans+=4;
            }
        }
    }
    if(c==1)
    {
        for(int i=0;i<=9;i++)
        {
            if(i==lo[1][id[1]]||i==lo[2][id[1]])
                continue;
            ans++,mark[ans]=1;
            an[ans][fid[1]]=lo[1][fid[1]],an[ans][fid[2]]=lo[1][fid[2]],an[ans][fid[3]]=lo[1][fid[3]],an[ans][fid[4]]=lo[1][fid[4]];
            an[ans][id[1]]=i;
        }
        if(id[1]!=1)
        {
            mark[ans+1]=mark[ans+2]=1;
            an[ans+1][fid[1]]=an[ans+2][fid[1]]=lo[1][fid[1]],an[ans+1][fid[2]]=an[ans+2][fid[2]]=lo[1][fid[2]];
            an[ans+1][fid[3]]=an[ans+2][fid[3]]=lo[1][fid[3]],an[ans+1][fid[4]]=an[ans+2][fid[4]]=lo[1][fid[4]];
            an[ans+1][id[1]-1]=lo[1][id[1]-1],an[ans+1][id[1]]=(lo[1][id[1]]+lo[2][id[1]-1]-lo[2][id[1]]+10)%10;
            an[ans+2][id[1]-1]=lo[2][id[1]-1],an[ans+2][id[1]]=(lo[2][id[1]]+lo[1][id[1]-1]-lo[1][id[1]]+10)%10;
            ans+=2;
        }
        if(id[1]!=5)
        {
            mark[ans+1]=mark[ans+2]=1;
            an[ans+1][fid[1]]=an[ans+2][fid[1]]=lo[1][fid[1]],an[ans+1][fid[2]]=an[ans+2][fid[2]]=lo[1][fid[2]];
            an[ans+1][fid[3]]=an[ans+2][fid[3]]=lo[1][fid[3]],an[ans+1][fid[4]]=an[ans+2][fid[4]]=lo[1][fid[4]];
            an[ans+1][id[1]+1]=lo[1][id[1]+1],an[ans+1][id[1]]=(lo[1][id[1]]+lo[2][id[1]+1]-lo[2][id[1]]+10)%10;
            an[ans+2][id[1]+1]=lo[2][id[1]+1],an[ans+2][id[1]]=(lo[2][id[1]]+lo[1][id[1]+1]-lo[1][id[1]]+10)%10;
            ans+=2;
        }
    }
    int x=ans;
    for(int j=3;j<=n;j++)
    {
        c=0,s=0;
        memset(po,0,sizeof(po));
        memset(id,0,sizeof(id));
        memset(fid,0,sizeof(fid));
        for(int i=1;i<=x;i++)
        {
            if(!mark[i])
                continue;
            for(int k=1;k<=5;k++)
                if(lo[j][k]!=an[i][k])
                {
                    po[k]=1;
                    c++;
                    id[k]=i;
                }
                else
                    fid[++s]=i;
            if(c>=3)
            {
                mark[i]=0;
                ans--;
            }
            if(c==2&&(lo[j][id[1]]-lo[j][id[2]]!=an[i][id[1]]-an[i][id[2]]))
            {
                mark[i]=0;
                ans--;
            }
        }

    }
    cout<<ans<<endl;
    return 0;
}