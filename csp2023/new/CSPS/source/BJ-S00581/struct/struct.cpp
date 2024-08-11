#include <iostream>
#include <algorithm>
#include  <cstdio>
#include <cstring>

using namespace std;
const int N = 105;
int T,k,t[N];
int op;
string s;
string x,tmp;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>op;
        if(op == 1)
        {
            cin>>s>>k;
            int tot = 0,maxx = 0;
            for(int i = 1;i <= k;++i)
            {
                cin>>x>>tmp;
                if(x == "byte")
                {
                    maxx = max(maxx,1);
                    tot += 1;
                }
                else if(x == "short")
                {
                    maxx = max(maxx,2);
                    tot += 2;
                }
                else if(x == "int")
                {
                    maxx = max(maxx,4);
                    tot += 4;
                }
                else if(x == "long long")
                {
                    maxx = max(maxx,8);
                    tot += 8;
                }
            }
            int ans1 = tot/maxx;
            if(tot%maxx != 0) ++ans1;
            cout<<ans1*maxx<<" "<<maxx<<endl;
        }
    }
    return 0;
}
