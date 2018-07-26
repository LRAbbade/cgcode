// Evita redefini��o de s�mbolos do arquivo de cabe�alho (caso j� tenha sido inclu�do)
#ifndef CG_GLOBAL_H
#define CG_GLOBAL_H

#include <ostream>
#include <cmath>

// Constantes num�ricas
#define CG_E 2.71828182845904523536
#define CG_PI 3.14159265358979323846
#define CG_INV_PI 0.31830988618379067154
#define CG_EPSILON 2.2204460492503131e-016
#define CG_INFINITY 1.7976931348623158e+308

// Converte �ngulo de radiano para grau
double degrees(double radians) {
    return radians * 180.0 * CG_INV_PI;
}
// Converte �ngulo de grau para radiano
double radians(double degrees) {
    return degrees * CG_PI / 180.0;
}

// Vetor real bidimensional
class Vector2 {
public:
	// Componentes do vetor
	double x, y;
	
	// Construtor padr�o (vetor zero)
	Vector2() : x(0), y(0) {}
	// Construtor de valores iniciais
	Vector2(double x, double y) : x(x), y(y) {}
	
	// Sobrecarga da opera��o "vetor[i]" (retorno mut�vel)
	double & operator [](unsigned int i) {
		return (&x)[i];
	}
	// Sobrecarga da opera��o "vetor[i]" (retornon imut�vel)
	const double & operator [](unsigned int i) const {
		return (&x)[i];
	}
	// Sobrecarga da opera��o "+vetor"
	Vector2 operator +() const {
		return *this;
	}
	// Sobrecarga da opera��o "-vetor"
	Vector2 operator -() const {
		return Vector2(-x, -y);
	}
	// Sobrecarga da opera��o "vetorA + vetorB"
	Vector2 operator +(const Vector2 & rhs) const {
		return Vector2(x + rhs.x, y + rhs.y);
	}
	// Sobrecarga da opera��o "vetorA - vetorB"
	Vector2 operator -(const Vector2 & rhs) const {
		return Vector2(x - rhs.x, y - rhs.y);
	}
	// Sobrecarga da opera��o "vetor * escalar"
	Vector2 operator *(double rhs) const {
		return Vector2(x * rhs, y * rhs);
	}
	// Sobrecarga da opera��o "escalar * vetor"
	friend Vector2 operator *(double lhs, const Vector2 & rhs) {
		return rhs * lhs;
	}
	// Sobrecarga da opera��o "vetor / escalar"
	Vector2 operator /(double rhs) const {
		return Vector2(x / rhs, y / rhs);
	}
	// Sobrecarga da opera��o "vetorA += vetorB"
	Vector2 & operator +=(const Vector2 & rhs) {
		x += rhs.x;
		y += rhs.y;
		
		return *this;
	}
	// Sobrecarga da opera��o "vetorA -= vetorB"
	Vector2 & operator -=(const Vector2 & rhs) {
		x -= rhs.x;
		y -= rhs.y;
		
		return *this;
	}
	// Sobrecarga da opera��o "vetorA *= escalar"
	Vector2 & operator *=(double rhs) {
		x *= rhs;
		y *= rhs;
		
		return *this;
	}
	// Sobrecarga da opera��o "vetorA /= escalar"
	Vector2 & operator /=(double rhs) {
		x /= rhs;
		y /= rhs;
		
		return *this;
	}
	// Sobrecarga da opera��o "vetorA == vetorB"
	bool operator ==(const Vector2 & rhs) const {
		return x == rhs.x && y == rhs.y;
	}
	// Sobrecarga da opera��o "vetorA != vetorB"
	bool operator !=(const Vector2 & rhs) const {
		return !(*this == rhs);
	}
	// Sobrecarga da opera��o "stream << vetor" (imprimir sa�da de dados)
	friend std::ostream & operator <<(std::ostream & lhs, const Vector2 & rhs)  { 
        return lhs << '(' << rhs.x << ' ' << rhs.y << ')'; 
    }
	
