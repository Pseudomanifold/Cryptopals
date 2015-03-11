#include <iostream>

#include <tools/decrypt_single_byte_xor.hh>

int main(int, char**)
{
  std::string in  = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
  std::string out = crypto::decryptSingleByteXOR(in);

  if( out != "Cooking MC's like a pound of bacon" )
    return -1;

  return 0;
}

