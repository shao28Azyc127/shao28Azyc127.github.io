#include<bits/stdc++.h>
using namespace std;
map< string,vector <string> > mpn;
map<string,string> mpn_t;
map<string,int> mpn_s;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    cin>>n;
    int tmp=0;
    while(n--)
    {
        int o;
        cin>>o;
        if(o==1)
        {
            int su=8,a=0;
            string name;
            int k;
            cin>>name;
            cin>>k;
            for(int i=1;i<=k;i++)
            {
                string c,d;
                cin>>c>>d;
                if(c=="long"){mpn[name].push_back(d);a+=8;}
                else
                {
                    for(auto j:mpn[c])
                    {
                        mpn[name].push_back(j);
                        a+=8;
                    }
                }
            }
            a+=su;
            cout<<a<<' '<<su<<'\n';
            mpn_s[name]=a;
        }
        else if(o==2)
        {
            string a,b;
            cin>>a>>b;
            mpn_t[b]=a;
            cout<<tmp<<'\n';
            tmp+=8;
        }
        else if(o==3)
        {
            string t1,t2;
            string s;
            cin>>s;
            for(int i=1;s[i]!='.';i++)
            {
                t1+=s[i];
            }
            for(int i=s.size()-1;s[i]!='.';i--)
            {
                t2+=s[i];
            }
            reverse(t2.begin(),t2.end());
            cout<<(mpn[t1].find(t2)-mpn[t1].begin())*8+8<<'\n';
        }
        else{
            int c;
            cin>>c;
            int i;
            for(i=0;i<mpn[name].size()&&c>0;i++)c-=8;
            if(c>0)
            {
                cout<<"ERR\n";
            }
        }
    }
    return 0;
}
