#include <stdio.h>
#include <stdint.h>

static uint8_t index2letter(uint8_t index)
{
	if(index <= 25)
		return 'A' + index;
	else if(index <= 51)
		return 'a' + index - 26;
	else if(index <= 63)
		return '0' + index - 52;
	else
		return 0;
}

size_t hex2base64(uint8_t *inbuf, size_t inlen, uint8_t *outbuf, size_t outlen)
{
	int i;

	if(!inlen || !outlen)
		return 0;

	if(inlen >= ((SIZE_MAX / 4 - 1) * 3) + 1)
		return 0;

	size_t minlen = ((inlen - 1) / 3 + 1) * 4;

	if(outlen < minlen)
		return 0;

	for(i = 2; i < inlen; i = i + 3)
	{
		uint32_t trio = (inbuf[i - 2] << 16) | (inbuf[i - 1] << 8) | inbuf[i];
		*outbuf++ = index2letter((trio >> 18) & 0x3F);
		*outbuf++ = index2letter((trio >> 12) & 0x3F);
		*outbuf++ = index2letter((trio >> 6) & 0x3F);
		*outbuf++ = index2letter(trio & 0x3F);
	}

	i -= 2;
	if(i != inlen)
	{
		uint32_t trio = 0;
		trio |= (uint32_t)(inbuf[i] << 16);

		if((inlen - i) == 2)
		{
			trio |= (uint32_t)(inbuf[i + 1] << 8);
		}
		*outbuf++ = index2letter((trio >> 18) & 0x3F);
		*outbuf++ = index2letter((trio >> 12) & 0x3F);
		if((inlen - i) == 2)
			*outbuf++ = index2letter((trio >> 6) & 0x3F);
		else
			*outbuf++ = '=';

		*outbuf++ = '=';
	}

	return minlen;
}

int32_t run_all_tests(uint32_t num);

int main(int argc, char **argv) {
	run_all_tests(0);
	return 0;
}
