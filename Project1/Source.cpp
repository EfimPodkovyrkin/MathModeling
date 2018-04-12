#include <iostream>
#include <vector>
#include <cmath>
#include <io.h>
#include <fcntl.h> 
#include "strangeMath.h"
int main()
try {
	//
	_setmode(_fileno(stdout), _O_U16TEXT);
	unsigned long long int binary{ 0 };
	double eps = DBL_EPSILON;
	std::memcpy(&binary, &eps, sizeof(eps));
	std::wcout << L"машинная точность: " << std::hex << DBL_EPSILON << '\n';

	
	//int m{ 0 };
	//std::wcout << FLT_MAX << '\n';
	std::wcout << !-1 << '\n';
	test(-4, 4, 100);
	std::wcout << "sqrt:\n";
	tests(1, 10, 100);
	std::wcout << "my sqrt:\n";
	testmy(1, 10, 100);
	std::cin.get();
}
catch (std::exception& s) {
	std::wcerr << "runtime error: " << s.what() << '\n';
	system("pause");
	return 1;
}
catch (std::runtime_error& s) {
	std::wcerr << "runtime error: " << s.what() << '\n';
	system("pause");
	return 2;
}
catch (...) {
	std::wcerr << "wow";
	system("pause");
	return 3;
}