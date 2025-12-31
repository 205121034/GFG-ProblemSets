/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/

class Solution {
  public:
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        while (head) {
            Node* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    bool isPalindrome(Node* head) {
        if (!head || !head->next) return true;

        // Step 1: Find middle
        Node* slow = head;
        Node* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        Node* secondHalf = reverse(slow->next);

        // Step 3: Compare both halves
        Node* firstHalf = head;
        Node* temp = secondHalf;

        while (temp) {
            if (firstHalf->data != temp->data)
                return false;
            firstHalf = firstHalf->next;
            temp = temp->next;
        }

        return true;
    }
};

