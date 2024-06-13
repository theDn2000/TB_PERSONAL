#include <iostream>
#include <string>
#include <vector>

#include <algorithm>

// Include the functions
#include "functions.h"

using namespace std;


/*
struct Car {
    string brand;
    string plate;
};

struct Person {
    string name;
    int age;
    string dni;
    string mail;
    Car car;
    bool regalo;
};


// Person
void printPerson(Person p) 
{
    p.name = "Pepe";
    cout << "Age: " << p.age << endl;
    cout << "DNI: " << p.dni << endl;
    cout << "Mail: " << p.mail << endl;
    cout << "Car brand: " << p.car.brand << endl;
}

void PrintPerson_optimus(Person &p) 
{
    p.name = "Pepe"; // EFECTO COLATERAL, se modifica el valor original NO SE DEBE HACER NUNCA!!!
    cout << "Age: " << p.age << endl;
    cout << "DNI: " << p.dni << endl;
    cout << "Mail: " << p.mail << endl;
    cout << "Car brand: " << p.car.brand << endl;
}

void PrintPerson_optimus_solved(Person const &p) 
{
    //p.name = "Pepe"; // EFECTO COLATERAL SOLUCIONADO, no se puede modificar el valor original
    cout << "Age: " << p.age << endl;
    cout << "DNI: " << p.dni << endl;
    cout << "Mail: " << p.mail << endl;
    cout << "Car brand: " << p.car.brand << endl;
}


//Strings
vector<string> separate_string_separator(string & s, string separator)
{
    vector<string> v;
    int pos = 0;
    while ((pos = s.find(separator)) != string::npos)
    {
        v.push_back(s.substr(0, pos));
        s.erase(0, pos + separator.length());
    }
    v.push_back(s);
    return v;
}



// Print the name of the persons that are not minors
void print_adults(vector<Person> const &personas) // En el caso de no ser una funcion, podemos poner &p para que no se copie
    {
        for (auto p : personas)  // Como el vector es de personas, p es de tipo persona. Auto es para que el compilador lo deduzca
        {
            if (p.age >= 18) {
                // Pon el parametro regalo a false
                p.regalo = false;
                cout << p.name << endl;
            }
        }
    }
*/
int main() {
/*
    int myNumber{3};
    int myOtherNumber = 3;
    long myLongNumber{3};
    long long myLongLongNumber{3};
    unsigned int myUnsignedNumber{3};
    unsigned long myUnsignedLongNumber{3};
    unsigned long long myUnsignedLongLongNumber{3}; // Enteros largos sin signo

    float myFloatNumber{3.0}; // Decimales
    double myDoubleNumber{3.0}; // Decimales

    // habitualmente int, float

    // Text
    char myChar{'a'}; // Caracteres 
    //std::string myString{"Hola mundo"}; // Cadenas de texto
    string myString{"Hola mundo"}; // Cadenas de texto

    // Boolean
    bool myBoolean{true}; // Verdadero o falso

    // Structs
    Person alberto{"Alberto", 30, "12345678A", "alberto@mail.com", Car{"Seat", "1234ABC"}, true}; // Estructuras
    Person juan = {"Juan", 15, "12345678A", "juan@mail.com", Car{"Mini", "5678DEF"}, true};
    Person jose = {"Jose", 74, "12345678A", "jose@mail.com", Car{"Renault", "5678DEF"}};
    Person marta = {"Marta", 51, "12345678A", "marta@mail.com", Car{"Citroen", "5678DEF"}, true};
    Person claudia = {"Claudia", 8, "12345678A", "claudia@mail.com", Car{"Ferrari", "5678DEF"}, true};

    vector<Person> personas{alberto, juan};
    personas.push_back(jose);
    personas.push_back(marta);
    personas.push_back(claudia);



    print_adults(personas);

*/

    //PrintPerson_optimus_solved(alberto);
    //std::cout << "Hola mundo, esto es una prueba secundaria" << std::endl;
    

/*
    // STRINGS
    // Ejercicio 1: Crear string y remplazar por _
    std::string s{"Hello"};

    for (int i = 0; i < s.size(); i++)
    {
        s[i] = '_';
    }
    cout << s << endl;

    // Ejercicio 2: 3 Strings concatenadas con +
    std::string s1{"Hola"};
    std::string s2{"soy"};
    std::string s3{"Dani"};

    std::string s4 = s1 + " " + s2 + " " + s3;
    
    cout << s4 << endl;
    
    // Ejercicio 3: Buscar subcadena dentro de otra, si la encuentra la remplaza por otra
    std::string s5{"Hola soy Dani"};
    std::string s6{"Dani"};

    int pos = s5.find(s6);
    if (pos != -1)
    {
        s5.replace(pos, s6.size(), "Alberto");
        cout << s5 << endl;
    }
    else
    {
        cout << "No se ha encontrado la subcadena" << endl;
    }

    // Ejercicio 4: Invierte una cadena
    std::string s7{"Hola soy Dani"};

    for (int i = 0; i < s7.size() / 2; i++)
    {
        char temp = s7[i];
        s7[i] = s7[s7.size() - 1 - i];
        s7[s7.size() - 1 - i] = temp;
    }
    cout << s7 << endl;

    std::reverse(s7.begin(), s7.end());

    cout << s7 << endl;
    
    
    // Ejercicio 5: Cuenta las vocales de una cadena
    std::string s8{"Hola soy Dani"};
    int count = 0;

    for (auto & letra : s8)
    {
        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u')
        {
            count++;
        }
    }

    cout << "Vocales: " <<count << endl;

    // Ejercicio 6: Compara si dos cadenas son iguales
    std::string s9{"Hola"};
    std::string s10{"Hello"};

    if (s9 == s10)
    {
        cout << "Son iguales" << endl;
    }
    else
    {
        cout << "No son iguales" << endl;
    }

    // Ejercicio 7: Extrae subcadena de una cadena hasta encontrar un espacio
    std::string s11{"Hola soy Dani"};
    s11 = s11.substr(0, s11.find(' '));
    cout << s11 << endl;

    // Ejercicio 8: Eliminar vocales
    std::string s13{"Holaa soy Dani"};

    for (int i = 0; i < s13.size(); i++)
    {
        if (s13[i] == 'a' || s13[i] == 'e' || s13[i] == 'i' || s13[i] == 'o' || s13[i] == 'u' || s13[i] == 'A' || s13[i] == 'E' || s13[i] == 'I' || s13[i] == 'O' || s13[i] == 'U')
        {
            s13.erase(i, 1);
            i--;
        }
    }
    cout << s13 << endl;

    // Ejercicio 9: Convertir en mayusculas
    std::string s14{"Hola soy Dani"};

    for (int i = 0; i < s14.size(); i++)
    {
        if (s14[i] >= 'a' && s14[i] <= 'z')
        {
            s14[i] = s14[i] - 32;
        }
    }
    cout << s14 << endl;

    // Ejercicio 10: Contar palabras (puede haber mas de un espacio entre palabras)
    std::string s15{"Hola soy Dani"};
    int count2 = 1;

    for (int i = 0; i < s15.size(); i++)
    {
        if (s15[i] == ' ' && s15[i+1] != ' ')
        {
            count2++;
        }
    }
    cout << "Palabras: " << count2 << endl;


    // Ejercicio string robocup 1: separar string por un separador
    std::string s16{"Hola soy Dani que tal"};
    vector<string> v = separate_string(s16, " ");
    for (auto & s : v)
    {
        cout << s << endl;
    }

    // Ejercicio string robocup 2: separar string por parentesis
    std::string s17{"((hola) (soy) (dani)) (que tal) (estas)"};
    vector<string> v2 = separate_string_parenthesis(s17);
    for (auto & s : v2)
    {
        cout << s << endl;
    }
*/


    // TESTS UNITARIOS Y TEST DRIVEN DEVELOPMENT




    
    return 0;
}


