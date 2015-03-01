#ifndef FREQUENCIES_HH__
#define FREQUENCIES_HH__

#include <algorithm>
#include <map>
#include <string>

#include <cctype>

std::string frequencies( std::string s )
{
  std::map<char, unsigned int> f;

  std::transform(s.begin(), s.end(), s.begin(), ::toupper);

  for( auto&& c : s )
    f[c] = f[c] + 1;

  std::string result;
  for( auto&& pair : f )
    if( 'A' <= pair.first && pair.first <= 'Z' )
      result.push_back(pair.first);

  std::sort( result.begin(), result.end(),
             [&]( char c, char d )
             {
               return f.at(c) > f.at(d);
             } );

  return result;
}

unsigned int rate(const std::string& frequencies)
{
  std::string expected = "ETAOINSHRDLU";
  unsigned int length  = std::min(frequencies.length(), expected.length());
  unsigned int score   = 0;

  for(unsigned int i = 0; i < length; i++)
  {
    unsigned int penalty = expected.length() - i;

    if( frequencies[i] != expected[i] )
      score += penalty;
  }

  return score;
}

#endif
