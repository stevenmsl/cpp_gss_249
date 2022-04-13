#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <queue>
using namespace sol249;
using namespace std;

/*takeaways
  - the most crucial part is to come up with a scheme that
    you can generate the same key for strings that belong
    to the same group
  - abc vs bcd
    - let's look at abc. a need to walk one step to become b.
      In the mean time, b and c need to walk one step as well
      so abc will become bcd. The distance between each char
      remains the same
  - ab is not the same as ba!!
    - ab can never become ba, so that are not in the same group
    - a needs to walk 1 step to become b; b needs to walk 25
      steps to become a. So we need to define the distance
      so it can be used to tell these two cases apart
    - for ab the distance is calculated as ('b'-'a'+26) % 26 = 1
    - for ba the distance is calculated as ('a'-'b'+26) % 26 = 25
    - we use the same formula to yield different distances for
      these two cases

*/

string Solution::generateKey(string &s)
{
  auto key = string();
  for (auto i = 1; i < s.size(); i++)
  {
    /* to distinguish "ab" from "ba" */
    auto steps = (s[i] - s[i - 1] + 26) % 26;
    key += to_string(steps) + ",";
  }

  return key;
}

vector<vector<string>> Solution::group(vector<string> &ss)
{
  auto result = vector<vector<string>>();
  auto m = unordered_map<string, vector<string>>();

  for (auto &s : ss)
    m[generateKey(s)].push_back(s);

  for (auto &[_, entries] : m)
    result.push_back(entries);

  return result;
}