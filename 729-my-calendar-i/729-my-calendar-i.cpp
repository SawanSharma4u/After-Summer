class MyCalendar {
public:
    set<pair<int,int>> st;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto i : st){
            if(i.first< end && i.second>start) return false;
        }
        st.insert(make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */