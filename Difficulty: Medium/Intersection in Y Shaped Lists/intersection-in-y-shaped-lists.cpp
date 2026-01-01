/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
         Node* p1 = head1;
        Node* p2 = head2;

        // Traverse until both pointers meet
        while (p1 != p2) {
            p1 = (p1 == NULL) ? head2 : p1->next;
            p2 = (p2 == NULL) ? head1 : p2->next;
        }

        // p1 (or p2) is the intersection point
        return p1;
    }
};