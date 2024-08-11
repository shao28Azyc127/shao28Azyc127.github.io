#include<bits/stdc++.h>
using namespace std;
queue<int> apple;
queue<int> applet;
int main(){
    popen("apple.in","r");
    popen("apple.out","w");
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        apple.push(i);
       }
       int d=0,ans;
     while(!apple.empty()){
		 d++;
		 for(int i=1;!apple.empty();i++){
			 if(i%3==1){
				 if(apple.front()==n and !apple.empty()){
					ans=d;
				}
				 apple.pop();
			 }
			 else{
				applet.push(apple.front());
				apple.pop();
			 }
		 }
		 apple=applet;
		 while(!applet.empty())
		 applet.pop();
	 }
    cout<<d<<" "<<ans;
    return 0;
}
