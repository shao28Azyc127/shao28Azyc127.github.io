#include <iostream>
#define maxn 2000010
using namespace std;

int n;
char str[maxn];
int check[maxn];
bool alr[maxn];
int sum = 0;

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n;
    cin >> str;
    for (int i = n-1;i >= 0;i--) str[i+1] = str[i];
    str[0] = '!';
    for (int i = 1;i <= n;i++){
        if (str[i]==str[i+1]){
            check[i] = i+1;
            alr[i] = true;
        }
    }
    for (int i = 1;i <= n;i++){
        if (check[i]){
            int delta = 1;
            while (str[i-delta]==str[i+delta+1] && i-delta>0){
                if (check[i-delta]==0) check[i-delta] = i+delta+1;
                delta++;
            }
        }
    }
    for (int i = 1;i <= n;i++){
        //cout << i << " " << check[i] << " " << alr[i] << endl;
        if (check[i]) sum++;
    }
    //cout << "checkpoint1\n";
    for (int i = 1;i <= n;i++){
        while(1){
            if (check[i]&&check[check[i]+1]){
                sum++;
                check[i] = check[check[i]+1];
            }else{
                break;
            }
        }
    }
    //for (int i = 1;i <= n;i++){
    //    cout << i << " " << check[i] << " " << alr[i] << endl;
    //}
    cout << sum;
    return 0;
}
