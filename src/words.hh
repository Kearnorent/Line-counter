#pragma once

#include <vector>
#include <string>

class Words
{
    public:
        Words () = default;
        std::string operator[] (size_t i);
        void set_words (std::string words);
        std::vector<std::string> get_words () { return words_; }
        size_t get_size () { return words_.size(); }

    private:
        std::vector<std::string> words_;
};

void count_words_in_file (std::string filename, std::string file_content, Words& words, std::vector<int>& words_count);
