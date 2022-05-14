#ifndef COMPARE_HPP
# define COMPARE_HPP

#include "VectorIter.hpp"
#include <type_traits>


namespace ft{

template< class InputIt1, class InputIt2 >
bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2 ){
	for (; first1 != last1; ++first1, ++first2) {
		if (!(*first1 == *first2))
			return false;
	}
	return true;
}

template< class InputIt1, class InputIt2, class BinaryPredicate >
bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p ){
	for (; first1 != last1; ++first1, ++first2) {
		if (!p(*first1, *first2))
			return false;
	}
	return true;
}

template< class InputIt1, class InputIt2 >
bool lexicographical_compare( InputIt1 first1, InputIt1 last1,
							InputIt2 first2, InputIt2 last2 ){
	for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
		if (*first1 < *first2) return true;
		if (*first2 < *first1) return false;
	}
	return (first1 == last1) && (first2 != last2);
}

template< class InputIt1, class InputIt2, class Compare >
bool lexicographical_compare( InputIt1 first1, InputIt1 last1,
						InputIt2 first2, InputIt2 last2, Compare comp ){
	for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
		if (comp(*first1, *first2)) return true;
		if (comp(*first2, *first1)) return false;
	}
	return (first1 == last1) && (first2 != last2);
}


template <class T> struct is_integral{
	// figure this shit out
}

template <>          struct is_integral<bool>               : true_type {};
template <>          struct is_integral<char>               : true_type {};
template <>          struct is_integral<signed char>        : true_type {};
template <>          struct is_integral<unsigned char>      : true_type {};
template <>          struct is_integral<wchar_t>            : true_type {};
template <>          struct is_integral<char16_t>           : true_type {};
template <>          struct is_integral<char32_t>           : true_type {};
template <>          struct is_integral<short>              : true_type {};
template <>          struct is_integral<unsigned short>     : true_type {};
template <>          struct is_integral<int>                : true_type {};
template <>          struct is_integral<unsigned int>       : true_type {};
template <>          struct is_integral<long>               : true_type {};
template <>          struct is_integral<unsigned long>      : true_type {};
template <>          struct is_integral<long long>          : true_type {};
template <>          struct is_integral<unsigned long long> : true_type {};

} //end namespace
#endif