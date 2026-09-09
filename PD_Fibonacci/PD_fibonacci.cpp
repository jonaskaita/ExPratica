#include <iostream>
#include <vector>
#include <chrono>
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

// Fibonacci com PD recursiva
int fibonacciPDfront(int n, vector<int> &f){
    if(f[n] == -1){
        if(n > 1){
            f[n] = fibonacciPDfront(n-1, f) + fibonacciPDfront(n-2, f);
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

// Fibonacci com PD iterativa

int fibonacciPDback(int n, vector<int> &f){
        for(int i = 0; i <= n; i++){
        if(i == 0){
            f[0] = 0;
        }

        else if(i == 1){
            f[1] = 1;
        }

        else{
            f[i] = f[i - 1] + f[i - 2];
        }
        
    }

    return(f[n]);

}

int main(){
    int n;
    cin >> n;

    auto t1_start = chrono::high_resolution_clock::now();
    int fspd = fibonacci(n);
    auto t1_end = chrono::high_resolution_clock::now();

    double t_fspd = chrono::duration<double, milli>(t1_end-t1_start).count();

    vector<int> f_front = vector<int>(n + 1, -1);

    auto t2_start = chrono::high_resolution_clock::now();
    int fpd_front = fibonacciPDfront(n, f_front);
    auto t2_end = chrono::high_resolution_clock::now();

    double t_fpd_front = chrono::duration<double, milli>(t2_end-t2_start).count();

    vector<int> f_back = vector<int>(n + 1, -1);

    auto t3_start = chrono::high_resolution_clock::now();
    int fpd_back = fibonacciPDback(n, f_back);
    auto t3_end = chrono::high_resolution_clock::now();

    double t_fpd_back = chrono::duration<double, milli>(t3_end-t3_start).count();



    cout << "Fibonacci sem PD " << fspd << " Tempo: " << t_fspd << endl;
    cout << "Fibonacci com PD front " << fpd_front << " Tempo: " << t_fpd_front << endl;
    cout << "Fibonacci com PD back " << fpd_back << " Tempo: " << t_fpd_back << endl;
    return(0);
}