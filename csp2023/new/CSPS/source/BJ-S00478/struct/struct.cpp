#include <bits/stdc++.h>
using namespace std;
map <string,pair <int,int> > mp;
map <string,int> siz;
string a[1000000];
int last=0;

int main()
{
    siz["byte"]=1;
    siz["short"]=2;
    siz["int"]=4;
    siz["long"]=8;
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    cin>>n;
    int tmp;
    for(int i = 0;i <n;i++)
    {
        cin>>tmp;
        if(tmp==2)
        {
            string type,name;
            cin>>type>>name;
            while(last%siz[type]!=0) last++;
            mp[name]=make_pair(last,last+siz[type]-1);
            for(int i = last;i<last+siz[type];i++)
                a[i]=name;
            last+=siz[type];
        }
        if(tmp==3)
        {
            string s;
            cin>>s;
            pair <int,int> pp=mp[s];
            cout<<pp.first<<endl<<pp.second<<endl;
        }
        if(tmp==4)
        {
            int tmpp;
            cin>>tmpp;
            if(a[tmpp]=="")
            {
                cout<<"ERR"<<endl;
                continue;
            }
            cout<<a[tmpp]<<endl;
        }
    }
    return 0;
}
