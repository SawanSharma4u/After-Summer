class Solution {
public:
    vector<string> wordSubsets(vector<string>& word1, vector<string>& word2) {
        vector<int> arr(26);
        for(int i = 0; i < word2.size(); i++){
            vector<int> temp(26, 0);
            for(int j = 0; j < word2[i].length(); j++){
                temp[word2[i][j]-'a']++;
            }
            for(int j = 0; j < 26; j++){
                arr[j] = max(arr[j], temp[j]);
            }
        }
        vector<string> ans;
        for(int i = 0; i < word1.size(); i++){
            vector<int> temp(26);
            for(int j = 0; j < word1[i].length(); j++){
                temp[word1[i][j]-'a']++;
            }
            int j = 0;
            for(; j < 26; j++){
                if(arr[j] > temp[j]){
                    break;
                }
            }
            if(j==26){
                ans.push_back(word1[i]);
            }
        }
        return ans;
    }
};