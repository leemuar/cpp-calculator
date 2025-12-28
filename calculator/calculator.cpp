#include <iostream>
#include <string>
#include <cmath>
#include "calculator.h"


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
    
    // результаты возврата функции
    const bool SUCCESS = true;
    const bool FAIL    = false;
    
    // значение, изменяемое калькулятором
    Number current = 0;
    // значение следующего операнда
    Number next    = 0;
    // команда операции
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

        // вывод сохраненного значения
        if ( operation == "="s ) {
            std::cout << current << std::endl;
            continue;    
        }

        // очистка сохраненного значения
        if ( operation == "c"s ) {
            current = 0;
            continue;
        } 

        // сохранение текущего значения в ячейку памяти
        if ( operation == "s"s ) {
            memory_value    = current;
            is_memory_empty = false;
            continue;
        }

        // загрузка текущего значения из ячейки памяти
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

        // сложение
        if ( operation == "+"s ) {
            current += next;
            continue;    
        } 

        // вычитание
        if ( operation == "-"s ) {
            current -= next;
            continue; 
        }

        // умножение
        if ( operation == "*"s ) {
            current *= next;
            continue;
        }

        // деление
        if ( operation == "/"s ) {
            current /= next;
            continue;
        } 

        // возведение в степень
        if ( operation == "**"s ) {
            current = std::pow( current, next );
            continue;    
        } 

        // явное задание числа, хранимого в калькуляторе 
        if ( operation == ":"s ) {
            current = next;
            continue;
        }  
        
        // если дошли сюда - значит ни один оператор выше не сработал
        std::cerr << "Error: Unknown token "s << operation << std::endl;
        return FAIL;

    }
    
    // основной цикл калькулятора выше прервется в случае успешного завершения
    // и дойдет сюда
    // вернем признак успешности выполнения рассчетов
    return SUCCESS;
}