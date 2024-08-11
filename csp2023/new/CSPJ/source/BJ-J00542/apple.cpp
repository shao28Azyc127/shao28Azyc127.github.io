#include<iostream>

using namespace std;

const int N = 1005;
long long arr[N];

int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int a;
    cin >> a;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    for(int i = 4; i <= a; i++){
        arr[i] = arr[i - 3] + arr[i - 1] + 1;
        //cout << arr[i] << ' ' << i << endl;
    }
    if(a <= 3){
        cout << a << ' ' << a;
        return 0;
    }
    for(int i = 1; i <= a; i++){
        if(arr[i] >= a)
        {
            if(arr[i] == a) cout << i << ' ' << i;
            else{
                if(a % 3 == 1) cout << i - 1 << ' ' << 1;
                else if(a % 8 == 1) cout << i - 1 << ' ' << 3;
                else cout << i - 1 << ' ' << 2;
            }
            return 0;
        }
    }
}
//1 2 3 5 8 12 18 27
//1 2 3 4 5  6  7  8 9 10
