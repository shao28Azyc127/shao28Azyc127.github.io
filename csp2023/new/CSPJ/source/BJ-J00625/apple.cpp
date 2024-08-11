#include<iostream>
#include<cstdio>
using namespace std;

int main(){

    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n;
    cin >> n;
    if(n==1){
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    int day=0,endD=0;
    int flag=0;
    while(n!=0){

        if(n<4){
            day = day +n;
            if(flag == 0) endD=day;
            break;
        }
        if(n%3==1 && flag==0){
            endD = day+1;
            flag = 1;
        }
        n = n-(n/3+1);
        day++;

    }
    cout << day << " " << endD;

    fclose(stdin);
    fclose(stdout);
    return 0;
}