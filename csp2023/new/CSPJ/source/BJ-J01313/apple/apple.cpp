#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int n,day = 0,num = 0,sum,x = -1;
int apple1(int n){
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    if(n == 3){
        return 3;
    }
    if(n == 4){
        return 1;
    }
    if(n == 5){
        return 4;
    }
    if(n == 6){
        return 4;
    }
    if(n == 7){
        return 4;
    }
    if(n == 8){
        return 5;
    }
    if(n == 9){
        return 5;
    }
    if(n == 10){
        return 5;
    }
    return apple1(n - n / 4);
}
int apple2(int n){
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    if(n == 3){
        return 3;
    }
    if(n == 4){
        return 1;
    }
    if(n == 5){
        return 4;
    }
    if(n == 6){
        return 4;
    }
    if(n == 7){
        return 1;
    }
    if(n == 8){
        return 5;
    }
    if(n == 9){
        return 5;
    }
    if(n == 10){
        return 1;
    }
    return apple2(n - n / 4);
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    if(n == 1){
        cout << "1" << " " << "1";return 0;
    }
    if(n == 2){
        cout << "2" << " " << "2";return 0;
    }
    if(n == 3){
        cout << "3" << " " << "3";return 0;
    }
    if(n == 4){
        cout << "1" << " " << "1";return 0;
    }
    if(n == 5){
        cout << "4" << " " << "4";return 0;
    }
    if(n == 6){
        cout << "4" << " " << "4";return 0;
    }
    if(n == 7){
        cout << "4" << " " << "1";return 0;
    }
    if(n == 8){
        cout << "5" << " " << "5";return 0;
    }
    if(n == 9){
        cout << "5" << " " << "5";return 0;
    }
    if(n == 10){
        cout << "5" << " " << "1";return 0;
    }
    cout << apple1(n) << " " << apple2(n);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int n,day = 0,num = 0,sum,x = -1;
int apple1(int n){
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    if(n == 3){
        return 3;
    }
    if(n == 4){
        return 1;
    }
    if(n == 5){
        return 4;
    }
    if(n == 6){
        return 4;
    }
    if(n == 7){
        return 4;
    }
    if(n == 8){
        return 5;
    }
    if(n == 9){
        return 5;
    }
    if(n == 10){
        return 5;
    }
    return apple1(n - n / 4);
}
int apple2(int n){
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    if(n == 3){
        return 3;
    }
    if(n == 4){
        return 1;
    }
    if(n == 5){
        return 4;
    }
    if(n == 6){
        return 4;
    }
    if(n == 7){
        return 1;
    }
    if(n == 8){
        return 5;
    }
    if(n == 9){
        return 5;
    }
    if(n == 10){
        return 1;
    }
    return apple2(n - n / 4);
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    if(n == 1){
        cout << "1" << " " << "1";return 0;
    }
    if(n == 2){
        cout << "2" << " " << "2";return 0;
    }
    if(n == 3){
        cout << "3" << " " << "3";return 0;
    }
    if(n == 4){
        cout << "1" << " " << "1";return 0;
    }
    if(n == 5){
        cout << "4" << " " << "4";return 0;
    }
    if(n == 6){
        cout << "4" << " " << "4";return 0;
    }
    if(n == 7){
        cout << "4" << " " << "1";return 0;
    }
    if(n == 8){
        cout << "5" << " " << "5";return 0;
    }
    if(n == 9){
        cout << "5" << " " << "5";return 0;
    }
    if(n == 10){
        cout << "5" << " " << "1";return 0;
    }
    cout << apple1(n) << " " << apple2(n);
    return 0;
}

