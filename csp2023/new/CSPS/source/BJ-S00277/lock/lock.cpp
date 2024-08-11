#include <bits/stdc++.h>
using namespace std;

const int max_n=8;
int n;
int status[max_n+1][6];
int password_num;

inline void Input()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=5; ++j) cin>>status[i][j];
}

inline bool Is_password(int para_password)
{
    int digit[6];
    for (int i=1; i<=5; ++i) digit[i]=(int)(para_password/pow(10, 5-i))%10;
    for (int i=1; i<=n; ++i)
    {
        int diff_digit_num=0, diff_digit_id[6];
        for (int j=1; j<=5; ++j) if (digit[j]!=status[i][j]) {diff_digit_id[++diff_digit_num]=j;}
        if (diff_digit_num==1) continue;
        else if (diff_digit_num==2)
        {
            if (abs(diff_digit_id[1]-diff_digit_id[2])==1) 
            {
                int temp_digit_1=digit[diff_digit_id[1]], temp_digit_2=digit[diff_digit_id[2]];
                if (temp_digit_1<status[i][diff_digit_id[1]]) temp_digit_1+=10;
                if (temp_digit_2<status[i][diff_digit_id[2]]) temp_digit_2+=10;
                if (temp_digit_1-status[i][diff_digit_id[1]]==temp_digit_2-status[i][diff_digit_id[2]]) continue;
                else return false;
            }
            else return false;
        }
        else return false;
    }
    return true;
}

inline void Count_password_num() {for (int i=0; i<=99999; ++i) {if (Is_password(i)) ++password_num;}}

inline void Output() {cout<<password_num<<endl;}

int main()
{
    ios::sync_with_stdio(false);
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    Input();
    Count_password_num();
    Output();
    return 0;
}