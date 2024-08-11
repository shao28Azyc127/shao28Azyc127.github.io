#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("srruct.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            string a;
            int n,max1=0;
            cin>>a>>n;
            for(int i=1;i<=n;i++)
            {
                string x;
                cin>>x;
                if(x=="short")
                    max1=max(max1,2);
                else if(x=="int")
                    max1=max(max1,4);
                else if(x=="long")
                    max1=max(max1,8);
                else
                    max1=max(m[x],max1);
                string ls;
                cin>>ls;
            }
            cout<<max1*n<<" "<<max1<<endl;
            m[a]=max1*n;
        }
        else if(op==2)
        {
            string aa,bb;
            cin>>aa>>bb;
            cout<<0<<endl;
        }
        else if(op==3)
        {
            string aa;
            cin>>aa;
            cout<<"ERR"<<endl;
        }
        else
        {
            int aa;
            cin>>aa;
            cout<<"ERR"<<endl;
        }
    }
    return 0;
}