#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int N = 3010, M = 3010;
char strs[N][M];

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", strs[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        int p1 = 0;
        bool flag = true;
        for (int j = 0; j < m; ++j)
        {
            int p2 = 0;
            flag = true;
            while (true)
            {
                if (strs[i][p1] > strs[j][p2] ||
                     (p1 == m - 1 && p2 == m - 1 && strs[i][p1] == strs[j][p2]))
                {
                    print("0");
                    flag = false;
                    break;
                }
                else if (strs[i][p1] < strs[j][p2])
                {
                    break;
                }
                // 找到str1最后一个最小的字符
                char minCh1 = 'z' + 1;
                int minPos1 = -1;
                for (int pt = m - 1; pt >= p1; --pt)
                {
                    // 相等也不会改变minCh1=>找到str1最后一个最小的字符
                    if (strs[i][pt] < minCh1)
                    {
                        minCh1 = strs[i][pt];
                        minPos1 = pt;
                    }
                }
                swap(strs[i][p1], strs[i][minPos1]);
                swap(strs[j][p2], strs[j][maxPos2]);
                p1 = minPos1;
                p2 = maxPos2;
            }
            if (!flag)
            {
                break;
            }
        }
        if (flag)
        {
            printf("1");
        }
    }
}
