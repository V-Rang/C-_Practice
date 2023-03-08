class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs)
    {
        vector<int>lengths;
        for(int i=0;i<strs.size();i++)
        {
            lengths.push_back(strs[i].length());
        }

        string res = "";

        for(int i=0;i<strs.size();i++)
        {
            res += std::to_string(lengths[i]) + "#" + strs[i];
        }

        return res;
    }

    /*
     * @param str: A string
     * @return: dcodes a single string to a list of strings
     */
    vector<string> decode(string &str)
    {
        vector<string>strs2;
        int i=0;
        while(i<str.length())
        {
            int j = i;
            while(str[j] != '#')
            {
                j++;
            }
            //int l_to_read = int(str[i-1] - '0'); wrong because length could be 2 or 3 digit,etc
            int l_to_read = int( str.substr(i,j-1) - '0');
            strs2.push_back(str.substr(j+1,l_to_read));
            i = j + l_to_read+1;
        }
        return strs2;

    }
};
