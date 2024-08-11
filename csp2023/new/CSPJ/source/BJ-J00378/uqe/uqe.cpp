#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int prime[1000] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997}
int a,b,c,delta;
int gcd(int a,int b){
    if(a < b) swap(a,b);
    if(a % b == 0) return b;
    return gcd(b,a - b);
}
int main(){
    //freopen("uqe.in","r",stdin);
    //freopen("uqe.out","w",stdout);
    scanf("%d %d",&t,&m);
    while(t--){
        scanf("%d %d %d",&a,&b,&c);
        delta = b * b - 4 * a * c;
        if(delta < 0) printf("NO\n");
            else{
                if(a * b < 0) printf("-");
                if(a < 0) a *= -2;
                else a *= 2;
                if(b < 0) b *= -1;
                int ch = gcd(a,b);
                int a2 = a
                int r = 1;
                for(int i = 0;i < 11;i++){
                    while(delta % (prime[i] * prime[i]) == 0){
                        delta /= prime[i];
                        delta /= prime[i];
                        r *= prime[i];
                    }
                }
                if(delta == 1) b += r;
                if(ch == 1) printf("%d/%d",b,a);
                    else{
                        a /= ch;
                        b /= ch;
                        printf("%d",b);
                        if(a != 1) printf("/%d",a);
                    }
                ch = gcd(r,a2);
                if(ch != 1){
                    a2 /= ch;
                    r /= ch;
                }
                if(delta != 1){
                    if(a2 != 1){
                        if(r != 1) printf("+%dsqrt(%d)/%d",r,delta,a2);
                            else  printf("+sqrt(%d)/%d",delta,a2);
                    }else{
                        if(r != 1)  printf("+%dsqrt(%d)",r,delta);
                        else  printf("+sqrt(%d)",delta);
                    }
                
                }
            }
    }
    return 0;
}
