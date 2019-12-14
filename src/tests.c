#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define TESTS_NUM 5
size_t hex2base64(uint8_t *inbuf, size_t inlen, uint8_t *outbuf, size_t outlen);
void fixed_length_xor(uint8_t *in, uint8_t *inout, size_t len);

int32_t hex2base64_norm(void)
{
	printf("hex2base64 normal: ");
	uint8_t inbuf[] = {0x49, 0x27, 0x6d, 0x20, 0x6b, 0x69, 0x6c, 0x6c, 0x69, 0x6e, 0x67, 0x20, 0x79, 0x6f,
						 0x75, 0x72, 0x20, 0x62, 0x72, 0x61, 0x69, 0x6e, 0x20, 0x6c, 0x69, 0x6b, 0x65, 0x20,
						 0x61, 0x20, 0x70, 0x6f, 0x69, 0x73, 0x6f, 0x6e, 0x6f, 0x75, 0x73, 0x20, 0x6d, 0x75,
						 0x73, 0x68, 0x72, 0x6f, 0x6f, 0x6d};
	uint8_t outbuf[] = {'S', 'S', 'd', 't', 'I', 'G', 't', 'p', 'b', 'G', 'x', 'p', 'b', 'm', 'c', 'g', 'e',
						'W', '9', '1', 'c', 'i', 'B', 'i', 'c', 'm', 'F', 'p', 'b', 'i', 'B', 's', 'a', 'W',
						't', 'l', 'I', 'G', 'E', 'g', 'c', 'G', '9', 'p', 'c', '2', '9', 'u', 'b', '3', 'V',
						'z', 'I', 'G', '1', '1', 'c', '2', 'h', 'y', 'b', '2', '9', 't'};

	uint8_t base64buf[70];
	size_t ret = hex2base64(inbuf, sizeof(inbuf), base64buf, sizeof(base64buf));

	if(memcmp(base64buf, outbuf, sizeof(outbuf)) == 0)
	{
		printf("Test PASS\n");
		return 0;
	}
	else
	{
		printf("in len = %ld\n", sizeof(inbuf));
		for(uint32_t i = 0; i < sizeof(inbuf); i++)
			printf("%x ", inbuf[i]);
		printf("\n");

		printf("out len = %ld\n", ret);
		for(uint32_t i = 0; i < ret; i++)
			printf("%c ", base64buf[i]);
		printf("\n");

		printf("Test FAIL\n");
		return -1;
	}
}

int32_t hex2base64_no_allign1(void)
{
	printf("hex2base64 not aligned by 1: ");
	uint8_t inbuf[] = {0x49, 0x27, 0x6d, 0x20, 0x6b, 0x69, 0x6c, 0x6c, 0x69, 0x6e, 0x67, 0x20, 0x79, 0x6f,
						 0x75, 0x72, 0x20, 0x62, 0x72, 0x61, 0x69, 0x6e, 0x20, 0x6c, 0x69, 0x6b, 0x65, 0x20,
						 0x61, 0x20, 0x70, 0x6f, 0x69, 0x73, 0x6f, 0x6e, 0x6f, 0x75, 0x73, 0x20, 0x6d, 0x75,
						 0x73, 0x68, 0x72, 0x6f, 0x6f};
	uint8_t outbuf[] = {'S', 'S', 'd', 't', 'I', 'G', 't', 'p', 'b', 'G', 'x', 'p', 'b', 'm', 'c', 'g', 'e',
						'W', '9', '1', 'c', 'i', 'B', 'i', 'c', 'm', 'F', 'p', 'b', 'i', 'B', 's', 'a', 'W',
						't', 'l', 'I', 'G', 'E', 'g', 'c', 'G', '9', 'p', 'c', '2', '9', 'u', 'b', '3', 'V',
						'z', 'I', 'G', '1', '1', 'c', '2', 'h', 'y', 'b', '2', '8', '='};

	uint8_t base64buf[70];
	size_t ret = hex2base64(inbuf, sizeof(inbuf), base64buf, sizeof(base64buf));

	if(memcmp(base64buf, outbuf, ret) == 0)
	{
		printf("Test PASS\n");
		return 0;
	}
	else
	{
		printf("in len = %ld\n", sizeof(inbuf));
		for(uint32_t i = 0; i < sizeof(inbuf); i++)
			printf("%x ", inbuf[i]);
		printf("\n");

		printf("out len = %ld\n", ret);
		for(uint32_t i = 0; i < ret; i++)
			printf("%c ", base64buf[i]);
		printf("\n");

		printf("Test FAIL\n");
		return -1;
	}
}

