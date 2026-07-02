class Solution {
public:
    bool checkValidString(string s) {
        int min=0;
        int max=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                min++;
                max++;
            }
            else if(s[i]==')'){
                min--;
                max--;
            }
            else{
                // ranges[-1,0,1]
                min--; // add -1 for min value
                max++; //add +1 for max value
            }

            if(min<0) min=0;
            if(max<0) return false;
        }
        return (min==0);
    }
};
