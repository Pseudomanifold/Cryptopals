#include "conversions.hh"

#include <iostream>

int main(int, char**)
{
  std::string s  = "Man is distinguished, not only by his reason, but by this singular passion "
                   "from other animals, which is a lust of the mind, that by a perseverance of "
                   "delight in the continued and indefatigable generation of knowledge, exceeds "
                   "the short vehemence of any carnal pleasure.";

  std::cout << toBase64(s.c_str(), s.length() ) << "\n";

  return 0;
}
