#include <cstring>
#include <iostream>
#include <memory>
#include <vector>
#include <string>

#include "options.hh"
#include "utils.hh"

void Options::parse_options (int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-h") == 0 or strcmp(argv[i], "--help") == 0)
        {
            add_option(std::shared_ptr<Option>(new Option("h", "y")));
        }
        else if (strcmp(argv[i], "-v") == 0 or strcmp(argv[i], "--verbose") == 0)
        {
            add_option(std::shared_ptr<Option>(new Option("v", "y")));
        }
        else if (i + 1 < argc
        and (strcmp(argv[i], "-p") == 0 or strcmp(argv[i], "--patterns") == 0))
        {
            add_option(std::shared_ptr<Option>(new Option("p", argv[i + 1])));
            i++;
        }
        else if (i + 1 < argc
        and (strcmp(argv[i], "-d") == 0 or strcmp(argv[i], "--dir") == 0))
        {
            add_option(std::shared_ptr<Option>(new Option("d", argv[i + 1])));
            i++;
        }
        else if (i + 1 < argc
        and (strcmp(argv[i], "-w") == 0 or strcmp(argv[i], "--words") == 0))
        {
            add_option(std::shared_ptr<Option>(new Option("w", argv[i + 1])));
            i++;
        }
        else
        {
            print_arg_error();
            exit(EXIT_FAILURE);
        }
    }
}

std::string Options::find_option_if_set (std::string opt)
{
    for (size_t i = 0; i < options_.size(); i++)
    {
        if (options_[i]->get_name() == opt)
        {
            return options_[i]->get_value();
        }
    }
    return "";
}

void Options::add_option (std::shared_ptr<Option> opt)
{
    options_.push_back(opt);
}

Option::Option (std::string name, std::string value)
{
    name_ = name;
    value_ = value;
}
