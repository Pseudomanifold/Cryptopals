#include <conversions/bytes.hh>
#include <tools/hamming_distance.hh>

#include <string>

int main(int, char**)
{
  std::string s = "this is a test";
  std::string t = "wokka wokka!!!";

  unsigned int d
    = crypto::hammingDistance(  crypto::toBytes( s.begin(), s.end() ),
                                crypto::toBytes( t.begin(), t.end() ) );

  if( d != 37 )
    return -1;

  return 0;
}
