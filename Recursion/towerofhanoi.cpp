// tower of hanoi recursive problem - O(2^n)

#include <iostream>

void tower_of_hanoi(int n, char source = 'A', char auxillary = 'B', char destination = 'C') {
    if (n == 0)
        return;
    
    // suppose we have 2 disks where disk 1 is the smaller one and disk 2 below is the larger one
    // the solution would be to move disk 1 to auxiliary, disk 2 to destination, and then disk 1 from auxiliary to destination
    // where there are many disks, we can think of the disks from 0 to n-1 together as disk 1, and disk n as disk 2
    tower_of_hanoi(n - 1, source, destination, auxillary);  // move disks n-1 to auxiliary
    std::cout << "Move disk " << n << " from " << source << " to " << destination << std::endl; // move disk n to destination
    tower_of_hanoi(n - 1, auxillary, source, destination);  // then move disks n-1 from auxiliary to destination
}

int main(int argc, char const *argv[]) {
    int n;
    std::cout << "Enter number of disks: ";
    std::cin >> n;
    tower_of_hanoi(n);
    return 0;
}
