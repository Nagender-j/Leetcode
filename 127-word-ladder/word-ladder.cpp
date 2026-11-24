class Solution {
public:
  

    void bfs(int si,int ei,vector<int>&vis,vector<int>&dist,vector<int>adj[],int d)
    {
        dist[si]=d;

        queue<int>q;
        q.push(si);
        vis[si]=1;

       

        while(!q.empty())
        {
           
                int node=q.front();q.pop();
            
                for(int child:adj[node])
                {
                    if(!vis[child])
                    {
                           dist[child]=dist[node]+1;
                           vis[child]=1;
                           q.push(child);
                    }

                }
           
        }

    }

    bool matched(string a,string b)
    {
        int d=0;
        if(a.size()!=b.size())
            return 0;

        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=b[i])
                d++;
        }
        
        return d<=1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>&a) {
        
        int n=a.size();
        unordered_set<string>s;
      
        vector<int>adj[n+1];
        for(int i=0;i<n;i++)
        {
            s.insert(a[i]);
            for(int j=i+1;j<n;j++)
            {
                if(matched(a[i],a[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                    
                }
            }
        }

        int sidx=-1,eidx=-1;
        
        for(int i=0;i<n;i++)
        {
            if(a[i] == beginWord)
            {
                sidx=i;
                break;
            
            }
            else if(matched(beginWord,a[i]))
            {
                sidx=i;
            }



        }
        
        for(int i=0;i<n;i++)
        {
            
           if(a[i] == endWord)
                eidx = i;
        }

        if( eidx==-1 || sidx==-1)
            return 0;

        int d=2;
        
        if(s.count(beginWord))
            d=1;


        vector<int>vis(n,0),dist(n,0);
        
       
        bfs(sidx,eidx,vis,dist,adj,d);
        
        return dist[eidx];




    }
};