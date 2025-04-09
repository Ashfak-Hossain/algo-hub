### C++ Build

To actually include this `debug.h` file you will have to compile your code with the `BERLIN` flag as follows: `g++ -DBERLIN <your-normal-compile-flags> a.cpp`. To do this just edit your build system and add `-DBERLIN` tag among the other tags.

### Sublime Build
```
{
  "shell_cmd": "g++-11 -Wl,-stack_size,0x20000000 -std=c++17 -DBERLIN \"${file}\" -o \"${file_path}/${file_base_name}\" && timeout 2s \"${file_path}/${file_base_name}\" < ~/battlefield/algo-hub/playground/input.txt > ~/battlefield/algo-hub/playground/output.txt 2> ~/battlefield/algo-hub/playground/error.txt && rm \"${file_path}/${file_base_name}\"",
  "file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
  "working_dir": "${file_path}",
  "selector": "source.c++"
}
``` 