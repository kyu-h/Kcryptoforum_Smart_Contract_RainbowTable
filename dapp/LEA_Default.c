#include "LEA_Default.h"

#include <stdio.h>
#include <stdlib.h>

unsigned int delta[8] = {0xc3efe9db,0x44626b02,0x79e27c8a,0x78df30ec,0x715ea49e,0xc785da0a,0xe04ef22a,0xe5c40957}; 

unsigned int T[8];

unsigned int rk_enc[32][6];

unsigned int rk_dec[32][6];

void encrypt_128(unsigned char* p, unsigned char* c)
{
    int i=0;
    unsigned int Xi[4];

    for(i=0; i<4; ++i)
    {
        Xi[i] = p[4 * i + 3];
        Xi[i] = Xi[i] << 8 | p[4 * i + 2];
        Xi[i] = Xi[i] << 8 | p[4 * i + 1];
        Xi[i] = Xi[i] << 8 | p[4 * i];
    }   

    //printf("============================ Encrypt Round ===========================\n");

    for(i=0; i<24; ++i)
    {
        round_enc_128(i, Xi);
//		printf("X%d \t= %8x %8x %8x %8x \n",i+1,Xi[0],Xi[1],Xi[2],Xi[3]);
    }

    for(i=0; i<16; ++i)
    {
        c[i] = (Xi[i/4] >> (i * 8 % 32)) & 0x000000ff;
        //printf(" %02x", c[i]);
    }
}

void decrypt_128(unsigned char* c, unsigned char* p)
{
    int i = 0;
    unsigned int Xi[4];

    for(i=0; i<4; ++i)
    {
        Xi[i] = c[4 * i + 3];
        Xi[i] = Xi[i] << 8 | c[4 * i + 2];
        Xi[i] = Xi[i] << 8 | c[4 * i + 1];
        Xi[i] = Xi[i] << 8 | c[4 * i];
    }

    printf("============================ Decrypt Round ===========================\n");

    for(i=0; i<24; ++i)
    {
        round_dec_128(i, Xi);
//		printf("X%d \t= %8x %8x %8x %8x \n",i+1,Xi[0],Xi[1],Xi[2],Xi[3]);
    }

    for(i=0; i<16; ++i)
    {
        p[i] = (Xi[i / 4] >> (i * 8 % 32)) & 0x000000ff;
        printf(" %02x", p[i]);
    }
}

void encrypt_192(unsigned char* p, unsigned char* c)
{
    int i=0;
    unsigned int Xi[4];

    for(i=0; i<4; ++i)
    {
        Xi[i] = p[4 * i + 3];
        Xi[i] = Xi[i] << 8 | p[4 * i + 2];
        Xi[i] = Xi[i] << 8 | p[4 * i + 1];
        Xi[i] = Xi[i] << 8 | p[4 * i];
    }

    //printf("============================ Encrypt Round ===========================\n");

    for(i=0; i<28; ++i)
    {
        round_enc_192(i, Xi);
//		printf("X%d \t= %8x %8x %8x %8x \n",i+1,Xi[0],Xi[1],Xi[2],Xi[3]);
    }

    for(i=0; i<16; ++i)
    {
        c[i] = (Xi[i/4] >> (i * 8 % 32)) & 0x000000ff;
        //printf(" %02x", c[i]);
    }
}

void decrypt_192(unsigned char* c, unsigned char* p)
{
    int i = 0;
    unsigned int Xi[4];

    for(i=0; i<4; ++i)
    {
        Xi[i] = c[4 * i + 3];
        Xi[i] = Xi[i] << 8 | c[4 * i + 2];
        Xi[i] = Xi[i] << 8 | c[4 * i + 1];
        Xi[i] = Xi[i] << 8 | c[4 * i];
    }

    printf("============================ Decrypt Round ===========================\n");

    for(i=0; i<28; ++i)
    {
        round_dec_192(i, Xi);
//		printf("X%d \t= %8x %8x %8x %8x \n",i+1,Xi[0],Xi[1],Xi[2],Xi[3]);
    }

    for(i=0; i<16; ++i)
    {
        p[i] = (Xi[i/4] >> (i * 8 % 32)) & 0x000000ff;
        printf(" %02x", p[i]);
    }
}

