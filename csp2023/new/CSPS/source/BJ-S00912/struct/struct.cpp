#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Type
{
    int msize;
    string type, s;
    vector<Type> p;
    Type() {}
    Type(string t, string _s)
    {
        type = t;
        s = _s;
    }
};

struct Num
{
    string type, s;
    int begin, end;
    vector<Num> p;
    Num() {}
    Num(string t, string _s, int b, int e)
    {
        type = t;
        s = _s;
        begin = b;
        end = e;
    }
};

int n, op, k, tot1, tot2, adr;
string basic[4] = {"byte", "short", "int", "long"};
Type type[100];
Num num[10000];
map<string, long long> size;

bool in(string t)
{
    for (int i = 0; i < 4; i++)
    {
        if (t == basic[i])
        {
            return true;
        }
    }
    return false;
}

int find1(string t)
{
    for (int i = 0; ; i++)
    {
        if (type[i].s == t)
        {
            return i;
        }
    }
}

Num add(string t, string s, int msize)
{
    if (in(t))
    {
        if (msize == 0)
        {
            adr += size[t];
            return Num(t, s, adr - size[t], adr - 1);
        }
        else
        {
            adr += msize;
            return Num(t, s, adr - msize, adr - 1);
        }
    }
    else
    {
        Num ans;
        if (msize == 0)
        {
            ans = Num(t, s, adr, adr + size[t] - 1);
        }
        else
        {
            ans = Num(t, s, adr, adr + msize - 1);
        }
        int x = find1(t);
        for (int i = 0; i < type[x].p.size(); i++)
        {
            ans.p.push_back(add(type[x].p[i].type, type[x].p[i].s, type[x].msize));
        }
        adr = ans.end + 1;
        return ans;
    }
}

int find2(string s)
{
    for (int i = 0; ; i++)
    {
        if (num[i].s == s)
        {
            return i;
        }
    }
}

int find3(vector<Num> num1, string s)
{
    for (int i = 0; ; i++)
    {
        if (num1[i].s == s)
        {
            return i;
        }
    }
}

bool find4(vector<Num> num1, int x)
{
    for (int i = 0; i < num1.size(); i++)
    {
        if (num1[i].begin <= x && num1[i].end >= x)
        {
            if (in(num1[i].type))
            {
                return true;
            }
            else
            {
                return find4(num1[i].p, x);
            }
        }
    }
    return false;
}

bool find5(int x)
{
    for (int i = 0; i < tot2; i++)
    {
        if (num[i].begin <= x && num[i].end >= x)
        {
            if (in(num[i].type))
            {
                return true;
            }
            else
            {
                return find4(num[i].p, x);
            }
        }
    }
    return false;
}

bool print4(vector<Num> num1, int x)
{
    for (int i = 0; i < num1.size(); i++)
    {
        if (num1[i].begin <= x && num1[i].end >= x)
        {
            if (in(num1[i].type))
            {
                cout << num1[i].s;
            }
            else
            {
                cout << num1[i].s << '.';
                print4(num1[i].p, x);
            }
        }
    }
    return false;
}

bool print5(int x)
{
    for (int i = 0; i < tot2; i++)
    {
        if (num[i].begin <= x && num[i].end >= x)
        {
            if (in(num[i].type))
            {
                cout << num[i].s;
            }
            else
            {
                cout << num[i].s << '.';
                print4(num[i].p, x);
            }
        }
    }
    return false;
}

int main(void)
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);

    size["byte"] = 1;
    size["short"] = 2;
    size["int"] = 4;
    size["long"] = 8;

    cin >> n;
    while (n--)
    {
        cin >> op;
        switch (op)
        {
            case 1:
            {
                long long msize = 0, totsize = 0, length;
                cin >> type[tot1].s >> k;
                for (int i = 0; i < k; i++)
                {
                    string t, n;
                    cin >> t >> n;
                    type[tot1].p.push_back(Type(t, n));
                    msize = max(msize, size[t]);
                    totsize += size[t];
                }
                type[tot1].msize = msize;

                if (msize == 0)
                {
                    length = 0;
                }
                else if (totsize % msize == 0)
                {
                    length = totsize;
                }
                else
                {
                    length = msize * (totsize / msize + 1);
                }
                cout << length << " " << msize << endl;
                size[type[tot1].s] = length;
                tot1++;
                break;
            }

            case 2:
            {
                cout << adr << endl;
                string t, s;
                cin >> t >> s;
                num[tot2++] = add(t, s, 0);
                break;
            }

            case 3:
            {
                string s;
                cin >> s;
                int x = 0, y = s.find('.');
                if (y != -1)
                {
                    Num now;
                    now = num[find2(s.substr(x, y))];
                    x = y + 1;
                    while (true)
                    {
                        y = s.find('.', x);
                        if (y != -1)
                        {
                            now = now.p[find3(now.p, s.substr(x, y - x))];
                            x = y + 1;
                        }
                        else
                        {
                            cout << now.p[find3(now.p, s.substr(x, s.length() - x))].begin << endl;
                            break;
                        }
                    }
                }
                else
                {
                    cout << num[find2(s)].begin << endl;
                }
                break;
            }

            case 4:
            {
                int addr;
                cin >> addr;
                if (find5(addr))
                {
                    print5(addr);
                    cout << endl;
                }
                else
                {
                    cout << "ERR" << endl;
                }
            }
        }
    }

    return 0;
}
