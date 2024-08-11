#include <iostream>
#include <cmath>
#include <map>
using namespace std;
#define int long long
map<string,int> tsz;
map<string,int> tdq;
map<string,int> whe;//for adds
map<string,int> whe2[110];//for tys;
map<string,int> whe3;//for local
int sizes[110];//for tys
struct adds
{
    int has;
    string nam,ty[110],na[110];
    int dq;
}tys[110];
int op,cnt,ans;
string t1,t2;
int q;
int cnt2,dq2;
string now[110],nty[110];
string ans114;
int solve(string typ,int nowy)
{
    if(typ=="")
        return 0;
    t2="";
    int nowt=0;
    for(int i=0;i<typ.size();i++)
    {
        nowt=i;
        if(typ[i]=='.')
            break;
        t2=t2+typ[i];
    }
    nowt++;
    int whet=whe2[nowy][t2];
    int ansn=tys[nowy].dq*(whet-1);
    t2="";
    for(;nowt<typ.size();nowt++)
        t2=t2+typ[nowt];
    ansn+=solve(t2,whe[tys[nowy].ty[whet]]);
    return ansn;
}
void solve514(int num,int nowy)
{
    if(num>=sizes[nowy])
    {
        ans114="ERR\n";
        return;
    }
    int whe514=num/tys[nowy].dq+1;
    if(whe514>sizes[nowy]/tys[nowy].dq)
    {
        ans114="ERR\n";
        return;
    }
    int tadd=num%tys[nowy].dq;
    string tmp514=tys[nowy].ty[whe514],nam514=tys[nowy].na[whe514];
    if(tmp514=="byte"||tmp514=="short"||tmp514=="int"||tmp514=="long")
    {
        int siz514=tsz[tmp514];
        if(tadd>=siz514)
        {
            ans114="ERR\n";
            return;
        }
        else
        {
            ans114=ans114+'.';
            ans114=ans114+nam514;
            ans114=ans114+'\n';
            return;
        }
    }
    ans114=ans114+'.';
    ans114=ans114+nam514;
    solve514(tadd,whe[tmp514]);
}
signed main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>q;
    tsz["byte"]=1;
    tsz["short"]=2;
    tsz["int"]=4;
    tsz["long"]=8;
    tdq["byte"]=1;
    tdq["short"]=2;
    tdq["int"]=4;
    tdq["long"]=8;
    while(q--)
    {
        cin>>op;
        if(op==1)
        {
            cin>>tys[++cnt].nam;
            cin>>tys[cnt].has;
            tys[cnt].dq=0;
            for(int i=1;i<=tys[cnt].has;i++)
            {
                cin>>t1>>t2;
                tys[cnt].ty[i]=t1;
                tys[cnt].na[i]=t2;
                tys[cnt].dq=max(tys[cnt].dq,tdq[tys[cnt].ty[i]]);
                whe2[cnt][tys[cnt].na[i]]=i;
            }
            for(int i=1;i<=tys[cnt].has;i++)
            {
               tsz[tys[cnt].nam]+=max(tys[cnt].dq,tsz[tys[cnt].ty[i]]); 
            }
            cout<<tsz[tys[cnt].nam]<<" "<<tys[cnt].dq<<endl;
            tdq[tys[cnt].nam]=tys[cnt].dq;
            whe[tys[cnt].nam]=cnt;
            sizes[cnt]=tsz[tys[cnt].nam];
        }
        else if(op==2)
        {
            cnt2++;
            cin>>nty[cnt2]>>now[cnt2];
            dq2=max(dq2,tsz[nty[cnt2]]);
            whe3[now[cnt2]]=cnt2;
            cout<<dq2*(cnt2-1)<<endl;
        }
        else if(op==3)
        {
            cin>>t1;
            t2="";
            int nowt=0;
            for(int i=0;i<t1.size();i++)
            {
                nowt=i;
                if(t1[i]=='.')
                    break;
                t2=t2+t1[i];
            }
            nowt++;
            int now114=whe3[t2];
            ans=(now114-1)*dq2;
            t2="";
            for(;nowt<t1.size();nowt++)
                t2=t2+t1[nowt];
            ans+=solve(t2,whe[nty[now114]]);
            cout<<ans<<endl;
        }
        else
        {
            int addt;
            cin>>addt;
            int whe114=addt/dq2+1;
            int add114=addt%dq2;
            if(whe114>cnt2)
            {
                cout<<"ERR\n";
                continue;
            }
            if(nty[whe114]=="byte"||nty[whe114]=="short"||nty[whe114]=="int"||nty[whe114]=="long")
            {
                int size810=tsz[nty[whe114]];
                if(size810<=add114)
                {
                    cout<<"ERR\n";
                    continue;
                }
                else
                {
                    cout<<now[whe114]<<endl;
                    continue;
                }
            }
            ans114=now[whe114];
            solve514(add114,whe[nty[whe114]]);
            cout<<ans114;
        }
    }
    return 0;
}// gan  ti yi li jie cuo le