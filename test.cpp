#include <iostream>
#include "custom_vector.h"

void test_basic() {
    std::cout << "-------------------\nBasic test\n";
    custom_vector v(5), v_empty; 
    v[1] = 4;
    v[4] = v[1];
    std::cout << "Expected: 0 4 0 0 4\n" << "Recieved: ";
    for (size_t i = 0; i < 5; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n-------------------\n";
}

void func(custom_vector a) {
    a[0] = a[0] + 1;
}

void test_copy() {
    std::cout << "-------------------\n" << "Test copy\n";
    std::cout << "Passing argument:\n";
    custom_vector a(3), b;
    func(a);
    std::cout << "    Expected: 0\n" << "    Recieved: " << a[0] << "\n";
    std::cout << "Assigning:\n";
    b = a;
    a[0] = 1;
    std::cout << "    Expected: 0\n" << "    Recieved: " << b[0] << "\n";
    std::cout << "-------------------\n";
}

void test_push() {
    std::cout << "-------------------\n" << "Test push\n";
    custom_vector a;
    for (size_t i = 0; i < 9; i ++) {
        a.push_back(i);
    }
    std::cout << "Expected: 0 1 2 3 4 5 6 7 8\n" << "Recieved: ";
    for (size_t i = 0; i < 9; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n-------------------\n";
}

int main() {
    test_basic();
    test_copy();
    test_push();
}
