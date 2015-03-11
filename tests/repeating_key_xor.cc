#include <algorithms/xor.hh>
#include <conversions/bytes.hh>

#include <iomanip>

#include <string>
#include <sstream>

int main(int, char**)
{
  std::string in = "Burning 'em, if you ain't quick and nimble\n"
                   "I go crazy when I hear a cymbal";

  crypto::ByteArray bytes = crypto::repeatingKeyXOR( crypto::toBytes( in.begin(), in.end() ), "ICE" );

  std::ostringstream stream;
  stream << std::hex;

  for( auto&& byte : bytes )
    stream << std::setfill('0') << std::setw(2) << static_cast<unsigned>( byte );

  std::string expected = "0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272"
                         "a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f";

  if( stream.str() != expected )
    return -1;

  return 0;
}
