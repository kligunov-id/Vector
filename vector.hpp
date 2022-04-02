#ifndef CUSTOM_VECTOR
#define CUSTOM_VECTOR

class CustomVector {
private:
    size_t n, allocated_n;
    int64_t *arr;
public:
    explicit CustomVector(size_t n);
    ~CustomVector();
    CustomVector(const CustomVector &other);
    CustomVector& operator=(CustomVector other);
    CustomVector(CustomVector&& other);

    friend void swap(CustomVector& first, CustomVector& second);

    int64_t& operator[](size_t i);
    const int64_t& operator[] (size_t i) const;

    void Reserve(size_t new_size);
    void Resize(size_t new_size, int64_t value);    
    void ShrinkToFit();

    void push_back(int64_t x);
    void pop_back();

    int64_t& front();
    int64_t& back();

    size_t Size() const;
    size_t Capacity() const;
};

void swap(CustomVector& first, CustomVector& second) {
    std::swap(first.n, second.n);
    std::swap(first.allocated_n, second.allocated_n);
    std::swap(first.arr, second.arr);
}

void CustomVector::Resize(size_t new_size, int64_t value = 0) {
    if (new_size > allocated_n) {
        Reserve(new_size);
    }
    if (new_size > n) {
        for (size_t i = n; i < new_size; i++) {
            arr[i] = value;
        }
    }
    n = new_size;
}

int64_t& CustomVector::front() {
    return arr[0];
}

int64_t& CustomVector::back() {
    return arr[n - 1];
}

size_t CustomVector::Size() const {
    return n;
}

size_t CustomVector::Capacity() const {
    return allocated_n;
}

void CustomVector::Reserve(size_t new_size) {
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

void CustomVector::pop_back() {
    if (n) {
        --n;
    }
}

void CustomVector::push_back(int64_t x) {
    if (!allocated_n) {
        Reserve(1);
    }
    if (n == allocated_n) {
        Reserve(allocated_n << 1);
    }
    arr[n++] = x;
}

void CustomVector::ShrinkToFit() {
    Reserve(n);
}

CustomVector::CustomVector(size_t n = 0): n(n), allocated_n(n) {
    arr = new int64_t[allocated_n]{};
}

CustomVector::~CustomVector() {
    delete[] arr;
}

CustomVector::CustomVector(const CustomVector &other) {
    n = other.n;
    allocated_n = other.allocated_n;
    arr = new int64_t[allocated_n];
    for (size_t i = 0; i < n; ++i) {
        arr[i] = other.arr[i];
    }
}

CustomVector::CustomVector(CustomVector &&other): n(other.n), allocated_n(other.allocated_n) {
    arr = other.arr;
    other.arr = nullptr;
}

// Copy-and-swap
// Accepts by value, so it is both copy assignment and move assignment
CustomVector& CustomVector::operator=(CustomVector other) {
    swap(*this, other);
    return *this;
}

int64_t& CustomVector::operator[](size_t i) {
    return arr[i];
}

const int64_t& CustomVector::operator[](size_t i) const {
    return arr[i];
}

#endif
