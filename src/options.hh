#pragma once

#include <memory>
#include <vector>
#include <string>

class Option
{
    public:
        Option (std::string name, std::string value);
        std::string get_name () { return name_; }
        std::string get_value () { return value_; }

    private:
        std::string name_;
        std::string value_;
};

class Options
{
    public:
        Options () = default;
        void parse_options (int argc, char *argv[]);
        void add_option (std::shared_ptr<Option> opt);
        std::string find_option_if_set(std::string opt);

    private:
        std::vector<std::shared_ptr<Option>> options_;
};

extern Options options;
