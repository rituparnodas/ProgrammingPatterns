#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>
#include "SingleResponsiblityPrinciple.h"
#include "OpenClosedPrinciple.h"
#include "LiskovSubstitutionPrinciple.h"
#include "DependencyInversionPrinciple.h"

int main()
{
    Person parent{ "John" };
    Person child1{ "Chris" };
    Person child2{ "Matt" };

    Relationships relationships;
    relationships.add_parent_and_child(parent, child1);
    relationships.add_parent_and_child(parent, child2);

    Research _(relationships);

    return 0;
}