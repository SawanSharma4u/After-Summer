class Solution {
public:
    string longestDiverseString(int lg, int med, int sm, char ch_lg = 'a', char ch_med = 'b', char ch_sm = 'c') {
    if (lg < med)
        return longestDiverseString(med, lg, sm, ch_med, ch_lg, ch_sm);
    if (med < sm)
        return longestDiverseString(lg, sm, med, ch_lg, ch_sm, ch_med);
    if (med == 0)
        return string(min(2, lg), ch_lg);
    auto use_lg = min(2, lg), use_med = lg - use_lg >= med ? 1 : 0; 
    return string(use_lg, ch_lg) +  string(use_med, ch_med) + 
		longestDiverseString(lg - use_lg, med - use_med, sm, ch_lg, ch_med, ch_sm);
}
};