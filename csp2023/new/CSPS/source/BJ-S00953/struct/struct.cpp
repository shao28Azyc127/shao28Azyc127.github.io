// Let LRH bless me, I love LRH forever !!!

#include<bits/stdc++.h>
using namespace std;
map<string,int> memories; //所占字节


struct A_struct{
    map<string,int> Begpos; // struct 内开始
    vector<string> Values;
};
map<string,A_struct> mp_str; // 通过 struct 定义名称找 struct
map<string,int> begpos;
map<string,string> Name_To_Type; // 通过变量名称找  type
vector<string> Allvals;
void newstruct()
{
    string nm;int id;
    cin>>nm;
    scanf("%d",&id);
    int nowid=0,maxid=0;
    A_struct qwq;
    for(int i=1;i<=id;++i)
    {
        string type,name;
        cin>>type>>name;
        qwq.Begpos[name]=nowid;
        //cout<<"Begpos["<<name<<"]="<<nowid<<endl;
        qwq.Values.push_back(name);
        nowid+=memories[type];
        maxid=max(maxid,memories[type]);
    }
    string ENDTAG="--------------";
    qwq.Begpos[ENDTAG]=nowid;
    qwq.Values.push_back(ENDTAG);
    int Realmem=nowid;
    while((Realmem+1)%maxid!=0)
    {
        Realmem++;
    }
    memories[nm]=Realmem+1;
    mp_str[nm]=qwq;
}
int nowpos=0;
void newvalue()
{
    string type,name;
    cin>>type>>name;
    Name_To_Type[name]=type;
    begpos[name]=nowpos;
    nowpos+=memories[type];
    Allvals.push_back(name);
}
int findinastruct(string Name,string node)
{
    string type=Name_To_Type[Name];
    A_struct Node=mp_str[Name];
    return Node.Begpos[node];
}
void FindPosInStruct(string name,string type,int pos)
{
    A_struct tp=mp_str[type];
    int ans=-1;

    //cout<<"LastValue="<<tp.Values[tp.Values.size()-1]<<endl;
    for(int i=0;i<tp.Values.size()-1;i++)
    {
        string now=tp.Values[i],nxt=tp.Values[i+1];
        int newpos=tp.Begpos[now],nxtpos=tp.Begpos[nxt];
        //cout<<newpos<<" "<<pos<<" "<<nxtpos<<endl;
        if(newpos<=pos && pos<nxtpos)
        {
            cout<<name<<".";
            cout<<now<<'\n';
            return ;
        }
    }
    cout<<"ERR"<<'\n';
}
void findaddress()
{
    int addr;
    scanf("%d",&addr);
    int ansit;
    for(int i=0;i<Allvals.size();i++)
    {
        int newpos=begpos[Allvals[i]];
        int nxtpos;
        if(i==Allvals.size()-1)
        {
            nxtpos=nowpos-1;
        }else{
            nxtpos=begpos[Allvals[i+1]]-1;
        }
        //cout<<newpos<<" "<<addr<<" "<<nxtpos<<endl;
        if(newpos<=addr && addr<=nxtpos)
        {
            ansit=i;
            break;
        }
    }

    //cout<<"-----"<<endl;

    //return ;
    string name=Allvals[ansit];
    string type=Name_To_Type[name];
    if(type=="type" || type=="int" || type=="long" || type=="short")
    {
        cout<<name<<'\n';
    }else{
        FindPosInStruct(name,type,addr-(begpos[name]));
    }
}
int n;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    memories["byte"]=1;memories["short"]=2;
    memories["int"]=4;memories["long"]=8;
    scanf("%d",&n);
    int cnt1=0;
    for(int i=1;i<=n;i++)
    {
        int opt;
        scanf("%d",&opt);
        //cout<<"opt="<<opt<<endl;
        if(opt==1)
        {
            newstruct();
        }else if(opt==2){
            newvalue();
        }else if(opt==3){
            string str;
            cin>>str;
            string tmp="",tmp2="";int type=0;
            for(int i=0;i<str.size();i++)
            {
                if(str[i]=='.')
                {
                    type=1;
                }else{
                    if(type==0) tmp+=str[i];
                    else tmp2+=str[i];
                }
            }

            int beg=begpos[tmp];
            if(type==0)
            {
                printf("%d\n",beg);
            }else{
                int ans=findinastruct(tmp,tmp2);
                printf("%d\n",beg+ans);
            }
        }else{
            //return 0;
            findaddress();
        }
    }
    return 0;
}
