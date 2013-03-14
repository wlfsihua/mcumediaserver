/* 
 * File:   opusdecoder.cpp
 * Author: Sergio
 * 
 * Created on 14 de marzo de 2013, 11:19
 */

#include "opusdecoder.h"
#include "log.h"

OpusDecoder::OpusDecoder()
{
	int error = 0;
	//Create decoder
	dec = opus_decoder_create(8000,1,&error);
	//Check error
	if (!dec || error)
		Error("Could not open OPUS encoder");
}

OpusDecoder::~OpusDecoder()
{
	if (dec)
		opus_decoder_destroy(dec);
}

int OpusDecoder::Decode(BYTE *in,int inLen,SWORD* out,int outLen)
{
	//Decode without FEC
	return opus_decode(dec,in,inLen,out,outLen,0);
}