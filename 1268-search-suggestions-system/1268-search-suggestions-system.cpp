struct Trie {
        unordered_map<char, Trie*> leaves;
        vector<string> suggestions;
    };
    
    void insertTrie(Trie* root, string word) {
        for(const char& c: word) {
            if(root->leaves.find(c) == root->leaves.end())
                root->leaves[c] = new Trie();
            root = root->leaves[c];
            if(root->suggestions.size() < 3)
                root->suggestions.emplace_back(word);
        }
    }
    
class Solution {
public:    
    vector<vector<string>> suggestionTrie(vector<string>& products, string searchWord) {
        vector<vector<string>> result(searchWord.size());
        sort(begin(products), end(products));
        
        Trie *root = new Trie();
        for(const string &word: products)
            insertTrie(root, word);
        
        string prefix;
        for(int i = 0; i < searchWord.size(); i++) {
            auto it = root->leaves.find(searchWord[i]);
            if(it != root->leaves.end()) {
                root = it->second;
            }
            else
                break;
            result[i] = root->suggestions;
        }
        return result;
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        return suggestionTrie(products, searchWord);
    }
};