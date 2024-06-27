#include "node.h"

/**
 * Adds at the end of the list a student
 * @return the head of the list BY REFERENCE
 * @param head The head of the list
 * @param st The student
 */
PNode &push(PNode &head, Student const &st)
{
    if (!head)
    {
        head = make_shared<Node>(Node{st, nullptr});
        return head;
    }
    auto it = head;
    while (it->next)
    {
        it = it->next;
    }

    PNode node = make_shared<Node>(Node{st,nullptr});
    it->next = node;
    return head;
}


/**
 * Iterates over the list and performs f
 */
void forEach(PNode const &head, LambdaForEach const &f)
{
    auto it = head;
    while (it->next)
    {
        f(it->data);
        it = it->next;
    }
}

vector<PNode> filter(PNode const &head, function<bool(Student const &)> const &f)
{
    vector<PNode> res;
    auto it = head;
    while (it->next)
    {
        if (f(it->data))
        {
            res.push_back(it);
        }
        it = it->next;
    }
    return res;
}