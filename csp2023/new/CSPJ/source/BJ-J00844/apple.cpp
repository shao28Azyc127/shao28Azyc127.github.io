#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("apple.in");
    ofstream fout("apple.out");
    int n;
    fin >> n;
    int x = n , cnt = 0 , day;
    bool picked = false;
    while(x)
    {
        if(!picked && (x - 1) % 3 == 0){picked = true;day = cnt + 1;}
        x -= (x - 1) / 3 + 1;
        cnt++;
    }
    fout << cnt << " " << day << endl;
    return 0;
}