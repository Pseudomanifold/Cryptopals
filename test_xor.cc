#include "conversions.hh"
#include "xor.hh"

int main(int, char**)
{
  std::string s = "1c0111001f010100061a024b53535009181c";
  std::string t = "686974207468652062756c6c277320657965";
  std::string u = "746865206b696420646f6e277420706c6179";

  std::string sBytes = toBytes(s.c_str(), s.length());
  std::string tBytes = toBytes(t.c_str(), t.length());
  std::string uBytes = toBytes(u.c_str(), u.length());
  std::string sXORt  = xorBuffers(sBytes.c_str(), tBytes.c_str(), sBytes.length());

  if( uBytes == sXORt )
    return 0;

  return -1;
}
