#ifndef UNIQUE_PTR
#define UNIQUE_PTR

#include <algorithm>
#include <cstddef>

template <typename T> class unique_ptr {
  private:
    T *pointer;

  public:
    unique_ptr()
        : pointer(nullptr) {}

    unique_ptr(T *ptr)
        : pointer(ptr) {}

    unique_ptr(const unique_ptr &u_ptr) = delete;

    unique_ptr(unique_ptr &&u_ptr)
        : pointer(u_ptr.release()) {}

    ~unique_ptr() { delete pointer; }

    T *release() {
        T *tmp = get();
        pointer = nullptr;
        return tmp;
    }

    void reset(T *ptr = nullptr) {
        delete pointer;
        pointer = ptr;
    }

    void swap(unique_ptr &u_ptr) { std::swap(pointer, u_ptr.pointer); }

    T *get() const { return pointer; }

    operator bool() const { return get() != nullptr; }

    unique_ptr &operator=(const unique_ptr &u_ptr) = delete;

    unique_ptr &operator=(unique_ptr &&u_ptr) {
        reset(u_ptr.release());
        return *this;
    }

    bool operator==(const unique_ptr &u_ptr) const { return get() == u_ptr.get(); }

    bool operator!=(const unique_ptr &u_ptr) const { return get() != u_ptr.get(); }

    T &operator*() { return *get(); }

    T *operator->() { return get(); }
};

template <typename T> class unique_ptr<T[]> {
  private:
    T *pointer;

  public:
    unique_ptr()
        : pointer(nullptr) {}

    unique_ptr(T ptr[])
        : pointer(ptr) {}

    unique_ptr(const unique_ptr &u_ptr) = delete;

    unique_ptr(unique_ptr &&u_ptr)
        : pointer(u_ptr.release()) {}

    ~unique_ptr() { delete[] pointer; }

    T *release() {
        T *tmp = get();
        pointer = nullptr;
        return tmp;
    }

    void reset(T *ptr = nullptr) {
        delete[] pointer;
        pointer = ptr;
    }

    void swap(unique_ptr &u_ptr) { std::swap(pointer, u_ptr.pointer); }

    T *get() const { return pointer; }

    operator bool() const { return get() != nullptr; }

    unique_ptr &operator=(const unique_ptr &u_ptr) = delete;

    unique_ptr &operator=(unique_ptr &&u_ptr) {
        reset(u_ptr.release());
        return *this;
    }

    bool operator==(const unique_ptr &u_ptr) const { return get() == u_ptr.get(); }

    bool operator!=(const unique_ptr &u_ptr) const { return get() != u_ptr.get(); }

    T &operator[](const std::size_t index) { return pointer[index]; }
};

#endif