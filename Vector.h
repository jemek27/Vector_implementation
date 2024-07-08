
#ifndef EJ_VECTOR_VECTOR_H
#define EJ_VECTOR_VECTOR_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Vector {
private:
    std::size_t Size;
    std::size_t Capacity;
    T* Elements;

public:
    Vector();
    Vector(std::size_t n);
    Vector(const Vector<T> &otherV);
    Vector(Vector<T> &&otherV);

    ~Vector();

    class ConstIterator;
    class Iterator;

    void push_back(const T& value);
    void pop_back();
    void insert(std::size_t index, T element);
    void insert(Vector<T>::Iterator position, T element);
    void erase(std::size_t index);
    void clear();
    void erase(Vector<T>::Iterator position);
    Iterator find(T Element) const;
    std::size_t size() const;
    std::size_t capacity() const;
    T at(std::size_t index) const;

    Vector<T>& operator=(const Vector<T>& other);
    Vector<T>& operator=(Vector<T>&& other);
    bool operator==(const Vector<T>& other) const;
    bool operator!=(const Vector<T>& other) const;
    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;

    class ConstIterator {
        T* Ptr;
    public:
        ConstIterator(T* const ptr) : Ptr(ptr) {};
        ConstIterator(const Vector<T>& vec) : Ptr(vec.Elements) {};

        ConstIterator& operator++() noexcept {++Ptr; return *this;}
        ConstIterator  operator++(int) noexcept {ConstIterator temp = *this; ++Ptr; return temp;}
        ConstIterator& operator--() noexcept {--Ptr; return *this;}
        ConstIterator  operator--(int) noexcept {ConstIterator temp = *this; --Ptr; return temp;}
        ConstIterator operator-(std::ptrdiff_t n) const {return Iterator(Ptr - n);}
        ConstIterator operator+(std::size_t n) const {return Iterator(Ptr + n);}
        const T& operator*() const noexcept {return *Ptr;}
        bool operator==(const ConstIterator& other) const noexcept {return Ptr == other.Ptr;}
        bool operator!=(const ConstIterator& other) const noexcept {return Ptr != other.Ptr;}
    };

    class Iterator {
        T* Ptr;
    public:
        Iterator(T* const ptr) : Ptr(ptr) {};
        Iterator(const Vector<T>& vec) : Ptr(vec.Elements) {};

        Iterator& operator++() noexcept {++Ptr; return *this;}
        Iterator  operator++(int) noexcept {Iterator temp = *this; ++Ptr; return temp;}
        Iterator& operator--() noexcept {--Ptr; return *this;}
        Iterator  operator--(int) noexcept {Iterator temp = *this; --Ptr; return temp;}
        Iterator operator-(std::ptrdiff_t n) const {return Iterator(Ptr - n);} //std::size_t też git
        Iterator operator+(std::size_t n) const {return Iterator(Ptr + n);}
        T& operator*() const noexcept {return *Ptr;}
        bool operator==(const Iterator& other) const noexcept {return Ptr == other.Ptr;}
        bool operator!=(const Iterator& other) const noexcept {return Ptr != other.Ptr;}
    };

    Iterator begin();
    Iterator end();
    ConstIterator begin() const;
    ConstIterator end() const;
};

#include "Vector.cpp"


#endif //EJ_VECTOR_VECTOR_H