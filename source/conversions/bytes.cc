#include "bytes.hh"

namespace crypto
{

// ---------------------------------------------------------------------

std::string toString( const ByteArray& bytes )
{
  std::string result;
  result.reserve( bytes.size() );

  for( auto&& byte : bytes )
    result.push_back( static_cast<char>(byte) );

  return result;
}

// ---------------------------------------------------------------------

}
