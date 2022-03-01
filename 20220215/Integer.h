#ifndef INTEGER_H
#define INTEGER_H

class Integer {
public:
    Integer(long long int = 0LL);
    long long int getValue() const;
    void setValue(long long int);

    operator long long int() const;
    Integer operator-() const;
    Integer operator+() const;
    Integer& operator--();
    Integer& operator++();
    Integer operator--(int);
    Integer operator++(int);
    Integer operator-(const Integer&) const;
    Integer operator+(const Integer&) const;
    bool operator<(const Integer&) const;

private:
    long long int v;
};

Integer operator+(Integer l, double r) {
    return Integer(l.getValue() + r);
}

#endif