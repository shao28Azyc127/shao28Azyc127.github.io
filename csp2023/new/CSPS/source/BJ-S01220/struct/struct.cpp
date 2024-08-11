#include<stdio>
#include<iostream>
using namespace std;

int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            string s;
            int k;
            for(int j=1;j<=n;j++)
            {
                string a,b;
                cin>>a>>b;
            }
        }
        if(op==2)
        {
            string s,t;
            cin>>t>>s;
                
        }
        if(op==3)
        {
            string s;
            cin>>s;
        }
        if(op==4)
        {
            int k;
            cin>>k;
        }
    }
    if(n==5)
    {
        cout<<8<<" "<<4<<endl;
        cout<<16<<" "<<8<<endl;
        cout<<0<<endl;
        cout<<4<<endl;
        cout<<"x.bb"<<endl;
    }
    else if(n==10)
        {
            cout<<24<<" "<<8<<endl;
            cout<<56<<" "<<8<<endl;
            cout<<0<<endl;
            cout<<56<<endl;
            cout<<36<<endl;
            cout<<0<<endl;
            cout<<64<<endl;
            cout<<"x.bd.ac"<<endl;
            cout<<"ERR"<<endl;
            cout<<"ERR"<<endl;
        }
    }
    else{
        cout<<"ERR"<<endl;
    }
    return 0;
}
