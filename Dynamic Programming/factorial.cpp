#include <iostream>

int factorial(int n){
    int total = 1;

    for(int i = 1; i <= n; ++i)
        total *= i;

    return total;
}

int main(){
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    std::cout << "Factorial: " << factorial(n);
}
