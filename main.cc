#include <iostream>
#include <dirent.h>
#include <sys/types.h>
#include <cstring>
#include <string>

#include "src/find.hh"
#include "src/utils.hh"
#include "src/pattern.hh"

int count_glo = 0;

int main (int argc, char *argv[])
{
    if (argc == 2 and (strcmp(argv[1], "-h") == 0
                       or strcmp(argv[1], "--help") == 0))
    {
        print_help();
        return 0;
    }

    if (argc < 3)
    {
        print_arg_error();
        return 1;
    }

    std::string input = argv[1];
    std::string dir_path = argv[2];

    DIR *dir = opendir(dir_path.c_str());
    test_dir(dir);

    // Instanciate Pattern object
    Pattern pattern(input);
    // Local line counter
    size_t line_count = 0;

    // Main function
    iterate_dir(dir_path, pattern, line_count);

    std::cout << "There is exactly: \'" << line_count << "\' lines in the files contained in this directory (and its sub-directories) that match the given patterns." << "\n";
    //std::cout << "Global counter: " << count_glo << " lines" << "\n";

    return 0;
}
