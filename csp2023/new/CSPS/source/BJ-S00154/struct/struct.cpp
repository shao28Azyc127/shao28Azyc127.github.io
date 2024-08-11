#include<bits/stdc++.h>
using namespace std;
string s[100],a;
int start;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    cin>>n;
    while(n--)
    {
        int op;
        cin>>op;
        if(op==2)
        {
            cin>>s[start]>>s[start];
            cout<<start*8<<endl;
        }
        if(op==3)
        {
            cin>>a;
            for(int i=0;i<=start;i++)
            {
                if(s[i]==a)
                {
                    cout<<i*8<<endl;
                    break;
                }
            }
        }
        if(op==4)
        {
            int addr;
            cin>>addr;
            if(addr/4<=start)
            {
                cout<<addr/4*8<<endl;
            }
            else
            {
                cout<<"ERR"<<endl;
            }
        }
    }
    return 0;
}
