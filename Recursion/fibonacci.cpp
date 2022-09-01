#include <iostream>

int get_fibonacci(int n) {
    if (n < 0) {
        return -1;
    } else if (n < 2) {
        return n;
    } else {
        return get_fibonacci(n - 1) + get_fibonacci(n - 2);
    }
}

int main(int argc, char const *argv[]) {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    int out = get_fibonacci(n);
    if (out == -1) {
        std::cout << "Invalid input" << std::endl;
    } else {
        std::cout << "Fibonacci number: " << out << std::endl;
    }
    return 0;
}
