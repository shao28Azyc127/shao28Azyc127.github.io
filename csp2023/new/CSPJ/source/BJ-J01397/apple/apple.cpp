#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
    int n;
    cin >> n;
    int t=0,day=0;
    double ne=n;
    if(n==1||n==4||n==7||n==10){
		day= 1;
	}else if(n==2||n==6){
		day=2;
	}else if(n==3||9){
		day=3;
	}else if(n==5){
		day=4;
	}else if(n==8){
		day=5;
	}else{
		day=1;
	}
    while(ne>=3){
        if(ne/3.0>int(ne/3)){
            ne=ne-(int(ne/3)+1);
        }else{
            ne=ne-ne/3;
        }
        t++;
    }
    t=t+ne;
    cout << t <<" "<< day;
    fclose(stdin);
	fclose(stdout);
    return 0;
}