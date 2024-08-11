#include <bits/stdc++.h>

using namespace std;
const int N = 8e6 + 10, M = 110, sz[4] = {1, 2, 4, 8};
string st[M], stdd[4];
int n, szsz[M], c[M], v[N], lst = -1, cnt, fa[N], yq[M], tp[M][M], idx[M][M]; //geshu mingzi fujiegouti yaoqiu type id
string stst[M * M];
map <string, int> mp, mp2, mp3; //jiegouti jiben qishidizhi

int ins(int tp, int yq, int fat, int id) //dqyq
{
    lst++;
    while(lst % yq) lst++;
    int res = lst;
    for(int i = lst; i < lst + sz[tp]; i++)
    {
        v[i] = id, fa[i] = fat;
    }
    lst = lst + sz[tp] - 1;
    return res;
}

int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    memset(v, -1, sizeof(v));
    stdd[0] = "byte", stdd[1] = "short", stdd[2] = "int", stdd[3] = "long";
    mp2[stdd[0]] = 0, mp2[stdd[1]] = 1, mp2[stdd[2]] = 2, mp2[stdd[3]] = 3;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int op;
        scanf("%d", &op);
        if(op == 1)
        {
            cin >> st[i];
            mp[st[i]] = i;
            int k;
            scanf("%d", &k);
            c[i] = k;
            for(int j = 1; j <= k; j++)
            {
                string sss;
                cin >> sss >> stst[++cnt];
                tp[i][j] = mp2[sss];
                idx[i][j] = cnt;
                yq[i] = max(yq[i], sz[tp[i][j]]);
            }
            int llst = lst;
            int st = ins(tp[i][1], yq[i], i, idx[i][1]);
            for(int j = 2; j <= c[i]; j++)
            {
                ins(tp[i][j], sz[tp[i][j]], i, idx[i][j]);
            }
            szsz[i] = lst - st + 1;
            while(szsz[i] % yq[i]) szsz[i]++;
            printf("%d %d\n", szsz[i], yq[i]);
            for(int i = llst; i <= lst; i++) v[i] = fa[i] = 0;
            lst = llst;
        }
        else if(op == 2)
        {
            string s1;
            cin >> s1 >> stst[++cnt];
            int res;
            if(mp2.count(s1))
            {
                res = ins(mp2[s1], sz[mp2[s1]], 0, cnt);
                mp3[stst[cnt]] = res;
            }
            else
            {
                int id = mp[s1];
                int llst = lst;
                res = ins(tp[id][1], yq[id], id, idx[id][1]);
                mp3[st[id] + "." + stst[idx[id][1]]] = res;
                for(int j = 2; j <= c[id]; j++)
                {
                    mp3[st[id] + "." + stst[idx[id][j]]] = ins(tp[id][j], sz[tp[id][j]], id, idx[id][j]);
                }
                llst++;
                while(llst % yq[id]) llst++;
                llst += szsz[id];
                llst--;
                lst = llst;
            }
            printf("%d\n", res);
        }
        else if(op == 3)
        {
            string s;
            cin >> s;
            printf("%d\n", mp3[s]);
        }
        else if(op == 4)
        {
            int addr;
            scanf("%d", &addr);
            if(v[addr] == -1)
            {
                puts("ERR");
            }
            else
            {
                if(fa[addr])
                {
                    cout << st[fa[addr]] << "." << stst[v[addr]];
                }
                else
                {
                    cout << stst[v[addr]];
                }
                cout << endl;
            }
        }
    }
    return 0;
}
