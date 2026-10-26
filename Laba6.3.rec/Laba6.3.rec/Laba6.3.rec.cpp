#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int Sum(int* a, const int size, int i);
template <typename T>
T Sum(T* a, const int size, int i);
template <typename T>
void Print(T* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(5) << a[i];
	cout << endl;
}
int main()
{
	const int n = 10;
	int a[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	Print(a, n);
	int s1 = Sum(a, n, 0);
	cout << "Sum(a, n) = " << s1 << endl;
	int s2 = Sum<int>(a, n, 0);
	cout << "Sum<int>(a, n) = " << s2 << endl;
	double b[n] = { 1.1, 2.2, 3.3, 4.3, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0 };
	Print(b, n);
	double s3 = Sum<double>(b, n, 0);
	cout << "Sum<double>(a, n) = " << s3 << endl;
	string c[n] = { "1 ", "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", "10 " };
	Print(c, n);
	string s4 = Sum<string>(c, n, 0);
	cout << "Sum<string>(a, n) = " << s4 << endl;
	return 0;
}
int Sum(int* a, const int size, int i)
{
	if (i < size)
		return a[i] + Sum(a, size, i + 1);
	else
		return 0;
}
template <typename T>
T Sum(T * a, const int size, int i)
{
	if (i < size)
		return a[i] + Sum<T>(a, size, i + 1);
	else
		return T();
}