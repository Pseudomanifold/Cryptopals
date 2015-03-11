ADD_EXECUTABLE( base64 base64.cc )
TARGET_LINK_LIBRARIES( base64 conversions )

ADD_EXECUTABLE( xor xor.cc )
TARGET_LINK_LIBRARIES( xor algorithms conversions )

ADD_TEST( NAME base64 COMMAND base64 )
ADD_TEST( NAME xor    COMMAND xor )
