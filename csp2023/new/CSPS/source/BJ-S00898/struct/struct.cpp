#include<iostream>
#include<map>
using namespace std;
struct _class
{
    int type[105];
    string mem[105];
    map<string,int>  memid;
    int duiqi,k;
    int pos[105];
    string name;
    int size_;
} a[415];
map<string,int> id;
struct node
{
    int kind;//101:byte 102:short 103:int 104:long
    int pos;
    string name;
} b[105];
map<string,int> nodeid;
int n,op,acnt,bcnt,pos;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    //std::ios::sync_with_stdio(false);
    cin>>n;
    id["byte"]=401;
    a[401].duiqi=a[401].size_=1;
    a[401].k=0;
    a[402].duiqi=a[402].size_=2;
    a[402].k=0;
    a[403].duiqi=a[403].size_=4;
    a[403].k=0;
    a[404].duiqi=a[404].size_=8;
    a[404].k=0;
    id["short"]=405;
    a[405].duiqi=a[405].size_=2;
    a[405].k=0;
    a[406].duiqi=a[406].size_=4;
    a[406].k=0;
    a[407].duiqi=a[407].size_=8;
    a[407].k=0;
    id["int"]=408;
    a[408].duiqi=a[408].size_=4;
    a[408].k=0;
    a[409].duiqi=a[409].size_=8;
    a[409].k=0;
    id["long"]=410;
    a[410].duiqi=a[410].size_=8;
    a[410].k=0;

    for(int iiiii=1;iiiii<=n;iiiii++)
    {
        cin>>op;
        switch(op)
        {
            case 1:
            {
                ++acnt;
                cin>>a[acnt].name>>a[acnt].k;
                id[a[acnt].name]=acnt;
                for(int i=1;i<=a[acnt].k;i++)
                {
                    string str;
                    cin>>str>>a[acnt].mem[i];
                    a[acnt].type[i]=id[str];
                    a[acnt].memid[a[acnt].mem[i]]=i;
                    a[acnt].duiqi=max(a[acnt].duiqi,a[id[str]].duiqi);

                }
                for(int i=1;i<=a[acnt].k;i++)
                    while(a[a[acnt].type[i]].duiqi<a[acnt].duiqi&&a[acnt].type[i]>400)
                        a[acnt].type[i]++;
                for(int i=1;i<=a[acnt].k;i++)
                    a[acnt].size_+=a[a[acnt].type[i]].size_;
                for(int i=2;i<=a[acnt].k;i++)
                    a[acnt].pos[i]=a[acnt].pos[i-1]+max(a[acnt].duiqi,a[a[acnt].type[i-1]].size_);
                //printf("size=%d,duiqi=%d,k=%d\n",a[acnt].size_,a[acnt].duiqi,a[acnt].k);
                //for(int i=1;i<=a[acnt].k;i++)
                //    printf("pos=%d,type=%d,typesize=%d,mem=",a[acnt].pos[i],a[acnt].type[i],a[a[acnt].type[i]].size_),cout<<a[acnt].mem[i]<<'\n';
                cout<<a[acnt].size_<<' '<<a[acnt].duiqi<<'\n';
                /*while(a[acnt].duiqi!=8)
                {
                    ++acnt;
                    a[acnt]=a[acnt-1];
                    a[acnt].duiqi*=2;
                    for(int i=1;i<=a[acnt].k;i++)
                        while(a[a[acnt].type[i]].duiqi!=a[acnt].duiqi&&a[acnt].type[i]>400)
                            a[acnt].type[i]++;
                    for(int i=2;i<=a[acnt].k;i++)
                        a[acnt].pos[i]=a[acnt].pos[i-1]+max(a[acnt].duiqi,a[a[acnt].type[i-1]].size_);
                    for(int i=1;i<=a[acnt].k;i++)
                        a[acnt].size_+=a[a[acnt].type[i]].size_;
                }*/
                break;
            }
            case 2:
            {
                ++bcnt;
                string str;
                cin>>str>>b[bcnt].name;
                //cout<<"findstr:"<<id.count(str)<<'\n';
                b[bcnt].kind=id[str];
                b[bcnt].pos=pos;
                //cout<<"kind="<<b[bcnt].kind<<" pos="<<b[bcnt].pos<<'\n';
                cout<<pos<<'\n';
                pos+=a[b[bcnt].kind].size_;
                nodeid[b[bcnt].name]=bcnt;
                break;
            }
            case 3:
            {
                string sttr,tmps="";
                cin>>sttr;
                int spos=sttr.find('.');
                int nid=nodeid[sttr.substr(0,spos)],tid=b[nid].kind;
                //cout<<"scanned:"<<sttr.substr(0,spos)<<'\n';
                int ans=b[nid].pos;
                //cout<<"pos="<<ans<<'\n';
                //cout<<"nid="<<nid<<" tid="<<tid<<"\n";
                sttr=sttr.substr(spos+1);
                while((spos=sttr.find('.'))!=string::npos)
                {
                    //cout<<"scanned:"<<sttr.substr(0,spos)<<" find:"<<(a[tid].memid.count(sttr.substr(0,spos)))<<'\n';
                    int mid=a[tid].memid[sttr.substr(0,spos)];
                    //cout<<"mid="<<mid<<'\n';
                    ans+=a[tid].pos[mid];
                    tid=a[tid].type[mid];
                    //cout<<"pos="<<ans<<'\n';
                    sttr=sttr.substr(spos+1);
                }
                int mid=a[tid].memid[sttr];
                ans+=a[tid].pos[mid];
                cout<<ans<<'\n';
                break;
            }
            case 4:
            {
                int addr;
                cin>>addr;
                if(addr>pos)
                {
                    cout<<"ERR";
                    break;
                }
                int Nid=1;
                while(b[Nid+1].pos<=addr&&Nid<bcnt) Nid++;
                string output=b[Nid].name;
                int Tid=b[Nid].kind;
                addr-=b[Nid].pos;
                while(Tid<=400)
                {
                    output+='.';
                    int Mid=1;
                    while(a[Tid].pos[Mid+1]<=addr&&Mid<a[Tid].k) Mid++;
                    addr-=a[Tid].pos[Mid];
                    output+=a[Tid].mem[Mid];
                    Tid=a[Tid].type[Mid];
                }
                cout<<output;
                cout<<'\n';
                break;
            }
        }
    }
    return 0;
}
