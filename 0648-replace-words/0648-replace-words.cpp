class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {

        // we need to search in dictionary for words, keep it in a unordered_set
        // for O(1) access
        unordered_set<string> st;

        for (auto word : dictionary) {
            st.insert(word);
        }

        // using string stream we need to split the given sentence into words
        stringstream ss(sentence);
        string word; // this is where we are going to extract and keep words

        string ans;

        while (getline(ss, word, ' ')) {
            ans = ans + getRoot(word, st) +
                  ' '; // words should be space seperated
        }

        // remove the last space

        ans.pop_back();

        return ans;
    }

    string getRoot(string& word, unordered_set<string>& st) {
        // fn will give root if present in the dictionary otherwise will return
        // the word itself

        // we need to search for each substring of word starting from first char
        int n = word.size();

        for (int i = 1; i <= n; i++) {
            if (st.find(word.substr(0, i)) != st.end()) {
                return word.substr(0, i);
            }
        }

        return word;
    }
};