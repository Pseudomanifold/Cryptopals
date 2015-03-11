#include <algorithms/xor.hh>
#include <conversions/bytes.hh>

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

void usage( const std::string& program )
{
  std::cerr << "Usage: " << program << " KEY\n"
            << "Applies XOR with the given key to STDIN of the program\n"
            << "and writes the results to STDOUT.\n\n";
}

int main(int argc, char** argv)
{
  if( argc != 2 )
  {
    usage(argv[0]);
    return -1;
  }

  std::cin >> std::noskipws;

  std::istream_iterator<char> it( std::cin );
  std::istream_iterator<char> end;

  std::string input = std::string( it, end );
  std::string key   = argv[1];

  crypto::ByteArray out
    = crypto::repeatingKeyXOR( crypto::toBytes( input.begin(), input.end() ),
                                                key );

  for( auto&& byte : out )
    std::cout << byte;

  return 0;
}
