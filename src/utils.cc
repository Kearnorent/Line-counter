#include <iostream>
#include <fstream>
#include <istream>
#include <iterator>
#include <string>
#include <dirent.h>
#include <vector>

#include "words.hh"
#include "pattern.hh"

void final_print (Words& words, std::vector<int> words_count, Pattern& pattern, size_t line_count)
{

    for (size_t c = 0; c < words.get_size(); c++)
    {
        std::cout << "\033[1;34m" << "The word " << "\033[1;30m" << "\'" << words[c] << "\'" << "\033[34m" << " appeared: " << "\033[0;32m" << words_count[c] << "\033[1;34m" << " times." << "\033[0m" << '\n';
    }

    std::cout << "\033[1;34m"  << "The total number of lines is: " << "\033[0;32m" << line_count << "\033[1;34m" << " (from the files matching the following file names: " << "\033[1;30m";
    for (size_t i = 0; i < pattern.get_size(); i++)
    {
        if (i == pattern.get_size() - 1)
            std::cout << pattern[i];
        else
            std::cout << pattern[i] << "\033[1;34m" << ", " << "\033[1;30m";
    }
    std::cout << "\033[1;34m" << ")" << "\033[0m" << '\n';
}

std::string read_file (std::string& path)
{
    // Open file
    std::ifstream file(path);
    // Read file
    std::string content((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
    // Close file
    file.close();

    return content;
}

size_t count_newlines (std::string& content)
{
    size_t c = 0;
    size_t len = content.size();
    for (size_t i = 0; i < len; i++)
    {
        if (content[i] == '\n')
        {
            c += 1;
        }
    }
    return c;
}

void test_dir (DIR *dir)
{
    if (dir == NULL)
    {
        std::cerr << "Wrong directory name." << std::endl;
        exit(1);
    }
    else
    {
        closedir(dir);
    }
}

void print_help ()
{
    //FIXME
}

void print_arg_error ()
{
    std::cerr << "Usage: ./cl -p [Patterns] -d [Directory] -w [Words] -v" << std::endl;
}
