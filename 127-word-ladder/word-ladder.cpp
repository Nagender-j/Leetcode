class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        
        int levels = 1;
        
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> vis;
        vis.insert(beginWord);

        // bfs
        while(q.size()) {
            int sz = q.size();

            while(sz--) {
                string item = q.front(); q.pop();
                if(item == endWord) return levels;

                 for(int i = 0 ; i < 26; i++) {
                    for(int j = 0; j < item.size(); j++) {
                        string temp = item;
                        temp[j] = (char)('a'+i);
                        if(words.count(temp) && vis.count(temp) == 0) {
                            q.push(temp);
                            vis.insert(temp);
                        }
                    }
                  }

                
            }
            levels++;
        }

       

       return 0;
    }
};