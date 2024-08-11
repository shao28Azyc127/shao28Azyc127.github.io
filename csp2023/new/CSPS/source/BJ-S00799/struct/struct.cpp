#ifdef OJ
#include <iostream>
#else
#include <fstream>
#endif
#include <vector>
#include <map>
#include <string>
#include <queue>
#define ulli unsigned long long int

using namespace std;

#ifndef OJ
ifstream cin("struct.in");
ofstream cout("struct.out");
#endif

struct stru
{
    vector<ulli> memsz, ps;
    map<string, int> tom;
    map<string, string> as;
    ulli tot, srt;
    ulli get(string mem)
    {
        return memsz[tom[mem]];
    }
    ulli getps(string mem)
    {
        return ps[tom[mem]];
    }
    string mmb(string mem)
    {
        return as[mem];
    }
    void add(string type, string name, stru wis)
    {
        as[name] = type;
        tom[name] = memsz.size();
        memsz.push_back(wis.tot);
        if(ps.empty())
        {
            ps.push_back(0);
        }
        else ps.push_back(ps[ps.size()-1] + memsz[memsz.size()-1]);
        srt = max(srt, wis.srt);
    }
    stru()
    {
        memsz.clear();
        tom.clear();
        as.clear();
        tot = srt = 0;
    }
};

map<string, stru> strs;

vector<string> memo;
vector<ulli> strtp;
map<string, int> memm;

int n, op, ui;
string ua, ub, uc;

queue<string> split(string st)
{
    int i, pre;
    pre = 0;
    queue<string> ret;
    while(pre < st.size())
    {
        i = 0;
        while(pre+i < st.size(), st[i+pre] != '.') i++;
        ret.push(st.substr(pre, i));
        pre = pre+i+1;
    }
    return ret;
}

ulli dif(stru parn, queue<string> nw)
{
    if(nw.size() == 1)
    {
        return parn.getps(nw.front());
    }
    ulli nenn = parn.getps(nw.front());
    stru nextp = strs[parn.as[nw.front()]];
    nw.pop();
    return nenn + dif(nextp, nw);
}

int main(int argc, char **argv)
{
    cin >> n;
    {
        stru tmp;
        tmp.tot = 1,
        tmp.srt = 1;
        strs["byte"] = tmp;
        tmp.tot = 2,
        tmp.srt = 2;
        strs["short"] = tmp;
        tmp.tot = 4,
        tmp.srt = 4;
        strs["int"] = tmp;
        tmp.tot = 8,
        tmp.srt = 8;
        strs["byte"] = tmp;
    }
    while(n--)
    {
        cin >> op;
        if(op == 1)
        {
            cin >> ua >> ui;
            stru tmp;
            for(int i = 0; i < ui; i++)
            {
                cin >> ub >> uc;
                tmp.add(ub, uc, strs[ub]);
            }
            strs[ua] = tmp;
        }
        else if(op == 2)
        {
            cin >> ua >> ub;
            memm[ub] = memo.size();
            memo.push_back(ua);
            if(strtp.empty())
            {
                strtp.push_back(strs[ua].srt);
            }
            else
            {
                stru tmp = strs[ua];
                strtp.push_back(strtp[strtp.size()-1]+(tmp.srt-strtp[strtp.size()-1]%tmp.srt)%tmp.srt);
            }
        }
        else if(op == 3)
        {
            cin >> ua;
            queue<string> path = split(ua);
            int endn = memm[path.front()];
            ulli res = strtp[endn];
            path.pop();
            cout << res + dif(strs[memo[endn]], path);
        }
    }
    return 0;
}