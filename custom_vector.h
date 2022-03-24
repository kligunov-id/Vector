#ifndef CUSTOM_VECTOR
#define CUSTOM_VECTOR

class custom_vector {
private:
    size_t n, allocated_n;
    int64_t *arr;

public:
    custom_vector(size_t n);
    ~custom_vector();

    int64_t& operator[](size_t i);
};

custom_vector::custom_vector(size_t n = 0): n(n), allocated_n(n) {
    arr = new int64_t[allocated_n]{};
}

custom_vector::~custom_vector() {
    delete[] arr;
}

int64_t& custom_vector::operator[](size_t i) {
    return arr[i];
}

#endif