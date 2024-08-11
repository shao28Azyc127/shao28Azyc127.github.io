// 2023/10/21 15:00
// By Jerry1031
//freopen checked!
#include <iostream>
using namespace std;

int n;
int a[10][10], b[10];

#define A a[m]
int difpos[10];
bool check1(int m)
{
    int dif = 0;
    for(int i = 1; i <= 5; i++)
    {
        if(A[i] != b[i])
        {
            dif++;
            difpos[dif] = i;
        }
    }
    if(dif == 0 || dif >= 3)
        return false;
    if(dif == 1)
        return true;

    //dif == 2
    if(difpos[1] + 1 != difpos[2])
        return false;

    if(
       (A[difpos[1]] - b[difpos[1]] + 10) % 10 !=
       (A[difpos[2]] - b[difpos[2]] + 10) % 10)
        return false;
    return true;
}

bool check()
{
    for(int i = 1; i <= n; i++)
        if(!check1(i))
            return false;
    return true;
}

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= 5; j++)
            cin >> a[i][j];

    //if(n == 1)
    //{
    //    cout << 81 << endl;
    //    return 0;
    //}

    int ans = 0;

    for(b[1] = 0; b[1] < 10; b[1]++)
        for(b[2] = 0; b[2] < 10; b[2]++)
            for(b[3] = 0; b[3] < 10; b[3]++)
                for(b[4] = 0; b[4] < 10; b[4]++)
                    for(b[5] = 0; b[5] < 10; b[5]++)
                        if(check())
                            ans++;
    cout << ans << endl;
    return 0;
}
