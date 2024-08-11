#include<iostream>
using namespace std;
int n,f[200002];
struct nd
{
    int tp,xi;
    nd operator-()const
    {
        nd ret;
        ret.tp=-tp;
        if(!tp)
            ret.xi=-xi;
        else
            ret.xi=xi;
        return ret;
    }
}stc[100002];
int fd(int x)
{
    if(x==f[x]) return x;
    f[x]=fd(f[x]);
    return f[x];
}
int mat(int x)
{
    if(x<=n)    return x+n;
    return x-n;
}
void merg(int x,int y)
{
    if(fd(x)!=fd(y))
        f[fd(x)]=fd(y);
}
bool v[200002];
int cnt[200002];
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(0);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            stc[i].tp=1;
            stc[i].xi=i;
        }
        for(int i=1;i<=m;i++)
        {
            char ch;
            int x,y;
            cin>>ch;
            cin>>x;
            if(ch=='+'||ch=='-')
                cin>>y;
            switch(ch)
            {
                case 'T':stc[x].tp=0;stc[x].xi=1;break;
                case 'F':stc[x].tp=0;stc[x].xi=-1;break;
                case 'U':stc[x].tp=0;stc[x].xi=0;break;
                case '+':stc[x]=stc[y];break;
                case '-':stc[x]=-stc[y];break;
                default:break;
            }
        }
        for(int i=1;i<=2*n;i++)
            f[i]=i;
        for(int i=1;i<=n;i++)
        {
            //cout<<i<<' '<<stc[i].xi<<endl;
            if(stc[i].tp==1)
            {
                merg(i,stc[i].xi);
                merg(mat(i),mat(stc[i].xi));
            }
            if(stc[i].tp==-1)
            {
                merg(i,mat(stc[i].xi));
                merg(mat(i),stc[i].xi);
            }
        }
        for(int i=1;i<=2*n;i++)
            v[i]=1,cnt[i]=0;
        for(int i=1;i<=n;i++)
        {
            if(fd(i)==fd(mat(i)))
                v[fd(i)]=0;
            else if(stc[i].tp==0)
                v[fd(i)]=v[fd(mat(i))]=(stc[i].xi!=0);
        }
        for(int i=1;i<=2*n;i++)
            cnt[fd(i)]++;
        int ans=0;
        for(int i=1;i<=2*n;i++)
        {
            //cout<<cnt[i]<<' ';
            if(i==f[i] && !v[i])
                ans+=cnt[i];
        }
        //cout<<endl;
        cout<<ans/2<<endl;
    }
    return 0;
}