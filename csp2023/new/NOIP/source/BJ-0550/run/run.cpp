#include <bits/stdc++.h>
using namespace std;
int c,_t;
int n,m,k,d,ans;
struct node{
    int l,r;
    int w;
    int num;
    bool operator < (const node &aaa) const
    {
        return r>aaa.r;
    }
}tz[600004],t;
struct node2{
    int r;
    int ans1;
    bool operator < (const node2 &qq) const{

        return r>qq.r;
    }
}t4;
priority_queue <node> q;
priority_queue <node2> q2;
int ansl[600003],ansr[600003];
int cmp(node x,node y)
{
    return x.l<y.l;
}
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%d%d",&c,&_t);
    //printf("%d %d\n",c,_t);
    while(_t--)
    {
        ans=0;
        memset(ansl,0,sizeof(ansl));
        memset(ansr,0,sizeof(ansr));
        scanf("%d%d%d%d",&n,&m,&k,&d);
        for(int i=1;i<=m;i++)
        {
            int t1,t2;
            scanf("%d%d%d",&t1,&t2,&tz[i].w);
           // printf("%d %d %d\n",t1,t2,tz[i].w);
            tz[i].r=t1;
            tz[i].l=t1-t2+1;
            tz[i].num=i;
        }
        sort(tz+1,tz+m+1,cmp);
       // for(int i=1;i<=m;i++)
            //printf("%d %d %d\n",tz[i].l,tz[i].r,tz[i].w);
        for(int i=1;i<=m;i++)
        {
            while(q2.size()&&q2.top().r<tz[i].l)
            {
                ans=max(ans,q2.top().ans1);
                q2.pop();
            }
            int temp=ans,tl=tz[i].l;
            for(int j=i;tz[j].l<=tz[i].r&&j<=m;j++)
            {
                if(tz[j].r-tz[i].l>=k) continue;
                q.push(tz[j]);
                //printf("i=%d j=%d %d %d ",i,j,tz[j].r,tz[i].l);
            }
            while(!q.empty()){
                t=q.top();
                q.pop();
                ansr[t.num]=max(ansr[t.num],temp+t.w-(t.r-tl+1)*d);
                //printf("%d %d %d %d %d %d    %d\n",ansr[t.num],temp,t.w,t.r,tl,d,temp+t.w-(t.r-tl+1)*d);
                temp+=t.w;
                tl=t.r;
            }
            t4.ans1=ansr[i];
            t4.r=tz[i].r;
            q2.push(t4);

        }
        while(q2.size())
            {
                ans=max(ans,q2.top().ans1);
                q2.pop();
            }
        //for(int i=1;i<=m;i++)
            //printf("%d ",ansr[i]);
        printf("%d\n",ans);
    }
    return 0;
}
