#pragma once

#include <vector>

class Pattern
{
    public:
        Pattern(std::string& intput);
        std::vector<std::string> get_patterns ();
        void fill_patterns (std::string& content);
        std::string operator[] (size_t i);
        size_t get_size () { return patterns.size(); }
    private:
        std::vector<std::string> patterns;
};
