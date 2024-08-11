#include<bits/stdc++.h>
using namespace std;
struct su
{
    int siz=0;//this
    int dq=0;//mem
    map<string,int> memnatoh;//<typecoad,bianhao>
    vector<int> memty;//hao to type
    vector<string> memna;//hao to name
    bool basc=false;
};
vector<su> stru;//typecode message
map<string,int> tytoco;//typename to typecode
long long nw=0;
map<string,int> xnametoad;//xname to start address
map<string,int> xnametoty;//xname to typecode
vector<pair<int,string> > m;//i:(<start address,xname>)
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    /*string a="111";
    int i=1145;
    stru[1].insert({a,i});
    cout<<(*(stru[1].find(a))).second;*/
    map<string,int> emp;
    su x={1,1,emp,{},{},true};
    tytoco.insert({"byte",stru.size()});
    stru.push_back(x);
    su x2={2,2,emp,{},{},true};
    tytoco.insert({"short",stru.size()});
    stru.push_back(x2);
    su x3={4,4,emp,{},{},true};
    tytoco.insert({"int",stru.size()});
    stru.push_back(x3);
    su x4={8,8,emp,{},{},true};
    tytoco.insert({"long",stru.size()});
    stru.push_back(x4);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            string name;
            int num;
            cin>>name>>num;
            tytoco.insert({name,stru.size()});
            su x;
            for(int j=1;j<=num;j++)
            {
                string namem,typem;
                cin>>typem>>namem;
                x.dq=max(x.dq,stru[tytoco.find(typem)->second].siz);
                x.memnatoh.insert({namem,x.memty.size()});
                x.memty.push_back(tytoco.find(typem)->second);
                x.memna.push_back(namem);
            }
            x.siz=x.memna.size()*x.dq;
            stru.push_back(x);
            cout<<x.siz<<" "<<x.dq<<endl;
        }
        else if(op==2)
        {
            string typ,name;
            cin>>typ>>name;
            xnametoty.insert({name,tytoco.find(typ)->second});
            xnametoad.insert({name,nw});
            m.push_back({nw,name});
            cout<<nw<<endl;
            nw+=stru[tytoco.find(typ)->second].siz;

        }
        else if(op==3)
        {
            string s;
            cin>>s;
            string ma[1008];
            int cnt=1;
            for(int j=0;j<s.size();j++)
            {
                if(s[j]!='.')
                {
                    ma[cnt]=ma[cnt]+s[j];
                }
                else{
                    cnt++;
                }
            }
            int add=xnametoad.find(ma[1])->second;
            int typ=xnametoty.find(ma[1])->second;
            for(int j=2;j<=cnt;j++)
            {
                if(stru[typ].basc)
                {
                    add+=stru[typ].siz;
                    break;
                }
                add+=stru[typ].memnatoh.find(ma[j])->second*stru[typ].dq;
                typ=stru[typ].memty[stru[typ].memnatoh.find(ma[j])->second];
            }
            cout<<add<<endl;
        }else if(op==4)
        {
            int add;
            cin>>add;
            int ty=-1;
            int st=0;
            for(int j=m.size()-1;j>=0;j--)
            {
                if(m[j].first<add)
                {
                    ty=xnametoty.find(m[j].second)->second;
                    st=xnametoad.find(m[j].second)->second;
                    break;
                }
            }
            if(yt==-1)
            {
                cout<<"ERR\n";
                continue;
            }
            int h=0;
            for(int j=stru[ty].memty.size()-1;j>=0;j--)
            {
                if(j*stru[ty].dq+st<add)
                {
                    if(j*stru[ty].dq+st>j*stru[ty].dq+st)
                    ty=xnametoty.find(m[j].second)->second;
                    st=xnametoad.find(m[j].second)->second;
                    break;
                }
            }
            cout<<h;
        }
    }
return 0;
}
