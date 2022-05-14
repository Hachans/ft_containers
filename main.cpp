#include "Vector.hpp"

int main(){

	ft::VectorClass<int> vec;
	// std::cout << vec.empty() << std::endl;
	// vec.reserve(5);
	// vec.push_back(4);
	// vec.push_back(55);
	// vec.push_back(55);
	// vec.push_back(55);
	// vec.push_back(55);
	// vec.push_back(55);
	// vec.push_back(7);
	// vec.push_back(55);
	// std::cout << vec.size() << std::endl;
	// std::cout << vec.capacity() << std::endl;
	// vec.clear();
	// std::cout << vec.size() << std::endl;
	// std::cout << vec.capacity() << std::endl;
	// vec.pop_back();
	// std::cout << vec.front() << std::endl;
	// std::cout << vec.back() << std::endl;
	// std::cout << vec.size() << std::endl;
	// std::cout << vec.max_size() << std::endl;
	// vec.reserve(4);

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << '\n';

	vec.resize(5, 69);

	for(ft::VectorClass<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';

	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << '\n';

	vec.resize(2, 69);

	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec.data()[i] << ' ';
	std::cout << '\n';

	std::cout << vec.at(1) << std::endl;
	std::cout << "test vec2\n";
	ft::VectorClass<int> vec2(vec);
	for (size_t i = 0; i < vec2.size(); i++)
		std::cout << vec2[i] << ' ';
	std::cout << '\n';
	
	std::cout << vec.front() << std::endl;
	std::cout << vec.back() << std::endl;
	std::cout << vec.size() << std::endl;
	std::cout << vec.capacity() << std::endl;

	std::cout << vec2.front() << std::endl;
	std::cout << vec2.back() << std::endl;
	std::cout << vec2.size() << std::endl;
	std::cout << vec2.capacity() << std::endl;






}