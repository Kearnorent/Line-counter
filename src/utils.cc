#include <iostream>
#include <fstream>
#include <istream>
#include <iterator>
#include <string>
#include <dirent.h>

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
    std::cout << "This is the line counter!" << std::endl;
    std::cout << "This program usually takes two arguments:" << std::endl;
    std::cout << "The first is a string either representing literally a string OR a path to an input file" << std::endl;
    std::cout << "Both these inputs represent a list of patterns usually like this : \"cc,hh,json,txt\"" << std::endl;
    std::cout << "This program counts the total number of lines of all the matching files (depending on the extensions)" << std::endl;
    std::cout << "Example of use: \" ./cl \"cc\" . \", or: \" ./cl file.in ./src \"" << std::endl;
}

void print_arg_error ()
{
    std::cerr << "Please do: './cl -h' for the documentation." << std::endl;
}
