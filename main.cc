#include <iostream>
#include <dirent.h>
#include <sys/types.h>
#include <cstring>
#include <string>

#include "src/find.hh"
#include "src/utils.hh"
#include "src/pattern.hh"
#include "src/options.hh"
#include "src/words.hh"

// Options global variable
Options options = Options();

int main (int argc, char *argv[])
{
    options.parse_options(argc, argv);

    if (options.find_option_if_set("h") != "")
    {
        print_arg_error();
        return 0;
    }

    std::string patterns = options.find_option_if_set("p");
    std::string dir_path = options.find_option_if_set("d");
    std::string words_str = options.find_option_if_set("w");
    if (dir_path != "")
    {
        DIR *dir = opendir(dir_path.c_str());
        test_dir(dir);

        Words words = Words();
        if (words_str != "")
        {
            words.set_words(words_str);
        }
        // Instanciate Pattern object
        Pattern pattern(patterns);
        // Local line counter
        size_t line_count = 0;

        // Local vector that stores the words counter
        std::vector<int> words_count;
        for (size_t c = 0; c < words.get_size(); c++)
            words_count.push_back(0);

        // Main function
        iterate_dir(dir_path, pattern, words, line_count, words_count);

        // Prints the final results
        final_print(words, words_count, pattern, line_count);
    }
    else
    {
        print_arg_error();
        return 1; 
    }
    return 0;
}
