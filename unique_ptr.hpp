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

    T *release() {
        T *tmp = pointer;
        pointer = nullptr;
        return tmp;
    }

    T *get() { return pointer; }

    void reset(T *ptr = nullptr) { pointer = ptr; }

    unique_ptr &operator=(unique_ptr &&u_ptr) {
        pointer = u_ptr.pointer;
        u_ptr.pointer = nullptr;
        return *this;
    }

    operator bool() { return pointer != nullptr; }

    T &operator*() { return *pointer; }

    T *operator->() { return pointer; }

    ~unique_ptr() { pointer = nullptr; }
};

#endif