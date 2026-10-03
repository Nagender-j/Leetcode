class MovieRentingSystem {
public:
    // map<movie, map<price,set<shop>>>
    unordered_map<int, map<int, set<int>>> unrentedMovies;

    // map<price, map<movie, set<shop>>> 
    map<int, map<int, set<int>>> rentedMovies;
    map<pair<int,int>, int> movieShopToPrice;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto entry : entries) {
            int shop = entry[0], movie = entry[1], price = entry[2];
            unrentedMovies[movie][price].insert(shop);
            
            movieShopToPrice[{movie, shop}] = price;
        }
    }
     // map<movie, map<price,set<shop>>> unrentedMovies
     // map<price, map<shop, set<movie>>> rentedMovies
    vector<int> search(int movie) {
        vector<int> res;
        if(unrentedMovies.count(movie) == 0) return res;

        int count = 0;
        // map<int, set<int>> priceToShops = unrentedMovies[movie];
        for(const auto& [price, shops] : unrentedMovies[movie]) {
            for(int shop : shops) {
                res.push_back(shop);
                count++;
                if(count == 5) {
                    return res;
                } 
            }

        }

        return res;
    }
    
    // map<movie, map<price,set<shop>>> unrentedMovies
    void rent(int shop, int movie) {
        if(unrentedMovies.count(movie) == 0) return;
        
        // string key = to_string(movie)+":"+to_string(shop);
        int price = movieShopToPrice[{movie, shop}];

        unrentedMovies[movie][price].erase(shop);
        // if(unrentedMovies[movie][price].size() == 0) {
        //     unrentedMovies[movie].erase(price);
        // }

        // logic to add to rentedMovies

        rentedMovies[price][shop].insert(movie);
        
    }
    
     // map<price, map<shop, set<movie>>> rentedMovies
    void drop(int shop, int movie) {
        int price = movieShopToPrice[{movie, shop}];
        rentedMovies[price][shop].erase(movie);
        //  if(rentedMovies[price][shop].size() == 0) {
        //     unrentedMovies[price].erase(shop);
        // }
        // add it back to unrentedMovies;
        unrentedMovies[movie][price].insert(shop);
        
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        
        int count = 0;
        for(const auto& [price, shopMovies] : rentedMovies) {
            for(const auto& [shop, movies] : shopMovies) {
                for(int movie : movies) {
                    res.push_back({shop, movie});
                    count++;
                    if(count == 5) {
                        return res;
                    }
                }
            }
        }
        
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */