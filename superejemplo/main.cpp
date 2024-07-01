#include "student.h"
#include "node.h"

int main()
{
  Student st1{"1234", "Alberto", {"Progra I", "Progra 2", "EDA"}};
  Student st2{"4321", "Luisa", {"Progra I", "Progra 2", "EDA"}};
  PNode head = nullptr;
  push(head, st1);
  push(head, st2);

  /*
  forEach(head, [](Student const &st)
          { cout << st << endl; });
  */
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
  cout << "|Bienvendio a la base de datos de estudiantes|" << endl;
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
  cout << "|1. Agregar estudiante                       |" << endl;









  return 1;
}