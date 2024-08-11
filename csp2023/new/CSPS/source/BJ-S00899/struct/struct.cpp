#include<bits/stdc++.h>
using namespace std;
#define LL long long
struct node{
    string s;
    LL siz, K, mx;
    map<string, LL> pos;
    LL id[105];
    string name[105];
}a[110];
LL cnt, sum;
map<string, LL> id;
struct one{
    LL type;
    string name;
    LL st, l;
}x[110];
LL num;
map<string, LL> pos;
int main(){
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    id["byte"] = 1; a[++ cnt].s = "byte"; a[cnt].mx = a[cnt].siz = 1;
    id["short"] = 2; a[++ cnt].s = "short"; a[cnt].mx = a[cnt].siz = 2;
    id["int"] = 3; a[++ cnt].s = "int"; a[cnt].mx = a[cnt].siz = 4;
    id["long"] = 4; a[++ cnt].s = "long"; a[cnt].mx = a[cnt].siz = 8;
    while (n --)
    {
        int opt; cin >> opt;
        if (opt == 1)
        {
            cin >> a[++ cnt].s >> a[cnt].K;
            id[a[cnt].s] = cnt; string type;
            for (int i = 1; i <= a[cnt].K; i ++)
            {
                cin >> type >> a[cnt].name[i];
                a[cnt].pos[a[cnt].name[i]] = i;
                a[cnt].id[i] = id[type];
                a[cnt].mx = max(a[cnt].mx, a[id[type]].mx);
            }
            for (int i = 1; i <= a[cnt].K; i ++)
            {
                LL tmp = a[a[cnt].id[i]].mx;
                a[cnt].siz = (a[cnt].siz + tmp - 1) / tmp * tmp;
                a[cnt].siz += a[a[cnt].id[i]].siz;
            }
            a[cnt].siz = (a[cnt].siz + a[cnt].mx - 1) / a[cnt].mx * a[cnt].mx;
            cout << a[cnt].siz << " " << a[cnt].mx << "\n";
        }
        if (opt == 2)
        {
            string type; cin >> type >> x[++ num].name;
            pos[x[num].name] = num;
            LL i = id[type], tmp = a[i].mx;
            sum = (sum + tmp - 1) / tmp * tmp;
            x[num].st = sum; sum += a[i].siz - 1;
            x[num].l = a[i].siz; x[num].type = id[type];
            cout << x[num].st << "\n";
        }
        if (opt == 3)
        {
            string s; cin >> s;
            if (!s.find('.'))
                cout << x[pos[s]].st << "\n";
            else
            {
                LL i = s.find('.');
                string who = s.substr(0, i), which = s.substr(i + 1, s.size() - i - 1);
                i = pos[who]; LL tmp = x[i].st; i = x[i].type;
                for (LL ii = 1; ii <= a[i].K; ii ++)
                {
                    tmp = (tmp + a[a[i].id[ii]].mx - 1) / a[a[i].id[ii]].mx * a[a[i].id[ii]].mx;
                    if (a[i].name[ii] == which) break;
                    tmp += a[a[i].id[ii]].siz - 1;
                }
                cout << tmp << "\n";
            }
        }
        if (opt == 4)
        {
            LL key; cin >> key;
            LL i; bool flg = 0;
            for (i = 0; i < num; i ++)
                if (x[i + 1].st >= key)
                    break;
            i = min(i, num);
            LL tmp = x[i].st; LL j = i; i = x[i].type;
            if (i <= 4)
            {
                if (key >= tmp && key < x[j].st + x[j].l - 1)
                    cout << x[j].name << "\n";
                else
                    cout << "ERR\n";
                continue;
            }
            for (int ii = 1; ii <= a[i].K; ii ++)
            {
                LL nxt = (tmp + a[a[i].id[ii]].mx - 1) / a[a[i].id[ii]].mx * a[a[i].id[ii]].mx;
                if (key >= tmp && key < nxt)
                {
                    cout << "ERR\n";
                    flg = 1; break;
                }
                if (key < tmp)
                {
                    cout << x[j].name << "." << a[i].name[ii - 1] << "\n";
                    flg = 1; break;
                }
                tmp = nxt + a[a[i].id[ii]].siz - 1;
            }
            if (flg) continue;
            if (key < tmp)
                cout << x[j].name << "." << a[i].name[a[i].K] << "\n";
            else
                cout << "ERR\n";
        }
    }

    return 0;
}
