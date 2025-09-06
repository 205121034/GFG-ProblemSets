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
    int lengthOfLoop(Node *head) {
        // code here
        int index = 1, ans = 0;
        unordered_map<Node*, int> map;
        Node *temp = head;
        
        while (temp) {
            if (map.count(temp)) {
                ans = index - map[temp];
                break;
            } else {
                map[temp] = index;
                index++;
            }
            temp = temp->next;
        }
        return ans;
    }
};