#include "conversions.hh"
#include "frequencies.hh"
#include "xor.hh"

#include <fstream>
#include <iostream>
#include <iterator>
#include <utility>

#include <cctype>

bool isPlainText(const std::string& s)
{
  for(auto&& c : s)
    if( c < 32 && c != '\n' )
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

std::pair<unsigned int, std::string> decrypt(const std::string& s)
{
  std::string bytes = toBytes(s.c_str(), s.length());

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

  return std::make_pair(score, candidate);
}

int main(int argc, char* argv[])
{
  if( argc == 1 )
    return -1;

  std::ifstream in(argv[1]);

  std::istream_iterator<std::string> it( in );
  std::istream_iterator<std::string> end;

  unsigned int score = 0;
  std::string candidate;

  for( ; it != end; ++it )
  {
    unsigned int s;
    std::string result;

    std::tie( s, result ) = decrypt(*it);

    if( s > score )
    {
      score     = s;
      candidate = result;
    }
  }

  std::cout << "Candidate [" << candidate << "]" << " with a score of "
            << score << "\n";

  return 0;
}
