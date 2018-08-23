// File:    Utility.h
// Author:  Danilo Peixoto
// Date:    15/08/2018

// Evita redefini��o de s�mbolos do arquivo de cabe�alho (caso j� tenha sido inclu�do)
#ifndef CGC_UTILITY_H
#define CGC_UTILITY_H

#include <string>

// Declara��o de tipo incompleto no cabe�alho evita depend�ncia c�clica de arquivos
class TriangleMesh;
class Viewport3D;

// Inst�ncia de "viewport" 3D padr�o
extern Viewport3D viewport3D;

// L� objeto geom�trico triangulado de um arquivo Wavefront OBJ
TriangleMesh * readObject(const std::string & filename);
// Escreve objeto geom�trico triangulado para um arquivo Wavefront OBJ
bool writeObject(const std::string & filename, const TriangleMesh * triangleMesh);
// Exibe objeto geom�trico em uma "viewport" 3D
void showObject(const TriangleMesh * triangleMesh);

#endif