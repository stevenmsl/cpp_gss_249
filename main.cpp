#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol249;

/*
Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
Output:
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
*/

tuple<vector<string>, vector<vector<string>>> testFixture1()
{
  auto input = vector<string>{"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
  auto output = vector<vector<string>>{
      {"abc", "bcd", "xyz"}, {"az", "ba"}, {"acef"}, {"a", "z"}};

  return make_tuple(input, output);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - expect to see " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  cout << "result: " << Util::toString(sol.group(get<0>(f))) << endl;
}

main()
{
  test1();
  return 0;
}