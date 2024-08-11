#include<bits/stdc++.h>
using namespace std;

#define file(filename) freopen(filename ".in", "r", stdin); freopen(filename ".out", "w", stdout)
#define cppio ios::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define rep(i, b, e) for(register int i(b); i<=(e); ++i)
#define re(i, b, e) for(register int i(b); i<(e); ++i)

constexpr int maxn = 1e5 + 17;
int a[maxn], b[maxn], c[maxn];

vector<int> gph[maxn];

bool xingZhiA = true, xingZhiB = true, xingZhiC = true, xingZhiD = true;

int n;

inline void inputs()
{
    for(int i=1; i<=n; ++i)
    {
        cin >> a[i] >> b[i] >> c[i];
        if(c != 0) xingZhiA = false;
    }
    for(int i=1; i<n; ++i)
    {
        int u, v;
        cin >> u >> v;
        if(u != i || v != i+1) xingZhiB = false;
        if(u != 1) xingZhiD = false;
        gph[u].emplace_back(v);
        gph[v].emplace_back(u);
    }
    for(int i=1; i<=n; ++i)
    {
        if(gph[i].size() > 2) xingZhiC = false;
    }
}

namespace prepare
{
    bool canFind = false;
    namespace cBig0
    {
        bool chk(int i, int begDays, int allDays)
        {
            return (1ll*allDays*(allDays+1) - 1ll*begDays*(begDays-1))/2*c[i] + (allDays-begDays+1)*b[i] >= a[i];
        }

        inline int binarySearch(int i, int allDays)
        {
            int l = 0, r = allDays, mid;
            while(l+1 != r)
            {
                if(r == 0)
                {
                    canFind = false, break;
                }
                mid = l+r>>1;
                if(chk(i, mid, allDays))
                {
                    canFind = true;
                    r = mid;
                }else
                {
                    l = mid;
                }
            }
            return mid;
        }
    }
    namespace cSmall0
    {
        bool chk(int i, int begDays, int allDays)
        {
            register int tmp = (1-b[i])/c[i];
            if(tmp >= allDays)
            {
                return (1ll*allDays*(allDays+1) - 1ll*begDays*(begDays-1))/2*c[i] + (allDays-begDays+1)*b[i] >= a[i];
            }
            else if(begDays > tmp)
            {
                return (allDays-begDays+1) >= a[i];
            }
            else
            {
                // begDays <= tmp < allDays
                return (
                        (1ll*tmp*(tmp+1) - 1ll*begDays*(begDays-1))/2*c[i] + (tmp-begDays+1)*b[i]
                        + (allDays-tmp)
                        ) >= a[i];
            }
        }

        inline int binarySearch(int i, int allDays)
        {
            int l = 0, r = allDays, mid;

            while(l+1 != r)
            {
                if(r == 0)
                {
                    canFind = false, break;
                }
                mid = l+r>>1;
                if(chk(i, mid, allDays))
                {
                    canFind = true;
                    r = mid;
                }else
                {
                    l = mid;
                }
            }
            return mid;
        }
    }

    int lastDays[maxn];// 最小开始种植的日期
    bool isOk = true;
    inline void prepare(int allDays)// 考虑共 allDays 天完成任务
    {
        for(int i=1; i<=n; ++i)
        {
            canFind = false;
            if(c[i] > 0)
            {
                lastDays[i] = cBig0::binarySearch(i, allDays);
            }
            else if(c[i] < 0)
            {
                lastDays[i] = cSmall0::binarySearch(i, allDays);
            }
            else // c[i] == 0
            {
                lastDays[i] = allDays-(a[i]+b[i]-1)/b[i]+1;
            }
            if(lastDays[i] < 0 || !canFind) isOk = false;
        }
    }
}

namespace gphPre
{
    int fa[maxn], dep[maxn];
    void dfs(int u, int fat, int deep)
    {
        dep[u] = deep, fa[u] = fat;
        for(auto x: gph[u])
        {
            if(x == fa) continue;
            dfs(x, u, deep+1);
        }
    }
}

namespace sol20
{
    bitset<maxn> booked;
    bool chk(int days)
    {
        booked.reset();
        prepare::prepare(days);
        if(prepare::isOk == false) return false;

        for(int i=1; i<=n; ++i)
        {
            int mini = 1e9, miniNod = 0;

        }
    }

