// Authors Nathan Lin, Fnu Vijay Kumar
#ifndef DECODER_H
#define	DECODER_H

//#include "LeftistHeap.h"

class Decoder
{
public:
  Decoder();
  ~Decoder();
  void decode(const unsigned char* encodedMessage, const int encodedSize, 
    unsigned char* decodedMessage, int *decodedSize);
private:
  //int codes[256][8];
  //int lengths[256];

};

#endif	/* DECODER_H */

