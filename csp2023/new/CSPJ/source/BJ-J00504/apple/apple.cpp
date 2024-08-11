#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

queue<int> q;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, day = 0, ans;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) q.push(i);
    while (!q.empty()){
        int finish = q.size(); day++;
        for (int t = 1; t <= finish; t++){
            if (t % 3 == 1){
                //cout << q.front() << " ";
                if (q.front() == n) ans = day;
                q.pop();
            }
            else{
                int tmp = q.front();
                q.push(tmp);
                q.pop();
            }
        }
        //cout << endl;
    }
    printf("%d %d", day, ans);
    return 0;
}
