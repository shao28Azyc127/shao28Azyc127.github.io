#include <cstdio>
#include <cstdint>
#include <utility>
#include <tuple>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

#define wzc(f) freopen(f".in", "r", stdin); freopen(f".out", "w", stdout)

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using i128 = __int128_t;
using u128 = __uint128_t;

inline u64 align_to(u64 x, u64 align)
{
    return ((x - 1) | (align - 1)) + 1;
}

struct type
{
    bool atom;
    u64 len, align;
    std::vector<std::tuple<u64, std::string, const type&>> members;
    // {displacement, name, type}

    inline type() : atom(false) {}

    inline type(u64 len) : atom(true), len(len), align(len), members() {}

    inline type(const std::vector<std::pair<std::string, const type&>>& vec) : atom(false)
    {
        members.reserve(vec.size());
        len = align = 0;
        
        for (auto&& [_, t] : vec)
            align = std::max(align, t.align);

        u64 pos = 0;
        for (auto&& [name, t] : vec)
        {
            pos = align_to(pos, t.align);
            members.emplace_back(pos, name, t);
            pos += t.len;
        }
        len = align_to(pos, align);
    }
};

type byte_(1), short_(2), int_(4), long_(8);

struct value
{
    const type* t;
    u64 addr;

    inline value() : t(&byte_), addr(0) {}

    inline value(const type& t, u64 addr) : t(&t), addr(addr) {}

    inline bool operator<(const value& other) const
    {
        return addr < other.addr;
    }
};

int main()
{
    wzc("struct");
    std::map<std::string, value> vals; u64 pos = 0;
    std::map<std::string, type> types;
    types.emplace("byte", byte_);
    types.emplace("short", short_);
    types.emplace("int", int_);
    types.emplace("long", long_);

    int q; scanf("%d", &q);
    while (q--)
    {
        int op; scanf("%d", &op);
        if (op == 1)
        {
            std::string s; int k;
            std::cin >> s; scanf("%d", &k);
            
            std::vector<std::pair<std::string, const type&>> vec;
            vec.reserve(k);
            for (int i = 0; i < k; i++)
            {
                std::string t, n;
                std::cin >> t >> n;
                vec.emplace_back(n, types[t]);
            }
            type t(vec);
            types.emplace(s, t);
            printf("%llu %llu\n", t.len, t.align);
        }
        if (op == 2)
        {
            std::string t, n;
            std::cin >> t >> n;
            type& tt = types[t];
            pos = align_to(pos, tt.align);
            vals.emplace(n, value(tt, pos));
            printf("%llu\n", pos);
            pos += tt.len;
        }
        if (op == 3)
        {
            std::string s;
            std::cin >> s;
            
            const char *p = s.c_str(), *q = p, *end = p + s.size();
            while ((*q) && (*q) != '.')
                q++;
            value vv = vals[std::string(p, q)];
            value& v = vv;

            while (q != end)
            {
                q++;
                p = q;
                while ((*q) && (*q) != '.')
                    q++;
                std::string mem(p, q);

                for (const auto& [disp, name, t] : v.t -> members)
                    if (name == mem)
                        v = value(t, v.addr + disp);
            }

            printf("%llu\n", v.addr);
        }
        if (op == 4)
        {
            u64 addr;
            scanf("%llu", &addr);

            bool ok = false;
            std::string s;
            for (auto&& [key, val] : vals)
                if (val.addr <= addr && addr < val.addr + (val.t -> len))
                {
                    ok = true;
                    s = key;
                    value v = val;
                    while (!(v.t -> atom))
                    {
                        bool found = false;
                        for (const auto& [disp, name, t] : v.t -> members)
                            if (v.addr + disp <= addr &&
                                addr < v.addr + disp + t.len)
                            {
                                s += ".";
                                s += name;
                                v = value(t, v.addr + disp);
                                found = true;
                                break;
                            }
                        if (!found)
                        {
                            ok = false;
                            break;
                        }
                    }
                    if (ok)
                        std::cout << s << '\n';
                    break;
                }
            if (!ok)
                printf("ERR\n");
        }
    }
}