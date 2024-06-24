#include <memory>

using namespace std;

typedef shared_ptr<Node> P_Node;

struct Node
{
    int data;
    shared_ptr<Node> next;
};

P_Node push(P_Node first, int data)
{
    auto it = first;
    while (it->next)
    {
        it = it->next;
    }
    P_Node new_node = make_shared<Node>(Node{data, nullptr});
    it->next = new_node;
}

P_Node push_r(P_Node first, int data)
{
    if (first->next)
    {
        return push_r(first->next, data);
    }
    P_Node nNode = make_shared<Node>(Node{data, nullptr});
    first->next = nNode;
    return nNode;
}

int main()
{
    P_Node start = make_shared<Node>(Node{1, nullptr});
    P_Node other = make_shared<Node>(Node{2, nullptr});
    P_Node other3 = make_shared<Node>(Node{3, nullptr});

    push(start, 2);
    push(start, 3);
    push(start, 4);
}