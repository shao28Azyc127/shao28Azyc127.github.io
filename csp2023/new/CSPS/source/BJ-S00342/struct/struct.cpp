#include <bits/stdc++.h>
#define TBYTE   1
#define TSHORT  2
#define TINT    3
#define TLONG   4


using namespace std;
struct stc
{
    vector <string> type;
    vector <string> name;
    long long dq=0;
    long long cou;
};

map <string,stc> strs;
int n;
long long SizeOf(string type)
{
    if(type == "byte") return 1;
    else if(type == "short") return 2;
    else if(type == "int") return 4;
    else if(type == "long") return 8;
    else return strs[type].cou * strs[type].dq;
}
vector <string> varname;
vector <string> vartype;
vector <long long> varpos;
map <string,long long> name2in;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    int op;
    int k;
    string s;
    string type;
    string name;
    string com;
    long long cur_pos=0;
    long long vis_pos=0;
    while(n--)
    {
        cin>>op;
        if(op==1)
        {
            cin>>s>>k;
            strs[s].cou = k;
            for(int i=0;i<k;i++)
            {
                cin>>type>>name;

                strs[s].name.push_back(name);
                strs[s].type.push_back(type);
                strs[s].dq = max(strs[s].dq,SizeOf(type));
            }
            cout<<SizeOf(s)<<" "<<strs[s].dq<<endl;
        }
        if(op==2)
        {
            cin>>type>>name;
            if(cur_pos==0)
            {
                cout<<cur_pos<<endl;
                cur_pos+=strs[name].cou * strs[name].dq;
                varname.push_back(name);
                vartype.push_back(type);
                varpos.push_back(cur_pos);
                name2in[name] = varname.size()-1;
            }
            else
            {
                cout<<((cur_pos/strs[name].dq)+1)*strs[name].dq<<endl;
                cur_pos = ((cur_pos/strs[name].dq)+1)*strs[name].dq;
                cur_pos+=strs[name].cou * strs[name].dq;
                varname.push_back(name);
                vartype.push_back(type);
                varpos.push_back(cur_pos);
                name2in[name] = varname.size()-1;
            }


        }
        stringstream ss;
        int dq;
        if(op==3)
        {
            cin>>com;
            vis_pos = 0;
            //cout<<com;
            for(int i=0;i<com.length();i++)
            {
                if(com[i]=='.')
                {
                    com[i]=' ';
                }
            }
            //cout<<com;
            ss<<com;
            if(ss>>name)
            {
                //cout<<name;
                vis_pos = varpos[name2in[name]];
                //cout<<vis_pos;
                while(ss>>name)
                {
                    dq = strs[name].dq;
                    for(int i=0;i<strs[name].name.size();i++)
                    {
                        if(name!=strs[name].name[i])
                        {
                            vis_pos+=dq;
                        }
                    }
                }
            }
            cout<<vis_pos<<endl;
        }
    }
    return 0;
}
