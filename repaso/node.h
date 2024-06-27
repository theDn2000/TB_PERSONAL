#pragma once

#include "student.h"
#include <memory>
#include<functional>

using namespace std;

struct Node;

using PNode = shared_ptr<Node>;
using LambdaForEach = function<void(Student const &)>;

struct Node
{
    Student data; // Datos del nodo
    PNode next; // Siguiente nodo
};


/**
 * Adds at the end of the list a student
 * @return the head of the list BY REFERENCE
 * @param head The head of the list
 * @param st The student
 */
PNode &push(PNode &head, Student const &st); // Esta funcion devuelve el head POR REFERENCIA


/**
 * Iterates over the list and performs f
 */
void forEach(PNode const &head, LambdaForEach const &f);