int32_t hex2base64_no_allign2(void)
{
	printf("hex2base64 not aligned by 2: ");
	uint8_t inbuf[] = {  0x49, 0x27, 0x6d, 0x20, 0x6b, 0x69, 0x6c, 0x6c, 0x69, 0x6e, 0x67, 0x20, 0x79, 0x6f,
						 0x75, 0x72, 0x20, 0x62, 0x72, 0x61, 0x69, 0x6e, 0x20, 0x6c, 0x69, 0x6b, 0x65, 0x20,
						 0x61, 0x20, 0x70, 0x6f, 0x69, 0x73, 0x6f, 0x6e, 0x6f, 0x75, 0x73, 0x20, 0x6d, 0x75,
						 0x73, 0x68, 0x72, 0x6f};
	uint8_t outbuf[] = {'S', 'S', 'd', 't', 'I', 'G', 't', 'p', 'b', 'G', 'x', 'p', 'b', 'm', 'c', 'g', 'e',
						'W', '9', '1', 'c', 'i', 'B', 'i', 'c', 'm', 'F', 'p', 'b', 'i', 'B', 's', 'a', 'W',
						't', 'l', 'I', 'G', 'E', 'g', 'c', 'G', '9', 'p', 'c', '2', '9', 'u', 'b', '3', 'V',
						'z', 'I', 'G', '1', '1', 'c', '2', 'h', 'y', 'b', 'w', '=', '='};

	uint8_t base64buf[70];
	size_t ret = hex2base64(inbuf, sizeof(inbuf), base64buf, sizeof(base64buf));

	if(memcmp(base64buf, outbuf, ret) == 0)
	{
		printf("Test PASS\n");
		return 0;
	}
	else
	{
		printf("in len = %ld\n", sizeof(inbuf));
		for(uint32_t i = 0; i < sizeof(inbuf); i++)
			printf("%x ", inbuf[i]);
		printf("\n");

		printf("out len = %ld\n", ret);
		for(uint32_t i = 0; i < ret; i++)
			printf("%c ", base64buf[i]);
		printf("\n");

		printf("Test FAIL\n");
		return -1;
	}
}

int32_t hex2base64_limits(void)
{
	printf("hex2base64 limits check: ");
	uint8_t testresult = 0;
	uint8_t inbuf[] = {0x49, 0x27};
	uint8_t outbuf[2][4] = {{'S', 'S', 'c', '='}, {'S', 'Q', '=', '='}};
//	uint8_t outbuf2[] = {'S', 'Q', '=', '='};
	uint8_t base64buf[4];

	for(uint8_t i = 0; i < 2; i++)
	{
		size_t ret = hex2base64(inbuf, sizeof(inbuf) - i, base64buf, sizeof(base64buf));
		if(memcmp(base64buf, outbuf[i], ret) == 0)
		{
			testresult++;
		}
		else
		{
			printf("in len = %ld\n", sizeof(inbuf));
			for(uint32_t i = 0; i < sizeof(inbuf); i++)
				printf("%x ", inbuf[i]);
			printf("\n");

			printf("out len = %ld\n", ret);
			for(uint32_t i = 0; i < ret; i++)
				printf("%c ", base64buf[i]);
			printf("\n");

			printf("Test FAIL\n");
		}
	}

	if(hex2base64(inbuf, 2, base64buf, 3) == 0)
		testresult++;
	else
		printf("Bad outlength test failed\n");

	if(hex2base64(inbuf, SIZE_MAX - 42, base64buf, 3) == 0)
		testresult++;
	else
		printf("MaxLen test failed\n");


	if(testresult == 4)
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

int32_t fixed_length_xor_test()
{
	printf("fixed length xor: ");
	uint8_t inbuf[] =  {0x1c, 0x01, 0x11, 0x00, 0x1f, 0x01, 0x01, 0x00, 0x06,
			            0x1a, 0x02, 0x4b, 0x53, 0x53, 0x50, 0x09, 0x18, 0x1c};
	uint8_t outbuf[] = {0x68, 0x69, 0x74, 0x20, 0x74, 0x68, 0x65, 0x20, 0x62,
						0x75, 0x6c, 0x6c, 0x27, 0x73, 0x20, 0x65, 0x79, 0x65};
	uint8_t refbuf[] = {0x74, 0x68, 0x65, 0x20, 0x6b, 0x69, 0x64, 0x20, 0x64,
						0x6f, 0x6e, 0x27, 0x74, 0x20, 0x70, 0x6c, 0x61, 0x79};

	fixed_length_xor(inbuf, outbuf, sizeof(inbuf));
	if(memcmp(outbuf, refbuf, sizeof(refbuf)) == 0)
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
	switch(num)
	{
	case 1: return hex2base64_norm();
	case 2: return hex2base64_no_allign1();
	case 3: return hex2base64_no_allign2();
	case 4: return hex2base64_limits();
	case 5: return fixed_length_xor_test();
	default: return -1;
	}
}


int32_t run_all_tests(uint32_t num)
{
	if(num)
		return run_test(num);

	for(uint32_t i = 1; i <= TESTS_NUM; i++)
	{
		run_test(i);
	}
	return 0;
}
