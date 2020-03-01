#pragma once

#include "pattern.hh"

extern int count_glo;

size_t iterate_dir (std::string& path, Pattern& pattern, size_t& line_count);

bool is_match_pattern (std::string& path, Pattern& pattern);
