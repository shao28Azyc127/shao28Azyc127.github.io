// 2023/10/21 18:15
// By Jerry1031
// 40 pts?
#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define BYTE 1
#define SHORT 2
#define INT 4
#define LONG 8

struct Member
{
    string name;
    string type;
    long long sz;
    long long from, to;
} a[110];

struct Struct
{
    string name;
    vector<Member> members;
    int membercnt;
    long long sz, maxmembersz;
    long long from, to;
} b[110];

map<string, long long> mp1; // 名称 -> 地址
map<long long, string> mp2; // 地址 -> 名称

int n = 0;

void solve1()
{
    n++;
    cin >> b[n].name >> b[n].membercnt;
    long long nowsz = 0;
    b[n].members.push_back(Member{});
    for(int i = 1; i <= b[n].membercnt; i++)
    {
        Member t;
        cin >> t.type >> t.name;
        t.name = b[n].name + "." + t.name;
        b[n].members.push_back(t);
        if(b[n].members[i].type == "byte")
            b[n].members[i].sz = BYTE;
        if(b[n].members[i].type == "short")
            b[n].members[i].sz = SHORT;
        if(b[n].members[i].type == "int")
            b[n].members[i].sz = INT;
        if(b[n].members[i].type == "long")
            b[n].members[i].sz = LONG;

        b[n].maxmembersz = max(b[n].maxmembersz, b[n].members[i].sz);
        b[n].members[i].from = (i == 1 ? 0 : (b[n].members[i - 1].to / b[n].members[i].sz + 1) * b[n].members[i].sz);
        b[n].members[i].to = b[n].members[i].from + b[n].members[i].sz - 1;
    }

    b[n].sz = a[n].sz = (b[n].members.back().to / b[n].maxmembersz + 1) * b[n].maxmembersz;

    b[n].from = a[n].from = (n == 1 ? 0 : (a[n - 1].to / b[n].maxmembersz + 1) * b[n].maxmembersz);


    b[n].to = a[n].to = b[n].from + b[n].sz - 1;


    mp1[b[n].name] = b[n].from;

    for(int i = 1; i <= b[n].membercnt; i++)
    {
        b[n].members[i].from += b[n].from;
        b[n].members[i].to += b[n].from;

        mp1[b[n].members[i].name] = b[n].members[i].from;

        for(long long j = b[n].members[i].from; j <= b[n].members[i].to; j++)
            mp2[j] = b[n].members[i].name;
    }

    cout << b[n].sz << " " << b[n].maxmembersz << endl;

}

void solve2()
{
    n++;
    cin >> a[n].type >> a[n].name;

    if(a[n].type == "byte")
        a[n].sz = BYTE;
    if(a[n].type == "short")
        a[n].sz = SHORT;
    if(a[n].type == "int")
        a[n].sz = INT;
    if(a[n].type == "long")
        a[n].sz = LONG;

    a[n].from = (n == 1 ? 0 : (a[n - 1].to / a[n].sz + 1) * a[n].sz);
    a[n].to = a[n].from + a[n].sz - 1;

    mp1[a[n].name] = a[n].from;
    for(long long i = a[n].from; i <= a[n].to; i++)
        mp2[i] = a[n].name;

    cout << a[n].from << endl;
}

void solve3()
{
    string s;
    cin >> s;
    cout << mp1[s] << endl;
}

void solve4()
{
    long long t;
    cin >> t;
    if(mp2[t] == "")
        cout << "ERR" << endl;
    else
        cout << mp2[t] << endl;
}

int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--)
    {
        int op;
        cin >> op;
        if(op == 1)
            solve1();
        if(op == 2)
            solve2();
        if(op == 3)
            solve3();
        if(op == 4)
            solve4();
    }
    return 0;
}
