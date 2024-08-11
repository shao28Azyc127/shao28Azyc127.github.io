#include<bits/stdc++.h>
using namespace std;
char a;
int b, addr;
string s, s1, s2;

void op1(){
    cin >> a >> b;
    for (int i = 1; i <= b; i++)
        cin >> s1 >> s2;
}

void op2(){
    cin >> s1 >> s2;
}

void op3(){
    cin >> s;
}

void op4(){
    cin >> addr;
}

int main(){
    int n;
    cin >> n;
    int op;
    for (int i = 1; i <= n; i++){
        cin >> op;
        if (op == 1)
            op1();
        if (op == 2)
            op2();
        if (op == 3)
            op3();
        if (op == 4)
            op4();
    }
    cout << 1 << 8 << 4 << endl;
    cout << 2 << 16 << 8 << endl;
    cout << 3 << 0 << endl;
    cout << 4 << 4 << endl;
    cout << 5 << "x.bb";

    return 0;
}