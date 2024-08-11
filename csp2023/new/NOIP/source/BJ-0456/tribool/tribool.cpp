#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
const int N = 100005;
int c,T;
int n,m;

int var[20],tmpvar[20],ans;
struct node
{
    int type,x,y;
}op[N];
int reverse(int x)
{
    if(x == 0) return 1;
    if(x == 1) return 0;
    if(x == 2) return 2;
}
void numer(int num)
{
    if(num == n+1)
    {
        for(int i = 1;i <= n;++i) tmpvar[i] = var[i];
        int u_num = 0;
        for(int i = 1;i <= n;++i) if(tmpvar[i] == 2) ++u_num;
        for(int i = 1;i <= m;++i)
        {
            if(op[i].type == 1||op[i].type == 0||op[i].type == 2)
            {
                tmpvar[op[i].x] = op[i].type;
            }
            else if(op[i].type == 3) tmpvar[op[i].x] = tmpvar[op[i].y];
            else if(op[i].type == 4) tmpvar[op[i].x] = reverse(tmpvar[op[i].y]);
        }
        int fl = 1;
        for(int i = 1;i <= n;++i) if(tmpvar[i] != var[i]) {fl = 0;break;}
        if(fl == 1) ans = min(ans,u_num);
        return;
    }
    for(int i = 0;i <= 2;++i)
    {
        var[num] = i;
        numer(num+1);
    }
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>T;
    if(c == 1||c == 2)
    {
        while(T--)
        {
            cin>>n>>m;
            char aa;
            for(int i = 1;i <= m;++i)
            {
                cin>>aa>>op[i].x;
                if(aa == 'T') op[i].type = 1;
                if(aa == 'F') op[i].type = 0;
                if(aa == 'U') op[i].type = 2;
                if(aa == '+') op[i].type = 3;
                if(aa == '-') op[i].type = 4;
                if(op[i].type == 3||op[i].type == 4) cin>>op[i].y;
            }
            ans = 0x3f3f3f3f;
            numer(1);
            cout<<ans<<endl;
        }
    }
    if(c == 3||c == 4)
    {
        int last[N];
        while(T--)
        {
            memset(last,0,sizeof(last));
            ans = 0;
            cin>>n>>m;
            char aa;int ip;
            for(int i = 1;i <= m;++i)
            {
                cin>>aa>>ip;
                if(aa == 'T') last[ip] = 1;
                if(aa == 'F') last[ip] = 0;
                if(aa == 'U') last[ip] = 2;
            }
            for(int i = 1;i <= n;++i) if(last[i] == 2) ++ans;
            cout<<ans<<endl;
        }
    }

    return 0;
}
