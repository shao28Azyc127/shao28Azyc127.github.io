#include <iostream>
#include <vector>
using namespace std;
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, days = 0, dayn = 0;
    vector<int> a;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        a.push_back(i);
    while (!a.empty()){
        days ++;
        for (int i = 0; i < a.size(); i += 2){
            if (a[i] == n) dayn = days;
            a.erase(a.begin() + i);
        }
    }
    cout << days << " " << dayn << endl;
    return 0;
}
