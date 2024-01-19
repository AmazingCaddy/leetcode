/*
 *	原来只需要在两个级别之间做减法，999是CMXCIX，而不是IM
 */
class Solution {
public:
	void test () {
		int numbers[] = {
			1,
			10,
			100,
			1000,
			88,
			999
		};
		string expected[] = {

		};
		int n = 6;
		for (int i = 0; i < n; i ++) {
			cout << this->intToRoman(numbers[i]) << "\n";
		}
	}

    string intToRoman(int num) {
    	string roman[4][10] = {
			{"", "M", "MM", "MMM"},
			{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
			{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
			{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
		};
		int r[] = {1000, 100, 10, 1};
    	string ans = "";
        for (int i = 0; i < 4; i ++) {
        	ans = ans + roman[i][num / r[i]];
        	num %= r[i];
        }
        return ans;
    }
};