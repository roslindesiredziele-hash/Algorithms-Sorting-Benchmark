#include "Vec.h"
#include <algorithm>
#include <stdexcept>

Vec::Vec(int n)
    : cap(n), len(0), mem(new int[cap])
{
}

Vec::Vec(const Vec& other) :
    cap(other.cap),
    len(other.len),
    mem(new int[cap])
{
    for (int i = 0; i < len; i++)
    {
		mem[i] = other.mem[i];
    }
}

Vec& Vec::operator=(Vec other)
{
    std::swap(cap, other.cap);
    std::swap(len, other.len);
    std::swap(mem, other.mem);
    return *this;
}



Vec::~Vec()
{
    delete[] mem;
}

int Vec::size() const
{
    return len;
}

int Vec::capacity() const
{
    return cap;
}

int& Vec::get(int i)
{
    if (i < 0 || i >= len)
        throw std::out_of_range("Index out of range");
    return mem[i];

}

const int& Vec::get(int i) const
{
    return mem[i];
}

void Vec::pop()
{
    if (!empty())
        len--;
}

bool Vec::empty() const
{
    return len == 0;
}

void Vec::resize(int new_cap)
{
    // Ensure capacity is at least 1
    cap = std::max(1, new_cap);

    // Allocate new memory
    int* new_mem = new int[cap];

    // Adjust length if needed
    len = std::min(len, cap);

    // Copy existing elements
    for (int i = 0; i < len; i++)
        new_mem[i] = mem[i];

    // Replace old memory
    delete[] mem;
    mem = new_mem;
}

void Vec::push(int el)
{
    if (len == cap)
        resize(2 * cap);

    mem[len] = el;
    len++;
}

int& Vec::first()
{
    if (empty())
    {
		throw std::out_of_range("Vector is empty");
    }
    return mem[0];
}

const int& Vec::first() const
{
    if (empty())
    {
        throw std::out_of_range("Vector is empty");
    }
    return mem[0];
}

int& Vec::last()
{
    if (empty())
    {
        throw std::out_of_range("Vector is empty");
    }
    return mem[len - 1];
}

const int& Vec::last() const
{
    if (empty())
    {
        throw std::out_of_range("Vector is empty");
    }
    return mem[len - 1];
}

void Vec::clear()
{
    len = 0;
}

bool Vec::contains(int x) const
{
    for (int i = 0; i < len; i++)
        if (mem[i] == x)
            return true;
    return false;
}

int Vec::sum() const
{
    int s = 0;
    for (int i = 0; i < len; i++)
        s += mem[i];
    return s;
}

double Vec::avg() const
{
    if (len == 0)
        return 0.0; // avoid division by zero

    return static_cast<double>(sum()) / len;
}

void Vec::reverse()
{
    for (int i = 0; i < len / 2; i++)
        std::swap(mem[i], mem[len - 1 - i]);
}

void Vec::reverse(int l, int r)
{
    while (l < r)
    {
        std::swap(mem[l], mem[r]);
        l++;
        r--;
    }
}

void Vec::rotate(int x)
{
    if (len == 0)
        return;

    // Normalize x
    x = x % len;
    if (x < 0)
        x += len;

    // If x == 0, no rotation needed
    if (x == 0)
        return;

    // Three-step rotation
    reverse();                 // reverse whole vector
    reverse(0, x - 1);         // reverse first part
    reverse(x, len - 1);       // reverse second part
}
