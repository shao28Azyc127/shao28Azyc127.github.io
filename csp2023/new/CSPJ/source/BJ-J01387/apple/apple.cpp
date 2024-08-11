#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("r","apple.in",stdin);
	freopen("w","apple.out",stdout);
    int n;
    cin >> n;
    long long s[100006];
    for(long i = 1;i <= n;i++){
        s[i] = 1;
    }
    int delta = 3;
    bool flag = 1;
    int ans2 = 0;
    int ans1 = 0;
    int la1;
    while (flag == 1){
        //flag = 0;
        ans2++;
        int beg = 1;
        for(int i = 1;i <= n;i++){
            if(s[i] == 1){
                beg = i;
                break;
            }
        }
        cout << beg << endl;
        ans1++;
        int sum = 0;
        while()
        for(int i = 1;i <= 3;i++){
            //sum++;

            while(s[beg + sum] == 0){
                sum++;
            }
            sum++;

        }
        if( beg + sum> n){
            //cout << ans;
            flag = 0;
            //break;
        }
        else{
            s[beg+sum-1] = 0;

        }

        //s[i]= 0;
            //flag = 1;
        if(s[n] == 0){
            la1 = ans1;
        }
        //if(flag == 0) break;
    }
    cout << ans2 << " " << la1;
    return 0;
}
