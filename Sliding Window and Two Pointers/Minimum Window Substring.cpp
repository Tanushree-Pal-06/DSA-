class Solution {
public:
    string minWindow(string s, string t) {
        int cnt=0;
        int n=s.size();
        int m=t.size();
        int l=0;
        int r=0;
        int minlen=INT_MAX;
        unordered_map<char,int> hash;
        int startInd=-1;
        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }

        while(r<n){
            if(hash[s[r]]>0) cnt++;
            hash[s[r]]--;

            while(cnt==m){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    startInd=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0) cnt--;
                
                l++;
            }
            r++;
        }
        return startInd==-1? "": s.substr(startInd,minlen);
    }
};
