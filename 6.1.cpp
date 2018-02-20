#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int strToInt(const std::string& s) {
	//string t = "654";
	int digit = 1;
	int result = 0;
	//cout << t.length() << endl;
	//cout << t[0] << endl;
	if (s[0] == '-') {
		for (int i=(s.length()-1); i > 0; i--){
			result += (int(s[i])-48) * digit;
			digit *= 10;
		}
		result *= -1;
		cout << "RESULT: " << endl;
		cout << result << endl;
	}
	else {
		for (int i=(s.length()-1); i >= 0; i--){
			result += (int(s[i])-48) * digit;
			digit *= 10;
		}
		cout << "RESULT: " << endl;
		cout << result << endl;
	}
	return result;
}

std::string intToStr(const int i){
	int t = i;

	std::string result = "";
	if (t<0){
		t *= -1;
		result += "-";
	}
	int numdigits = (log10 (t)) + 1;

	int nextdigit; 
    for (int j=numdigits; j>0; j--){
		nextdigit = t/pow(10,(j-1));
		result += char((nextdigit+48));
		cout << "TEST:" << endl;
		cout << result << endl;
		t -= nextdigit*pow(10,j-1);
	}

	return result;
}

TEST_CASE("Test 6.1") {
	REQUIRE(strToInt("333")==333);
	REQUIRE(strToInt("12345")==12345);
	REQUIRE(strToInt("-27")==-27);
	REQUIRE(strToInt("-2")==-2);

	REQUIRE(intToStr(333)=="333");
	REQUIRE(intToStr(79873)=="79873");
	REQUIRE(intToStr(-32)=="-32");
	REQUIRE(intToStr(-4)=="-4");
	
}