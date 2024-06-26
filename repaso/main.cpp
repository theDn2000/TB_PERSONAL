#include "student.h"
#include "node.h"


int main()
{
    Student st1{"1234", "Alberto", {"Progra 1", "Progra 2", "EDA"}};
    Student st2{"1234", "Luisa", {"Progra 1", "Progra 2", "EDA"}};
    cout << st1 << endl;
    PNode head = nullptr;
    push(head, st1);
    push(head, st2);

    forEach(head, [](Student const &st)
    {
        cout << st << endl;
    });
    return 1;
}