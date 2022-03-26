#ifndef CUSTOM_VECTOR
#define CUSTOM_VECTOR

class custom_vector {
private:
    size_t n, allocated_n;
    int64_t *arr;
public:
    custom_vector(size_t n);
    ~custom_vector();
    custom_vector(const custom_vector &other);
    custom_vector& operator=(const custom_vector &other);

    int64_t& operator[](size_t i);

    void reserve(size_t new_size);
    void resize(size_t new_size, int64_t value);    
    void shrink_to_fit();

    void push_back(int64_t x);
    void pop_back();

    int64_t& front();
    int64_t& back();

    int64_t size();
    int64_t capacity();
};

void custom_vector::resize(size_t new_size, int64_t value = 0) {
    if (new_size > allocated_n) {
        reserve(new_size);
    }
    if (new_size > n) {
        for (size_t i = n; i < new_size; i++) {
            arr[i] = value;
        }
    }
    n = new_size;
}

int64_t& custom_vector::front() {
    return arr[0];
}

int64_t& custom_vector::back() {
    return arr[n - 1];
}

int64_t custom_vector::size() {
    return n;
}

int64_t custom_vector::capacity() {
    return allocated_n;
}

void custom_vector::reserve(size_t new_size) {
    if (new_size < n) {
        return;
    }
    allocated_n = new_size;
    int64_t *new_arr = new int64_t[allocated_n];
    for (size_t i = 0; i < n; i++) {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
}

void custom_vector::pop_back() {
    if (n) {
        --n;
    }
}

void custom_vector::push_back(int64_t x) {
    if (!allocated_n) {
        reserve(1);
    }
    if (n == allocated_n) {
        reserve(allocated_n << 1);
    }
    arr[n++] = x;
}

void custom_vector::shrink_to_fit() {
    reserve(n);
}

custom_vector::custom_vector(size_t n = 0): n(n), allocated_n(n) {
    arr = new int64_t[allocated_n]{};
}

custom_vector::~custom_vector() {
    delete[] arr;
}

custom_vector::custom_vector(const custom_vector &other) {
    n = other.n;
    allocated_n = other.allocated_n;
    arr = new int64_t[allocated_n];
    for (size_t i = 0; i < n; ++i) {
        arr[i] = other.arr[i];
    }
}

custom_vector& custom_vector::operator=(const custom_vector &other) {
    n = other.n;
    allocated_n = other.allocated_n;
    delete[] arr;
    arr = new int64_t[allocated_n];
    for (size_t i = 0; i < n; ++i) {
        arr[i] = other.arr[i];
    }
    return *this;
}

int64_t& custom_vector::operator[](size_t i) {
    return arr[i];
}

#endif
