#include "decrypt_single_byte_xor.hh"
#include "detect_single_byte_xor.hh"

#include <tuple>

namespace crypto
{

// ---------------------------------------------------------------------

std::pair<std::string, std::string> detectSingleByteXOR( const std::vector<std::string>& strings )
{
  unsigned int index = 0;
  unsigned int score = 0;

  std::string candidate;

  unsigned int i = 0;
  for( auto&& string : strings )
  {
    unsigned int s = 0;
    std::string str;

    std::tie( std::ignore, s, str ) = decryptSingleByteXOR(string);

    if( s > score )
    {
      candidate = str;
      score     = s;
      index     = i;
    }

    ++i;
  }

  return std::make_pair( strings.at(index), candidate );
}

// ---------------------------------------------------------------------

}
