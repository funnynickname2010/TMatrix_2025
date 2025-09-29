#pragma once
#include <iostream>
#include <stdexcept>
#include <algorithm> // for std::copy and std::swap

using namespace std;

#ifndef MAX_VECTOR_SIZE;
#define constexpr int MAX_VECTOR_SIZE 100000000;
#endif // !MAX_VECTOR_SIZE

// Динамический вектор - 
// шаблонный вектор на динамической памяти
template<typename T>
class TDynamicVector
{
protected:
    size_t size;
    T* pMem;
public:
    // конструктор по умолчанию
    TDynamicVector(size_t sz = 1);

    // конструктор от массива
    TDynamicVector(T* arr, size_t sz);

    // конструктор копирования
    TDynamicVector(const TDynamicVector& v);

    // конструктор перемещения
    TDynamicVector(TDynamicVector&& v) noexcept;

    // деструктор
    ~TDynamicVector();

    //---------------------------------------------------------

    // присваивание
    TDynamicVector& operator=(const TDynamicVector& v);

    // присваивание перемещением
    TDynamicVector& operator=(TDynamicVector&& v) noexcept;

    size_t GetSize() const noexcept { return sz; }

    // индексация
    T& operator[](size_t ind) noexcept;

    // индексация константного вектора
    const T& operator[](size_t ind) const noexcept;

    // индексация с контролем
    T& at(size_t ind);

    // индексация константного вектора с контролем
    const T& at(size_t ind) const;

    // сравнение
    bool operator==(const TDynamicVector& v) const noexcept;
    bool operator!=(const TDynamicVector& v) const noexcept;

    // скалярные операции
    TDynamicVector operator+(T val);
    TDynamicVector operator-(T val);
    TDynamicVector operator*(T val);

    // векторные операции
    TDynamicVector operator+(const TDynamicVector& v);
    TDynamicVector operator-(const TDynamicVector& v);
    T operator*(const TDynamicVector& v) noexcept(noexcept(T())); // What if T() doesn't exist?

    // обмен
    friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept
    {
        std::swap(lhs.sz, rhs.sz);
        std::swap(lhs.pMem, rhs.pMem);
    }

    // ввод/вывод
    friend istream& operator>>(istream& istr, TDynamicVector& v)
    {
        for (size_t i = 0; i < v.sz; i++)
            istr >> v.pMem[i]; // требуется оператор>> для типа T
        return istr;
    }
    friend ostream& operator<<(ostream& ostr, const TDynamicVector& v)
    {
        for (size_t i = 0; i < v.sz; i++)
            ostr << v.pMem[i] << ' '; // требуется оператор<< для типа T
        return ostr;
    }
};