void encrypt_256(unsigned char* p, unsigned char* c)
{
    int i = 0;
    unsigned int Xi[4];

    for(i=0; i<4; ++i)
    {
        Xi[i] = p[4 * i + 3];
        Xi[i] = Xi[i] << 8 | p[4 * i + 2];
        Xi[i] = Xi[i] << 8 | p[4 * i + 1];
        Xi[i] = Xi[i] << 8 | p[4 * i];
    }

    //printf("============================ Encrypt Round ===========================\n");

    for(i=0; i<32; ++i)
    {
        round_enc_256(i, Xi);
//		printf("X%d \t= %8x %8x %8x %8x \n",i+1,Xi[0],Xi[1],Xi[2],Xi[3]);        
    }

    for(i=0; i<16; ++i)
    {
        c[i] = (Xi[i/4] >> (i * 8 % 32)) & 0x000000ff;
        //printf(" %02x", c[i]);
    }
}

void decrypt_256(unsigned char* c, unsigned char* p)
{
    int i=0;
    unsigned int Xi[4];

    for(i=0; i<4; ++i)
    {
        Xi[i] = c[4 * i + 3];
        Xi[i] = Xi[i] << 8 | c[4 * i + 2];
        Xi[i] = Xi[i] << 8 | c[4 * i + 1];
        Xi[i] = Xi[i] << 8 | c[4 * i];
    }
    printf("============================ Decrypt Round ===========================\n");

    for(i=0; i<32; ++i)
    {
        round_dec_256(i, Xi);
//		printf("X%d \t= %8x %8x %8x %8x \n",i+1,Xi[0],Xi[1],Xi[2],Xi[3]);
    }

    for(i=0; i<16; ++i)
    {
        p[i] = (Xi[i/4] >> (i * 8 % 32)) & 0x000000ff;
        printf(" %02x", p[i]);
    }
}

void KeySchedule_enc_128(unsigned char* key)
{
    int i=0, n=0;

    n = 4; // 16/4

    for(i=0; i<n; ++i)
    {
        T[i] = key[4 * i +3];
        T[i] = T[i] << 8 | key[4 * i + 2];
        T[i] = T[i] << 8 | key[4 * i + 1];
        T[i] = T[i] << 8 | key[4 * i];
    }

    for(i=0; i<24; ++i)
    {
        T[0] = rol_i(1,     (T[0] + (rol_i(i, delta[i%4]))      %4294967296));
        T[1] = rol_i(3,     (T[1] + (rol_i(i+1, delta[i%4]))    %4294967296));
        T[2] = rol_i(6,     (T[2] + (rol_i(i+2, delta[i%4]))    %4294967296));
        T[3] = rol_i(11,    (T[3] + (rol_i(i+3, delta[i%4]))    %4294967296));

        rk_enc[i][0] = T[0];
        rk_enc[i][1] = T[1];
        rk_enc[i][2] = T[2];
        rk_enc[i][3] = T[1];
        rk_enc[i][4] = T[3];
        rk_enc[i][5] = T[1];
    }
}

void KeySchedule_dec_128(unsigned char* key)
{
    int i=0, n=0;
    for(i=0; i<24; ++i)
    {
        rk_dec[i][0] = rk_enc[24-i-1][0];
        rk_dec[i][1] = rk_enc[24-i-1][1];
        rk_dec[i][2] = rk_enc[24-i-1][2];
        rk_dec[i][3] = rk_enc[24-i-1][3];
        rk_dec[i][4] = rk_enc[24-i-1][4];
        rk_dec[i][5] = rk_enc[24-i-1][5];
    }
}

void KeySchedule_enc_192(unsigned char* key)
{
    int i=0, n=0;

    n = 6; // 24/4
    for(i=0; i<n; ++i)
    {
        T[i] = key[4 * i +3];
        T[i] = T[i] << 8 | key[4 * i + 2];
        T[i] = T[i] << 8 | key[4 * i + 1];
        T[i] = T[i] << 8 | key[4 * i];
    }

    for(i=0; i<28; ++i)
    {
		T[0] = rol_i(1,  (T[0]+ (rol_i(i,delta[i%6]))    %4294967296));
		T[1] = rol_i(3,  (T[1]+ (rol_i(i+1,delta[i%6]))  %4294967296));
		T[2] = rol_i(6,  (T[2]+ (rol_i(i+2,delta[i%6]))  %4294967296));
		T[3] = rol_i(11, (T[3]+ (rol_i(i+3,delta[i%6]))  %4294967296));
		T[4] = rol_i(13, (T[4]+ (rol_i(i+4,delta[i%6]))  %4294967296));
		T[5] = rol_i(17, (T[5]+ (rol_i(i+5,delta[i%6]))  %4294967296));

		rk_enc[i][0] = T[0]; 
		rk_enc[i][1] = T[1]; 
		rk_enc[i][2] = T[2]; 
		rk_enc[i][3] = T[3]; 
		rk_enc[i][4] = T[4]; 
		rk_enc[i][5] = T[5];         
    }
}

