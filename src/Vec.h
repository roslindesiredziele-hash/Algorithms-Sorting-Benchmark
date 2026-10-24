#ifndef VEC_H
#define VEC_H

class Vec
{
private:
    int cap;
    int len;
    int* mem;

public:
    Vec(int n);
    ~Vec();

    int size() const;
    int capacity() const;

    int& get(int i);
    const int& get(int i) const;

    void pop();
    bool empty() const;

    void resize(int new_cap);

    void push(int el);

    int& first();
    const int& first() const;

    int& last();
    const int& last() const;

    void clear();
    bool contains(int x) const;
    int sum() const;
    double avg() const;

    void reverse();
    void reverse(int l, int r);

    void rotate(int x);

    Vec(const Vec& other);
    Vec& operator=(Vec cpy);
};

#endif

