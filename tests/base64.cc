#include <conversions/base64.hh>
#include <conversions/bytes.hh>
#include <conversions/hex.hh>

#include <string>

int main(int, char**)
{
  {
    std::string in  = "Man is distinguished, not only by his reason, but by this singular passion "
                      "from other animals, which is a lust of the mind, that by a perseverance of "
                      "delight in the continued and indefatigable generation of knowledge, exceeds "
                      "the short vehemence of any carnal pleasure.";

    std::string out = "TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0aGlz"
                      "IHNpbmd1bGFyIHBhc3Npb24gZnJvbSBvdGhlciBhbmltYWxzLCB3aGljaCBpcyBhIGx1c3Qgb2Yg"
                      "dGhlIG1pbmQsIHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZGVsaWdodCBpbiB0aGUgY29udGlu"
                      "dWVkIGFuZCBpbmRlZmF0aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRzIHRo"
                      "ZSBzaG9ydCB2ZWhlbWVuY2Ugb2YgYW55IGNhcm5hbCBwbGVhc3VyZS4=";

    crypto::ByteArray bytes = crypto::toBytes( in.begin(), in.end() );
    std::string base64      = crypto::toBase64( bytes );

    if( base64 != out )
      return -1;
  }

  {
    std::string hex         = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    crypto::ByteArray bytes = crypto::hexToBytes( hex );
    std::string base64      = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";

    if( crypto::toBase64( bytes ) != base64 )
      return -2;
  }

  return 0;
}
