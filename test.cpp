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

int main() {
    test_basic();
}