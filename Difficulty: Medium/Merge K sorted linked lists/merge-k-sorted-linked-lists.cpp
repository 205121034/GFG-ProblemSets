/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* merge(Node *h1, Node *h2){
        Node *head, *p;
        head = p = NULL;
        
        while(h1 && h2){
            if((h1->data) < (h2->data)){
                if(!head){
                    head = h1;
                    p = h1;
                }else{
                    p->next = h1;
                    p = p->next;
                }
                h1 = h1->next;
                
            }else{
                if(!head){
                    head = h2;
                    p = h2;
                }else{
                    p->next = h2;
                    p = p->next;
                }
                h2 = h2->next;
                
            }
            
        }
        
        if(h1){
            if(!head){
                head = h1;
                p = h1;
            }else{
                p->next = h1;
                p = p->next;
            }
        }
        if(h2){
            if(!head){
                head = h2;
                p = h2;
            }else{
                p->next = h2;
                p = p->next;
            }
        }
        
          
        return head;
        
    }
  
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        Node *res;
        res = NULL;
        
        int n = arr.size();
        for(int i=0;i<n;i++){
            res = merge(res, arr[i]);
        }
        
        return res;
    }
};

