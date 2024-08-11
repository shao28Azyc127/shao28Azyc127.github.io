#include<fstream>
using namespace std;
#define ll long long
ll n,d;
ll u[100010];
ll a[100010];
ll b;
ll cc,sum,num;
int main(){
    ifstream inFile("road.in");
    ofstream outFile("road.out");
    inFile >> n >> d;
    for(int i = 1;i<=n - 1;i++){
        inFile >> u[i];
    }
    for(int i = 1;i<=n;i++){
        inFile >> a[i];
        b = min(a[1],a[i]);
    }
    if(b == a[1]){
        for(int i = 1;i<=n - 1;i++){
            sum += u[i];
        }
        if(sum % d != 0){
            cc = (sum / d + 1) * a[1];
        }
        else{
            cc = sum  / d * a[1];
        }
        outFile << cc;
        return 0;
    }
    for(int i = 1;i<=n;i++){
        if(i == n-1){
            u[i] -= num;
        }
        if(a[i] >= a[i+1]){
            if(u[i] % d != 0){
                cc+=(u[i] / d +1)*a[i];
                num += (u[i] / d +1)*d - u[i];
            }
            else{
                cc+=u[i] / d * a[i];
            }
        }
        if(a[i] < a[i+1]){
            if((u[i]+u[i+1]) % d != 0){
                cc+=((u[i] + u[i+1])/d + 1) * a[i];
                num += ((u[i] + u[i - 1])/ d +1)*d - u[i] - u[i + 1];
                i++;
            }
            else{
                cc+=(u[i] + u[i+1])/d * a[i];
                i++;
            }
        }
    }
    outFile << cc;
    inFile.close();
    outFile.close();
    return 0;
}
