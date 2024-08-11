
#include<map>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
struct typ{
    string name;
    int sz,num,scale;
    int elmt[105];
    long long pos[105];
    string elm[105];
}a[108];
string tyn;
map<string,int> mp,ma;
int T,op,n,k,cnt=4,macnt;
int elmt[105];
string elm[105],ans;
char s[2005];
long long now,sta[105],ty,tp,id,tx,tz;
int flo(int x,int y)
{
    return (x%y==0)?x:(((x+y)/y)*y);
}
signed main()
{
    freopen("struct.in" ,"r",stdin );
    freopen("struct.out","w",stdout);
    a[1].sz=1,a[1].num=1,a[1].scale=1,mp["byte"]=1;
    a[2].sz=2,a[2].num=1,a[2].scale=2,mp["short"]=2;
    a[3].sz=4,a[3].num=1,a[3].scale=4,mp["int"]=3;
    a[4].sz=8,a[4].num=1,a[4].scale=8,mp["long"]=4;
    
    cin>>T;
    while(T--)
    {
        cin>>op;
        if(op==1)
        {
            cnt++;
            cin>>tyn>>k;
            a[cnt].name=tyn;
            mp[tyn]=cnt,a[cnt].num=k;
            for(int i=1;i<=k;i++)
            {
                cin>>tyn>>a[cnt].elm[i];
                a[cnt].elmt[i]=mp[tyn];
                a[cnt].pos[i]=flo(a[cnt].pos[i-1]+a[a[cnt].elmt[i-1]].sz,a[a[cnt].elmt[i]].scale);
                // cout<<a[cnt].pos[i]<<endl;
                a[cnt].scale=max(a[cnt].scale,a[a[cnt].elmt[i]].scale);
            }
            a[cnt].sz=flo(a[cnt].pos[k]+a[a[cnt].elmt[k]].sz,a[cnt].scale);
            cout<<a[cnt].sz<<" "<<a[cnt].scale<<endl;
            continue;
        }
        if(op==2)
        {
            macnt++;
            cin>>tyn>>elm[macnt];
            elmt[macnt]=mp[tyn];
            now=flo(now,a[elmt[macnt]].scale);
            cout<<now<<endl;
            sta[macnt]=now;
            now+=a[elmt[macnt]].sz;
            continue;
        }
        if(op==3)
        {
            cin>>(s+1);
            id=tp=0;
            for(int i=1;s[i];i++)
            {
                tyn="";
                while(s[i]&&s[i]!='.')
                {
                    tyn+=s[i];
                    s[i]=0;
                    i++;
                }
                s[i]=0;
                //cout<<tyn<<endl;
                if(id==0)
                {
                    for(int i=1;i<=macnt;i++)
                    {
                        if(elm[i]==tyn)
                        {
                            id=elmt[i];
                            break;
                        }
                        tp+=a[elmt[i]].sz;
                    }
                //cout<<id<<endl;
                    continue;
                }
                for(int i=1;i<=a[id].num;i++)
                {
                    //cout<<a[id].elm[i]<<endl;
                    if(a[id].elm[i]==tyn)
                    {
                        tp+=a[id].pos[i];
                        id=a[id].elmt[i];
                        break;
                    }
                }
                //cout<<id<<endl;
            }
            cout<<tp<<endl;
            continue;
        }
        if(op==4)
        {
            ans="";
            cin>>ty;
            for(int i=1;i<=macnt;i++)
            {
                if(sta[i]<=ty&&sta[i]+a[elmt[i]].sz>ty)
                {
                    ty-=sta[i],tx=i;
                    goto nxt;
                }
            }
            cout<<"ERR\n";
            continue;
            nxt:;
            ans+=elm[tx];
            //cout<<elm[tx];
            tz=sta[tx];
            tx=elmt[tx];
            while(tz!=ty)
            {
                if(tx<5)
                    break;
                for(int i=1;i<=a[tx].num;i++)
                {
                    if(tz+a[tx].pos[i]<=ty&&tz+a[tx].pos[i]+a[a[tx].elmt[i]].sz>ty)
                    {
                        ans+='.';
                        ans+=a[tx].elm[i];
                        //cout<<"."<<a[tx].elm[i];
                        tz+=a[tx].pos[i],tx=a[tx].elmt[i];
                        goto Nt;
                    }
                }
                ans="ERR";
                break;
                Nt:;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}