#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;

int n;
int arr[N];
bool brr[N] = {false};

bool check(){
    for(int i=1;i<=n;i++)
    {
        if(!brr[i]) return false;
    }
    return true;
}

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    int cnt, m = 1;
    while(!check()){
        cnt = 2;
        for(int i=1;i<=n;i++){
            if(brr[i]) continue;
            if(cnt == 2)
            {
                arr[i] = m;
                brr[i] = true;
                cnt = 0;
            }
            else{
                cnt++;
            }

        }
        m++;
    }
    cout << m-1 << " " << arr[n];
    /*
    for(int i=1;i<=n;i++){
        cout << arr[i] <<" ";
        if(i% 27 == 0) cout << endl;
    }*/

    return 0;
}
