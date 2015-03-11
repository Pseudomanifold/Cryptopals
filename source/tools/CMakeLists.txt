SET( TOOLS_SRC
  decrypt_single_byte_xor.cc
  detect_single_byte_xor.cc
)

ADD_LIBRARY( tools ${TOOLS_SRC} )
TARGET_LINK_LIBRARIES( tools algorithms conversions )

ADD_EXECUTABLE( xor xor.cc )
TARGET_LINK_LIBRARIES( xor algorithms )
