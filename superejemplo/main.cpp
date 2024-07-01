#include "student.h"
#include "node.h"

int main()
{
  Student st1{"1234", "Alberto", {"Progra I", "Progra 2", "EDA"}};
  Student st2{"4321", "Luisa", {"Progra I", "Progra 2", "EDA"}};
  Student st2{"5555", "Alberto", {"Progra 3", "Aero", "SRF"}};
  PNode head = nullptr;
  push(head, st1);
  push(head, st2);

  /*
  forEach(head, [](Student const &st)
          { cout << st << endl; });
  */
  while (true)
  {

    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    cout << "|Bienvendio a la base de datos de estudiantes|" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "|1. Agregar estudiante                       |" << endl;
    cout << "|2. Mostrar todos los estudiantes            |" << endl;
    cout << "|3. Filtrar estudiantes                      |" << endl;
    cout << "|4. Buscar estudiante (primero)              |" << endl;
    cout << "|5. Buscar estudiante (ultimo)               |" << endl;
    cout << "|6. Escribir en archivo                      |" << endl;
    cout << "|7. Leer de archivo                          |" << endl;
    cout << "|8. Salir                                    |" << endl;
    cout << "----------------------------------------------" << endl;



    int option;
    cin >> option;
    string name;
    PNode node;
    Student st;
    vector<PNode> filtered_list;

    switch (option)
    {
    case 1:
      cout << "Ingrese los datos del estudiante: (name Alberto Valero)(subjects Progra I Progra 2 EDA)" << endl;
      cin >> st;
      push(head, st);
      break;
    case 2:
      forEach(head, [](Student const &st)
              { cout << st << endl; });
      break;
    case 3:
      cout << "Ingrese el nombre o parte del nombre para filtrar: ";
      cin >> name;
      filtered_list = filter(head, [name](Student const &st)
            { return st.name.find(name) != string::npos; });
      for (auto node : filtered_list)
      {
        cout << node->data << endl;
      }
      break;
    case 4:
      cout << "Ingrese el nombre o parte del nombre para buscar: ";
      cin >> name;
      node = find(head, [name](Student const &st)
                      { return st.name.find(name) != string::npos; });
      cout << node->data << endl;
      break;
    case 5:
      cout << "Ingrese el nombre o parte del nombre para buscar: ";
      cin >> name;
      node = findLast(head, [name](Student const &st)
                          { return st.name.find(name) != string::npos; });
      cout << node->data << endl;
      break;
    case 8:
      return 0;
      break;
    default:
      cout << "Opción no válida" << endl;
      break;
    }
  }
}