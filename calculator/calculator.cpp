// В этом файле определения функций.
// За основу возьмите решение предыдущей задачи.

#include <iostream>
#include <string>
#include <cmath>
#include "calculator.h"


void Plus( Number& dest, const Number operand ) {
    dest += operand;
}

void Minus( Number& dest, const Number operand ) {
    dest -= operand;
}

void Multiply( Number& dest, const Number operand ) {
    dest *= operand;
}

void Divide( Number& dest, const Number operand ) {
    dest /= operand;
}

void Power( Number& dest, const Number operand ) {
    dest = std::pow( dest, operand );
}


bool ReadNumber( Number& result ) 
{
    std::cin >> result;
    if ( !std::cin ) {
         std::cerr << "Error: Numeric operand expected" << std::endl;
         return false;
    }
    return true;
}


bool RunCalculatorCycle()
{
    using namespace std::literals;
    
    // значения результата возврата функции
    const bool SUCCESS = true;
    const bool FAIL    = false;
    
    Number current = 0;
    Number next    = 0;
    std::string operation = ""s;
    
    // ячейка памяти калькулятора
    Number memory_value  = 0;
    bool is_memory_empty = true;
    
    // гарантируется что ввод первым содержит число, прочитаем его
    // если не получится - сразу завершим работу
    if ( ! ReadNumber( current ) ) {
        return FAIL;
    }
    
    // основной цикл калькулятора
    while ( true ) {
        
        // прочитаем следующую операцию
        std::cin >> operation;
        
        // в зависимости от операции - выполним действия калькулятора
        // сначала проверим операции, не требующие чтения второго операнда
        if ( operation == "q"s ) {
            return SUCCESS; 
        }

        if ( operation == "="s ) {
            std::cout << current << std::endl;
            continue;    
        }

        if ( operation == "c"s ) {
            current = 0;
            continue;
        } 

        if ( operation == "s"s ) {
            memory_value    = current;
            is_memory_empty = false;
            continue;
        }

        if ( operation == "l"s ) {
            if ( is_memory_empty ) {
                std::cerr << "Error: Memory is empty"s << std::endl;
                return FAIL;
            }
            current = memory_value;
            continue;
        }
        
        // дальше операции, требующие второго операнда
        
        // прочитаем второй операнд
        if( !ReadNumber( next ) ) {
            return FAIL;
        }
        
        // выполним операции
        if ( operation == "+"s ) {
            Plus( current, next );
            continue;    
        } 

        if ( operation == "-"s ) {
            Minus( current, next );
            continue; 
        }

        if ( operation == "*"s ) {
            Multiply( current, next );
            continue;
        }

        if (operation == "/"s) {
            Divide( current, next );
            continue;

        } 

        if (operation == "**"s) {
            Power( current, next );
            continue;    
        } 

        if (operation == ":"s) {
            current = next;
            continue;
        }  
        
        // если дошли сюда - значит ни один оператор выше не сработал
        std::cerr << "Error: Unknown token "s << operation << std::endl;
        return FAIL;

    }
    
    return SUCCESS;
}