#include<bits/stdc++.h>
using namespace std;

#define file(filename) freopen(filename ".in", "r", stdin); freopen(filename ".out", "w", stdout)
#define cppio ios::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define rep(i, b, e) for(register int i(b); i<=(e); ++i)
#define re(i, b, e) for(register int i(b); i<(e); ++i)

/*
枚举所有密码可能（？
10*10*10*10*10......
对于每一个判断：
2^5=32, 100
*/

struct pwd
{
    vector<int> a;

    pwd() {a.resize(5);}
    pwd(int* a_)
    {
        a.resize(5);
        re(i, 0, 5) a[i] = a_[i];
    }
    pwd(const vector<int>& o): a(o) {}

    inline void normalize()
    {
        rep(i, 0, 4) a[i] = (a[i]%10+10)%10;
    }

    inline pwd operator+(const pwd& o) const
    {
        pwd res(*this);
        rep(i, 0, 4) res.a[i] += o.a[i];
        res.normalize();
        return res;
    }

    inline pwd operator-() const
    {
        pwd res(*this);
        rep(i, 0, 4) res.a[i] = 10-res.a[i];
        return res;
    }

    inline void input()
    {
        cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
    }

    inline void dbgOut()
    {
        cout << "Debug:  " << a[0] << '\t' << a[1] << '\t' << a[2] << '\t' << a[3] << '\t' << a[4];
    }
};

pwd inputs[13];

set<vector<int> > s, edis;
bitset<117> cnts;

vector<pwd> edits;
inline void prepare()
{
    register int tmp[5] = {0};
    re(i, 0, 5)
    {
        for(int t = 1; t<10; ++t)
        {
            tmp[i] = t;
            edits.emplace_back(tmp);
            // tmp[i] = -t;
            // edits.emplace_back(tmp);
        }
        
        tmp[i] = 0;
    }
    re(i, 0, 4)
    {
        for(int t = 1; t<10; ++t)
        {
            tmp[i] = tmp[i+1] = t;
            edits.emplace_back(tmp);
            // tmp[i] = tmp[i+1] = -t;
            // edits.emplace_back(tmp);
        }
        
        tmp[i] = tmp[i+1] = 0;
    }

    for(auto x: edits)
    {
        edis.insert(x.a);
    }
}
inline void prepareDbg()
{
    for(auto x: edits)
    {
        x.dbgOut();
        cout << endl;
    }

    cout << edits.size() << endl;
}

namespace sol
{
    inline void soln1(set<vector<int> > *s, int idx = 1)
    {
        int inde = 0;
        for(auto x: edits)
        {
            s->insert((x+inputs[idx]).a);
            cnts[inde++] = 1;
        }
    }

    inline void sol(int idx)
    {
        int inde = 0;
        for(auto x: s)// x: vector<int>
        {
            inde ++ ;
            register pwd tmp(x);
            tmp = -tmp;
            tmp = tmp + inputs[idx];
            // tmp.dbgOut(); cout << endl;
            if(edis.count(tmp.a)) continue;
            cnts[inde-1] = 0;
        }
    }
}

signed main()
{
    file("lock");
    cppio;

    prepare();
    // prepareDbg();
    int n;
    cin >> n;
    rep(i, 1, n) inputs[i].input();
    if(n == 1)
    {
        sol::soln1(&s);
        cout << cnts.count() << endl;
    }
    else
    {
        sol::soln1(&s);
        for(auto x: s)
        {
            rep(i, 2, n) if(x == inputs[i].a) cnts[i] = 0;
        }
        rep(i, 2, n) sol::sol(i);
        cout << cnts.count() << endl;
    }
    return 0;
}
