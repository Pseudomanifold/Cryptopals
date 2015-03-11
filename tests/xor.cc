#include <algorithms/xor.hh>
#include <conversions/hex.hh>

int main(int, char**)
{
  std::string s = "1c0111001f010100061a024b53535009181c";
  std::string t = "686974207468652062756c6c277320657965";
  std::string e = "746865206b696420646f6e277420706c6179";

  crypto::ByteArray sBytes = crypto::hexToBytes(s);
  crypto::ByteArray tBytes = crypto::hexToBytes(t);
  crypto::ByteArray eBytes = crypto::hexToBytes(e);

  if( eBytes != crypto::fixedXOR( sBytes, tBytes ) )
    return -1;

  return 0;
}
