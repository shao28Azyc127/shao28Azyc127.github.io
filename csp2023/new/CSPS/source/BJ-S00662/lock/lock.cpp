#include<fstream>

using namespace std;

ifstream cin ("lock.in");
ofstream cout ("lock.out");
const int N = 10;
int n,a[N][10];
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= 5;j ++){
            cin >> a[i][j];
        }
    }
    if(n == 1){
        cout << "81" << endl;
        return 0;
    } else {
        int cnt = 0;
        for(int i = 1;i < n;i ++){
            for(int j = 1;j <= 5;j ++){
                if(a[i][j] != a[i + 1][j]){
                    if(i == 1){
                        cnt = j;
                    } else {
                        if(cnt != j){
                            cout << "1" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "2" << endl;
    return 0;
}
