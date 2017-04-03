#include<iostream>
#include<math.h>
using namespace std;
long long gcd(long long n, long long m){
    //n>m
    if(m==0)
        return n;
    else
        return gcd(m, n%m);
}
// time out
void result1(){
    int N, M;
    cin>>N>>M;
    long long num1 = 0;
    long long num2 = 0;
    long long x = 0;
    for(int i=1;i<=N;i++){
        if(N%i==0){
            num1++;
        }
    }
    for(int i=1;i<=M;i++){
        if(M%i==0){
            num2++;
            if(N%i==0)
                x++;
        }
    }
    long long y = gcd(num1*num2, x);
    cout<<num1*num2/y<<" "<<x/y<<endl;
}
// AC
void result2(){
    long long N, M;
    cin>>N>>M;
    long long num1 = 0;
    long long num2 = 0;
    long long x = 0;
    //求N约数个数
    for(long long i=1;i<=sqrt(N);i++){
        if(N%i==0){
            if(N/i==i){
                num1++;
                //求公共约数
                if(M%i==0){
                    x++;
                }
            }
            else{
                num1+=2;
                //求公共约数
                if(M%i==0){
                    x++;
                }
                if(M%(N/i)==0){
                    x++;
                }
            }
        }
    }
    //求M约数个数
    for(long long i=1;i<=sqrt(M);i++){
        if(M%i==0){
            if(M/i==i)
                num2++;
            else
                num2+=2;

        }
    }
    long long y = gcd(num1*num2, x);
    cout<<num1*num2/y<<" "<<x/y<<endl;
}
int main(){
    result2();
    return 0;
}
