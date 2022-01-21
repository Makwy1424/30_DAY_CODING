// https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> Anagrams(vector<string> &string_list)
    {

        vector<string> copy = string_list;
        for (int i = 0; i < copy.size(); i++)
            sort(copy[i].begin(), copy[i].end());

        map<string, vector<int>> m;

        for (int i = 0; i < copy.size(); i++)
            m[copy[i]].push_back(i);

        vector<vector<string>> temp(m.size());
        int j = 0;
        for (auto &val : m)
        {

            for (int i = 0; i < val.second.size(); i++)
                temp[j].push_back(string_list[val.second[i]]);

            j++;
        }

        return temp;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> string_list(n);
        for (int i = 0; i < n; i++)
        {
            cin >> string_list[i];
        }
        Solution ob;
        vector<vector<string>> result = ob.Anagrams(string_list);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << "\n"
                 << endl;
        }
    }
    return 0;
}
