#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, m, i = 0, j;
    cin >> n;
    m = n, j = n;
    while(m > 3)
    {
        if(m % 3 == 0)
            m = m - m/3;
        else{
            if (m % 3 == 1){
                j = i;
                break;
            }
            m = m - (m+2)/3;
        }
        i++;
    }
    while(m > 3)
    {
        if(m % 3 == 0)
            m = m - m/3;
        else
            m = m - (m+2)/3;
        i++;
    }
    i += m;
    if (j == n)
        j = i;
    else
        j++;
    cout << i << " " << j;
    fclose(stdin);
    fclose(stdout);
    return 0;
}