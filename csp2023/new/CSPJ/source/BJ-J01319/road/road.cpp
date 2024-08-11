#include <iostream>
using namespace std;
const int maxn = 100;

int dist[maxn];
int n, k;

int getf(int dist[]){
    int ans = 0;
    int tmp = 0;

    for (int i = 0; i <= k; i++){
        if (dist[i] > n){
            return -1;
        }
    }
    for (int i = 0; i <= k; i++){
        tmp += dist[i];
        if (tmp > n){
            ans++;
            tmp = dist[i];
            cout << i << " ";
        }
    }
    cout << endl;
    return ans;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
    cin >> n >> k;
    for (int i = 0; i <= k; i++)
        cin >> dist[i];
    
    int ans = getf(dist);
    if (ans >= 0)
        cout<< ans << endl;

    return 0;
}