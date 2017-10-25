//
//  Fraction.cpp
//  assignment-5
//
//  Created by Ksenia on 22/10/2017.
//  Copyright © 2017 Ksenia. All rights reserved.
//

#include "Fraction.hpp"

//constructors

Fraction::Fraction(int in_num, int in_denum) //конструктор с параметрами
: num(in_num)
, denum(in_denum)
{
    if (denum == 0) {
        throw std::invalid_argument("Denum can't be zero. Instance not created.");
    }
    
    if (denum < 0) { //нормализация, переносим минус в числитель
        normalize();
    }
}

Fraction::Fraction(const Fraction& rhs) { //конструктор копирования
    num = rhs.num;
    
    if (rhs.denum == 0) {
        throw std::invalid_argument("Denum can't be zero. Instance not created.");
    }
    
    if (rhs.denum < 0) {
        num = -num;
        denum = -rhs.denum;
    }
    
    if (rhs.denum > 0) {
        denum = rhs.denum;
    }
}

Fraction::~Fraction() {
}

//getters

const int Fraction::get_num() const {
    return num;
}

const int Fraction::get_denum() const {
    return denum;
}

//setters

void Fraction::set_num(const int in_num) {
    num = in_num;
}

void Fraction::set_denum(const int in_denum) {
    if (in_denum == 0) {
        throw std::invalid_argument("Denum can't be zero. Instance not created.");
    }
    
    if (in_denum < 0) {
        num = -num;
        denum = -in_denum;
    }
    
    if (in_denum > 0) {
        denum = in_denum;
    }
}

//greatest common divisor & reduction

int gcd (int a, int b) { //greatest common divisor, алгоритм нахождения наибольшего общего делителя
    if (a == 0) return b;
    
    return gcd(b % a, a);
}

void Fraction::reduce() { //сокращение дроби
    if (denum == 0) {
        throw std::invalid_argument("Denum can't be zero. Instance not created.");
    }
    
    if (denum < 0) {
        normalize();
    }
    
    const auto tmp = gcd(num, denum);
    
    if (tmp != 1) {
        denum /= tmp;
        num /= tmp;
    }
}

void Fraction::normalize() {
    if (denum == 0) {
        throw std::invalid_argument("Denum can't be zero. Instance not created.");
    }
    
    num = -num;
    denum = -denum;
}

//overloaded ops

Fraction& Fraction::operator=(const Fraction& rhs) {
    if (denum == 0 || rhs.denum == 0) {
        throw std::invalid_argument("Denum can't be zero. Instance not created.");
    }
    
    if (this == &rhs) {
        
        return *this;
    }
    
    num = rhs.num;
    
    if (rhs.denum < 0) {
        num = -num;
        denum = -rhs.denum;
    }
    
    if (rhs.denum > 0) {
        denum = rhs.denum;
    }
    
    return *this;
}

Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    Fraction inst;
    
    if (lhs.get_denum() == 0 || rhs.get_denum() == 0) {
        throw std::invalid_argument("Denum can't be zero. Instance not created.");
    }
    
    if (lhs.get_denum() == rhs.get_denum()) {
        inst.set_num(lhs.get_num() + rhs.get_num());
        inst.set_denum(lhs.get_denum());
    }
    else {
        inst.set_num(lhs.get_num() * rhs.get_denum() + rhs.get_num() * lhs.get_denum());
        inst.set_denum(lhs.get_denum() * rhs.get_denum());
    }
    
    inst.reduce();
    return inst;
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
    Fraction inst;
    
    if (lhs.get_denum() == 0 || rhs.get_denum() == 0) {
        throw std::invalid_argument("Denum can't be zero. Instance not created.");
    }
    
    if (lhs.get_denum() == rhs.get_denum()) {
        inst.set_num(lhs.get_num() - rhs.get_num());
        inst.set_denum(lhs.get_denum());
    }
    else {
        inst.set_num(lhs.get_num() * rhs.get_denum() - rhs.get_num() * lhs.get_denum());
        inst.set_denum(lhs.get_denum() * rhs.get_denum());
    }
    
    inst.reduce();
    return inst;
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    Fraction inst;
    
    if (lhs.get_denum() == 0 || rhs.get_denum() == 0) {
        throw std::invalid_argument("Denum can't be zero. Instance not created.");
    }
    
    inst.set_num(lhs.get_num() * rhs.get_num());
    inst.set_denum(lhs.get_denum() * rhs.get_denum());
    
    inst.reduce();
    return inst;
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
    Fraction inst;
    
    if (lhs.get_denum() == 0 || rhs.get_denum() == 0) {
        throw std::invalid_argument("Denum can't be zero. Instance not created.");
    }
    
    inst.set_num(lhs.get_num() * rhs.get_denum());
    inst.set_denum(lhs.get_denum() * rhs.get_num());
    
    inst.reduce();
    return inst;
}

bool operator==(const Fraction& lhs, const Fraction& rhs) {
    if (lhs.get_denum() == 0 || rhs.get_denum() == 0) {
        throw std::invalid_argument("Denum can't be zero. Instance not created.");
    }
    
    return lhs.get_num() == rhs.get_num() && lhs.get_denum() == rhs.get_denum();
}

bool operator!=(const Fraction& lhs, const Fraction& rhs) {
    if (lhs.get_denum() == 0 || rhs.get_denum() == 0) {
        throw std::invalid_argument("Denum can't be zero. Instance not created.");
    }
    
    return !(lhs == rhs);
}

bool operator<(const Fraction& lhs, const Fraction& rhs){
    if (lhs.get_denum() == 0 || rhs.get_denum() == 0) {
        throw std::invalid_argument("Denum can't be zero. Instance not created.");
    }
    
    return (lhs.get_num() * rhs.get_denum()) < (rhs.get_num() * lhs.get_denum());
}

bool operator>(const Fraction& lhs, const Fraction& rhs){
    if (lhs.get_denum() == 0 || rhs.get_denum() == 0) {
        throw std::invalid_argument("Denum can't be zero. Instance not created.");
    }
    
    return (lhs.get_num() * rhs.get_denum()) > (rhs.get_num() * lhs.get_denum());
}

std::istream &operator>>(std::istream &is, Fraction &a) {
    int is_num, is_denum = 0;
    
    is >> is_num;
    a.set_num(is_num);
    
    is >> is_denum;
    a.set_denum(is_denum);
    
    return is;
}

std::ostream& operator<<(std::ostream &os, Fraction const &f) {
    os << f.get_num() << "/" << f.get_denum() << "  ";
    
    return os;
}

void even_change(size_t size, Fraction *fracs) { //функция из задания, меняет каждый четный элемент путём прибавления к нему следующего
    for (int i = 0; i < size; ++i) {
        if (i % 2 == 0) {
            fracs[i] = fracs[i] + fracs[i + 1];
        }
        std::cout << fracs[i];
    }
}

/*
 про normalize
 вынесла в функцию, однако это не нужно было, потому что дробь нормализуется для разных функций по разным аргументам, не уверена что это действительно стоит обобщать
 в принципе вместо normalize у меня стояли две строки
 
 про проверки denum == 0
 посчитала, что не стоит их выносить в функцию, так как это делает код менее наглядным
 хоть и копипаст, но его тут не сильно много
 */

