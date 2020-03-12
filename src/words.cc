#include <iostream>
#include <string>
#include <vector>

#include "options.hh"
#include "words.hh"

void count_words_in_file (std::string filename, std::string file_content, Words& words, std::vector<int>& words_count)
{
    size_t len_words = words.get_size();
    size_t len_file = file_content.size();
    for (size_t i = 0; i < len_words; i++)
    {
        std::string cur_word = words[i];
        int count_newlines = 0;
        for (size_t j = 0; j < len_file; j++)
        {
            size_t k = 0;
            if (file_content[j] == '\n')
                count_newlines += 1;
            while (cur_word[k] == file_content[j])
            {
                if (k == cur_word.size() - 1)
                {
                    words_count[i] += 1;
                    if (options.find_option_if_set("v") != "")
                    {
                        std::cout << "\033[1;34m" << "[" << filename << ":" << count_newlines << "]" << "\033[1;30m" << " \'" << words[i] << "\'" << "\033[0m" << "\n";
                    }
                    break;
                }
                k++;
                j++;
            }
        }
    }
}

std::string Words::operator[] (size_t i)
{
    return words_[i];
}

void Words::set_words (std::string words)
{
    size_t len = words.size();
    std::string buf = "";
    for (size_t i = 0; i < len; i++)
    {
        if (words[i] == ' ' or words[i] == '\t')
        {
            continue;
        }
        else if (words[i] == ',' or words[i] == '\n'
                or words[i] == '\0' or i == len - 1)
        {
            if (i == len - 1)
                buf += words[i];
            if (buf != "")
            {
                words_.push_back(buf);
                buf = "";
            }
        }
        else
        {
            buf += words[i];
        }
    }
}
