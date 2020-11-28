class Solution {
public:
    int maxRepeating(string sequence, string word) {
        if(word.size() > sequence.size()) return 0;
        int k = 0;
        int max_k;
        bool equal = false;
        
        int i = 0;
        while(i < sequence.size()) {
            equal = sequence.substr(i, word.size()) == word;
            if(equal) k++;
            max_k = max(max_k, k);
            if(!equal) {k = 0; i++;}
            else {i += word.size();}
        }
        
        return max_k;
    }
};
