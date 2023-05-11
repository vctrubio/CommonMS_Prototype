#include "../Headers.hpp"
#include "User.hpp"
#include "Business.hpp"
#include "Product.hpp"


int main()
{
	User	 v("Victor");
	Business b(&v, "Toms Garage");

	std::cout << "Helloworld\n";
	b.test();

}
