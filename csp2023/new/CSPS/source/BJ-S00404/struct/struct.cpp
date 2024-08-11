#include<iostream>
#include<map>
#include<string>
using namespace std;
const int maxn=105;
typedef long long ll;
typedef map<string,pair<ll,int> > msp;
struct type
{
    ll siz,maxsiz;
    msp son;
    type(ll siz_)
    {
        maxsiz=siz=siz_;
    }
    type()
    {
        siz=0;
    }
}atype[maxn+10];
struct object
{
    ll st;
    string name;
    int typenum;
}aobj[maxn];
string init[10]={"","byte","short","int","long"};
map<string,int> mpobj;
map<string,int> mptype;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(int v1=1,siz=1;v1<=4;v1++,siz<<=1)
    {
        atype[v1]=type(siz);
        mptype[init[v1]]=v1;
    }
    int typecnt=4,objcnt=0;
    int in;
    cin>>in;
    while(in--)
    {
        int iop;
        cin>>iop;
        //cout<<iop<<'-'<<endl;
        if(iop==1)
        {
            int ik;
            ll cnt=0;
            string name;
            cin>>name>>ik;
            mptype[name]=++typecnt;
            ll maxsiz=0;
            for(int v1=1;v1<=ik;v1++)
            {
                string curtype,curname;
                cin>>curtype>>curname;
                //cout<<curtype<<' '<<curname<<endl;
                ll curson=mptype[curtype],siz=atype[curson].maxsiz;
                if(cnt%siz!=0)cnt+=siz-cnt%siz;
                atype[typecnt].son[curname]=make_pair(cnt,curson);
                maxsiz=max(maxsiz,siz);
                cnt+=atype[curson].siz;
            }
            if(cnt%maxsiz!=0)cnt+=maxsiz-cnt%maxsiz;
            atype[typecnt].siz=cnt;
            atype[typecnt].maxsiz=maxsiz;
            printf("%lld %lld\n",cnt,maxsiz);
        }
        else if(iop==2)
        {
            string typen,name;
            cin>>typen>>name;
            ll tmp=aobj[objcnt].st+atype[aobj[objcnt].typenum].siz;
            int typepos=mptype[typen];
            aobj[++objcnt].typenum=typepos;
            if(tmp%atype[typepos].maxsiz!=0)tmp+=atype[typepos].maxsiz-tmp%atype[typepos].maxsiz;
            aobj[objcnt].st=tmp;
            aobj[objcnt].name=name;
            mpobj[name]=objcnt;
            printf("%lld\n",tmp);
        }
        else if(iop==3)
        {
            string path,curname="";
            ll curpos=-1,curtype;
            cin>>path;
            path+=".";
            for(int v1=0;v1<path.size();v1++)
            {
                if(path[v1]=='.')
                {
                    if(curpos==-1)
                    {
                        curpos=aobj[mpobj[curname]].st;
                        curtype=aobj[mpobj[curname]].typenum;
                    }
                    else
                    {
                        curpos+=atype[curtype].son[curname].first;
                        curtype=atype[curtype].son[curname].second;
                    }
                    curname="";
                }
                else curname+=path[v1];
            }
            printf("%lld\n",curpos);
        }
        else
        {
            ll addr;
            cin>>addr;
            //cout<<objcnt<<endl;
            string ans="";
            ll curtype;
            //for(int v1=objcnt;v1&&v1>=1;v1--)cout<<aobj[v1].st<<' ';
            //cout<<endl;
            if(objcnt==0)
            {
                printf("ERR\n");
                continue;
            }
            for(int v1=objcnt;v1>=1;v1--)if(addr>=aobj[v1].st)
            {
                curtype=aobj[v1].typenum;
                addr-=aobj[v1].st;
                ans=aobj[v1].name;
                break;
            }
            //cout<<addr<<' '<<aobj[objcnt].st<<' ';
            //cout<<curtype<<' ';
            while(curtype>4)
            {
                bool flag=false;
                //cout<<curtype<<' '<<addr<<' '<<ans<<endl;
                for(msp::iterator it=atype[curtype].son.begin();it!=atype[curtype].son.end();it++)
                {
                    if(addr>=it->second.first&&addr<(it->second.first+atype[it->second.second].siz))
                    {
                        flag=true;
                        addr-=it->second.first;
                        ans+="."+it->first;
                        curtype=it->second.second;
                        break;
                    }
                }
                if(!flag)
                {
                    curtype=10;
                    break;
                }
            }
            //cout<<curtype<<endl;
            if(curtype<=4)printf("%s\n",ans.c_str());
            else printf("ERR\n");
        }
    }
    return 0;
}
