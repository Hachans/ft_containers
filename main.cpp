#include <algorithm>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>
#include <deque>
#include <time.h>

#if 0  //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	#include <set>
	namespace ft = std;

#else
	#include "vector.hpp"
	#include "stack.hpp"
	#include "map.hpp"

#endif

template<typename T>
void	print_vector(ft::vector<T>& v, size_t id = 0, const std::string& delimiter = " ")
{
	std::cout << "vector" << id << ": " << "[ ";
	for (typename ft::vector<T>::iterator it1 = v.begin(); it1 != v.end(); it1++)
		std::cout << *it1 << delimiter;
	std::cout << "]" << std::endl;
}

template<typename T>
void	print_stack(ft::stack<T> s, size_t id = 0, const std::string& delimiter = "\n")
{
	size_t n_elems = s.size();
	std::cout << "stack" << id << ":\n";
	for (; !s.empty(); --n_elems)
	{
		std::cout << "[ " << s.top() << " ]" << delimiter;
		s.pop();
	}
}



#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	time_t	start, end;
	time(&start);
	const int seed = atoi(argv[1]);
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	ft::vector<Buffer> vector_buffer;
	ft::map<int, int> map_int;

	// for (int i = 0; i < COUNT; i++)
	// {
	// 	vector_buffer.push_back(Buffer());
	// }

	// for (int i = 0; i < COUNT; i++)
	// {
	// 	const int idx = rand() % COUNT;
	// 	vector_buffer[idx].idx = 5;
	// }
	// ft::vector<Buffer>().swap(vector_buffer);

	// try
	// {
	// 	for (int i = 0; i < COUNT; i++)
	// 	{
	// 		const int idx = rand() % COUNT;
	// 		(void)vector_buffer.at(idx);
	// 		std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
	// 	}
	// }
	// catch(const std::exception& e)
	// {
	// 	//NORMAL ! :P
	// }

	// MutantStack<char> iterable_stack;
	// for (char letter = 'a'; letter <= 'z'; letter++)
	// 	iterable_stack.push(letter);
	// for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	// {
	// 	std::cout << *it;
	// }
	// std::cout << std::endl;

	// /* vector */
	// ft::vector<int> v1;
	// print_vector(v1, 1);

	// ft::vector<int> v2(size_t(8), int(42));
	// print_vector(v2, 2);

	// ft::vector<int>::iterator it_tmp1 = v2.begin() + 1;
	// ft::vector<int>::const_iterator c_it_tmp = v2.end() - 2;
	// ft::vector<int>::iterator it_tmp2 = v2.end() - 2;

	// ft::vector<int> v3(it_tmp1, it_tmp2);
	// print_vector(v3, 3);

	// ft::vector<int> v4(v3);
	// print_vector(v4, 4);

	// ft::vector<int> v5 = v4;
	// print_vector(v5, 5);

	// std::cout << "it_tmp1 > c_it_tmp: " << std::boolalpha << (it_tmp1 > c_it_tmp) << std::endl;
	// std::cout << "it_tmp1 < c_it_tmp: " << std::boolalpha << (it_tmp1 < c_it_tmp) << std::endl;

	// std::cout << "v1 is empty: "<< v1.empty() << std::endl;
	// std::cout << "v5 is empty: "<< v5.empty() << std::endl;

	// std::cout << "v1 has size " << v1.size() << " and capacity " << v1.capacity() << std::endl;
	// std::cout << "v5 has size " << v5.size() << " and capacity " << v5.capacity() << std::endl;

	// std::cout << "v1 has max size of " << v1.max_size() << std::endl;
	// std::cout << "v5 has max size of " << v5.max_size() << std::endl;

	// v5.resize(20);
	// print_vector(v5, 5);
	// std::cout << v5[v5.size() - 1] << std::endl;
	// std::cout << v5.at(v5.size() - 1) << std::endl;
	
	// std::cout << v5.front() << std::endl;
	// std::cout << v5.back() << std::endl;

	// ft::vector<int> v6;
	// v6.assign(7, 100);
	// print_vector(v5, 5);
	
	// ft::vector<int>::iterator v6_it1 = v5.begin() + 3;
	// ft::vector<int>::iterator v6_it2 = v5.end() - 7;
	// v6.assign(v6_it1, v6_it2);
	// v6.assign(v5.begin() + 3, v5.end() - 7);
	// print_vector(v6, 6);
	// ft::vector<int>::allocator_type Allocator = v6.get_allocator();
	// ft::vector<int> v66(Allocator);

	// ft::vector<int>::iterator v6_it3 = v6.begin() + 3;
	// v6.erase(v6_it3);
	// print_vector(v6, 6);

	// ft::vector<int>::iterator v6_it4 = v6.begin() + 1;
	// ft::vector<int>::iterator v6_it5 = v6.begin() + 6;
	// v6.erase(v6_it4, v6_it5);
	// print_vector(v6, 6);

	// ft::vector<int> v7((size_t)10, (int)99);

	// v7.at(3) = 42;

	// try
	// {
	// 	v7.at(42) = 666;
	// } catch (std::out_of_range const& exc) {
	// 	std::cout << exc.what() << '\n';
	// }

	// v7[4] = 84;
	// v7[2] = 84;

	// print_vector(v7, 7);

	// v7.push_back(66);
	// v7.push_back(97);
	// v7.push_back(62);
	// v7.push_back(28);
	// v7.push_back(66);
	// v7.push_back(57);
	// v7.push_back(12);

	// ft::vector<int> v8 = v7;
	// print_vector(v8, 8);
	// v8.clear();
	// print_vector(v8, 8);

	// v8.insert(v8.begin(), 42);
	// v8.insert(v8.begin(), 41);
	// v8.insert(v8.begin(), 40);
	// v8.insert(v8.begin(), (size_t)5, 1);
	// v8.insert(v8.begin(), (size_t)5, 0);
	// v8.insert(v8.end(), v7.begin() + 2, v7.begin() + 4);

	// print_vector(v8, 8);

	// ft::vector<int>::iterator it1;
	// ft::vector<int>::iterator it2;
	// ft::vector<int>::iterator it3;
	// ft::vector<int>::const_iterator it_const;
	// ft::vector<int>::reverse_iterator it_r;
	// ft::vector<int>::const_reverse_iterator it_rconst;

	// v1.reserve(12);
	// v1.push_back( 0 );
	// v1.push_back( 1 );
	// v1.push_back( 2 );
	// v1.push_back( 3 );
	// v1.push_back( 4 );
	// v1.push_back( 5 );
	// v1.push_back( 6 );
	// v1.push_back( 7 );
	// v1.push_back( 8 );
	// v1.push_back( 9 );
	// v1.push_back( 10 );
	// v1.push_back( 11 );

	// print_vector(v1, 1);

	// it1 = v1.begin();
	// it2 = v1.begin() + 3;
	// it3 = v1.end() - 1;

	// std::cout << "it1 = v1.begin()" << std::endl;
	// std::cout << "it2 = v1.begin() + 3" << std::endl;
	// std::cout << "it3 = v1.end() - 2;" << std::endl;
	// std::cout << std::endl;

	// std::cout << "*(it1): " << *(it1) << std::endl;
	// std::cout << "(it2 - it1): " << (it2 - it1) << std::endl;


	// std::cout << "*(it1 + 1): " << *(it1 + 1) << std::endl;
	// std::cout << "*(1 + it1): " << *(1 + it1) << std::endl;
	// std::cout << "*(it2 - 1): " << *(it2 - 1) << std::endl;
	// std::cout << "*(-1 + it2): " << *(-1 + it2) << std::endl;

	// std::cout << "*(it1++): " << *(it1++) << " -> " << *it1 << std::endl;
	// std::cout << "*(it2++): " << *(it2++) << " -> " << *it2 << std::endl;
	// std::cout << "*(++it1): " << *(++it1) << " -> " << *it1 << std::endl;
	// std::cout << "*(++it2): " << *(++it2) << " -> " << *it2 << std::endl;
	// std::cout << "*(it1--): " << *(it1--) << " -> " << *it1 << std::endl;
	// std::cout << "*(it2--): " << *(it2--) << " -> " << *it2 << std::endl;
	// std::cout << "*(--it1): " << *(--it1) << " -> " << *it1 << std::endl;
	// std::cout << "*(--it2): " << *(--it2) << " -> " << *it2 << std::endl;

	// std::cout << "*(it1 += 3): " << *it1 << " -> " << *(it1 += 3) << std::endl;
	// std::cout << "*(it2 += 3): " << *it2 << " -> " << *(it2 += 3) << std::endl;
	// std::cout << "*(it1 -= 1): " << *it1 << " -> " << *(it1 -= 1) << std::endl;
	// std::cout << "*(it2 -= 1): " << *it2 << " -> " << *(it2 -= 1) << std::endl;

	// ft::reverse_iterator<ft::vector<int>::iterator> it4( v1.rbegin() + 6 );
	// ft::reverse_iterator<ft::vector<int>::iterator> it5( v1.rbegin() );
	// std::cout << "*(it4): " << *(it4) << std::endl;

	// std::cout << "*(it4++): " << *(it4++) << " -> " << *it4 << std::endl;
	// std::cout << "*(++it4): " << *(++it4) << " -> " << *it4 << std::endl;
	// std::cout << "*(it4--): " << *(it4--) << " -> " << *it4 << std::endl;
	// std::cout << "*(--it4): " << *(--it4) << " -> " << *it4 << std::endl;

	// std::cout << "*(it4 + 3): " << *(it4 + 3) << std::endl;
	// std::cout << "*(it4 - 3): " << *(it4 - 3) << std::endl;
	// std::cout << "it4 - it5: " << it4 - it5 << std::endl;

	// it1 = v1.begin();
	// it2 = v1.begin() + 3;

	// ft::vector<int>::const_iterator cit1 = it1;
	// ft::vector<int>::const_iterator cit2 = it2;

	// std::cout << "*cit1: " << *cit1 << std::endl;
	// std::cout << "*cit2: " << *cit2 << std::endl;

	// // nope!
	// //cit2 = 67;

	// // sure
	// *it1 = 55;

	// print_vector(v1, 1);
	// print_vector(v2, 2);

	// std::cout << std::boolalpha << (v1 == v2) << std::endl;
	// std::cout << std::boolalpha << (v1 != v2) << std::endl;
	// std::cout << std::boolalpha << (v1 < v2) << std::endl;
	// std::cout << std::boolalpha << (v1 > v2) << std::endl;
	// std::cout << std::boolalpha << (v1 >= v2) << std::endl;
	// std::cout << std::boolalpha << (v1 <= v2) << std::endl;

	// v1.swap(v2);

	// print_vector(v1, 1);
	// print_vector(v2, 2);

	// std::cout << std::endl;
	// std::cout << std::endl;

	// // stack 
	// ft::stack<int> stack0;
	// stack0.push(1);
	// stack0.push(2);
	// stack0.push(3);
	// stack0.push(4);
	// print_stack(stack0, 0);

	// ft::stack<int> stack1 = stack0;
	// print_stack(stack1, 1);

	// ft::stack<int> stack2(stack1);
	// print_stack(stack2, 2);

	// stack1.pop();

	// stack2.pop();
	// stack2.pop();

	// std::cout << stack0.top() << std::endl;
	// std::cout << stack1.top() << std::endl;
	// std::cout << stack2.top() << std::endl;

	// stack2.pop();
	// stack2.pop();
	// std::cout << std::boolalpha << "Stack2 is empty: " << stack2.empty() << '\n';
	// std::cout << std::boolalpha << "Stack0 is empty: " << stack0.empty() << '\n';
	// std::cout << "Stack2 size: " << stack2.size() << '\n';
	// std::cout << "Stack0 size: " << stack0.size() << '\n';

	// std::cout << "1) " << std::boolalpha << (stack0 == stack1) << std::endl;
	// std::cout << "2) " << std::boolalpha << (stack0 != stack1) << std::endl;
	// std::cout << "3) " << std::boolalpha << (stack0 <  stack1) << std::endl;
	// std::cout << "4) " << std::boolalpha << (stack0 >  stack1) << std::endl;
	// std::cout << "5) " << std::boolalpha << (stack0 >= stack1) << std::endl;
	// std::cout << "6) " << std::boolalpha << (stack0 <= stack1) << std::endl;

	// map

	ft::map<std::string, int> m1;
	std::cout << m1.empty() << std::endl;

	time(&end);
	double diff = difftime(end, start);
	int	tme = static_cast<int> (diff);
	std::cout << "Executed in " << tme << " seconds" << std::endl;
	return 0;









