#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool intint(string str){
    if(str[0]=='i'&&str[1]=='n'&&str[2]=='t'){
        return true;
    }
    return false;
}
bool shortshort(string str){
    if(str[0]=='s'&&str[1]=='h'&&str[2]=='o'&&str[3]=='r'&&str[4]=='t'){
        return true;
    }
    return false;
}
bool shortshort(string str){
    if(str[0]=='l'&&str[1]=='o'&&str[2]=='n'&&str[3]=='n'){
        return true;
    }
    return false;
}
bool bytebyte(string str){
    if(str[0]=='b'&&str[1]=='y'&&str[2]=='t'&&str[3]=='e'){
        return true;
    }
    return false;
}
int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    int a, n;
    string str1, str2;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a;
        if(a == 1){
            int num, maxnum = 0;
            cin >> str1 >> num;
            for(int j= 1; j <= num j++){
                cin >> str2;
                if(intint(str2)){
                    if(maxnum <= 4){
                        maxnum = 4
                    }
                }else if(shortshort(str2)){
                    if(maxnum <= 2){
                        maxnum = 2
                    }
                }else if(longlong(str2)){
                    if(maxnum <= 8){
                        maxnum = 8
                    }
                }else if(bytebyte(str2)){
                    if(maxnum <= 1){
                        maxnum = 1
                    }
                }
            }
            cout << num * maxnum << maxnum<<endl;
        }
    }
    return 0;
}
