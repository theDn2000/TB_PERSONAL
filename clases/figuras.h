#pragma once

class FiguraGeometricaRegular {
public:
    FiguraGeometricaRegular(int nLados, float lado);
    
    void setnLados(int nLados); 
    void setLado(float lado);
    int getnLados() const;
    float getLado() const;

    float getPerimetro(); //funcion comun en todas

    virtual float getArea() const = 0; //funcion virtual pura

    virtual void queSoy() const; //funcion virtual


    protected:
        float lado;
        int nLados;
};

class Cuadrado : public FiguraGeometricaRegular {

public:
    Cuadrado(float lado): FiguraGeometricaRegular(4, lado) {};

    float getArea() const; //comun en las hijas pero para cada una es distinta
    float getDiagonal() const; //comun solo de esta hija

    void queSoy() const; //comun en las hijas pero para cada una es distinta

};

class TrianguloEq : public FiguraGeometricaRegular {

public:
    TrianguloEq(float lado);

    float getArea() const;
    float getAltura() const;

    void queSoy() const;

};

class Pentagono : public FiguraGeometricaRegular {

public:
    Pentagono(float lado): FiguraGeometricaRegular(5, lado) {};

    float getArea() const;
    float getApotema() const;

    void queSoy() const;

};
/*
si todas las clases hija tiene una funcion comun que hacen disinto
puede ser una funcon virtual: en cada hijo se va a implementar
de una manera distinta, en cada hijo va a ser distinta y el
=0 significa que en el padre no la voy a implementar


si cuadrado hereda de figura.. me fuerza a que la funcion
virtual este en la clase cuadrado
es decir, en todos los hijos

en el padre tiene una implementacion cuando no es pura
es decir, que si una clase hija no la tiene implementada
cuando se ejecute llamara a la implementacion de la funcion 
del padre
*/