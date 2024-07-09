#include "figuras.h"
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

//inicializa el numero de lados y el lado
FiguraGeometricaRegular::FiguraGeometricaRegular(int nLados, float lado): nLados{nLados}, lado{lado} {
    if (nLados < 3 || lado <= 0) {
        throw new string {"El numero de lados debe ser mayor o igual a 3 y el lado debe ser mayor a 0"};
    }

}

int FiguraGeometricaRegular::getnLados() const {return nLados;}
float FiguraGeometricaRegular::getLado() const {return lado;}

void FiguraGeometricaRegular::queSoy() const {
    std::cout << "Soy una figura geometrica regular" << std::endl;
}

void FiguraGeometricaRegular::setnLados(int nLados) {
    if (nLados < 3) {
        throw new string {"El numero de lados debe ser mayor o igual a 3"};
    }
    this->nLados = nLados;
}

void FiguraGeometricaRegular::setLado(float lado) {
    if (lado <= 0) {
        throw new string {"El lado debe ser mayor a 0"};
    }
    this->lado = lado;
}

float FiguraGeometricaRegular::getPerimetro() {
    return nLados * lado;
}

Cuadrado::Cuadrado(float lado): FiguraGeometricaRegular(4, lado) {}
float Cuadrado::getDiagonal() const {
    return lado * sqrt(2);
}
float Cuadrado::getArea() const {
    return lado * lado;
}

void Cuadrado::queSoy() {
    cout << "Soy un cuadrado" << endl;
}

TrianguloEq::TrianguloEq(float lado): FiguraGeometricaRegular(3, lado) {}


float TrianguloEq::getArea() const {
    return (sqrt(3) / 4) * lado * lado;
}

float TrianguloEq::getAltura() const {
    return (sqrt(3) / 2) * lado;
}

void TrianguloEq::queSoy() {
    cout << "Soy un triangulo equilatero" << endl;
}

Pentagono::Pentagono(float lado): FiguraGeometricaRegular(5, lado) {}

float Pentagono::getArea() const {
    return (5 * lado * lado) / (4 * tan(3.1416 / 5));
}

float Pentagono::getApotema() const {
    return lado / (2 * tan(3.1416 / 5));
}

void Pentagono::queSoy() {
    cout << "Soy un pentagono" << endl;
}

