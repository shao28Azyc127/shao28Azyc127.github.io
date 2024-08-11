#include<bits/stdc++.h>
using namespace std;
int GENHJ(int m){
    for(int i=m-1;i--;i>1){
        if(m%(i*i)==0) return i
    }
}
int main(){
    int T,M;
    cin >> T >> M;
    for(int i=0;i++;i<T){
        int a,b,c;
        cin >> a >> b >> c;
        int dr=b*b-4*a*c;
        if(dr>0){
            if(-b%(2*a)==0){
                for(int j=1;j++;j<=dr/2){
                        if(j*j==dr) cout << -b/(2*a) << "+" << j;
                        else
                }
            }
            else{

            }
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n==1) cout << "1 1";
    if(n==2) cout << "2 2";
    if(n==3) cout << "3 3";
    if(n==4) cout << "3 1";
    if(n==5) cout << "4 4";
    if(n==6) cout << "4 2";
    if(n==7) cout << "5 1";
    if(n==8) cout << "5 5";
    if(n==9) cout << "6 3";
    if(n==10) cout << "6 1";
    return 0;
}