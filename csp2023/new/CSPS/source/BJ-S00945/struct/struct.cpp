#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
    int n=0,f=1,ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        n=n*10+ch-'0';
        ch=getchar();
    }
    return n*f;
}
map<string,int>ma;
int cd[105],ys[105],kj[105],cnt;
map<string,int>xb[105];
vector<int>lx[105],qs[105];
vector<string>mc[105];
int tmp;
int ks[105],bx[105],tsl;
string bm[105];
map<string,int>bl;
string fz[105];
int m;
string ans;
bool solve(int nlx,int wz)
{
    if(nlx<=4)
    {
        if(wz>=0&&wz<cd[nlx])return true;
        return false;
    }
    if(wz>=kj[nlx])
    {
        return false;
    }
    int pos=ys[nlx]-1;
    for(int i=0;i<ys[nlx]-1;i++)
    {
        if(wz<qs[nlx][i+1])
        {
            pos=i;
            break;
        }
    }
    ans=ans+"."+mc[nlx][pos];
    return solve(lx[nlx][pos],wz-qs[nlx][pos]);
}
signed main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ma["byte"]=1;
    cd[1]=1;
    kj[1]=1;
    ys[1]=1;
    ma["short"]=2;
    cd[2]=2;
    kj[2]=2;
    ys[2]=1;
    ma["int"]=3;
    cd[3]=4;
    kj[3]=4;
    ys[3]=1;
    ma["long"]=4;
    cd[4]=8;
    kj[4]=8;
    ys[4]=1;
    cnt=4;
    int n;
    n=read();
    for(int i=1;i<=n;i++)
    {
        int op;
        op=read();
        if(op==1)
        {
            string s;
            cin>>s;
            ++cnt;
            ma[s]=cnt;
            ys[cnt]=read();
            for(int j=0;j<ys[cnt];j++)
            {
                cin>>s;
                int nlx=ma[s];
                //printf("???%d\n",nlx);
                lx[cnt].push_back(nlx);
                if(j==0)qs[cnt].push_back(0);
                else
                {
                    int las=qs[cnt][j-1]+kj[lx[cnt][j-1]];
                    //printf("orz%d\n",las);
                    qs[cnt].push_back((las+cd[nlx]-1)/cd[nlx]*cd[nlx]);
                }
                cin>>s;
                mc[cnt].push_back(s);
                cd[cnt]=max(cd[cnt],cd[nlx]);
                xb[cnt][s]=j;
            }
            int las=qs[cnt][ys[cnt]-1]+kj[lx[cnt][ys[cnt]-1]];
            //printf("%d\n",las);
            kj[cnt]=(las+cd[cnt]-1)/cd[cnt]*cd[cnt];
            printf("%lld %lld\n",kj[cnt],cd[cnt]);
        }
        else if(op==2)
        {
            string s;
            cin>>s;
            ++tsl;
            bx[tsl]=ma[s];
            tmp=(tmp+cd[bx[tsl]]-1)/cd[bx[tsl]]*cd[bx[tsl]];
            printf("%lld\n",tmp);
            ks[tsl]=tmp;
            cin>>s;
            bm[tsl]=s;
            bl[s]=tsl;
            tmp+=kj[bx[tsl]];
        }
        else if(op==3)
        {
            string s;
            cin>>s;
            int pre=0;
            m=0;
            for(int j=0;j<s.length();j++)
            {
                if(s[j]=='.')
                {
                    ++m;
                    fz[m].resize(j-pre);
                    for(int k=pre;k<j;k++)fz[m][k-pre]=s[k];
                    pre=j+1;
                }
            }
            ++m;
            fz[m].resize(s.length()-pre);
            for(int k=pre;k<s.length();k++)fz[m][k-pre]=s[k];
            int nans=0;
            int xb1=bl[fz[1]];
            nans=ks[xb1];
            int nlx=bx[xb1];
            for(int j=2;j<=m;j++)
            {
                int pos=xb[nlx][fz[j]];
                nans+=qs[nlx][pos];
                nlx=lx[nlx][pos];
            }
            printf("%lld\n",nans);
        }
        else
        {
            ans.resize(0);
            int x;
            x=read();
            int dy=tsl;
            for(int j=1;j<tsl;j++)
            {
                if(x<ks[j+1])
                {
                    dy=j;
                    break;
                }
            }
            ans=bm[dy];
            if(solve(bx[dy],x-ks[dy])==false)printf("ERR\n");
            else cout<<ans<<endl;
        }
    }
}