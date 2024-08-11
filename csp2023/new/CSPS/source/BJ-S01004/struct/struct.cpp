#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
const int maxn=1e7;
int p[maxn];
struct node
{
    string name;
    int p;
    int t;
}arr[maxn];
int acnt=1;
signed main()
{
    ifstream cin ("struct.in");
    ofstream cout ("struct.out");
    int m;cin>>m;
    int cnt=0;
    while(m--)
    {
        int op;cin>>op;
        if(op==1)printf("1");
        if(op==2)
        {
            string s,n;
            cin>>s;
            cin>>n;
            int t;
            if(s=="int")t=4;
            if(s=="long long")t=8;
            if(s=="long")t=4;
            if(s=="short")t=2;
            arr[acnt]={n,cnt,t};
            for(int i=cnt;i<cnt+t;i++)p[i]=acnt;
            cout<<arr[acnt].p<<endl;
            cnt+=t;
            acnt++;
        }
        if(op==3)
        {
            string n;
            cin>>n;
            for(int i=1;i<acnt;i++)
            {
                if(arr[i].name==n)
                {
                    cout<<arr[i].p<<endl;
                    break;
                }
            }
        }
        if(op==4)
        {
            int pp;cin>>pp;
            if(pp>=cnt)
            {
                cout<<"ERR"<<endl;
            }
            else cout<<arr[p[pp]].name<<endl;
        }
    }
    return 0;
}