ADD_EXECUTABLE( base64 base64.cc )
TARGET_LINK_LIBRARIES( base64 conversions )

ADD_EXECUTABLE( xor xor.cc )
TARGET_LINK_LIBRARIES( xor algorithms conversions )

ADD_EXECUTABLE( decrypt_single_byte_xor decrypt_single_byte_xor.cc )
TARGET_LINK_LIBRARIES( decrypt_single_byte_xor tools )

ADD_EXECUTABLE( detect_single_byte_xor detect_single_byte_xor.cc )
TARGET_LINK_LIBRARIES( detect_single_byte_xor tools )

ADD_TEST( NAME "Base64_conversion"           COMMAND base64 )
ADD_TEST( NAME "Fixed-length_XOR_encryption" COMMAND xor )
ADD_TEST( NAME "Decrypt_single-byte_XOR"     COMMAND decrypt_single_byte_xor )
ADD_TEST( NAME "Detect_single-byte_XOR"      COMMAND detect_single_byte_xor )
