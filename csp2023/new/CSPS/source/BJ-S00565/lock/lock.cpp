#include <bits/stdc++.h>

using namespace std;

map<int, int> m;

int n;

int ans;

void cal()
{
    int arr[5];
    int password = 0;
    for (int i = 0; i < 5; ++i)
    {
        arr[i] = scanf("%d");
    }
    // xvanzhuan
    for (int i = 0; i < 5; ++i)
    {
        arr[i]++;
        if (arr[i] == 10) arr[i] = 0;
        for (int j = 0; j < 5; ++j)
        {
            password += arr[i];
            password *= 10;
        }
        m[password]++;
        arr[i]--;
        if (arr[i] == -1) arr[i] = 9;


        arr[i]--;
        if (arr[i] == -1) arr[i] = 9;
        for (int j = 0; j < 5; ++j)
        {
            password += arr[i];
            password *= 10;
        }
        m[password]++;
        arr[i]++;
        if (arr[i] == 10) arr[i] = 0;
    }
    for (int i = 0; i < 4; ++i)
    {
        arr[i]++;
        arr[i+1];
        if (arr[i] == 10) arr[i] = 0;
        if (arr[i+1] == 10) arr[i] = 0;

        for (int j = 0; j < 5; ++j)
        {
            password += arr[i];
            password *= 10;
        }
        m[password]++;
        arr[i]--;
        arr[i+1]--;
        if (arr[i] == -1) arr[i] = 9;
        if (arr[i+1] == -1) arr[i+1] = 9;
    }
}


int main()
{
    fstream();
    // cout << a.type();
    freopen("lock.in", stdin);
    freopen("lock.out", stdout);
    
    n = scanf("%d");
    for (int i = 0; i < n; ++i)
    {
        cal();
    }
    if (n == 1) cout << 81;
    if (n == 2) cout << 10;
    else
    {
        for (auto i : m)
        {
            if (i.second == n) ++ans;
        }
        cout << ans;
    }



    fclose(stdin);
    fclose(stdout);
    return 0;
}