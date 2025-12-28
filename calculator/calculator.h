// В этом файле объявления функций.
#pragma once

using Number = double;

bool ReadNumber( Number& result );

bool RunCalculatorCycle();

void Plus( Number& dest, const Number operand );

void Minus( Number& dest, const Number operand );

void Multiply( Number& dest, const Number operand );

void Divide( Number& dest, const Number operand );

void Power( Number& dest, const Number operand );
