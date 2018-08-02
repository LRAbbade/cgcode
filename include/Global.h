// File:    Global.h
// Author:  Danilo Peixoto
// Date:    02/08/2018

// Evita redefini��o de s�mbolos do arquivo de cabe�alho (caso j� tenha sido inclu�do)
#ifndef CGC_GLOBAL_H
#define CGC_GLOBAL_H

// Bibliotecas
#include <ostream>
#include <cmath>
#include <Vector.h>
#include <Matrix.h>

// Constantes num�ricas
#define CGC_E 2.71828182845904523536
#define CGC_PI 3.14159265358979323846
#define CGC_INV_PI 0.31830988618379067154
#define CGC_EPSILON 2.2204460492503131e-016
#define CGC_INFINITY 1.7976931348623158e+308

// Converte �ngulo de radiano para grau
double degrees(double radians) {
    return radians * 180.0 * CGC_INV_PI;
}
// Converte �ngulo de grau para radiano
double radians(double degrees) {
    return degrees * CGC_PI / 180.0;
}

#endif