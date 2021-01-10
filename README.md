# Line counter tool
---

:pushpin: The Project was implemented in C++.

:pushpin: This tool counts the total number of lines of certain files in a given directory. As well as find certain words in the matched files.

---
### How to build & Usage

    mkdir build && cd build/ && cmake .. && make -j && ./cl

###

    Options:

    -p (or --patterns) -> Patterns List [MANDATORY]

    -d (or --dir) -> Directory path [MANDATORY]

    -w (or --words) -> Words List (That the program will search in the files) [OPTIONAL]

    -v (or --verbose) -> Verbose print option (prints where the words were found, ie: file main.cc line 30) [OPTIONAL]

###
  
    Usage:
    
    ./cl -p [File_extensions] -d [directory_path]

    ./cl -p [File_extensions] -d [directory_path] -w [Words]

    ./cl -p [File_extensions] -d [directory_path] -w [Words] -v

    Example of 'File_extensions': "json, cc, c, hh, txt, h"

    Example of 'directory_path': "."

    Example of 'Words': "FIXME,TODO"

    (./cl -p "cc" -d "." -w "FIXME" -v)



