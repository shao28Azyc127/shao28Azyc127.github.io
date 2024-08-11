#include <iostream>

using namespace std;

const int N = 1e5+5;

int c,t;
int n,m,k,d;
struct challenge{
    int d,la,rew;
}ch[N];

int f[N][2];

int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%d%d",&c,&t);
    for(int T = 1;T <= t;T++){
        scanf("%d%d%d%d",&n,&m,&k,&d);
        for(int i = 1;i <= m;i++){
            scanf("%d%d%d",ch[i].d,ch[i].la,ch[i].rew);
        }
        for(int day = 1;day <= n;day++){
            f[day][0] = max(f[day-1][0],f[day-1][1]);
            int reward = 0;
            for(int i = 1;i <= m;i++){
                if(ch[i].d == day) reward += ch[i].rew;
            }
            f[day][1] = max(f[day-1][0]-d,f[day-1][1]-d+reward);
        }
        cout << max(f[n][1],f[n][0]);
    }
    return 0;
}
