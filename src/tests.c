#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define TESTS_NUM 2
size_t hex2base64(uint8_t *inbuf, size_t inlen, uint8_t *outbuf, size_t outlen);

int32_t hex2base64_norm(void)
{
	uint8_t inbuf[] = {0x49, 0x27, 0x6d, 0x20, 0x6b, 0x69, 0x6c, 0x6c, 0x69, 0x6e, 0x67, 0x20, 0x79, 0x6f,
						 0x75, 0x72, 0x20, 0x62, 0x72, 0x61, 0x69, 0x6e, 0x20, 0x6c, 0x69, 0x6b, 0x65, 0x20,
						 0x61, 0x20, 0x70, 0x6f, 0x69, 0x73, 0x6f, 0x6e, 0x6f, 0x75, 0x73, 0x20, 0x6d, 0x75,
						 0x73, 0x68, 0x72, 0x6f, 0x6f, 0x6d};
	uint8_t outbuf[] = {'S', 'S', 'd', 't', 'I', 'G', 't', 'p', 'b', 'G', 'x', 'p', 'b', 'm', 'c', 'g', 'e',
						'W', '9', '1', 'c', 'i', 'B', 'i', 'c', 'm', 'F', 'p', 'b', 'i', 'B', 's', 'a', 'W',
						't', 'l', 'I', 'G', 'E', 'g', 'c', 'G', '9', 'p', 'c', '2', '9', 'u', 'b', '3', 'V',
						'z', 'I', 'G', '1', '1', 'c', '2', 'h', 'y', 'b', '2', '9', 't'};

	printf("in len = %ld\n", sizeof(inbuf));
	for(uint32_t i = 0; i < sizeof(inbuf); i++)
		printf("%x ", inbuf[i]);

	printf("\n");

	uint8_t base64buf[70];
	size_t ret = hex2base64(inbuf, sizeof(inbuf), base64buf, sizeof(base64buf));

	printf("out len = %ld\n", ret);
	for(uint32_t i = 0; i < ret; i++)
		printf("%c ", base64buf[i]);

	printf("\n");

	if(memcmp(base64buf, outbuf, sizeof(outbuf)) == 0)
	{
		printf("Test PASS\n");
		return 0;
	}
	else
	{
		printf("Test FAIL\n");
		return -1;
	}
}

int32_t run_test(uint32_t num)
{
	printf("\nRunning test #%d\n", num);
	switch(num)
	{
	case 1: return hex2base64_norm();
	default: return -1;
	}
}


int32_t run_all_tests(uint32_t num)
{
	if(num)
		return run_test(num);

	for(uint32_t i = 1; i < TESTS_NUM; i++)
	{
		run_test(i);
	}
	return 0;
}
