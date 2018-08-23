// File:    Color.h
// Author:  Danilo Peixoto
// Date:    05/08/2018

// Evita redefini��o de s�mbolos do arquivo de cabe�alho (caso j� tenha sido inclu�do)
#ifndef CGC_COLOR_H
#define CGC_COLOR_H

#include <ostream>

// Cor RGB linear
class Color3 {
public:
    // Componentes de cor
    double r, g, b;

    // Construtor padr�o (cor preta)
    Color3();
    // Construtor c�pia
    Color3(const Color3 & color3);
    // Construtor para valores iniciais
    Color3(double r, double g, double b);
    // Destrutor padr�o
    ~Color3();

    // Sobrecarga da opera��o "cor[i]" (retorno mut�vel)
    double & operator [](size_t i);
    // Sobrecarga da opera��o "cor[i]" (retorno imut�vel)
    const double & operator [](size_t i) const;
    // Sobrecarga da opera��o "+cor"
    Color3 operator +() const;
    // Sobrecarga da opera��o "-cor"
    Color3 operator -() const;
    // Sobrecarga da opera��o "corA + corB"
    Color3 operator +(const Color3 & rhs) const;
    // Sobrecarga da opera��o "corA - corB"
    Color3 operator -(const Color3 & rhs) const;
    // Sobrecarga da opera��o "cor * escalar"
    Color3 operator *(double rhs) const;
    // Sobrecarga da opera��o "escalar * cor"
    friend Color3 operator *(double lhs, const Color3 & rhs);
    // Sobrecarga da opera��o "cor / escalar"
    Color3 operator /(double rhs) const;
    // Sobrecarga da opera��o "corA += corB"
    Color3 & operator +=(const Color3 & rhs);
    // Sobrecarga da opera��o "corA -= corB"
    Color3 & operator -=(const Color3 & rhs);
    // Sobrecarga da opera��o "cor *= escalar"
    Color3 & operator *=(double rhs);
    // Sobrecarga da opera��o "cor /= escalar"
    Color3 & operator /=(double rhs);
    // Sobrecarga da opera��o "corA == corB"
    bool operator ==(const Color3 & rhs) const;
    // Sobrecarga da opera��o "corA != corB"
    bool operator !=(const Color3 & rhs) const;
    // Sobrecarga da opera��o "sa�da << cor" (imprimir sa�da de dados)
    friend std::ostream & operator <<(std::ostream & lhs, const Color3 & rhs);

    // Aplica corre��o gamma � cor
    Color3 & applyGamma(double gamma);
    // Aplica corre��o de exposi��o � cor
    Color3 & applyExposure(double exposure);
    // Satura cor (linear)
    Color3 & saturate();
};

// Cor RGBA linear
class Color4 {
public:
    // Componentes de cor
    double r, g, b, a;

    // Construtor padr�o (transparente)
    Color4();
    // Construtor c�pia
    Color4(const Color4 & color4);
    // Construtor para valores iniciais
    Color4(double r, double g, double b, double a);
    // Destrutor padr�o
    ~Color4();

    // Sobrecarga da opera��o "cor[i]" (retorno mut�vel)
    double & operator [](size_t i);
    // Sobrecarga da opera��o "cor[i]" (retorno imut�vel)
    const double & operator [](size_t i) const;
    // Sobrecarga da opera��o "+cor"
    Color4 operator +() const;
    // Sobrecarga da opera��o "-cor"
    Color4 operator -() const;
    // Sobrecarga da opera��o "corA + corB"
    Color4 operator +(const Color4 & rhs) const;
    // Sobrecarga da opera��o "corA - corB"
    Color4 operator -(const Color4 & rhs) const;
    // Sobrecarga da opera��o "cor * escalar"
    Color4 operator *(double rhs) const;
    // Sobrecarga da opera��o "escalar * cor"
    friend Color4 operator *(double lhs, const Color4 & rhs);
    // Sobrecarga da opera��o "cor / escalar"
    Color4 operator /(double rhs) const;
    // Sobrecarga da opera��o "corA += corB"
    Color4 & operator +=(const Color4 & rhs);
    // Sobrecarga da opera��o "corA -= corB"
    Color4 & operator -=(const Color4 & rhs);
    // Sobrecarga da opera��o "cor *= escalar"
    Color4 & operator *=(double rhs);
    // Sobrecarga da opera��o "cor /= escalar"
    Color4 & operator /=(double rhs);
    // Sobrecarga da opera��o "corA == corB"
    bool operator ==(const Color4 & rhs) const;
    // Sobrecarga da opera��o "corA != corB"
    bool operator !=(const Color4 & rhs) const;
    // Sobrecarga da opera��o "sa�da << cor" (imprimir sa�da de dados)
    friend std::ostream & operator <<(std::ostream & lhs, const Color4 & rhs);

    // Aplica corre��o gamma � cor
    Color4 & applyGamma(double gamma);
    // Aplica corre��o de exposi��o � cor
    Color4 & applyExposure(double exposure);
    // Satura cor (linear)
    Color4 & saturate();
};

#endif