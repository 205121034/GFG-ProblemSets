/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
public:
  
    Node* reverse(Node* head) {
        Node* temp = nullptr;
        Node* current = head;

      
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;

            
            current = current->prev;
        }

        if (temp != nullptr) {
            head = temp->prev;
        }

        return head;
    }
};