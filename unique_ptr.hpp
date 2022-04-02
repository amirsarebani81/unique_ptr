#ifndef UNIQUE_PTR
#define UNIQUE_PTR

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <memory>

template <typename T, typename D = std::default_delete<T>> class unique_ptr {
  private:
    T *pointer;
    D deleter;
    friend std::ostream &operator<<(std::ostream &os, const unique_ptr &up) {
        os << up.get();
        return os;
    }

  public:
    unique_ptr()
        : pointer(nullptr) {}

    unique_ptr(T *ptr)
        : pointer(ptr) {}

    unique_ptr(const unique_ptr &u_ptr) = delete;

    unique_ptr(unique_ptr &&u_ptr)
        : pointer(u_ptr.release())
        , deleter(std::forward<D>(u_ptr.get_deleter())) {}

    unique_ptr(T *ptr, const D &deleter)
        : pointer(ptr)
        , deleter(deleter) {}

    unique_ptr(T *ptr, D &&deleter)
        : pointer(ptr)
        , deleter(std::forward<D>(deleter)) {}

    ~unique_ptr() { get_deleter()(pointer); }

    T *release() {
        T *tmp = get();
        pointer = nullptr;
        return tmp;
    }

    void reset(T *ptr = nullptr) {
        get_deleter()(pointer);
        pointer = ptr;
    }

    void swap(unique_ptr &u_ptr) { std::swap(pointer, u_ptr.pointer); }

    T *get() const { return pointer; }

    D &get_deleter() { return deleter; }

    const D &get_deleter() const { return deleter; }

    operator bool() const { return get() != nullptr; }

    unique_ptr &operator=(const unique_ptr &u_ptr) = delete;

    unique_ptr &operator=(unique_ptr &&u_ptr) {
        reset(u_ptr.release());
        get_deleter() = std::move(u_ptr.get_deleter());
        return *this;
    }

    bool operator==(const unique_ptr &u_ptr) const { return get() == u_ptr.get(); }

    bool operator!=(const unique_ptr &u_ptr) const { return get() != u_ptr.get(); }

    T &operator*() { return *get(); }

    T *operator->() { return get(); }
};

template <typename T, typename D> class unique_ptr<T[], D> {
  private:
    T *pointer;
    D deleter;
    friend std::ostream& operator<<(std::ostream& os, const unique_ptr<T[], D>& up) {
        os << up.get();
        return os;
    }

  public:
    unique_ptr()
        : pointer(nullptr) {}

    unique_ptr(T ptr[])
        : pointer(ptr) {}

    unique_ptr(const unique_ptr &u_ptr) = delete;

    unique_ptr(unique_ptr &&u_ptr)
        : pointer(u_ptr.release())
        , deleter(std::forward<D>(u_ptr.get_deleter())) {}

    unique_ptr(T *ptr, const D &deleter)
        : pointer(ptr)
        , deleter(deleter) {}

    unique_ptr(T *ptr, D &&deleter)
        : pointer(ptr)
        , deleter(std::forward<D>(deleter)) {}

    ~unique_ptr() { get_deleter()(pointer); }

    T *release() {
        T *tmp = get();
        pointer = nullptr;
        return tmp;
    }

    void reset(T *ptr = nullptr) {
        get_deleter()(pointer);
        pointer = ptr;
    }

    void swap(unique_ptr &u_ptr) { std::swap(pointer, u_ptr.pointer); }

    T *get() const { return pointer; }

    D &get_deleter() { return deleter; }

    const D &get_deleter() const { return deleter; }

    operator bool() const { return get() != nullptr; }

    unique_ptr &operator=(const unique_ptr &u_ptr) = delete;

    unique_ptr &operator=(unique_ptr &&u_ptr) {
        reset(u_ptr.release());
        get_deleter() = std::move(u_ptr.get_deleter());
        return *this;
    }

    bool operator==(const unique_ptr &u_ptr) const { return get() == u_ptr.get(); }

    bool operator!=(const unique_ptr &u_ptr) const { return get() != u_ptr.get(); }

    T &operator[](const std::size_t index) { return pointer[index]; }
};

#endif