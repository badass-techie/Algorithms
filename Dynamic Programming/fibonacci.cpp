// fibonacci number
// time complexity: O(n)
// space complexity: O(1)

#include <iostream>
#include <vector>

// get the nth fibonacci number by dynamic programming
int get_fibonacci(int n) {
    if (n > 2){
        int seq[n];

        seq[0] = 1;
        seq[1] = 1;

        for (int i = 2; i < n; ++i)
            seq[i] = seq[i-1] + seq[i-2];

        return seq[n-1];
    }
    else if (n > 0)
        return 1;
    else
        return -1;
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
