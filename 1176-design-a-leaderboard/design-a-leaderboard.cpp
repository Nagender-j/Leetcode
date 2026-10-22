class Leaderboard {
public:
    //map<score, set<id>>
    map<int, set<int>> scoreIds;
    map<int, int> idToScore;
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        if(idToScore.count(playerId)) {
            int oldScore = idToScore[playerId];
            idToScore[playerId] += score;
            scoreIds[oldScore].erase(playerId);
            scoreIds[oldScore+score].insert(playerId);
        } else {
            idToScore[playerId] = score;
            scoreIds[score].insert(playerId);
        }
    }
    
    int top(int k) {
        int sum = 0;
        for(auto it = scoreIds.rbegin(); it != scoreIds.rend(); it++) {
            int score = it->first;
            set<int> ids = it->second;
            int sz = ids.size();
            if(k == 0) break;
            if(sz <= k) {
                sum += sz*score;
                k -= sz;
            } else {
                sum +=  k*score;
                k = 0;
            }
        }

        return sum;
    }
    
    void reset(int playerId) {
        scoreIds[idToScore[playerId]].erase(playerId);
        idToScore.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */