#include <bits/stdc++.h>
using namespace std;

const int max_n=2e6;
int n;
char str[max_n+1];
int deletable_str_num;

inline void Input()
{
    cin>>n;
    for (int i=1; i<=n; ++i) cin>>str[i];
}

char temp_str[max_n+1];
int is_deleted_num;
bool is_deleted[max_n+1];

inline bool Is_deletable(int str_begin, int str_end)
{
    for (int i=1; i<=str_end-str_begin+1; ++i) temp_str[i]=str[i+str_begin-1];
    is_deleted_num=0;
    memset(is_deleted, false, sizeof(is_deleted));
    char last_letter_id, last_letter;
    while (true)
    {
        last_letter_id=0, last_letter='0';
        bool has_deleted=false;
        for (int i=1; i<=str_end-str_begin+1; ++i)
        {
            if (is_deleted[i]) continue;
            if (temp_str[i]==last_letter) 
                {is_deleted_num+=2, is_deleted[last_letter_id]=true, is_deleted[i]=true, has_deleted=true; break;}
            else {last_letter_id=i, last_letter=temp_str[i];}
        }
        if (!has_deleted) break;
    }
    if (is_deleted_num==str_begin-str_end+1) return true;
    else return false;
}

inline void Count_deletable_str_num()
{
    for (int i=1; i<=n; ++i)
        for (int j=i+1; j<=n; ++j) if (Is_deletable(i, j)) ++deletable_str_num;
}

inline void Output() {cout<<deletable_str_num<<endl;}

int main()
{
    ios::sync_with_stdio(false);
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    Input();
    Count_deletable_str_num();
    Output();
    return 0;
}