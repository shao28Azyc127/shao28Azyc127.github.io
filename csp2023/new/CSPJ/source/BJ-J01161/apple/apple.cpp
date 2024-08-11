#include<iostream>
using namespace std;
const int remain[]={0,0,1};
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,day=0,nleft=0;
	cin>>n;
	while(n>0)
	{
		day++;
		if(n%3==1 && !nleft)	nleft=day;
		n=(n/3)*2+remain[n%3];
//		cout<<n<<endl;
	}
	cout<<day<<" "<<nleft<<endl;
}