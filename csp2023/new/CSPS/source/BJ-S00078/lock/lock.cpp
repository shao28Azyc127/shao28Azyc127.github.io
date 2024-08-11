#include <iostream>
using namespace std;
int a[110][110];
int d[110];
int main()
{
    freopen("lock.in" , "r" , stdin);
    freopen("lock.out" , "w" , stdout);
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
    {
        for(int j = 1 ; j <= 5 ; j ++)
        {
            cin >> a[i][j];
        }
    }
    //1
    long long cnt = 0;
        for(int i1 = 0 ; i1 <= 9 ; i1 ++)
        {
            for(int i2 = 0 ; i2 <= 9 ; i2 ++)
            {
                for(int i3 = 0 ; i3 <= 9 ; i3 ++)
                {
                    for(int i4 = 0 ; i4 <= 9 ; i4 ++)
                    {
                        for(int i5 = 0 ; i5 <= 9 ; i5 ++)
                        {
                            d[1] = i1;
                            d[2] = i2;
                            d[3] = i3;
                            d[4] = i4;
                            d[5] = i5;
                            for(int h = 1 ; h <= 9 ; h ++)
                            {
                                bool flag = true;
                                int f = 0;
                                for(int i = 1 ; i <= n ; i ++)
                                {
                                    bool is = true;
                                    bool is2 = false;
                                    for(int k = 1 ; k <= 5 ; k ++)
                                    {
                                            is = true;
                                            int x = a[i][k];
                                            a[i][k] += h;
                                            a[i][k] %= 10;
                                            for(int j = 1 ; j <= 5 ; j ++)
                                            {
                                                if(d[j] != a[i][j])
                                                {
                                                    is = false;
                                                    break;
                                                }
                                            }
                                            a[i][k] = x;
                                            if(is == true)
                                            {
                                                is2 = true;
                                                break;
                                            }
                                    }
                                    if(is2 == true)
                                    {
                                        f ++;
                                    }
                                }
                                if(f == n)
                                {
                                    cnt ++;
                                    for(int j = 1 ; j <= 5 ; j ++)
                                    {
                                        //cout << d[j] << " ";
                                    }
                                    //cout << endl;
                                }

                                /*for(int i = 1 ; i <= n ; i ++)
                                {
                                    bool is = true;
                                    is2 = true;
                                    for(int k = 1 ; k <= 5 ; k ++)
                                    {
                                        is = true;
                                        int x = d[k];
                                        d[k] -= h;
                                        d[k] += 10;
                                        d[k] %= 10;

                                        for(int j = 1 ; j <= 5 ; j ++)
                                        {
                                            if(d[j] != a[i][j])
                                            {
                                                is = false;
                                                break;
                                            }
                                        }
                                        d[k] = x;
                                        if(is == true)
                                        {
                                            break;
                                        }
                                    }
                                    if(is == false)
                                    {
                                        is2 = false;
                                        break;
                                    }
                                }
                                if(is2 == true)
                                {
                                    cnt ++;
                                    for(int j = 1 ; j <= 5 ; j ++)
                                    {
                                        //cout << d[j] << " ";
                                    }
                                    //cout << endl;
                                }*/
                            }

                        }
                    }
                }
            }
        }
    //cout << cnt<< endl;
    long long cnt2 = 0;
    for(int i1 = 0 ; i1 <= 9 ; i1 ++)
        {
            for(int i2 = 0 ; i2 <= 9 ; i2 ++)
            {
                for(int i3 = 0 ; i3 <= 9 ; i3 ++)
                {
                    for(int i4 = 0 ; i4 <= 9 ; i4 ++)
                    {
                        for(int i5 = 0 ; i5 <= 9 ; i5 ++)
                        {
                            d[1] = i1;
                            d[2] = i2;
                            d[3] = i3;
                            d[4] = i4;
                            d[5] = i5;
                            for(int h = 1 ; h <= 9 ; h ++)
                            {
                                bool flag = true , is2 = true;
                                for(int i = 1 ; i <= n ; i ++)
                                {
                                    bool is = true;
                                    is2 = true;
                                    int f = 0;
                                    for(int k = 1 ; k < 5 ; k ++)
                                    {
                                            is = true;
                                            int x = a[i][k];
                                            int y = a[i][k + 1];
                                            a[i][k] += h;
                                            a[i][k + 1] += h;
                                            a[i][k] %= 10;
                                            a[i][k + 1] %= 10;
                                            for(int j = 1 ; j <= 5 ; j ++)
                                            {
                                                if(d[j] != a[i][j])
                                                {
                                                    is = false;
                                                    break;
                                                }
                                            }
                                            a[i][k] = x;
                                            a[i][k + 1] = y;
                                            if(is == true)
                                            {
                                                f ++;
                                            }
                                    }
                                    if(f == 0)
                                    {
                                        is2 = false;
                                        break;
                                    }/*
                                    for(int k = 1 ; k < 5 ; k ++)
                                    {
                                            is = true;
                                            int x = d[k];
                                            int y = d[k + 1];
                                            d[k] -= h;
                                            d[k + 1] -= h;
                                            d[k] += 10;
                                            d[k] %= 10;
                                            d[k + 1] += 10;
                                            d[k + 1] %= 10;
                                            for(int j = 1 ; j <= 5 ; j ++)
                                            {
                                                if(d[j] != a[i][j])
                                                {
                                                    is = false;
                                                    break;
                                                }
                                            }
                                            a[i][k] = x;
                                            a[i][k + 1] = y;
                                            if(is == true)
                                            {
                                                f ++;
                                            }

                                    }
                                    if(f == 0)
                                    {
                                        is2 = false;
                                        break;
                                    }*/
                                }
                                if(is2 == true)
                                {
                                    cnt2 ++;
                                    for(int j = 1 ; j <= 5 ; j ++)
                                    {
                                        //cout << d[j] << " ";
                                    }
                                    //cout << endl;
                                }
                                /*for(int i = 1 ; i <= n ; i ++)
                                {
                                    bool is = true;
                                    is2 = true;
                                    for(int k = 1 ; k <= 5 ; k ++)
                                    {
                                        is = true;
                                        int x = d[k];
                                        d[k] -= h;
                                        d[k] += 10;
                                        d[k] %= 10;

                                        for(int j = 1 ; j <= 5 ; j ++)
                                        {
                                            if(d[j] != a[i][j])
                                            {
                                                is = false;
                                                break;
                                            }
                                        }
                                        d[k] = x;
                                        if(is == true)
                                        {
                                            break;
                                        }
                                    }
                                    if(is == false)
                                    {
                                        is2 = false;
                                        break;
                                    }
                                }
                                if(is2 == true)
                                {
                                    cnt ++;
                                    for(int j = 1 ; j <= 5 ; j ++)
                                    {
                                        //cout << d[j] << " ";
                                    }
                                    //cout << endl;
                                }*/
                            }
                        }
                    }
                }
            }
        }
        /*
        /*for(int i1 = 0 ; i1 <= 9 ; i1 ++)
        {
            for(int i2 = 0 ; i2 <= 9 ; i2 ++)
            {
                for(int i3 = 0 ; i3 <= 9 ; i3 ++)
                {
                    for(int i4 = 0 ; i4 <= 9 ; i4 ++)
                    {
                        for(int i5 = 0 ; i5 <= 9 ; i5 ++)
                        {
                            d[1] = i1;
                            d[2] = i2;
                            d[3] = i3;
                            d[4] = i4;
                            d[5] = i5;
                            for(int h = 1 ; h <= 9 ; h ++)
                            {
                                bool flag = true , is2 = true;
                                for(int i = 1 ; i <= n ; i ++)
                                {
                                    bool is = true;
                                    is2 = true;
                                    for(int k = 1 ; k < 5 ; k ++)
                                    {
                                        is = true;
                                        int x = a[i][k];
                                        int y = a[i][k + 1];
                                        a[i][k] += h;
                                        a[i][k + 1] += h;
                                        a[i][k] %= 10;
                                        a[i][k + 1] %= 10;
                                        for(int j = 1 ; j <= 5 ; j ++)
                                        {
                                            if(d[j] != a[i][j])
                                            {
                                                is = false;
                                                break;
                                            }
                                        }
                                        a[i][k] = x;
                                        a[i][k + 1] = y;
                                        if(is == true)
                                        {
                                            break;
                                        }
                                    }
                                    if(is == false)
                                    {
                                        is2 = false;
                                        break;
                                    }
                                }
                                if(is2 == true)
                                {
                                    cnt2 ++;
                                    for(int j = 1 ; j <= 5 ; j ++)
                                    {
                                        //cout << d[j] << " ";
                                    }
                                    //cout << endl;
                                }
                                /*for(int i = 1 ; i <= n ; i ++)
                                {
                                    bool is = true;
                                    is2 = true;
                                    for(int k = 1 ; k <= 5 ; k ++)
                                    {
                                        is = true;
                                        int x = d[k];
                                        int y = d[k + 1];
                                        d[k] -= h;
                                        d[k + 1] -= h;
                                        d[k] += 10;
                                        d[k] %= 10;
                                        d[k + 1] += 10;
                                        d[k + 1] %= 10;
                                        for(int j = 1 ; j <= 5 ; j ++)
                                        {
                                            if(d[j] != a[i][j])
                                            {
                                                is = false;
                                                break;
                                            }
                                        }
                                        d[k] = x;
                                        if(is == true)
                                        {
                                            break;
                                        }
                                    }
                                    if(is == false)
                                    {
                                        is2 = false;
                                        break;
                                    }
                                }
                                if(is2 == true)
                                {
                                    cnt2 ++;
                                    for(int j = 1 ; j <= 5 ; j ++)
                                    {
                                        //cout << d[j] << " ";
                                    }
                                    //cout << endl;
                                }
                            }
                        }
                    }
                }
            }
        }*/
    //cout << cnt2 << endl;
    cout << cnt + cnt2 << endl;
    return 0;
}
