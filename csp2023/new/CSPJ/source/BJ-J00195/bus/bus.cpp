#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
    register int x = 0, f = 1;
    register char c = getchar();
    while(c < '0' || c > '9')
    {
        if(c == '-')f = -1;
        c = getchar();
    }
    while(c <= '9' && c >= '0')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

struct edge
{
    int v, w, t, nxt;
}e[200010];

int h[100010], cnt;

void addedge(int u, int v, int t)
{
    cnt++;
    e[cnt].nxt = h[u], e[cnt].v = v, e[cnt].w = 1, e[cnt].t = t;
    h[u] = cnt;
    return;
}

//binary search ans, bfs check if it's ok
//is it dandiao?
//it seems like a green prob
//I'll solve it

//����һ�����ܳ�ȥ�Ľ���ʱ�䣬����֮ǰ��ʱ����붼���ܳ�ȥ
//����һ���ܳ�ȥ�Ľ���ʱ�䣬����֮���ʱ�������ܱ�����
//����һ���ܳ�ȥ�Ľ���ʱ�䣬����֮ǰ��ʱ�����Ҳ���ܱ�����
//���Ƕ���һ���ܳ�ȥ�Ľ���ʱ�䣬������ȥ��ʱ��֮�������Բ���
//�������ǿ����ȶ���һ������ʱ�䣬ʹ�����ǵ�һ���ܳ�ȥ��ʱ��
//Ȼ�����������ȥ��ʱ����Ķ��֣������Ƿ�����·��֮���
//Ȼ��Ϲ���

//���������ǰ���ɶ�·��������ʱ�����ֵ
//��д��������ˣ���ȷ��˭֪����
//���ԼӼ�֦���Ż�������֤ʱ�䣬�������õ�����65pts��
//����û��65����

//���Զ��ִ�Ȼ������ͼ����Ƿ�����
//��̫��
//��ô���ǲ�Ҫʣ�µķ����ˣ���ʼ���֮ǰ����ȷ������AC

int n, m, k;

int ans = 100000000000;
struct node
{
    int x, a, t;//��ǰ�����a���ֵ������ʱ��
    bool operator <(const node &y)const
    {
        return t > y.t;
    }
};

queue <node> q;

int T = clock();

void bfs()
{
    node x;
    x.x = 1, x.a = 0, x.t = 0;
    q.push(x);
    int t = 0, i = 0;
    while(!q.empty())
    {
        i++;
        if(i % 1000 == 0)
        {
            if((clock() - T) / CLOCKS_PER_SEC > 0.9)
            {
                return;
            }
        }
        if(t > 100)return;
        x = q.front();
        q.pop();
        if(x.x == n && x.t % k == 0)
        {
            t++;
            ans = min(ans, ((x.a - 1) / k + 1) * k + x.t);
            continue;
        }
        if(x.t > ans)continue;
        //cout << x.x << " " << x.a << " " << x.t << "\n";
        int u = x.x;
        for(int i = h[u];i;i = e[i].nxt)
        {
            int v = e[i].v;
            ////cout << v << "\n\n";
            node nxt;
            nxt.x = v, nxt.a = max(x.a, e[i].t), nxt.t = x.t + 1;
            q.push(nxt);
        }
    }
    return;
}

signed main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    srand(time(0) + 2327);
    n = read(), m = read(), k = read();
    for(int i = 1;i <= m;i++)
    {
        int u = read(), v = read(),t = read();
        addedge(u, v, t);
    }
    bfs();
    cout << ans;
    return 0;
}