// #include "Vector.hpp"

// int main(){

// 	ft::VectorClass<int> vec;
// 	// std::cout << vec.empty() << std::endl;
// 	// vec.reserve(5);
// 	// vec.push_back(4);
// 	// vec.push_back(55);
// 	// vec.push_back(55);
// 	// vec.push_back(55);
// 	// vec.push_back(55);
// 	// vec.push_back(55);
// 	// vec.push_back(7);
// 	// vec.push_back(55);
// 	// std::cout << vec.size() << std::endl;
// 	// std::cout << vec.capacity() << std::endl;
// 	// vec.clear();
// 	// std::cout << vec.size() << std::endl;
// 	// std::cout << vec.capacity() << std::endl;
// 	// vec.pop_back();
// 	// std::cout << vec.front() << std::endl;
// 	// std::cout << vec.back() << std::endl;
// 	// std::cout << vec.size() << std::endl;
// 	// std::cout << vec.max_size() << std::endl;
// 	// vec.reserve(4);

// 	// vec.push_back(1);
// 	// vec.push_back(2);
// 	// vec.push_back(3);
// 	// for (size_t i = 0; i < vec.size(); i++)
// 	// 	std::cout << vec[i] << ' ';
// 	// std::cout << '\n';

// 	// vec.resize(5, 69);

