#include "doctest.h"
#include "FamilyTree.hpp"


#include <string>
#include <iostream>
using namespace family;
using namespace std;



TEST_CASE("Test matoda find") {
   family::Tree T ("ahmad"); 
	T.addFather("ahmad", "galb")  
	 .addMother("ahmad", "rasmya")   
	 .addFather("galb", "mohmed")
	 .addMother("galb", "latife")
	 .addFather("rasmya", "ahmad")
	 .addMother("rasmya", "soaad");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("ahmad") == "ahmad");
    CHECK(T.find("rasmya") == "rasmya");
    CHECK(T.find("mohamed") == "mohamed");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
    CHECK(T.find("galb") == "galb");
}

TEST_CASE("Test matoda relation") {
   family::Tree T ("ahmad"); 
	T.addFather("ahmad", "galb")  
	 .addMother("ahmad", "rasmya")   
	 .addFather("galb", "mohmed")
	 .addMother("galb", "latife")
	 .addFather("rasmya", "ahmad")
	 .addMother("rasmya", "soaad");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
    CHECK(T.relation("galb") == "galb");
}
