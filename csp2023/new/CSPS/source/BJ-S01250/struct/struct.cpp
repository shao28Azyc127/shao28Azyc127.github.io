#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
    long long xx,realsize,size;
    string name;
};
vector<node>v[100005];//nazhongleixing  mingzi
long long sizee[100005];
string name1[105],name2[105];
int cnt;
string base[5];
map<string,int>mm;
long long startt=-1;
void query1(int x,int len,string key)
{
    //cout<<"::"<<x<<" "<<len<<" "<<key<<endl;
    if(len==key.size()-1)
    {
        cout<<startt+1<<endl;
        return;
    }
    string now;
    //cout<<key.size()<<" "<<key[++len]<<endl;
    char tt;
    tt='.';
    for(;(int(len)<int(key.size()-1))&&key[++len]!=tt;)
    {
        //cout<<"!!"<<len<<endl;
        if(key[len]=='a')
        {
            now+='a';
        }
        else if(key[len]=='b')
        {
            now+='b';
        }
        else if(key[len]=='c')
        {
            now+='c';
        }
        else if(key[len]=='d')
        {
            now+='d';
        }
        else if(key[len]=='e')
        {
            now+='e';
        }
        else if(key[len]=='f')
        {
            now+='f';
        }
        else if(key[len]=='g')
        {
            now+='g';
        }
        else if(key[len]=='h')
        {
            now+='h';
        }
        else if(key[len]=='i')
        {
            now+='i';
        }
        else if(key[len]=='j')
        {
            now+='j';
        }
        else if(key[len]=='k')
        {
            now+='k';
        }
        else if(key[len]=='l')
        {
            now+='l';
        }
        else if(key[len]=='m')
        {
            now+='m';
        }
        else if(key[len]=='n')
        {
            now+='n';
        }
        else if(key[len]=='o')
        {
            now+='o';
        }
        else if(key[len]=='p')
        {
            now+='p';
        }
        else if(key[len]=='q')
        {
            now+='q';
        }
        else if(key[len]=='r')
        {
            now+='r';
        }
        else if(key[len]=='s')
        {
            now+='s';
        }
        else if(key[len]=='t')
        {
            now+='t';
        }
        else if(key[len]=='u')
        {
            now+='u';
        }
        else if(key[len]=='v')
        {
            now+='v';
        }
        else if(key[len]=='w')
        {
            now+='w';
        }
        else if(key[len]=='x')
        {
            now+='x';
        }
        else if(key[len]=='y')
        {
            now+='y';
        }
        else if(key[len]=='z')
        {
            now+='z';
        }
    }
    //cout<<"??"<<now<<endl;
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i].name==now)
        {
            query1(v[x][i].xx,len,key);
        }
        startt+=v[x][i].size;
    }
}
inline bool bj(string a,string b)
{
    if(a.size()!=b.size())
    {
        return false;
    }
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i])
        {
            return false;
        }
    }
    return true;
}
void solution2(int x,long long key,long long anss)
{
    for(int i=0;i<v[x].size();i++)
    {
        if(key<=v[x][i].size)
        {
            if(v[x][i].xx>=1&&v[x][i].xx<=4)
            {
                cout<<v[x][i].name<<endl;
                return;
            }
            cout<<v[x][i].name<<".";
            solution2(v[x][i].xx,key,anss);
        }
        key-=v[x][i].size;
    }
    return;
}
bool query2(int x,long long key,long long anss)
{
    //cout<<"::"<<key<<" "<<anss<<endl;
    for(int i=0;i<v[x].size();i++)
    {
        if(key<=v[x][i].size)
        {
            //cout<<v[x][i].name<<endl;
            if(v[x][i].xx>=1&&v[x][i].xx<=4)
            {
                solution2(0,anss,anss);
                return true;
            }
            else
            {
                return query2(v[x][i].xx,key,anss);
            }
            return false;
        }
        key-=v[x][i].size;
    }
    return false;
}
signed main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    int op;
    long long tt;
    string name;
    base[1]="byte";
    base[2]="short";
    base[3]="int";
    base[4]="long";
    for(int i=1;i<=4;i++)
    {
        if(i==1)
        {
            name=base[1];
            mm[name]=i;
            sizee[i]=1;
        }
        else if(i==2)
        {
            name=base[2];
            mm[name]=i;
            sizee[i]=2;
        }
        else if(i==3)
        {
            name=base[3];
            mm[name]=i;
            sizee[i]=4;
        }
        else
        {
            name=base[4];
            mm[name]=i;
            sizee[i]=8;
        }
    }
    cnt=4;
    long long cntt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>op;
        if(op==1)
        {
            cin>>name>>tt;
            mm[name]=++cnt;
            long long maxsize=0;
            for(int j=1;j<=tt;j++)
            {
                cin>>name1[j]>>name2[j];
                //cout<<"??"<<name1[j]<<" "<<mm[name1[j]]<<endl;
                maxsize=max(maxsize,sizee[mm[name1[j]]]);
            }
            sizee[cnt]=maxsize*tt;
            for(int j=1;j<=tt;j++)
            {
                node tmp;
                tmp.xx=mm[name1[j]];
                tmp.realsize=sizee[mm[name1[j]]];
                tmp.size=maxsize;
                tmp.name=name2[j];
                v[cnt].push_back(tmp);
            }
            cout<<sizee[cnt]<<" "<<maxsize<<endl;
        }
        if(op==2)
        {
            cin>>name1[0]>>name2[0];
            node tmp;
            tmp.xx=mm[name1[0]];
            tmp.realsize=sizee[mm[name1[0]]];
            tmp.size=sizee[mm[name1[0]]];
            tmp.name=name2[0];
            v[0].push_back(tmp);
            cout<<cntt<<endl;
            cntt+=sizee[mm[name1[0]]];
        }
        if(op==3)
        {
            cin>>name;
            startt=-1;
            query1(0,-1,name);
        }
        if(op==4)
        {
            cin>>tt;
            if(!query2(0,tt,tt))
            {
                cout<<"ERR"<<endl;
            }
        }
    }
    return 0;
}
