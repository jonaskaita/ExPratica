#include <iostream>
#include <vector>
using namespace std;

//Codigo Fibonacci Recursivo sem PD:

int fibonacci(int n){
    if (n > 1){
        int f = fibonacci(n - 1) + fibonacci(n - 2);
        return(f);
    }
    else if(n == 1){
        return(1);
    }
    else if(n == 0){
        return(0);
    }
    else{
        return(-1);
    }
}

int fibonacciPD(int n){
    vector<int> f = vector<int>(n + 1, -1);
    if(f[n] == -1){
        if(n > 1){
            f[n] = fibonacciPD(n-1) + fibonacciPD(n-2);
        }
        else if(n == 1){
            f[n] = 1;
        }
        else if(n == 0){
            f[n] = 0;
        }

        return(f[n]);
    }
    else{
        return(f[n]);
    }

}

int main(){
    int n;
    cin >> n;
    cout << "Fibonacci sem PD" << fibonacci(n) << endl;
    cout << "Fibonacci com PD" << fibonacciPD(n) << endl;
    return(0);
}