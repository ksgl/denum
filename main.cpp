//
//  main.cpp
//  assignment-5
//
//  Created by Ksenia on 22/10/2017.
//  Copyright © 2017 Ksenia. All rights reserved.
//
/*
 Реализовать класс «Дробь» – Fraction
 В классе перегрузить операции сложения, вычитания, умножения, деления, присваивания, операции отношения и вывода на экран.
 Создать массив объектов и передать его в функцию, которая изменяет каждый элемент массива с четным индексом путем добавления следующего за ним элемента массива, используя реализованные опе- рации.
 */

#include "Fraction.hpp"

int main(int argc, const char * argv[]) {
    try {
        size_t size = 0; //количество дробей в файле
        
        std::fstream file;
        file.exceptions(file.exceptions() | std::ios_base::badbit);
        file.open("/Users/ksenia/Desktop/C/assignment-5/assignment-5/fracs.txt");
        
        if (!file.good()) {
            throw std::runtime_error("unable to open file for reading");
        }
        
        file >> size;
        
        if (size <= 0) {
            throw std::runtime_error("input size is 0 or is less than 0");
        }
        
        Fraction* fracs = new Fraction[size];
        
        for (size_t i = 0; i < size; ++i) {
            file >> fracs[i];
            std::cout << fracs[i];
        }
        
        std::cout << "\n";
        
        while (file.good()) {
            if (file.get() != EOF && !std::isspace(file.get())) {
                throw std::runtime_error("extra data in the input");
            }
        }
        
        even_change(size, fracs);
        
        file.close();
        return EXIT_SUCCESS;
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        return EXIT_FAILURE;
    }
}

