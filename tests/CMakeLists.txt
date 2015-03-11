ADD_EXECUTABLE( base64 base64.cc )
TARGET_LINK_LIBRARIES( base64 conversions )

ADD_EXECUTABLE( test_xor xor.cc )
TARGET_LINK_LIBRARIES( test_xor algorithms conversions )

ADD_EXECUTABLE( decrypt_single_byte_xor decrypt_single_byte_xor.cc )
TARGET_LINK_LIBRARIES( decrypt_single_byte_xor tools )

ADD_EXECUTABLE( detect_single_byte_xor detect_single_byte_xor.cc )
TARGET_LINK_LIBRARIES( detect_single_byte_xor tools )

ADD_EXECUTABLE( repeating_key_xor repeating_key_xor.cc )
TARGET_LINK_LIBRARIES( repeating_key_xor algorithms )

ADD_EXECUTABLE( hamming_distance hamming_distance )
TARGET_LINK_LIBRARIES( hamming_distance tools ) 

ADD_TEST( NAME "Base64_conversion"           COMMAND base64 )
ADD_TEST( NAME "Fixed-length_XOR_encryption" COMMAND test_xor )
ADD_TEST( NAME "Decrypt_single-byte_XOR"     COMMAND decrypt_single_byte_xor )
ADD_TEST( NAME "Detect_single-byte_XOR"      COMMAND detect_single_byte_xor )
ADD_TEST( NAME "Repeating_key_XOR"           COMMAND repeating_key_xor )
ADD_TEST( NAME "Hamming_distance"            COMMAND hamming_distance )