	// Retorna produto escalar
	double dot(const Vector2 & rhs) const {
		return x * rhs.x + y * rhs.y;
	}
	// Retorna produto vetorial
	double cross(const Vector2 & rhs) const {
		return x * rhs.y - y * rhs.x;
	}
	// Normaliza vetor (vetor unit�rio)
	Vector2 & normalize() {
		double l2 = length2();
		
		if (l2 > CG_EPSILON * CG_EPSILON)
			*this /= std::sqrt(l2);
			
		return *this;
	}
	// Retorna comprimento do vetor ao quadrado
	double length2() const {
		return dot(*this);
	}
	// Retorna comprimento do vetor
	double length() const {
		return std::sqrt(length2());
	}
};

// Vetor real tridimensional
class Vector3 {
public:
	// Componentes do vetor
	double x, y, z;
	
	// Construtor padr�o (vetor zero)
	Vector3() : x(0), y(0), z(0) {}
	// Construtor de valores iniciais
	Vector3(double x, double y, double z) : x(x), y(y), z(z) {}
	
	// Sobrecarga da opera��o "vetor[i]" (retorno mut�vel)
	double & operator [](unsigned int i) {
		return (&x)[i];
	}
	// Sobrecarga da opera��o "vetor[i]" (retornon imut�vel)
	const double & operator [](unsigned int i) const {
		return (&x)[i];
	}
	// Sobrecarga da opera��o "+vetor"
	Vector3 operator +() const {
		return *this;
	}
	// Sobrecarga da opera��o "-vetor"
	Vector3 operator -() const {
		return Vector3(-x, -y, -z);
	}
	// Sobrecarga da opera��o "vetorA + vetorB"
	Vector3 operator +(const Vector3 & rhs) const {
		return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
	}
	// Sobrecarga da opera��o "vetorA - vetorB"
	Vector3 operator -(const Vector3 & rhs) const {
		return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
	}
	// Sobrecarga da opera��o "vetor * escalar"
	Vector3 operator *(double rhs) const {
		return Vector3(x * rhs, y * rhs, z * rhs);
	}
	// Sobrecarga da opera��o "escalar * vetor"
	friend Vector3 operator *(double lhs, const Vector3 & rhs) {
		return rhs * lhs;
	}
	// Sobrecarga da opera��o "vetor / escalar"
	Vector3 operator /(double rhs) const {
		return Vector3(x / rhs, y / rhs, z / rhs);
	}
	// Sobrecarga da opera��o "vetorA += vetorB"
	Vector3 & operator +=(const Vector3 & rhs) {
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		
		return *this;
	}
	// Sobrecarga da opera��o "vetorA -= vetorB"
	Vector3 & operator -=(const Vector3 & rhs) {
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		
		return *this;
	}
	// Sobrecarga da opera��o "vetorA *= escalar"
	Vector3 & operator *=(double rhs) {
		x *= rhs;
		y *= rhs;
		z *= rhs;
		
		return *this;
	}
	// Sobrecarga da opera��o "vetorA /= escalar"
	Vector3 & operator /=(double rhs) {
		x /= rhs;
		y /= rhs;
		z /= rhs;
		
		return *this;
	}
	// Sobrecarga da opera��o "vetorA == vetorB"
	bool operator ==(const Vector3 & rhs) const {
		return x == rhs.x && y == rhs.y && z == rhs.z;
	}
	// Sobrecarga da opera��o "vetorA != vetorB"
	bool operator !=(const Vector3 & rhs) const {
		return !(*this == rhs);
	}
	// Sobrecarga da opera��o "stream << vetor" (imprimir sa�da de dados)
	friend std::ostream & operator <<(std::ostream & lhs, const Vector3 & rhs)  { 
        return lhs << '(' << rhs.x << ' ' << rhs.y << ' ' << rhs.z << ')'; 
    }
	
	// Retorna produto escalar
	double dot(const Vector3 & rhs) const {
		return x * rhs.x + y * rhs.y + z * rhs.z;
	}
	// Retorna produto vetorial
	Vector3 cross(const Vector3 & rhs) const {
		return Vector3(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
	}
	// Normaliza vetor (vetor unit�rio)
	Vector3 & normalize() {
		double l2 = length2();
		
		if (l2 > CG_EPSILON * CG_EPSILON)
			*this /= std::sqrt(l2);
			
		return *this;
	}
	// Retorna comprimento do vetor ao quadrado
	double length2() const {
		return dot(*this);
	}
	// Retorna comprimento do vetor
	double length() const {
		return std::sqrt(length2());
	}
};

#endif