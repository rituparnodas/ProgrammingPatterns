#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>

/*
* Instead Of Directly Saving , We move The Save To Different Component
*/

struct Journal
{
    std::string title;
    std::vector<std::string> entries;

    Journal(const std::string& title) : title(title) {}

    void add_entry(const std::string& entry)
    {
        static int count = 1;
        entries.push_back(boost::lexical_cast<std::string>(count++) + ": " + entry);
    }

    void save(const std::string& filename)
    {
        std::ofstream ofs(filename);
        for (auto& e : entries)
        {
            ofs << e << std::endl;
        }
    }
};

struct PersistenceManager
{
    static void save(const Journal& j, const std::string& filename)
    {
        std::ofstream ofs(filename);
        for (auto& s : j.entries)
            ofs << s << std::endl;
    }
};