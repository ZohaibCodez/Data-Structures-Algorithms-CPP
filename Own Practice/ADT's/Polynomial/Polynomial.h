#include <stdexcept>
#include <math.h>
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

using namespace std;

struct term
{
    int coefficient;
    int power;
};

class Polynomial
{
private:
    term *terms = nullptr;
    int size;
    int capacity;

    void resize(int newCap)
    {
        term *newTerms = new term[newCap];
        for (int i = 0; i < size; i++)
        {
            newTerms[i] = this->terms[i];
        }
        delete[] terms;
        terms = newTerms;
        capacity = newCap;
    }

    int power(int val, int n)
    {
        int result = 1;
        while (n != 0)
        {
            result *= val;
            n--;
        }
        return result;
    }

public:
    // Constructor
    Polynomial(int cap = 0)
    {
        this->size = 0;
        this->capacity = cap;
        terms = new term[this->capacity];
    }
    // Copy Constructor
    Polynomial(const Polynomial &other)
    {
        this->size = other.size;
        this->capacity = other.capacity;
        this->terms = new term[capacity];
        for (int i = 0; i < size; i++)
        {
            this->terms[i] = other.terms[i];
        }
    }
    // Copy Assignment
    Polynomial &operator=(const Polynomial &other)
    {
        if (this != &other)
        {
            delete[] terms;

            capacity = other.capacity;
            size = other.size;
            terms = new term[capacity];
            for (int i = 0; i < size; i++)
            {
                terms[i] = other.terms[i];
            }
        }
        return *this;
    }
    void addTerm(int coef, int pow)
    {
        for (int i = 0; i < size; i++)
        {
            if (terms[i].power == pow)
            {
                terms[i].coefficient += coef;
                return;
            }
        }

        if (size == capacity)
        {
            resize(capacity * 2);
        }

        for (int i = 0; i < size; i++)
        {
            if (pow < terms[i].power)
            {
                for (int j = size; j > i; j--)
                {
                    terms[j] = terms[j - 1];
                }
                terms[i].power = pow;
                terms[i].coefficient = coef;
                size++;
                return;
            }
        }
        terms[size].coefficient = coef;
        terms[size].power = pow;
        size++;
    }

    int getDegree() const
    {
        if (size == 0)
        {
            return -1;
        }
        return terms[size - 1].power;
    }
    int getCoefficient(int pow) const
    {
        for (int i = 0; i < size; i++)
        {
            if (terms[i].power == pow)
                return terms[i].coefficient;
        }
        return 0;
    }
    int operator()(int value)
    {
        int ev = 0;
        for (int i = 0; i < size; i++)
        {
            ev += ((terms[i].coefficient) * power(value, terms[i].power));
        }
        return ev;
    }
    Polynomial operator+(const Polynomial &other) const
    {
        Polynomial result;
        for (int i = 0; i < size; i++)
            result.addTerm(terms[i].coefficient, terms[i].power);

        for (int i = 0; i < other.size; i++)
            result.addTerm(other.terms[i].coefficient, other.terms[i].power);

        return result;
    }
    Polynomial operator-(const Polynomial &other) const
    {
        Polynomial result = *this;
        for (int i = 0; i < other.size; i++)
        {
            result.addTerm(-other.terms[i].coefficient, other.terms[i].power);
        }
        return result;
    }

    void derivative()
    {
        int newSize = 0;
        for (int i = 0; i < size; i++)
        {
            if (terms[i].power > 0)
            {
                terms[i].coefficient = terms[i].coefficient * terms[i].power;
                terms[i].power = terms[i].power - 1;
                newSize++;
            }
        }
        size = newSize;
    }
    void antiDerivative()
    {
        for (int i = 0; i < size; i++)
        {
            terms[i].power += 1;
            terms[i].coefficient = terms[i].coefficient / terms[i].power;
        }

        if (size == capacity)
            resize(capacity * 2);

        // Adding random constant term
        terms[size].coefficient = 1.0;
        terms[size].power = 0;
        size++;
    }

    void clear()
    {
        for (int i = 0; i < size; i++)
        {
            terms[i].coefficient = 0;
        }
    }
    void setCoefficient(double newCoef, int pow)
    {
        // Check if term with given power already exists
        for (int i = 0; i < size; i++)
        {
            if (terms[i].power == pow)
            {
                terms[i].coefficient = newCoef; // replace
                return;
            }
        }

        // If not found, add new term
        addTerm(newCoef, pow);
    }
    friend ostream &operator<<(ostream &out, const Polynomial &p)
    {
        if (p.size == 0)
        {
            out << "0";
            return out;
        }
        for (int i = 0; i < p.size; i++)
        {
            out << p.terms[i].coefficient;
            if (p.terms[i].power != 0)
            {
                out << "x";
                if (p.terms[i].power != 1)
                {
                    out << "^" << p.terms[i].power;
                }
            }
            if (i != p.size - 1)
            {
                out << "+";
            }
        }
        return out;
    }
    ~Polynomial()
    {
        delete[] terms;
        this->terms = nullptr;
        this->size = 0;
        this->capacity = 0;
    }
};

#endif