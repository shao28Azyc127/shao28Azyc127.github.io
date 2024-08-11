#include<bits/stdc++.h>
using namespace std;
char a[1000][1000];
int d[1000]={0};
char data[1000];
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    int top=1;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        if(x==2)
        {
            cin>>data;
            cin>>a[top];
            if(data[0]=='b')
                d[top+1]=d[top]+1;
            else if(data[0]=='s')
                d[top+1]=d[top]+2;
            else if(data[0]=='i')
                d[top+1]=d[top]+4;
            else if(data[0]=='l')
                d[top+1]=d[top]+8;
            cout<<d[top]<<endl;
            top++;
        }
        else if(x==3)
        {
            int f=0;
            cin>>data;
            for(int i=1;i<top;i++)
            {
                if(strcmp(data,a[i])==0)
                {
                    cout<<d[i]<<endl;
                    f=1;
                    break;
                }
            }
            if(f==0)
                cout<<"ERR"<<endl;
        }
        else
        {
            int q,f=0;
            cin>>q;
            for(int i=1;i<=top;i++)
            {
                if(q==data[i])
                {
                    if(i!=top)
                    {
                        cout<<a[i]<<endl;
                        f=1;
                        break;
                    }
                }
                else if(q<data[i])
                {
                    cout<<a[i-1]<<endl;
                    f=1;
                    break;
                }
            }
            if(f==0)
                cout<<"ERR"<<endl;
        }
    }
    return 0;
}