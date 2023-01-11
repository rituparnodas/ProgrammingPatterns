#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>
#include "SingleResponsiblityPrinciple.h"
#include "OpenClosedPrinciple.h"

int main()
{
    Product apple{ "Apple", Color::green, Size::small };
    Product tree{ "Tree", Color::green, Size::large };
    Product house{ "House", Color::blue, Size::large };

    const vector<Product*> all{ &apple, &tree, &house };

    BetterFilter bf;
    ColorSpecification green(Color::green);
    auto green_things = bf.filter(all, green);
    for (auto& x : green_things)
        cout << x->name << " is green\n";


    SizeSpecification large(Size::large);
    AndSpecification<Product> green_and_large(green, large);

    //auto big_green_things = bf.filter(all, green_and_large);

    // use the operator instead (same for || etc.)
    auto spec = green && large;
    for (auto& x : bf.filter(all, spec))
        cout << x->name << " is green and large\n";

    // warning: the following will compile but will NOT work
    // auto spec2 = SizeSpecification{Size::large} &&
    //              ColorSpecification{Color::blue};

    //getchar();
    return 0;
}