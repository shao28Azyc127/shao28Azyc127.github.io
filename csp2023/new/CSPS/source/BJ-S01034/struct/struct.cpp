#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
string s;
int where=0;
string typer, ele;
vector<int> type;
vector<string> ask;
vector<int> ask_ty;
vector<int> type_in;
vector<string> types;
int k;
vector<string> in;

int type_two, name;

int m[100] = {100};
int maxn()
{
    int m1=0;
    for(int i=0;i<k;i++)
    {
        if(type[i]>m1)
        {
            m1=type[i];
        }
    }
    return m1;
}
int j;
bool cmp(int a, int b)
{
    if(a<b) return true;
    else return false;
}
int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    cin>>n;
    types.push_back("bytes");
    types.push_back("short");
    types.push_back("int");
    types.push_back("long");
    type_in.push_back(1);
    type_in.push_back(2);
    type_in.push_back(4);
    type_in.push_back(8);
    int op;
    for(int i=0;i<n;i++)
    {
        cin>>op;
        if(op==1)
        {
            cin>>s>>k;
            for(j=0;j<k;j++)
            {
                cin>>ask[j]>>in[j];
                if(ask[j]=="short")
                {
                    ask_ty.push_back(2);
                }
                else if(ask[j] == "int")
                {
                    ask_ty.push_back(4);
                }
                else if(ask[j] == "byte")
                {
                    ask_ty.push_back(1);
                }
                else
                {
                    ask_ty.push_back(8);
                }
            }
            type_in.push_back(k*maxn());
            types.push_back(s);
            cout<<k*maxn()<<' '<<maxn()<<endl;
        }
        else if(op==2)
        {
            cin>>typer>>ele;
            cout<<where<<endl;
            for(int i=0;i<types.size();i++)
            {
                if(types[i] == typer)
                {
                    where += type_in[i];
                }
            }
        }
    }
    for(int i=0;i<4;i++)
    {
        cout<<type_in[i];
    }
    return 0;
}
