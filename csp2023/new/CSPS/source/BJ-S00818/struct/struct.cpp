#include <iostream>
#include <map>
using namespace std;
int n;
int cnt;
map<int,string> mp;
map<string,int> pm;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int i,j;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        int op;
        cin>>op;
        if(op==2)
        {
            string x,y;
            cin>>y>>x;
            if(y=="byte")
            {
                pm[x]=cnt;
                mp[cnt]=x;
                cnt++;
            }
            if(y=="short")
            {
                pm[x]=cnt;
                mp[cnt]=x;
                cnt++;
                mp[cnt]=x;
                cnt++;
            }
            if(y=="int")
            {
                pm[x]=cnt;
                mp[cnt]=x;
                cnt++;
                mp[cnt]=x;
                cnt++;
                mp[cnt]=x;
                cnt++;
                mp[cnt]=x;
                cnt++;
            }
            if(y=="long")
            {
                pm[x]=cnt;
                mp[cnt]=x;
                cnt++;
                mp[cnt]=x;
                cnt++;
                mp[cnt]=x;
                cnt++;
                mp[cnt]=x;
                cnt++;
                mp[cnt]=x;
                cnt++;
                mp[cnt]=x;
                cnt++;
                mp[cnt]=x;
                cnt++;
                mp[cnt]=x;
                cnt++;
            }
        }
        else if(op==3)
        {
            string x;
            cin>>x;
            cout<<pm[x]<<endl;
        }
        else if(op==4)
        {
            int temp;
            cin>>temp;
            string x;
            x=mp[temp];
            if(x.size()==0)
                cout<<"ERR"<<endl;
            else
                cout<<mp[temp]<<endl;
        }
    }
    return 0;
}
/*
5
2 byte a
2 short b
2 int c
2 long d
*/
