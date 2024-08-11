#include<bits/stdc++.h>
using namespace std;
int c[1000001];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int a;
    cin>>a;
    int tian=2,sum=1;int max=-1;
    for(int i=1;i<=a;i++){
    	if(i%3==1){
    		c[i]=1;
		}
	}for(int j=1;j<=32;j++){
		sum=1;
		for(int i=1;i<=a;i++){
	    	if(c[i]==0){
	    		if(sum%3==1){
	    			max=tian;
	    			c[i]=tian;
				}sum++;
			}
		}tian++;
	}
	cout<<max<<" "<<c[a];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
