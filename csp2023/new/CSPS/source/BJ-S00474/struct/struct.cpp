# include <bits/stdc++.h>
# define N 105
using namespace std;
struct INT
{
    int num[300],len;
    INT()
    {
        memset(num,0,sizeof num);
        len=1;
    }
    INT operator +(const INT x)const
    {
        INT ans;
        int in=0;
        ans.len=max(len,x.len);
        for(int i=1;i<=max(len,x.len);i++)
        {
            ans.num[i]=num[i]+x.num[i]+in;
            in=ans.num[i]/10;
            ans.num[i]%=10;
        }
        if(in)
            ans.num[++ans.len]=1;
        return ans;
    }
    INT add(int x)
    {
        INT ans=(*this);
        ans.num[1]+=x;
        int pos=1;
        while(ans.num[pos]>=10)
        {
            ans.num[pos+1]++;
            ans.num[pos]-=10;
            pos++;
        }
        ans.len=max(len,pos);
        return ans;
    }
    INT doit(int x)
    {
        int now=num[1]+num[2]*10+num[3]*100,res=0;
        while(now%x!=0)
        {
            now++;
            res++;
        }
        return add(res);
    }
};
unordered_map<string,int> id;
int tot,cnt;
INT sze[N];
long long Sze[N];
string name[N];
vector<tuple<int,string,INT>> member[N];
int num[N];
INT nowpos;
long long Nowpos;
string Name[N];
int type[N];
long long pos[N];
const long long lim=1000000000000000001ll;
long long doit(long long num,int x)
{
    if(num==lim)
        return num;
    while(num%x!=0)
        num++;
    return num;
}
INT get(int id,string s)
{
    string p="";
    int pos=0;
    while(pos<s.size() && s[pos]!='.')
        p=p+s[pos],pos++;
    INT ans;
    for(auto &[ID,NAME,NOW]:member[id])
        if(NAME==p)
        {
            if(ID<=4 || pos==s.size())
                return NOW;
            else
                return NOW+get(ID,s.substr(pos+1));
        }
    return ans;
}
string get2(int id,long long pos)
{
    string ans="ERR";
    long long nowSze=0;
    for(auto &[ID,NAME,NOW]:member[id])
    {
        long long newSze=doit(nowSze,num[ID]);
        if(pos<newSze-nowSze)
            return "ERR";
        pos-=newSze-nowSze;
        nowSze=newSze;
        if(Sze[ID]>pos)
        {
            if(ID<=4)
                return NAME;
            ans=NAME;
            auto res=get2(ID,pos);
            if(res=="ERR")
                return res;
            return ans+'.'+res;
        }
        pos-=Sze[ID];
        nowSze+=Sze[ID];
    }
    return ans;
}
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    tot=4;
    sze[1].num[1]=Sze[1]=1;
    sze[2].num[1]=Sze[2]=2;
    sze[3].num[1]=Sze[3]=4;
    sze[4].num[1]=Sze[4]=8;
    name[1]="byte";
    name[2]="short";
    name[3]="int";
    name[4]="long";
    num[1]=1;
    num[2]=2;
    num[3]=4;
    num[4]=8;
    for(int i=1;i<=4;i++)
        id[name[i]]=i;
    int T;
    cin>>T;
    while(T--)
    {
        int op;
        scanf("%d",&op);
        if(op==1)
        {
            tot++;
            cin>>name[tot];
            id[name[tot]]=tot;
            int k;
            cin>>k;
            string a,b;
            while(k--)
            {
                cin>>a>>b;
                int now=id[a];
                sze[tot]=sze[tot].doit(num[now]);
                member[tot].push_back({now,b,sze[tot]});
                sze[tot]=sze[tot]+sze[now];
                Sze[tot]=min(doit(Sze[tot],num[now])+Sze[now],lim);
                num[tot]=max(num[tot],num[now]);
            }
            sze[tot]=sze[tot].doit(num[tot]);
            Sze[tot]=min(lim,doit(Sze[tot],num[tot]));
            for(int i=sze[tot].len;i>=1;i--)
                printf("%d",sze[tot].num[i]);
            printf(" %d\n",num[tot]);
        }
        else if(op==2)
        {
            string a,b;
            cin>>a>>b;
            int now=id[a];
            cnt++;
            Name[cnt]=b;
            type[cnt]=now;
            pos[cnt]=doit(Nowpos,num[now]);
            Nowpos=min(pos[cnt]+Sze[now],lim);
            nowpos=nowpos.doit(num[now]);
            for(int i=nowpos.len;i>=1;i--)
                printf("%d",nowpos.num[i]);
            printf("\n");
            nowpos=nowpos+sze[now];
        }
        else if(op==3)
        {
            string s,p;
            cin>>s;
            int pos=0;
            while(pos<s.size() && s[pos]!='.')
                p=p+s[pos],pos++;
            INT ans;
            for(int i=1;i<=cnt;i++)
                if(Name[i]!=p)
                    ans=ans.doit(num[type[i]])+sze[type[i]];
                else
                {
                    if(type[i]>4 && pos!=s.size())
                        ans=ans.doit(num[type[i]])+get(type[i],s.substr(pos+1));
                    break;
                }
            for(int i=ans.len;i>=1;i--)
                printf("%d",ans.num[i]);
            printf("\n");
        }
        else
        {
            long long pos;
            cin>>pos;
            string ans="ERR";
            long long nowSze=0;
            for(int i=1;i<=cnt;i++)
            {
                auto ID=type[i];
                auto NAME=Name[i];
                long long newSze=doit(nowSze,num[ID]);
                if(pos<newSze-nowSze)
                    break;
                pos-=newSze-nowSze;
                nowSze=newSze;
                if(Sze[ID]>pos)
                {
                    if(ID<=4)
                    {
                        ans=NAME;
                        break;
                    }
                    ans=NAME;
                    auto res=get2(ID,pos);
                    if(res=="ERR")
                    {
                        ans="ERR";
                        break;
                    }
                    ans=ans+'.'+res;
                    break;
                }
                pos-=Sze[ID];
                nowSze+=Sze[ID];
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}