#include<iostream>
#include<cstring>
using namespace std;
int n,p,ts,ds;
string t[200001];
int d[200001];
string space[1000001];
int output[100001],op=0;
string output2[100001],op2=0;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    t[1]="byte";
    t[2]="short";
    t[3]="int";
    t[4]="long";
    d[1]=1;
    d[2]=2;
    d[3]=4;
    d[4]=8;
    int line=0;
    for(int i=0;i<=100000)
    {
        space[i]="NULL";
        output2[i]="NULL";
    }
    for(int i=1;i<=n;i++)
    {
        cin>>p;
        if(p==2)
        {
            string type;
            string name;
            int l;
            for(int i=1;i<=4;i++)
            {
                if(t[i]==type)
                {
                    l=d[i];
                    break;
                }
            }
            while(line%l!=0)
            {
                line++;
            }
            output[op]=line;
            op++;
            for(int j=line;j<line+l;j++)
            {
                space[j]=name;
            }
            line=line+l;
        }
        if(p==3)
        {
            string name;
            cin>>name;
            for(int i=0;i<line;i++)
            {
                if(space[i]==name)
                {
                    output[op]=i;
                    op++;
                    break;
                }
            }
        }
        else if(p==4)
        {
            int r;
            cin>>r;
            if(space[r]!=NULL)
            {
                output2[op]=space[r];
            }
            else
            {
                output2[op]="ERR";
            }
            op++;
        }
    }
    for(int i=0;i<op;i++)
    {
        if(output2[i]!="NULL")
        {
            cout<<output2[i]<<endl;
        }
        else
        {
            cout<<output[i]<<endl;
        }
    }
    return 0;
}
