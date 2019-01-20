/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
       
        // will hold the result
        vector<Interval> result;
        
        // input sanity check
        if(intervals.size() == 0){
            return result;
        }
        
        // sort the intervals vector by start times
        sort(intervals.begin(),intervals.end(), [&] (Interval &a, Interval &b){
           return a.start < b.start; 
        });
       
        // iterate over the sorted vector
        for(int i = 0; i < intervals.size();i++){
            
            // if the current interval's start > the end of the current result
            
            // e.g. result has [1,2] and intervals[i] = [3,4]
            // intervals[i] will be pushed as is in the resultant vector
            if(result.empty() || intervals[i].start > result.back().end){
                result.push_back(intervals[i]);
            }
            
            // otherwise we would need to find the end among the candidate - intervals[i] and 
            // whatever interval is at the back of the resultant vector
            // the maximum among the two would constitute the end of the resultant vector
            else{
                result.back().end = max(result.back().end, intervals[i].end);
            }
                
            
        }
        return result;
    }
};