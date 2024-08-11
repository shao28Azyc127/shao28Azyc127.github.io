#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>

using namespace std;

const int N = 3010, M = 30;
int n, m, b[N][M];
char t[N][N], r[N][N];
string s[N];

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    //cout<<strcmp("axz", "ayz")<<endl;

    cin >> n >> m;
    for (int i = 0; i < n; ++ i )
    {
        cin >> s[i];
        for (int j = 0; j < m; ++ j )
            ++ b[i][s[i][j] - 'a'];
        for (int j = 0, k = 0; j < 26; ++ j )
        {
            for (int l = 0; l < b[i][j]; ++ l )
                t[i][k ++ ] = j + 'a';
        }
        for (int j = 25, k = 0; j >= 0; -- j )
        {
            for (int l = 0; l < b[i][j]; ++ l )
                r[i][k ++ ] = j + 'a';
        }
    }

    for (int i = 0; i < n; ++ i )
    {
        bool flag = 1;
        for (int j = 0; j < n; ++ j )
        {
            if (j != i && strcmp(r[j], t[i]) <= 0)
            {
                flag = 0;
                break;
            }
        }
        printf("%d", flag);
    }
    puts("");

    fclose(stdin);
    fclose(stdout);

    return 0;
}
