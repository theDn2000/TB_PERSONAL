#include <memory>

using namespace std;
typedef shared_ptr<Node> P_Node;

struct Node
{
    int data;
    shared_ptr<Node> next;
};

int main()
{
    P_Node start = make_shared<Node>(Node{1, nullptr});
}