/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
    vector<int>ans;
    Node *temp=head;
    
    while(temp!=NULL)
    {
        ans.push_back(temp->data);
        temp=temp->next;
    }
    
    sort(ans.begin(),ans.end());
    
    Node *temp1=head;
     for(int i=0;i<ans.size();i++)
     {
         temp1->data=ans[i];
         temp1=temp1->next;
     }
     
     return head;
    
    }
};

