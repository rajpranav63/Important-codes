struct TrieNode{
  TrieNode* link[26];
  bool fg=false;
    
  //containKey
  bool containKey(char c)
  {
      return (link[c-'a']!=NULL);
  }
  //put
  void put(char c ,TrieNode* node)
  {
      link[c-'a']=node;
  }
  //get
  TrieNode* get(char c)
  {
      return link[c-'a'];
  }
  //setEnd
  void setEnd()
  {
      fg=true;
  }
  //isEnd
  bool isEnd()
  {
      return fg;
  }
};
class Trie{
 private: TrieNode* root=new TrieNode();   
 public:
 void insert(string &word)
 {
     TrieNode* node=root;
     for(int i=0;i<word.size();i++)
     {
         if(!node->containKey(word[i]))
         {
             node->put(word[i],new TrieNode());
         }
         node=node->get(word[i]);
     }
     node->setEnd();
 }
  bool search(string &word)
 {
     TrieNode* node=root;
     for(int i=0;i<word.size();i++)
     {
         if(!node->containKey(word[i]))
         {
             return false;
         }
         node=node->get(word[i]);
     }
     return node->isEnd();
 }
};