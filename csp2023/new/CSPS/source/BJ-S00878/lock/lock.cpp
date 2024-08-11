#include <iostream>

using namespace std;

int n;

int a[10];
char order[8+5][5+5];
int different = 5;


void init_(){
    int flag = 0;
    for (int i=1;i<=5;i++)  // 五个锁圈
    {
        for (int j=0;j<=9;j++) // 9个密码
        {
            flag = 0;
            for (int p=1;p<=n;p++) // n种可能
            {
                if ('1'+j != order[p][i])flag = 1; // 如果可能的密码不和所有的圈的相等
            }
            if (flag == 0) // 如果等于，a的i位就是j
            {
                a[i] = j+1;
                different--;
                continue;
            }
        }
    }


}

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    for (int i=0;i<10;i++)
    {
        a[i] = -1;
    }

    cin >> n;

    if (n == 1)cout << 81;

    else{
        for (int i=1;i<=n;i++)
        {
            cin >> order[i][1] >> order[i][2] >> order[i][3] >> order[i][4] >> order[i][5];
        }

        init_();


        cout << (different*(10-n));

    }





    return 0;
}
