#include "frequency_analysis.hh"

#include <algorithm>
#include <cctype>

namespace crypto
{

// ---------------------------------------------------------------------

std::map<char, double> eightBitFrequencies( const ByteArray& bytes )
{
  std::map<char, double> frequencies;

  for( auto&& byte : bytes )
  {
    char c = static_cast<char>( byte );
    c      = static_cast<char>( std::toupper( c ) );

    if( ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9') )
      frequencies[c] = frequencies[c] + 1.0;
  }

  for( auto&& pair : frequencies )
    pair.second = pair.second / bytes.size();

  return frequencies;
}

// ---------------------------------------------------------------------

std::vector< std::pair<char, double> > sortedEightBitFrequencies( const ByteArray& bytes )
{
  auto frequencies = eightBitFrequencies( bytes );

  using CharacterPair = std::pair<char, double>;

  std::vector< std::pair<char, double> > characters( frequencies.begin(),
                                                     frequencies.end() );

  std::sort( characters.begin(), characters.end(),
             []( CharacterPair p, CharacterPair q )
             {
               return p.second > q.second;
             } );

  return characters;
}

// ---------------------------------------------------------------------

}
