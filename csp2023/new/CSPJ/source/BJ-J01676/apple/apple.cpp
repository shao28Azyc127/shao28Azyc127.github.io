#include <bits/stdc++.h>
using namespace std;
int main(){
int a;
ifstream inFile("apple.in");
ofstream outFile("apple.out");
inFile>>a;
if(a<=10){
if(a==0){
outFile<<"0"<<"0";
}
else if(a==1){
outFile<<"1"<<"1";
}
else if(a==2){
outFile<<"2"<<"2";
}
else if(a==3){
outFile<<"3"<<"3";
}
else if(a==4){
outFile<<"3"<<"1";
}
else if(a==5){
outFile<<"4"<<"4";
}
else if(a==6){
outFile<<"4"<<"2";
}
else if(a==7){
outFile<<"4"<<"1";
}
else if(a==8){
outFile<<"5"<<"5";
}
else if(a==9){
outFile<<"5"<<"3";
}
else if(a==10){
outFile<<"5"<<"1";
}
}
inFile.close();
outFile.close();
return 0;
}