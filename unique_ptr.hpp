#ifndef UNIQUE_PTR
#define UNIQUE_PTR

#include <algorithm>

template <typename T> class unique_ptr {
  private:
    T *pointer;

  public:
    unique_ptr()
        : pointer(nullptr) {}

    unique_ptr(T *ptr)
        : pointer(ptr) {}

    unique_ptr(unique_ptr &&u_ptr)
        : pointer(u_ptr.pointer) {
        u_ptr.pointer = nullptr;
    }

    ~unique_ptr() { delete pointer; }

    T *release() {
        T *tmp = pointer;
        pointer = nullptr;
        return tmp;
    }

    void reset(T *ptr = nullptr) {
        delete pointer;
        pointer = ptr;
    }

    void swap(unique_ptr &u_ptr) { std::swap(pointer, u_ptr.pointer); }

    T *get() { return pointer; }

    operator bool() const { return pointer != nullptr; }

    unique_ptr &operator=(unique_ptr &&u_ptr) {
        pointer = u_ptr.pointer;
        u_ptr.pointer = nullptr;
        return *this;
    }

    bool operator==(const unique_ptr &u_ptr) { return pointer == u_ptr.pointer; }

    bool operator!=(const unique_ptr &u_ptr) { return !operator==(u_ptr); }

    T &operator*() { return *pointer; }

    T *operator->() { return pointer; }
};

#endif