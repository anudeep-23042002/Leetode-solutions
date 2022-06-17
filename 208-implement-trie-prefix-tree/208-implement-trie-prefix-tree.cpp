struct Node{
    char a;
    int we;
    Node* arr[26];
    bool check(char b){
        return arr[b-'a']!=NULL;
    }
    void put(char c,Node* k){
        arr[c-'a']=k;
    }
    Node* get(char d){
        return arr[d-'a'];
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++){
            if(!temp->check(word[i])){
                Node* k=new Node();
                k->a=word[i];
                k->we=0;
                temp->put(word[i],k);
            }
            temp=temp->get(word[i]);
        }
        temp->we+=1;
    }
    
    bool search(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++){
            if(!temp->check(word[i])){
                return false;
            }
            temp=temp->get(word[i]);
        }
        if(temp->we>0){
            return true;
        }
        return false;
    }
    
    bool startsWith(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++){
            if(!temp->check(word[i])){
                return false;
            }
            temp=temp->get(word[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */