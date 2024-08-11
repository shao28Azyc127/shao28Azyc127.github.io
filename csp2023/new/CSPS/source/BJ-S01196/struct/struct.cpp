#include<bits/stdc++.h>
using namespace std;
#define int long long
string s,t,m,e;
int n,k,ad;
signed main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    int siz;
    map<string,int> fa;//first address
    map<string,string> z;
    fa["byte"]=1;
    fa["short"]=2;
    fa["int"]=4;
    fa["long"]=8;
    for(int i=1,op;i<=n;i++)
    {
        cin>>op;
        if(op==1)//create struct
        {
            cin>>s>>k;
            vector<string> v,w;
            int Max,cnt=0;
            for(int j=1;j<=k;j++)
            {
                cin>>t>>m;//members and their types
                string temp;
                temp+=cnt+'0';
                cnt+=fa[t];
                temp+=cnt+'0';
                z[m]=temp;
                Max=max(Max,fa[t]);
            }
            fa[s]=Max*k;
            cout<<Max*k<<" "<<Max<<endl;
        }
        if(op==2)//nex elements
        {
            cin>>s>>e;
            
        }
        if(op==3)//find elements' address
        {
            cin>>e;
        }
        if(op==4)//find elements
        {
            cin>>ad;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
