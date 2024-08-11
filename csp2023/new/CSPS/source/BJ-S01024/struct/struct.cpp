#include <bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int space[N]={0,1,2,4,8};
int n;
struct node{
    int type,space;
    string name;
    int st,real;
}

node member[N];
node element[N];
long long cnt=0;
long long next[N];
map<string,int> newtype;
int tn=5,now=0;
int main()
{
    //freopen("struct.in","r",stdin);
    //freopen("struct.out","w",stdout);
    newtype["byte"]=1;
    newtype["short"]=2;
    newtype["int"]=3;
    newtype["long"]=4;
    for(int i=1;i<=n;i++)
    {
        int op;
        switch(op):
        {
            case 1:
            {
                string s;
                cin>>s;
                int k;
                cin>>k;
                int sp=0,maxn=0;
                int linshi=++cnt;
                member[cnt].st=now;
                member[cnt].name=s;
                member[cnt].type=newtype[s];
                for(int j=1;j<=k;j++)
                {
                    string c;
                    cin>>c;
                    int type;
                    type=newtype[c];
                    sp+=space[type];
                    maxn=max(maxn,space[type])
                    member[++cnt].type=type;
                    cin>>member[cnt].name;
                    newtype[s]=tn++;
                }
                member[linshi].real=sp;
                if(sp%maxn!=0)sp+=sp/maxn*maxn;
                member[linshi].space=sp;
                break;
            }
            case 2:
            {
                string c;
                cin>>c;
                type=newtype[c];
                    element[++cnt].type=type;
                    cin>>element[cnt].name;
                break;
            }
        }
    }
    cout<<"ERR";
}