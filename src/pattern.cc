#include <iostream>
#include <istream>
#include <fstream>
#include <vector>
#include <iterator>

#include "pattern.hh"

std::string Pattern::operator[] (size_t i)
{
    return patterns[i];
}

std::vector<std::string> Pattern::get_patterns ()
{
    return this->patterns;
}

void Pattern::fill_patterns (std::string& content)
{
    // Fill 'patterns' vector
    size_t len = content.size();
    std::string buf = "*.";
    for (size_t i = 0; i < len; i++)
    {
        if (content[i] == ' ' or content[i] == '\t')
        {
            continue;
        }
        else if (content[i] == ',' or content[i] == '\n'
                 or content[i] == '\0' or i == len - 1)
        {
            if (i == len - 1)
                buf += content[i];
            patterns.push_back(buf);
            buf = "*.";
        }
        else
        {
            buf += content[i];
        }
    }
}

Pattern::Pattern (std::string& input)
{
    // Open file
    std::ifstream input_file(input);

    // Cas ou l'input n'est pas un file mais une string
    if (input_file.is_open() == false)
    {
        this->fill_patterns(input);
        return;
    }

    // Read file
    std::string content((std::istreambuf_iterator<char>(input_file)), (std::istreambuf_iterator<char>()));

    this->fill_patterns(content);

    // Close file
    input_file.close();
}
