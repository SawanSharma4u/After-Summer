class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> mp;
        for(auto i : cpdomains){
            string num = "";
            int j = 0;
            while(i[j]!=' '){
                num += i[j];
                j++;
            }
            string temp = "";
            j++;
            while(j < i.size()){
                if(i[j-1]==' ' || i[j-1]=='.'){
                    mp[i.substr(j)] += stoi(num);
                }
                j++;
            }
        }
        vector<string> ans;
        unordered_map<string, int> :: iterator it = mp.begin();
        while(it!=mp.end()){
            ans.push_back(to_string(it->second) + " " + it->first);
            it++;
        }
        return ans;
    }
};