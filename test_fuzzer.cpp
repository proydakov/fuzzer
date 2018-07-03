#include <cstdint>
#include <cstddef>
#include <iostream>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
  if(size >= 1500)
  {
    return 0;
  }
  std::uint64_t counter = 0;
  if (size > 0 && data[0] == 'H')
    if (size > 1 && data[1] == 'I')
       if (size > 1024 && data[2] == '!')
           counter++;
           //throw 1;
       //__builtin_trap();
  return 0;
}