void KeySchedule_dec_192(unsigned char* key)
{
    int i=0, n=0;
    for(i=0; i<28; ++i)
    {
		rk_dec[i][0] = rk_enc[28-i-1][0];
		rk_dec[i][1] = rk_enc[28-i-1][1];
		rk_dec[i][2] = rk_enc[28-i-1][2];
		rk_dec[i][3] = rk_enc[28-i-1][3];
		rk_dec[i][4] = rk_enc[28-i-1][4];
		rk_dec[i][5] = rk_enc[28-i-1][5];        
    }
}

void KeySchedule_enc_256(unsigned char* key)
{
    int i=0, n=0;

    n = 8; // 32/4

    for(i=0; i<n; ++i)
    {
        T[i] = key[4 * i +3];
        T[i] = T[i] << 8 | key[4 * i + 2];
        T[i] = T[i] << 8 | key[4 * i + 1];
        T[i] = T[i] << 8 | key[4 * i];
    }

    for(i=0; i<32; ++i)
    {
		T[(6*i)%8] = rol_i(1,  (T[(6*i)%8]+ (rol_i(i,delta[i%8]))    %4294967296));
		T[(6*i+1)%8] = rol_i(3,  (T[(6*i+1)%8]+ (rol_i(i+1,delta[i%8]))  %4294967296));
		T[(6*i+2)%8] = rol_i(6,  (T[(6*i+2)%8]+ (rol_i(i+2,delta[i%8]))  %4294967296));
		T[(6*i+3)%8] = rol_i(11, (T[(6*i+3)%8]+ (rol_i(i+3,delta[i%8]))  %4294967296));
		T[(6*i+4)%8] = rol_i(13, (T[(6*i+4)%8]+ (rol_i(i+4,delta[i%8]))  %4294967296));
		T[(6*i+5)%8] = rol_i(17, (T[(6*i+5)%8]+ (rol_i(i+5,delta[i%8]))  %4294967296));

		rk_enc[i][0] = T[(6*i)%8]; 
		rk_enc[i][1] = T[(6*i+1)%8]; 
		rk_enc[i][2] = T[(6*i+2)%8]; 
		rk_enc[i][3] = T[(6*i+3)%8]; 
		rk_enc[i][4] = T[(6*i+4)%8]; 
		rk_enc[i][5] = T[(6*i+5)%8];         
    }
}

void KeySchedule_dec_256(unsigned char* key)
{
    int i = 0,n = 0;

	for(i=0; i<32; ++i)
	{
		rk_dec[i][0] = rk_enc[32-i-1][0];
		rk_dec[i][1] = rk_enc[32-i-1][1];
		rk_dec[i][2] = rk_enc[32-i-1][2];
		rk_dec[i][3] = rk_enc[32-i-1][3];
		rk_dec[i][4] = rk_enc[32-i-1][4];
		rk_dec[i][5] = rk_enc[32-i-1][5];
    }
}

void round_enc_128(int i, unsigned int* x1)
{
    unsigned int x2[4];

    x2[0] = rol_i(9, (x1[0]^rk_enc[i][0]) + ((x1[1]^rk_enc[i][1]) % 4294967296));
    x2[1] = ror_i(5, (x1[1]^rk_enc[i][2]) + ((x1[2]^rk_enc[i][3]) % 4294967296)); 
    x2[2] = ror_i(3, (x1[2]^rk_enc[i][4]) + ((x1[3]^rk_enc[i][5]) % 4294967296));
    x2[3] = x1[0];

    x1[0] = x2[0];
    x1[1] = x2[1];
    x1[2] = x2[2];
    x1[3] = x2[3];
}

