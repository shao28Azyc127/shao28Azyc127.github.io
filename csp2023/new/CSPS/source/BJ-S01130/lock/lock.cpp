using namespace std;
int main(){
	int n,a[5],sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		sum+=9-a[i];
	}
	for(int i=2;i<=n;i++){
		sum+=9-a[i];
	}
	cout<<sum;
	return 0;
}
