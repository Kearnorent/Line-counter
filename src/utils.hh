#pragma once

std::string read_file (std::string& path);

size_t count_newlines (std::string& content);

void test_dir (DIR *dir);

void print_help ();

void print_arg_error ();
