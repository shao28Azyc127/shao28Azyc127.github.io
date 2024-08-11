#include<bits/stdc++.h>
using namespace std;
int n,op;
struct st
{
    string x;
    int y;
};
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    st d[22222];
    d[0].x="byte";
    d[1].x="short";
    d[2].x="int";
    d[3].x="long";
    d[0].y=1;
    d[1].y=2;
    d[2].y=4;
    d[3].y=8;
    int kind=4;
    for(int i=0;i<n;i++)
    {
        cin>>op;
        if(op==1)
        {
            string s;
            int k,maxi=0,flag=0;
            cin>>s>>k;
            for(int j=0;j<k;j++)
            {
                string a,b;
                cin>>a>>b;
                for(int z=0;z<=kind;z++)
                {
                    if(a==d[z].x)
                        if(maxi<d[z].y)
                        {
                            maxi=d[z].y;
                            break;
                        }
                }
            }
            cout<<k*maxi<<" "<<maxi<<endl;
            for(int z=0;z<=kind;z++)
            {
                if(s==d[z].x)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                d[kind].x=s;
                d[kind].y=maxi;
                kind++;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