void round_dec_128(int i, unsigned int* x1)
{
    unsigned int x2[4];

    x2[0] = x1[3];
    x2[1] = (ror_i(9, x1[0]) - ((x2[0]^rk_dec[i][0]) % 4294967296)) ^ rk_dec[i][1];
    x2[2] = (rol_i(5, x1[1]) - ((x2[1]^rk_dec[i][2]) % 4294967296)) ^ rk_dec[i][3];
    x2[3] = (rol_i(3, x1[2]) - ((x2[2]^rk_dec[i][4]) % 4294967296)) ^ rk_dec[i][5];

    x1[0] = x2[0];
    x1[1] = x2[1];
    x1[2] = x2[2];
    x1[3] = x2[3];
}

void round_enc_192(int i, unsigned int* x1)
{
	unsigned int x2[4];

	x2[0] = rol_i(9, (x1[0]^rk_enc[i][0]) + ((x1[1]^rk_enc[i][1]) % 4294967296));
	x2[1] = ror_i(5, (x1[1]^rk_enc[i][2]) + ((x1[2]^rk_enc[i][3]) % 4294967296));
	x2[2] = ror_i(3, (x1[2]^rk_enc[i][4]) + ((x1[3]^rk_enc[i][5]) % 4294967296));
	x2[3] = x1[0];

	x1[0] = x2[0];
	x1[1] = x2[1];
	x1[2] = x2[2];
	x1[3] = x2[3];    
}

void round_dec_192(int i, unsigned int* x1)
{
    unsigned int x2[4];

	x2[0] = x1[3];
	x2[1] = (ror_i(9,x1[0]) - ((x2[0]^rk_dec[i][0])%4294967296 )) ^ rk_dec[i][1] ; 
	x2[2] = (rol_i(5,x1[1]) - ((x2[1]^rk_dec[i][2])%4294967296 )) ^ rk_dec[i][3] ; 
	x2[3] = (rol_i(3,x1[2]) - ((x2[2]^rk_dec[i][4])%4294967296 )) ^ rk_dec[i][5] ; 
	

	x1[0] = x2[0];
	x1[1] = x2[1];
	x1[2] = x2[
        2];
	x1[3] = x2[3];
}

void round_enc_256(int i, unsigned int* x1)
{
    unsigned int x2[4];

	x2[0] = rol_i(9, (x1[0]^rk_enc[i][0]) + ((x1[1]^rk_enc[i][1]) % 4294967296));
	x2[1] = ror_i(5, (x1[1]^rk_enc[i][2]) + ((x1[2]^rk_enc[i][3]) % 4294967296));
	x2[2] = ror_i(3, (x1[2]^rk_enc[i][4]) + ((x1[3]^rk_enc[i][5]) % 4294967296));
	x2[3] = x1[0];

	x1[0] = x2[0];
	x1[1] = x2[1];
	x1[2] = x2[2];
	x1[3] = x2[3];
}

void round_dec_256(int i, unsigned int* x1)
{
    unsigned int x2[4];

	x2[0] = x1[3];
	x2[1] = (ror_i(9,x1[0]) - ((x2[0]^rk_dec[i][0])%4294967296 )) ^ rk_dec[i][1] ; 
	x2[2] = (rol_i(5,x1[1]) - ((x2[1]^rk_dec[i][2])%4294967296 )) ^ rk_dec[i][3] ; 
	x2[3] = (rol_i(3,x1[2]) - ((x2[2]^rk_dec[i][4])%4294967296 )) ^ rk_dec[i][5] ; 
	

	x1[0] = x2[0];
	x1[1] = x2[1];
	x1[2] = x2[2];
	x1[3] = x2[3];
}

unsigned int rol_i(int i, unsigned int x)
{
    int n = 0;

    unsigned int result = x;
    for(n=0; n < i; ++n)
    {
        result = x << 1;
        if((x & 0x80000000) == 0x80000000)
            result = result | 0x00000001;
        else
            result = result & 0xfffffffe;
        x = result;
    }
    return result;
}

unsigned int ror_i(int i, unsigned int x)
{
    int n = 0;

    unsigned int result = x;
    for(n = 0; n < i; ++n)
    {
        result = x >> 1;
        if((x & 0x00000001) == 0x00000001)
            result = result | 0x80000000;
        else
            result = result & 0x7fffffff;
        x = result;
    }
    return result;
}
