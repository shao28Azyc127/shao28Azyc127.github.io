#include<iostream>
#include<map>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;
map<string,int>id,valid;
struct value{
    int id;
    string name;
}a[110];
vector<value>v[110];
long long base[110],sz[110],beg[110];
int n,cnt,vcnt;
long long adsum;
string pathans[110];
int main()
{
    cnt=4;
    id["byte"]=1,base[1]=sz[1]=1;
    id["short"]=2,base[2]=sz[2]=2;
    id["int"]=3,base[3]=sz[3]=4;
    id["long"]=4,base[4]=sz[4]=8;
    cin>>n;
    while(n--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            string s;
            int k;
            cin>>s>>k;
            id[s]=++cnt;
            int sum=0;
            while(k--)
            {
                string kind,name;
                cin>>kind>>name;
                int kid=id[kind];
                base[cnt]=max(base[cnt],base[kid]);
                sum=ceill(sum*1.0/base[kid])*base[kid]+sz[kid];
            }
            sz[cnt]=ceill(sum*1.0/base[cnt])*base[cnt];
            cout<<sz[cnt]<<" "<<base[cnt]<<endl;
        }
        if(op==2)
        {
            string s,name;
            cin>>s>>name;
            int vid=id[s];
            a[++vcnt]={vid,name};
            valid[name]=vcnt;
            adsum=ceill(adsum*1.0/base[vid])*base[vid]+sz[vid];
            cout<<adsum-sz[vid]<<endl;
            beg[vcnt]=adsum-sz[vid];
        }
        if(op==3)
        {
            string path;
            cin>>path;
            path+=".";
            string now="";
            int node=0;
            long long addr=0;
            for(int i=0;i<path.size();i++)
            {
                if(path[i]=='.')
                {
                    if(!node)
                    {
                        node=a[valid[now]].id;
                        addr=beg[node];
                    }
                    else
                    {
                        for(auto j:v[i])
                            if(j.name==now)
                            {
                                node=j.id;
                                break;
                            }
                            else addr+=sz[j.id];
                    }
                    now="";
                }
                else now+=path[i];
            }
            cout<<addr<<endl;
        }
        if(op==4)
        {
            for(int i=1;i<=100;i++)pathans[i]="";
            int cur;
            long long addr;
            cin>>addr;
            int node;
            for(int i=1;i<=vcnt;i++)
                if(beg[i]<=addr&&addr<beg[i+1])
                {
                    pathans[++cur]=a[i].name;
                    node=a[i].id;
                }
            bool ff=1;
            while(v[node].size()>0)
            {
                int sum=0;
                bool fff=0;
                for(auto y:v[node])
                {
                    sum=ceill(sum*1.0/base[y.id])*base[y.id]+sz[y.id];
                    if(sum<=addr&&addr<sum+sz[y.id])
                    {
                        pathans[++cur]=y.name;
                        node=y.id;
                        fff=1;
                    }
                }
                if(!fff)
                {
                    ff=0;
                    break;
                }
            }
            if(ff)
            {
                for(int i=1;i<=cur;i++)
                {
                    cout<<pathans[i];
                    if(i<cur)cout<<'.';
                }
                cout<<endl;
            }
            else cout<<"ERR"<<endl;
        }
    }
    return 0;
}