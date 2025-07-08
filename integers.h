#ifndef INTEGERS_H
#define INTEGERS_H
#include <algorithm>
#include <cmath>

class Integers {
    unsigned int a;
    unsigned int b;
public:
    Integers() : a(0), b(0) {}

    Integers(unsigned int _a, unsigned int _b) : a(_a), b(_b) {}

    Integers(const Integers& other) : a(other.a), b(other.b) {}

    unsigned int gcd() const {
        if (a == 0 || b == 0) return 0;

        unsigned int x = a;
        unsigned int y = b;
        while (y != 0) {
            x %= y;
            std::swap(x, y);
        }
        return x;
    }

    unsigned int lcm() const {
        if (a == 0 || b == 0) return 0;
        unsigned int g = gcd();
        return (a / g) * b;
    }

    bool isPrime() const {
        if (a < 2) return false;
        if (a == 2) return true;

        if (a % 2 == 0) return false;

        int num = static_cast<int>(a);
        int limit = static_cast<int>(std::sqrt(num));
        for (int i = 2; i <= limit; ++i) {
            if (num % i == 0) return false;
        }
        return true;
    }
    bool isArmstrong() const {
        unsigned int number = a;
        if (number == 0) return true;

        int numDigits = 0;
        unsigned int temp = number;
        while (temp != 0) {
            numDigits++;
            temp /= 10;
        }

        unsigned long long sum = 0;
        temp = number;
        while (temp != 0) {
            unsigned int digit = temp % 10;
            unsigned long long power = 1;
            for (int i = 0; i < numDigits; ++i) {
                power *= digit;
            }
            sum += power;
            temp /= 10;
        }
        return (sum == number);
    }

    void setA(unsigned int value) {
        a = value;
    }
    void setB(unsigned int value) {
        b = value;
    }
};

#endif // INTEGERS_H
