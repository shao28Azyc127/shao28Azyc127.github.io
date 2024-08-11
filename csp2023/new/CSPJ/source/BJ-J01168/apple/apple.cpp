#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int a,day =1;
    cin >> a;
    while(true){
        if((a-1)%3==0){
            cout << day;
            return 0;
        }
        else{
            a = (a-1)/3;
            day++;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
