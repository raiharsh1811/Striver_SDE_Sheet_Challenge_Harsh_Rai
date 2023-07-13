// #include <bits/stdc++.h> 
// unordered_set<string> st;
//     void func(string &s, int id,vector<string>&res,vector<string>&temp)
//     {
//         if (id >= s.size())
//         {
//             string result = "";
//             for (auto it: temp)
//             {
//                 result += it + " ";
//             }
//             result.pop_back();
//             res.push_back(result);
//         }

//         for (int i = 1; id + i <= s.size(); i++)
//         {
//             string t = s.substr(id, i);
//             if (st.find(t) != st.end())
//             {
//                 temp.push_back(t);
//                 func(s, id + i,res,temp);
//             temp.pop_back();
//             }
//         }
//     }

// vector<string> wordBreak(string s, vector<string> &wordDict)
// {
//     sort(wordDict.begin(), wordDict.end());
//     for (auto it :wordDict)
//     {
//         st.insert(it);
//     }
//     vector<string>res,temp;
//     func(s,0,res,temp);
//     return res;
// }




#include <bits/stdc++.h>

void generate(string &s, string &t, unordered_map<string, bool> &ump, int idx, vector<string> &ans)
{
    if (idx == s.length())
    {
        ans.push_back(t);
        return;
    }

    for(int i=idx; i<s.length(); i++)
    {
        if (ump[s.substr(idx,i-idx+1)])
        {
            t.append(s.substr(idx, i-idx+1));
            t.push_back(' ');
            generate(s, t, ump, i+1, ans);
            int sz = t.length();
            t = t.substr(0, sz-(i-idx+2));
        }
    }

}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    unordered_map<string, bool> ump;
    for(auto &it: dictionary) ump[it] = true;
    vector<string> ans;
    string t;
    generate(s, t, ump, 0, ans);
    return ans;
}