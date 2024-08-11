/*#include <bits/stdc++.h>

using namespace std;
long long n,p[10005][10005],a[10005],b[10005],c[10005],vis[10005],ans=2147483647,d[10005];
void aaa(long long dep,long long k,long long cnt)
{
    long long x=1;
    if(cnt>=n)
    {

        //cout<<"a";
        int flag=1,mark=1;
        for(int i=1;i<=n;i++)
        {
            if(d[i]<a[i])
                flag=0;

            if(c[i]<0&&max(b[i]+dep*c[i],x)<a[i])mark=0;
        }
        if(flag==1)
        {
            ans=min(ans,dep-1);
            return;
        }
        else if(flag==0)
        {
            for(int i=1;i<=n;i++)
            d[i]+=max(b[i]+dep*c[i],x);
            aaa(dep+1,k,cnt);
            for(int i=1;i<=n;i++)
            d[i]-=max(b[i]+dep*c[i],x);
        }
    }
    else
    {
        int flag=0;
        for(long long i=1;i<=n;i++)
        {
            if(p[k][i]==1&&vis[i]==0)
            {
                //cout<<i<<dep<<"b";
                vis[i]=1;
                d[i]+=max(b[i]+dep*c[i],x);
                aaa(dep+1,i,cnt+1);
                d[i]-=max(b[i]+dep*c[i],x);
                vis[i]=0;
                flag=1;
            }
        }
        if(flag==0)
        {
            for(int i=1;i<=n;i++)
            {
                if(i!=k);
                {
                    for(int j=1;j<=n;j++)
                    {
                        if(p[i][j]!=0&&vis[j]==0&&vis[i]==1)
                        {
                            //cout<<j<<dep<<"c";
                            vis[j]=1;
                            d[j]+=max(b[j]+dep*c[j],x);
                            aaa(dep+1,j,cnt+1);
                            d[j]-=max(b[j]+dep*c[j],x);
                            vis[j]=0;
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    freopen("tree1.in","r",stdin);
    //freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        d[i]=b[i];
    }
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        p[x][y]=1;
        p[y][x]=1;
    }
    vis[1]=1;
    aaa(1,1,1);
    cout << ans<< endl;
    return 0;
}
#include <iostream>

using namespace std;
int n,a,b,c,d,e;
int ans[11][11][11][11][11];
int main()
{
    freopen("lock2.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    int k=0;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>c>>d>>e;

        for(int j=1;j<=9;j++)
        {
            int a1=a,b1=b,c1=c,d1=d,e1=e;
            if(j>a)a1=a+10;
            //else a1=a;
            if(j>b)b1=b+10;
            //else b1=b;
            if(j>c)c1=c+10;
            //else c1=c;
            if(j>d)d1=d+10;
            //else d1=a;
            if(j>e)e1=e+10;
            //else e1=e;
            ans[a1-j][b][c][d][e]++;
            ans[a][b1-j][c][d][e]++;
            ans[a][b][c1-j][d][e]++;
            ans[a][b][c][d1-j][e]++;
            ans[a][b][c][d][e1-j]++;
            ans[a1-j][b1-j][c][d][e]++;
            ans[a][b1-j][c1-j][d][e]++;
            ans[a][b][c1-j][d1-j][e]++;
            ans[a][b][c][d1-j][e1-j]++;
        }

    }
    int cnt=0;
    for(int a2=0;a2<10;a2++)
        for(int b2=0;b2<10;b2++)
            for(int c2=0;c2<10;c2++)
                for(int d2=0;d2<10;d2++)
                    for(int e2=0;e2<10;e2++)
                    {
                        if(ans[a2][b2][c2][d2][e2]==n)
                        {
                            cnt++;
                        }
                    }
    cout << cnt<< endl;
    return 0;
}

#include <iostream>

using namespace std;
int n;
string s1,s2,s3;
int ans=0,flag;
void aaa(int dep,int cnt)
{
    if(cnt==0&&flag!=0)
    {
        ans=1;
        //cout<<flag<<"     ";
        return;
    }
    else
    {
        for(int i=0;i<cnt-1;i++)
        {
            if(s2[i]==s2[i+1])
            {

                for(int j=i;j<=cnt-3;j++)
                    s2[j]=s2[j+2];
                flag++;
                aaa(dep+1,cnt-2);
                //s2=s3;
                break;
            }
        }
        if(flag==0)
        {
            ans=0;
            return;
        }
    }
}
int main()
{
    freopen("game1.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s1;
    int c=0;
    for(int i=0;i<=n-1;i++)
    {
        for(int j=i;j<=n-1;j++)
        {
            int tem=0;
            for(int k=i;k<=j;k++)
            {
                s2[k-i]=s1[k];
            }
            s3=s2;
            ans=0;
            flag=0;
            if((j-i+1)%2==0)
            {
                //cout<<i<<","<<j<<",";
                //cout<<j-i<<" ";
                aaa(0,j-i+1);
            if(ans==1)c++;

            }

        }
    }
    cout << c<< endl;
    return 0;
}
*/
#include <iostream>

using namespace std;
int n;
string s1,s2,s3;
int ans=0,flag;
void aaa(int dep,int cnt)
{
    if(cnt==0&&flag!=0)
    {
        ans=1;
        //cout<<flag<<"     ";
        return;
    }
    else
    {
        for(int i=0;i<cnt-1;i++)
        {
            if(s2[i]==s2[i+1])
            {

                for(int j=i;j<=cnt-3;j++)
                    s2[j]=s2[j+2];
                flag++;
                aaa(dep+1,cnt-2);
                //s2=s3;
                break;
            }
        }
        if(flag==0)
        {
            ans=0;
            return;
        }
    }
}
int main()
{
    char q[1000][1000];
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n,x=0,sum=0;
    cin>>n;
    int op;
    for(int i=0;i<n;i++)
    {
        cin>>op;
        if(op==1)x++;
        else if(op==2)
        {
            string s1,s2;
            cin>>s1>>s2;
            cout<<sum;
            if(s1[0]=='s')
            {
                sum+=2;
                q[i][0]=sum;
                for(int j=1;j<=sizeof(s1);j++)
                {
                    q[i][j]=s1[j-1];
                }
            }
                
            else if(s1[0]=='l')
                {
                sum+=8;
                q[i][0]=sum;
                for(int j=1;j<=sizeof(s1);j++)
                {
                    q[i][j]=s1[j-1];
                }
            }
            else if(s1[0]=='i')
            {
                sum+=4;
                q[i][0]=sum;
                for(int j=1;j<=sizeof(s1);j++)
                {
                    q[i][j]=s1[j-1];
                }
            }
            else 
            {
                sum+=1;
                q[i][0]=sum;
                for(int j=1;j<=sizeof(s1);j++)
                {
                    q[i][j]=s1[j-1];
                }
            }
        }
        else if(op==3)
        {
            string s2;
            cin>>s2;
            for(int j=0;j<n;j++)
            {
                int f=0;
                for(int k=1;k<n;k++)
                {
                    if(q[j][k]==s2[k-1])cout<<q[j][0];
                }
                
            }
        }
        else if(op==4)
        {
            int a;
            cin>>a;
            for(j=0;j<n;j++)
            {
                if(q[j][0]==a)
                {
                    for(int k=1;k<2;k++)
                    {
                        cout<<q[j][k]<<endl;
                    }
                }
            }
        }
    }
    cout << c<< endl;
    return 0;
}
