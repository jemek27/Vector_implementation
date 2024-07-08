
#ifndef VECTOR_CPP
#define VECTOR_CPP

#include "vector.h"

template <typename T>
Vector<T>::Vector() : Size(0), Capacity(1), Elements(nullptr) {
    Elements = new T[Capacity];
}

template <typename T>
Vector<T>::Vector(std::size_t n) : Size(0), Capacity(n) {
    Elements = new T[Capacity];
}

template <typename T>
Vector<T>::Vector(const Vector<T> &otherV) : Size(otherV.Size), Capacity(otherV.Capacity), Elements(new T[otherV.Capacity]) {
    for (int i = 0; i < Size; i++) {
        Elements[i] = otherV.Elements[i];
    }
}

template <typename T>
Vector<T>::Vector(Vector<T> &&otherV) : Size(otherV.Size), Capacity(otherV.Capacity), Elements(otherV.Elements) {
    otherV.Size = 0;
    otherV.Capacity = 0;
    otherV.Elements = nullptr;
}

template <typename T>
Vector<T>::~Vector() {
    delete[] Elements;
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    if (Size == Capacity) {
        //if fill increase capacity x2
        T* newElements = new T[Capacity * 2];
        for (int i = 0; i < Size; ++i) {
            newElements[i] = Elements[i];
        }
        delete[] Elements;
        Elements = newElements;
        Capacity *= 2;
    }

    Elements[Size++] = value;
}


template <typename T>
void Vector<T>::pop_back() {
    if (Size > 0) {--Size;}
}

template <typename T>
void Vector<T>::insert(std::size_t index, T element) {
    if (Size == Capacity) {
        T* newElements = new T[Capacity * 2];
        for (int i = 0; i < index; ++i) { newElements[i] = Elements[i];}

        newElements[index++] = element;

        for (std::size_t i = index; i <= Size; ++i) { newElements[i] = Elements[i - 1];}

        delete[] Elements;
        Elements = newElements;
        Capacity *= 2;
    } else {
        T temp = Elements[Size - 1];

        for (std::size_t i = Size - 1; i > index; --i) {
            Elements[i] = Elements[i - 1];
        }

        Elements[index] = element;
        Elements[Size] = temp;
    }
    Size++;
}

template <typename T>
void Vector<T>::insert(Vector<T>::Iterator position, T element) {
    if (Size == Capacity) {
        T* newElements = new T[Capacity * 2];
        auto itNew = newElements;
        for (auto it = begin(); it != position; ++it) {*itNew++ = *it;}

        *itNew++ = *position;

        for (auto it = position; it != end(); ++it) {*itNew++ = *it;}

        delete[] Elements;
        Elements = newElements;
        Capacity *= 2;
    } else {
        T temp = Elements[Size - 1];

        for (auto it = end() - 1; it != position; --it) {
            *it = *(it-1);
        }

        *position = element;
        Elements[Size] = temp;
    }
    Size++;
}

template <typename T>
void Vector<T>::erase(std::size_t index) {
    if (index < Size) {
        for (std::size_t i = index; i < Size - 1; i++) {
            Elements[i] = Elements[i + 1];
        }
        pop_back();
    }
}

template <typename T>
void Vector<T>::erase(Vector<T>::Iterator position) {
        for (auto it = position; it != end()-1; ++it) {
            *it = *(it+1);
        }
        pop_back();
}

template <typename T>
void Vector<T>::clear() {
    Size = 0;
    Capacity = 0;
    delete[] Elements;
    Elements = nullptr;
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::find(T Element) const {
    for (int i = 0; i < Size; ++i) {
        if (Element == Elements[i]) {return Iterator(Elements + i);}
    }
    return nullptr;
}

template <typename T>
std::size_t Vector<T>::size() const {
    return Size;
}

template <typename T>
std::size_t Vector<T>::capacity() const {
    return Capacity;
}

template <typename T>
T Vector<T>::at(std::size_t  index) const {
    if (index >= Size) {
        throw std::out_of_range("Index out of range");
    }
    return Elements[index];
}


template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &other) {
    if (this != &other) {
        delete[] Elements;

        Size = other.Size;
        Capacity = other.Capacity;
        Elements = new T[Capacity];

        for (int i = 0; i < Size; i++) {
            Elements[i] = other.Elements[i];
        }
    }

    return *this;
}

template<typename T>
Vector<T> &Vector<T>::operator=(Vector<T> &&other) {
    if (this != &other) {
        delete[] Elements;

        Size = other.Size;
        Capacity = other.Capacity;
        Elements = other.Elements;

        other.Size = 0;
        other.Capacity = 0;
        other.Elements = nullptr;
    }

    return *this;
}

template <typename T>
bool Vector<T>::operator==(const Vector &otherV) const{
    if (Size != otherV.Size) return false;

    for (int i = 0; i < Size; i++) {
        if (Elements[i] != otherV.Elements[i]) return false;
    }

    return true;
}

template <typename T>
bool Vector<T>::operator!=(const Vector &otherV) const{
    return !(*this == otherV);
}

template <typename T>
T &Vector<T>::operator[](const size_t index) {
    return Elements[index];
}

template <typename T>
const T &Vector<T>::operator[](const size_t index) const {
    return Elements[index];
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::begin() {
    return Iterator(Elements);
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::end() {
    return Iterator(Elements + Size);
}

template <typename T>
typename Vector<T>::ConstIterator Vector<T>::begin() const {
    return ConstIterator(Elements);
}

template <typename T>
typename Vector<T>::ConstIterator Vector<T>::end() const {
    return ConstIterator(Elements + Size);
}

#endif // VECTOR_CPP