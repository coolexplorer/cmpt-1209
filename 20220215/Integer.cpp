#include "Integer.h"

Integer::Integer(long long int x) {
    v = x;
}

long long int Integer::getValue() const {
    return v;
}

void Integer::setValue(long long int x) {
    v = x;
}

Integer Integer::operator-() const {
    Integer result(-v);
    return result;
}

Integer Integer::operator+() const {
    return *this;
}

bool Integer::operator<(const Integer &r) const {
    return v < r.v;
}

Integer Integer::operator+(const Integer &r) const {
    return Integer(v + r.v);
}

Integer::operator long long int() const {
    return v;
}

Integer& Integer::operator--() {
    v--;
    return *this;
}

Integer& Integer::operator++() {
    v++;
    return *this;
}

Integer Integer::operator--(int dummy) {
    Integer copy(*this);
    v--;
    return copy;
}

Integer Integer::operator++(int dummy) {
    Integer copy(*this);
    v++;
    return copy;
}

