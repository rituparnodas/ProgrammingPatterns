#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>
#include "SingleResponsiblityPrinciple.h"

int main()
{
    Journal journal{ "Dear Diary" };
    journal.add_entry("I Made Friends");
    journal.add_entry("I cried alone");
    journal.add_entry("I pick myself alone");

    //journal.save("diary.txt");

    PersistenceManager pm;
    pm.save(journal, "diary.txt");


    std::cout << "Hello World" << std::endl;

    return 0;
}