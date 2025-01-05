#include "Solution.hpp"

struct testcase {
    string s;
    vector<vector<int>> shifts;
    string output;
};

class UnitTest {
private:
    Solution obj;
    vector<testcase> testcases;
public:
    UnitTest() {
        testcases = {{"abc", {{0,1,0},{1,2,1},{0,2,1}}, "ace"},
                     {"dztz", {{0,0,0},{1,1,1}}, "catz"}};
    }

    void test() {
        for(int i = 0; i < testcases.size(); ++i) {
            string s = testcases[i].s;
            vector<vector<int>> shifts = testcases[i].shifts;
            string output = testcases[i].output;

            string result = obj.shiftingLetters(s, shifts);
            cout << "Testcase " << i+1 << ": " << ((result == output) ? "passed" : "failed") << endl;
        }
    }
};

int main() {
    UnitTest test;
    test.test();
}