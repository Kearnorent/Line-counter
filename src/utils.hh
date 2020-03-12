#pragma once

#include <dirent.h>
#include <vector>

#include "words.hh"
#include "pattern.hh"

std::string read_file (std::string& path);

size_t count_newlines (std::string& content);

void test_dir (DIR *dir);

void print_help ();

void print_arg_error ();

void final_print (Words& words, std::vector<int> words_count, Pattern& pattern, size_t line_count);
