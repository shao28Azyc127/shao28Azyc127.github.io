
#include<iostream>  
#include<cmath>
#include<windows.h>        
using namespace std;  
double a,b,c,x1,x2;
int main(){  
freopen("uqe.in","r",stdin);
freopen("uqe.out","w",stdout); 
    system("color F0");
    cin>>a; 
    cin>>b; 
    cin>>c; 
    if((b*b-4*a*c)>0){  
        x1=(-b+sqrt(b*b-4*a*c))/(2*a);  
        x2=(-b-sqrt(b*b-4*a*c))/(2*a);  
        cout<<x1<<x2<<endl;  
    }else if((b*b-4*a*c)>=0){
        x1=-b/(2*a);  
        cout<<x1<<endl;  
    }else{
    	cout<<"NO";
	}
	system("pause"); 
    return 0;  
}  

