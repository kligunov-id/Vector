#include <iostream>
#include "vector.hpp"

void test_basic() {
    std::cout << "-------------------\nBasic test\n";
    CustomVector v(5), v_empty; 
    v[1] = 4;
    v[4] = v[1];
    std::cout << "Expected: 0 4 0 0 4\n" << "Recieved: ";
    for (size_t i = 0; i < 5; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n-------------------\n";
}

void func(CustomVector a) {
    a[0] = a[0] + 1;
}

void test_copy() {
    std::cout << "-------------------\n" << "Test copy\n";
    std::cout << "Passing argument:\n";
    CustomVector a(3), b;
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
    CustomVector a;
    for (size_t i = 0; i < 9; i ++) {
        a.push_back(i);
    }
    std::cout << "Expected: 0 1 2 3 4 5 6 7 8\n" << "Recieved: ";
    for (size_t i = 0; i < 9; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n-------------------\n";
}

void test_utility() {
    std::cout << "-------------------\n" << "Test utility\n";
    CustomVector a(5);
    std::cout << "Expected:\n    5 5\n    6 10\n    6 6\n" << "Recieved:\n";
    std::cout << "    " << a.Size() << " " << a.Capacity() << "\n";
    a.push_back(0);
    std::cout << "    " << a.Size() << " " << a.Capacity() << "\n";
    a.ShrinkToFit();    
    std::cout << "    " << a.Size() << " " << a.Capacity() << "\n";
    std::cout << "-------------------\n";
}

void test_utility2() {
    std::cout << "-------------------\n" << "Test utility 2\n";
    CustomVector a;
    a.Resize(1);
    for (size_t i = 1; i < 5; i++){
        a.Resize(i + 1, i);
    }
    a.front()++;
    std::cout << "Expected: 4 3 2 1 1\nRecieved: ";
    for (size_t i = 0; i < 5; i++) {
        std::cout << a.back() << " ";
        a.pop_back();
    }
    std::cout << "\n-------------------\n";
}

void test_const() {
    std::cout << "-------------------\n" << "Test const\n";
    CustomVector v(3);
    for (size_t i = 0; i < 3; i ++) {
        v[i] = i;
    }
    const CustomVector v2 = v;
    std::cout << "Expected: 3 3 - 0 1 2\n";
    std::cout << "Recieved: " << v2.Size() << " " << v2.Capacity() << " -";
    for (size_t i = 0; i < 3; i ++) {
        std::cout << " " << v2[i];
    }
    std::cout << "\n-------------------\n";
}

int main() {
    test_basic();
    test_copy();
    test_push();
    test_utility();
    test_utility2();
    test_const();
}
