#include "doctest.h"
#include "FamilyTree.hpp"


#include <string>
#include <iostream>
using namespace family;
using namespace std;



TEST_CASE("Test matoda addFather") {
   family::Tree T ("ahmad"); 
	T.addFather("ahmad", "galb")  
	 .addMother("ahmad", "rasmya")   
	 .addFather("galb", "mohmed")
	 .addMother("galb", "latife")
	 .addFather("rasmya", "ahmad")
	 .addMother("rasmya", "soaad");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    /* Add more checks here */
}

