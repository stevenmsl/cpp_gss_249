
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;
namespace sol249
{
    class Solution
    {
    private:
        string generateKey(string &s);

    public:
        vector<vector<string>> group(vector<string> &ss);
    };
}
#endif