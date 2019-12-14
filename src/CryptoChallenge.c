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

uint8_t *hex2base64(uint8_t *inbuf, size_t inlen, uint8_t *outbuf, size_t outlen)
{
	for(int i = 0; i < inlen; i = i + 3)
	{
		uint32_t trio = (inbuf[i] << 16) | (inbuf[i + 1] << 8) | inbuf[i+2];
		*outbuf++ = index2letter((trio >> 18) & 0x3F);
		*outbuf++ = index2letter((trio >> 12) & 0x3F);
		*outbuf++ = index2letter((trio >> 6) & 0x3F);
		*outbuf++ = index2letter(trio & 0x3F);
	}

	return outbuf;
}

int main(int argc, char **argv) {
	uint8_t buf[] = {0x49, 0x27, 0x6d, 0x20, 0x6b, 0x69, 0x6c, 0x6c, 0x69, 0x6e, 0x67, 0x20, 0x79, 0x6f,
					 0x75, 0x72, 0x20, 0x62, 0x72, 0x61, 0x69, 0x6e, 0x20, 0x6c, 0x69, 0x6b, 0x65, 0x20,
					 0x61, 0x20, 0x70, 0x6f, 0x69, 0x73, 0x6f, 0x6e, 0x6f, 0x75, 0x73, 0x20, 0x6d, 0x75,
					 0x73, 0x68, 0x72, 0x6f, 0x6f, 0x6d};

	printf("in len = %ld\n", sizeof(buf));
	for(int i = 0; i < sizeof(buf); i++)
		printf("%x ", buf[i]);

	printf("\n");

	uint8_t base64buf[70];
	hex2base64(buf, sizeof(buf), base64buf, sizeof(base64buf));

	printf("out len = %ld\n", sizeof(base64buf));
	for(int i = 0; i < sizeof(base64buf); i++)
		printf("%c ", base64buf[i]);

	printf("\n");
	return 0;
}
