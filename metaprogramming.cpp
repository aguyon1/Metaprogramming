#include <iostream>

//Factorial
//////////////////////////////////////////////////////////////////////
template <unsigned int N, unsigned int ACC>
struct FactorialRec
{
	enum {value = FactorialRec<N-1U, ACC*N>::value};
};

template<unsigned int ACC>
struct FactorialRec<0U, ACC>
{
	enum {value = ACC};
};

template<unsigned int N>
struct Factorial
{
	enum {value = FactorialRec<N, 1U>::value};
};
////////////////////////////////////////////////////////////////////

//Fibonacci
//////////////////////////////////////////////////////////////////////
template <unsigned int N>
struct Fibonacci
{
	enum {prev = Fibonacci<N-1U>::curr, curr = Fibonacci<N-1U>::curr + Fibonacci<N-1U>::prev};
};

template <>
struct Fibonacci<1U>
{
	enum {prev = 0U, curr = 1U};
};

template<>
struct Fibonacci<0U>
{
	enum {prev = 0U, curr = 0U};
};
//////////////////////////////////////////////////////////////////////

//Sum of square
//////////////////////////////////////////////////////////////////////
template <unsigned int N, unsigned int ACC>
struct SumSquareRec
{
	enum {value = SumSquareRec<N-1U,ACC+N*N>::value};
};

template<unsigned int ACC>
struct SumSquareRec<0U, ACC>
{
	enum {value = ACC};
};

template <unsigned int N>
struct SumSquare
{
	enum {value = SumSquareRec<N, 0U>::value};
};
//////////////////////////////////////////////////////////////////////

int main(void)
{
	const unsigned int N = 12U;

	std::cout << "Factorial 12 : " << Factorial<N>::value << std::endl;
	std::cout << "Fibonnaci 12 : " << Fibonacci<N>::curr << std::endl;
	std::cout << "Sum of square [0...12] : " << SumSquare<N>::value << std::endl;
}
