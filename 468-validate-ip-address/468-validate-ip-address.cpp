class Solution {
public:
    string validIPAddress(string s) {
        int start = 0;
        int end = s.find('.');
        int cnt = 0;
        if(end!=-1){
            while(end!=-1){
                cnt++;
                string temp = s.substr(start, end-start);
                if(temp.size() > 3 || temp.size()==0) return "Neither";
                if(temp.size()>1 && temp[0]=='0') return "Neither";
                for(int i = 0; i < temp.size(); i++){
                    if(temp[i]-'0' < 0 || temp[i]-'0' > 9) return "Neither";
                }
                if(stoi(temp) > 255) return "Neither";
                start = end+1;
                end = s.find('.', start);
            }
            if(cnt!=3) return "Neither";
            string temp = s.substr(start);
            if(temp.size() > 3 || temp.size()==0) return "Neither";
            if(temp.size()>1 && temp[0]=='0') return "Neither";
            for(int i = 0; i < temp.size(); i++){
                if(temp[i]-'0' < 0 || temp[i]-'0' > 9) return "Neither";
            }
            if(stoi(temp) > 255) return "Neither";
            return "IPv4";
        }
        else if(s.find(':')!=-1){
            end = s.find(':');
            while(end!=-1){
                cnt++;
                string temp = s.substr(start, end-start);
                if(temp.size() > 4 || temp.size() < 1) return "Neither";
                for(int i = 0; i < temp.size(); i++){
                    if((temp[i]-'0' >= 0 && temp[i]-'0' <= 9) || (temp[i]-'a'>=0 && temp[i]-'a' <= 5) || (temp[i]-'A'>=0 && temp[i]-'A' <= 5)) continue;
                    else return "Neither";
                }
                start = end+1;
                end = s.find(':', start);
            }
            if(cnt!=7) return "Neither";
            string temp = s.substr(start);
            if(temp.size() > 4 || temp.size() < 1) return "Neither";
            for(int i = 0; i < temp.size(); i++){
                if((temp[i]-'0' >= 0 && temp[i]-'0' <= 9) || (temp[i]-'a'>=0 && temp[i]-'a' <= 5) || (temp[i]-'A'>=0 && temp[i]-'A' <= 5)) continue;
                else return "Neither";
            }
            return "IPv6";
        }
        return "Neither";
    }
};