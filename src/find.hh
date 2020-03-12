#pragma once

#include "pattern.hh"
#include "words.hh"

size_t iterate_dir (std::string& path, Pattern& pattern, Words& words, size_t& line_count, std::vector<int>& words_count);

bool is_match_pattern (std::string& path, Pattern& pattern);
