#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int gcd(int x,int y){
    if (x % y == 0)
        return y;
    else if(y % x == 0)
        return x;
}
int main(){
int t,m;
int a,b,c;
cin>>t>>m;
for(int i = 1; i <= t;i++){
cin>>a>>b>>c;
if (b == 0 && c == 0){
cout<<"0"<<endl;
continue;
}
if(b * b - 4 * a * c == 0 && b!= 0 &&(float)((-1*b/(2 * a)) / 1 != 0))
cout<<(b / (2 *a)) *(-1)<<endl;
else if(b * b - 4 * a * c == 0 && b!= 0 &&(float)((-1*b/(2 * a)) / 1 == 0))
cout<< (-1 * b)/gcd(a,b)<<"/"<<(2 * a)/gcd(a,b)<<endl;
else if (b * b - 4 * a * c < 0){
cout<<"NO"<<endl;
}
else if(b * b - 4 * a * c > 0 && (-1*b+sqrt(b*b-4*a*c) / (2*a))/ 1 != 0){
    cout<<(-1*b+sqrt(b*b-4*a*c)) / (2*a)<<endl;
}
else if((b * b - 4 * a * c > 0 && (-1*b+sqrt(b*b-4*a*c) / (2*a))/ 1 == 0)){
    cout<<(-1*b+sqrt(b*b-4*a*c))<<"/"<<2*a<<endl;
}
}
return 0;
}
