#include<iostream>
using namespace std;
string nn[105],tt[105];
string s;
int k;
int op;
int ttt,nnn;
int n;
string ss;
int addr;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>op;
        if(op==1)
        {
            cin>>s>>k;
            for(int j=0;j<n;j++)
            {
                cin>>nn[j]>>tt[j];
            }
        }
        if(op==2)
        {
            cin>>ttt>>nnn;
            cout<<i+1;
        }
        if(op==3)
        {
            cin>>ss;
            cout<<i+1;
        }
        if(op==4)
        {
            cin>>addr;
            cout<<"ERR";
        }
    }
    return 0;
}
