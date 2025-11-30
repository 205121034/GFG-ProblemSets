class Solution {
    
    struct TrieNode
    {
        TrieNode* child[26];
        TrieNode()
        {
            for(int i=0;i<26;++i)
            child[i]=nullptr;
        }
    };
    
  public:
    int countSubs(string& s) {
        int n=(int)s.size();
        TrieNode* root =new TrieNode();
        int distinct=0;
        
        for(int i=0;i<n;i++){
            TrieNode* node=root;
            for(int j=i;j<n;++j)
            {
                int idx=s[j]- 'a';
                if(node->child[idx] == nullptr){
                    node->child[idx]=new TrieNode();
                    ++distinct;
                }
                node=node->child[idx];
            }
        }
        return distinct;
        
    }
};