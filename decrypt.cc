#include "conversions.hh"
#include "frequencies.hh"
#include "xor.hh"

#include <cctype>
#include <iostream>

bool isPlainText(const std::string& s)
{
  for(auto&& c : s)
    if( c < 32 )
      return false;

  return true;
}

unsigned int numEnglishCharacters(const std::string& s)
{
  unsigned int count = 0;

  for(auto&& c : s)
    if( std::isalnum(c) || std::isspace(c) )
      count++;

  return count;
}

int main(int, char**)
{
  std::string in = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
  std::string bytes = toBytes(in.c_str(), in.length());

  std::string candidate;
  unsigned int score = 0;

  for(unsigned short key = 0; key < 256; key++)
  {
    std::string keyBytes(bytes.length(), static_cast<char>(key));
    std::string result = xorBuffers(bytes.c_str(), keyBytes.c_str(), bytes.length());

    if(!isPlainText(result))
      continue;

    unsigned int s = numEnglishCharacters( result );
    if( s > score )
    {
      score     = s;
      candidate = result;
    }
  }

  std::cout << score << "\n";
  std::cout << candidate << "\n";

  return 0;
}