    inline void binarySearch()
    {
        int l = n-1, r = 1e9, mid;
        // 区间: [l+1, r], 答案考虑为最后区间仅仅剩下的一个点 l+1==r
        while(l+1 != r)
        {
            mid = l+r>>1;
            if(chk(mid))// 如果 mid 天可以: 答案在区间 [l+1, mid]
            {
                r = mid;
            }else // mid 天不可以，答案在区间 [mid+1, r]
            {
                l = mid;
            }
            // cout << mid << ' ' << l << ' ' << r << endl;
        }
        cout << mid << endl;
    }
}
namespace sol500
{
    bool chk(int days)
    {

    }

    inline void binarySearch()
    {
        int l = n-1, r = 1e9, mid;
        // 区间: [l+1, r], 答案考虑为最后区间仅仅剩下的一个点 l+1==r
        while(l+1 != r)
        {
            mid = l+r>>1;
            if(chk(mid))// 如果 mid 天可以: 答案在区间 [l+1, mid]
            {
                r = mid;
            }else // mid 天不可以，答案在区间 [mid+1, r]
            {
                l = mid;
            }
            // cout << mid << ' ' << l << ' ' << r << endl;
        }
        cout << mid << endl;
    }
}
namespace sol1e5
{
    namespace xingZhiA
    {
        bool chk(int days)
        {

        }

        inline void binarySearch()
        {
            int l = n-1, r = 1e9, mid;
            // 区间: [l+1, r], 答案考虑为最后区间仅仅剩下的一个点 l+1==r
            while(l+1 != r)
            {
                mid = l+r>>1;
                if(chk(mid))// 如果 mid 天可以: 答案在区间 [l+1, mid]
                {
                    r = mid;
                }else // mid 天不可以，答案在区间 [mid+1, r]
                {
                    l = mid;
                }
                // cout << mid << ' ' << l << ' ' << r << endl;
            }
            cout << mid << endl;
        }
    }
    namespace xingZhiB
    {
        bool chk(int days)
        {
            prepare::prepare(days);
            if(prepare::isOk == false) return false;
            for(int i=1; i<=n; ++i)
            {
                if(prepare::lastDays[i] < gphPre::dep[i]) return false;
            }
            return true;
        }

        inline void binarySearch()
        {
            int l = n-1, r = 1e9, mid;
            // 区间: [l+1, r], 答案考虑为最后区间仅仅剩下的一个点 l+1==r
            while(l+1 != r)
            {
                mid = l+r>>1;
                if(chk(mid))// 如果 mid 天可以: 答案在区间 [l+1, mid]
                {
                    r = mid;
                }else // mid 天不可以，答案在区间 [mid+1, r]
                {
                    l = mid;
                }
                // cout << mid << ' ' << l << ' ' << r << endl;
            }
            cout << mid << endl;
        }
    }
    namespace xingZhiC
    {
        bool chk(int days)
        {

        }

        inline void binarySearch()
        {
            int l = n-1, r = 1e9, mid;
            // 区间: [l+1, r], 答案考虑为最后区间仅仅剩下的一个点 l+1==r
            while(l+1 != r)
            {
                mid = l+r>>1;
                if(chk(mid))// 如果 mid 天可以: 答案在区间 [l+1, mid]
                {
                    r = mid;
                }else // mid 天不可以，答案在区间 [mid+1, r]
                {
                    l = mid;
                }
                // cout << mid << ' ' << l << ' ' << r << endl;
            }
            cout << mid << endl;
        }
    }
    namespace xingZhiD
    {
        bool chk(int days)
        {
            prepare::prepare(days);
            if(prepare::isOk == false) return false;
            return true;
        }

        inline void binarySearch()
        {
            int l = n-1, r = 1e9, mid;
            // 区间: [l+1, r], 答案考虑为最后区间仅仅剩下的一个点 l+1==r
            while(l+1 != r)
            {
                mid = l+r>>1;
                if(chk(mid))// 如果 mid 天可以: 答案在区间 [l+1, mid]
                {
                    r = mid;
                }else // mid 天不可以，答案在区间 [mid+1, r]
                {
                    l = mid;
                }
                // cout << mid << ' ' << l << ' ' << r << endl;
            }
            cout << mid << endl;
        }
    }
}

signed main()
{
file("tree");
    cppio;
    cin >> n;
    inputs();
    gphPre::dfs(1, 0, 1);
    if(n <= 20)
    {
        sol20::binarySearch();
    }
    else if(n <= 500)
    {
        sol500::binarySearch();
    }
    else
    {
        // n: 1e5
        if(xingZhiB)
        {
            sol1e5::xingZhiB::binarySearch();
        }else if(xingZhiD)
        {
            sol1e5::xingZhiD::binarySearch();
        }else if(xingZhiC)
        {
            sol1e5::xingZhiC::binarySearch();
        }
    }
    return 0;
}
