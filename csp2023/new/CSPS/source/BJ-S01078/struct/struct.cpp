#include <bits/stdc++.h>
using namespace std;

const int NR=110;
map <string,int> mp;
struct node{
    string na;
    string name[110];
    int kind[110],k;
    long long pos[NR];
    long long sz,o;
    map <string,int> mp;
}a[NR];

struct Node{
    string name;
    int kind;
    int pos;
}b[NR];
map <string,int> qwq;

int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    scanf("%d",&n);
    int cnt=0,cnt1=0;
    a[++cnt].na="byte";
    a[++cnt].na="short";
    a[++cnt].na="int";
    a[++cnt].na="long";
    mp["byte"]=1;
    mp["short"]=2;
    mp["int"]=3;
    mp["long"]=4;
    a[1].sz=1,a[1].o=1;
    a[2].sz=2,a[2].o=2;
    a[3].sz=4,a[3].o=4;
    a[4].sz=8,a[4].o=8;
    while(n--)
    {
        int opt;
        scanf("%d",&opt);
        if(opt==1)
        {
            cnt++;
            cin>>a[cnt].na;
            mp[a[cnt].na]=cnt;
            scanf("%d",&a[cnt].k);
            for(int i=1;i<=a[cnt].k;i++)
            {
                string tmp;
                cin>>tmp;
                a[cnt].kind[i]=mp[tmp];
                cin>>a[cnt].name[i];
                a[cnt].mp[a[cnt].name[i]]=i;
                a[cnt].o=max(a[cnt].o,a[a[cnt].kind[i]].o);
            }
            for(int i=2;i<=a[cnt].k;i++)
            {
                a[cnt].pos[i]=a[cnt].pos[i-1]+a[a[cnt].kind[i-1]].sz;
                long long num=(a[cnt].pos[i]-1)/(a[a[cnt].kind[i]].o)+1;
                a[cnt].pos[i]=1ll*num*(a[a[cnt].kind[i]].o);
                //printf("===%d \n",a[cnt].pos[i]);
            }
            long long num=a[cnt].pos[a[cnt].k]+a[a[cnt].kind[a[cnt].k]].sz;
            long long now=(num-1)/a[cnt].o+1;
            num=now*a[cnt].o;
            a[cnt].sz=num;
            printf("%lld %lld\n",a[cnt].sz,a[cnt].o);
        }
        if(opt==2)
        {
            cnt1++;
            string tmp;
            cin>>tmp;
            b[cnt1].kind=mp[tmp];
            cin>>b[cnt1].name;
            qwq[b[cnt1].name]=cnt1;
            if(cnt1==1) b[cnt1].pos=0;
            else
            {
                b[cnt1].pos=b[cnt1-1].pos+a[b[cnt1-1].kind].sz;
                long long num=(b[cnt1].pos-1)/(a[b[cnt1].kind].o)+1;
                b[cnt1].pos=1ll*num*(a[b[cnt1].kind].o);
            }
            printf("%lld\n",b[cnt1].pos);
        }
        if(opt==3)
        {
            string tmp;
            cin>>tmp;
            long long len=tmp.length();
            string now="";
            long long num=0,pos,pre;
            tmp=tmp+".";
            for(int i=0;i<=len;i++)
            {
                if(tmp[i]!='.') now=now+tmp[i];
                else{
                    if(num==0)
                    {
                        num++;
                        pos=b[qwq[now]].pos;
                        pre=b[qwq[now]].kind;
                    }
                    else
                    {
                        num++;
                        pos=pos+a[pre].pos[a[pre].mp[now]];
                        pre=a[pre].kind[a[pre].mp[now]];
                    }
                    now="";
                }
            }
            printf("%lld\n",pos);
        }
        if(opt==4)
        {
            string ans="";
            long long add;
            scanf("%d",&add);
            long long pos=0,pre;
            string tmpp;
            for(int i=1;i<=cnt1;i++)
            {
                if(b[i].pos<=add) pre=b[i].kind,tmpp=b[i].name;
            }
            pos=b[pre].pos;
            ans=ans+tmpp;
            if(pre<=4)
                {
                    if(pos+a[pre].sz>=add)
                    cout<<ans;
                    else printf("ERR\n");
                    continue;
                }
            ans=ans+".";
            while(true)
            {
                //printf("fjslfk %d\n",pre);
                long long qaq,pree;
                for(int i=1;i<=a[pre].k;i++)
                {
                    //printf("3333 %d %d %d %d\n",a[pre].pos[i],pos,pre,i);
                    if(pos+a[pre].pos[i]<=add) pree=a[pre].kind[i],qaq=pos+a[pre].pos[i],tmpp=a[pre].name[i];
                }
                pos=qaq,pre=pree;
                ans=ans+tmpp;
                //printf("222 %d\n",pre);
                if(pre<=4)
                {
                    if(pos+a[pre].sz>=add)
                    {
                        cout<<ans;
                    puts("");
                    }
                    else printf("ERR\n");
                    break;
                }
                else ans=ans+".";
            }
        }
    }
    return 0;
}