// 	// for(ft::VectorClass<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
// 	// 	std::cout << *it << ' ';
// 	// std::cout << '\n';

// 	// for (size_t i = 0; i < vec.size(); i++)
// 	// 	std::cout << vec[i] << ' ';
// 	// std::cout << '\n';

// 	// vec.resize(2, 69);

// 	// for (size_t i = 0; i < vec.size(); i++)
// 	// 	std::cout << vec.data()[i] << ' ';
// 	// std::cout << '\n';

// 	// std::cout << vec.at(1) << std::endl;
// 	// std::cout << "test vec2\n";
// 	// ft::VectorClass<int> vec2(vec);
// 	// for (size_t i = 0; i < vec2.size(); i++)
// 	// 	std::cout << vec2[i] << ' ';
// 	// std::cout << '\n';
	
// 	// std::cout << vec.front() << std::endl;
// 	// std::cout << vec.back() << std::endl;
// 	// std::cout << vec.size() << std::endl;
// 	// std::cout << vec.capacity() << std::endl;

// 	// std::cout << vec2.front() << std::endl;
// 	// std::cout << vec2.back() << std::endl;
// 	// std::cout << vec2.size() << std::endl;
// 	// std::cout << vec2.capacity() << std::endl;

// 	// vec.assign(5, 'a');
// 	// for (size_t i = 0; i < vec.size(); i++)
// 	// 	std::cout << vec[i] << ", ";
// 	// std::cout << '\n';

// 	// vec.assign(3, 'b');
// 	// for (size_t i = 0; i < vec.size(); i++)
// 	// 	std::cout << vec[i] << ", ";
// 	// std::cout << '\n';

// 	// vec.assign(1, 'x');
// 	// for (size_t i = 0; i < vec.size(); i++)
// 	// 	std::cout << vec[i] << ", ";
// 	// std::cout << '\n';

// 	vec.assign(10, 6);
// 	for (size_t i = 0; i < vec.size(); i++)
// 		std::cout << vec[i] << ", ";
// 	std::cout << '\n';

// 	vec.insert(vec.begin() + 2, 3, 9);
// 	for (size_t i = 0; i < vec.size(); i++)
// 		std::cout << vec[i] << ", ";
// 	std::cout << '\n';

// 	vec.insert(vec.begin()+3, 11);
// 	for (size_t i = 0; i < vec.size(); i++)
// 		std::cout << vec[i] << ", ";
// 	std::cout << '\n';

// 	vec.erase(vec.begin() + 2);
// 	for (size_t i = 0; i < vec.size(); i++)
// 		std::cout << vec[i] << ", ";
// 	std::cout << '\n';










}