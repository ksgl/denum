//
//  Fraction.hpp
//  assignment-5
//
//  Created by Ksenia on 22/10/2017.
//  Copyright © 2017 Ksenia. All rights reserved.
//

#ifndef Fraction_hpp
#define Fraction_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>

class Fraction {
private:
    int num = 0;
    int denum = 1;
    
public:
    explicit Fraction(int in_num = 0, int in_denum = 1); //такая реализация проинтерпретирует Fraction frac(5) (то есть только один аргумент) как 5/1, чего я и хотела
    Fraction(const Fraction& rhs);
    ~Fraction();
    
    const int get_num() const;
    const int get_denum() const;
    
    void set_num(int in_num);
    void set_denum(int in_denum);
    
    void reduce();
    void normalize();
    
    Fraction& operator=(const Fraction& rhs);
};

Fraction operator+(const Fraction& lhs, const Fraction& rhs);
Fraction operator-(const Fraction& lhs, const Fraction& rhs);
Fraction operator*(const Fraction& lhs, const Fraction& rhs);
Fraction operator/(const Fraction& lhs, const Fraction& rhs);

bool operator==(const Fraction& lhs, const Fraction& rhs);
bool operator!=(const Fraction& lhs, const Fraction& rhs);
bool operator<(const Fraction& lhs, const Fraction& rhs);
bool operator>(const Fraction& lhs, const Fraction& rhs);

int gcd(int a, int b);

std::ostream& operator<<(std::ostream &os, Fraction const &f);
std::istream &operator>>(std::istream &is, Fraction &a);

void even_change(size_t size, Fraction *fracs);

/*
 почему не сделала операторы членами класса (точнее сначала сделала так, но потом переделалала :) :
 1) https://stackoverflow.com/questions/1145022/difference-between-global-operator-and-member-operator
 2) во Fraction есть весь необходимый интерфейс, для того, чтобы не делать операторы memeber-ами
 3) member -- излишние привилегии для функции, соответственно, больше возможностей повлиять негативно на данные (если функция не нуждается в этих привилегиях, то лучше их не давать)
 4) можно было даже = написать вне класса (это очень просто), но я решила его оставить в классе for the sake of diversity
 5) из минусов такой реализации -- если кто-то будет использовать мой namespace Fraction и переопределит эти операторы, то для Fraction они тоже перестанут нести прежнюю смысловую нагрузку
 
 но + больше, чем -
 поэтому так))
 */


#endif /* Fraction_hpp */

