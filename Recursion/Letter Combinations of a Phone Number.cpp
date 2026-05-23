class Solution {
public:
    void func(string &digits,int ind,string combo,vector<string> &res, const unordered_map<char,string> &diglet){
        if(ind==digits.length()){
            res.push_back(combo);
            return;
        }
        string letters=diglet.at(digits[ind]);// more effiecient than []
        for( char letter:letters){
            func(digits,ind+1,combo+letter,res,diglet);
            //no need to pop_back() here since we are not making any alternation to the original string , we are just dealing with the copy of combo here.
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) return res;
        unordered_map<char,string> diglet={
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"},
        };
        func(digits,0,"",res,diglet);
        return res;
        
    }
};
