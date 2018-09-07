#include "LEA_ConfigMode.h"

#include <stdio.h>
#include <stdlib.h>

#include "LEA_Default.h"

#define BLOCK_LENGTH 16

void Counter(unsigned char* ctr)
{
    unsigned char* byteCtrCur;
    int k = 0;
    byteCtrCur = (unsigned char*)ctr;

    if((*(byteCtrCur+15)) != 0xff)
    {
        (*(byteCtrCur+15)) +=1;
    }
    else{
        *(byteCtrCur+15) = 0;
        for(k=1; k<16; ++k)
        {
            if(*(byteCtrCur+15-k) == 0xff)
            {
                *(byteCtrCur+15-k) = 0;
                if(k==15) (*(byteCtrCur+15)) = 0x00;
            }
            else
            {
                *(byteCtrCur+15-k) += 1;
                break;
            }
        }
    }
}

void CBC_enc_128(unsigned char* m, unsigned char* c, int mLength, unsigned char* key, unsigned char* iv)
{
    int i=0, j=0;
    int bNum = mLength/BLOCK_LENGTH;
    unsigned char* X = (unsigned char*)malloc(sizeof(unsigned char*)*BLOCK_LENGTH);
    unsigned char* Y = (unsigned char*)malloc(sizeof(unsigned char*)*BLOCK_LENGTH);
    unsigned char* C0 = (unsigned char*)malloc(sizeof(unsigned char*)*BLOCK_LENGTH);

    printf(" ##############################  CBC Encrypt ##################################\n\n");

    for(i=0; i<BLOCK_LENGTH; ++i)
    {
        C0[i] = iv[i];
    }

    for(i=0; i<bNum; ++i)
    {
        printf(" ===============================  BLOCK %d ===============================\n", i);
        printf("Plaintext P%d \t = ", i);
        for(j=0; j<BLOCK_LENGTH; ++j)
        {
            printf( "%2x", m[j+(16*i)]);
        }
        printf("\n");
        printf(" Input I%d \t = ", i);
        for(j=0; j<BLOCK_LENGTH; ++j)
        {
            if(i==0)
            {
                X[j] = m[j+(16*i)] ^ C0[j];
                printf(" %2x", X[j]);
            }else
            {
                X[j] = m[j+(16*i)] ^ c[j+(16*(i-1))];
                printf(" %2x", X[j]);
            }
        }
        printf("\n");
        KeySchedule_enc_128(key);
        encrypt_128(X,Y);
        printf(" Output O%d \t = ", i);
        for(j=0; j<BLOCK_LENGTH; ++j)
        {
            printf(" %2x", Y[j]);
        }
        printf("\n");

        printf(" Ciphertext C%d \t = ", i);
        for(j=0; j<BLOCK_LENGTH; ++j)
        {
            c[j+ (16 * i)] = Y[j];
            printf(" %2x", c[j+(16*i)]);
        }
        printf("\n\n\n");
    }
}

void CBC_dec_128(unsigned char* m, unsigned char* p, int mLength, unsigned char* key, unsigned char* iv)
{
    int i=0, j=0;
    int bNum = mLength/BLOCK_LENGTH;
    unsigned char* X = (unsigned char*)malloc(sizeof(unsigned char)*BLOCK_LENGTH);
    unsigned char* Y = (unsigned char*)malloc(sizeof(unsigned char)*BLOCK_LENGTH);
    unsigned char* C0 = (unsigned char*)malloc(sizeof(unsigned char)*BLOCK_LENGTH);

    printf(" ##############################  CBC Decrypt ##################################\n\n");
    for(i=0; i<BLOCK_LENGTH; ++i)
    {
        C0[i] = iv[i];
    }
    for(i=0; i<bNum; ++i)
    {
        printf(" ===============================  BLOCK %d ===============================\n", i);
		printf(" Ciphertext C%d \t = ",i);
        for(j=0; j<BLOCK_LENGTH;++j)
        {
            printf(" %2x", m[j+(16*i)]);
        }
        printf("\n");
        printf(" Input I%d \t = ", i);
        for(j=0; j<BLOCK_LENGTH; ++j)
        {
            X[j] = m[j+(16*i)];
            printf(" %2x", X[j]);
        }
        printf("\n");

		KeySchedule_dec_128(key);
		decrypt_128(X,Y);
		printf(" Output O%d \t = ",i);
		for(j=0; j<BLOCK_LENGTH; ++j)
		{
			printf(" %2x",Y[j]);
		}
		printf("\n");
        printf(" Plaintext C%d \t = ", i);
        for(j=0; j<BLOCK_LENGTH; ++j)
        {
            if(i==0)
            {
                p[j+(16*i)] = Y[j] ^ C0[j];
                printf(" %2x", p[j+(16*i)]);
            }
            else
            {
                p[j+(16*i)] = Y[j] ^ m[j+(16*(i-1))];
                printf(" %2x", p[j+(16*i)]);
            }
        }
        printf("\n\n\n");
    }
}

void CBC_enc_192(unsigned char* m, unsigned char* c, int mLength, unsigned char* key, unsigned char* iv)
{
    int i=0, j=0;
    int bNum = mLength/BLOCK_LENGTH;
    unsigned char* X = (unsigned char*)malloc(sizeof(unsigned char*)*BLOCK_LENGTH);
    unsigned char* Y = (unsigned char*)malloc(sizeof(unsigned char*)*BLOCK_LENGTH);
    unsigned char* C0 = (unsigned char*)malloc(sizeof(unsigned char*)*BLOCK_LENGTH);

    printf(" ##############################  CBC Encrypt ##################################\n\n");

    for(i=0; i<BLOCK_LENGTH; ++i)
    {
        C0[i] = iv[i];
    }

    for(i=0; i<bNum; ++i)
    {
        printf(" ===============================  BLOCK %d ===============================\n", i);
        printf("Plaintext P%d \t = ", i);
        for(j=0; j<BLOCK_LENGTH; ++j)
        {
            printf( "%2x", m[j+(16*i)]);
        }
        printf("\n");
        printf(" Input I%d \t = ", i);
        for(j=0; j<BLOCK_LENGTH; ++j)
        {
            if(i==0)
            {
                X[j] = m[j+(16*i)] ^ C0[j];
                printf(" %2x", X[j]);
            }else
            {
                X[j] = m[j+(16*i)] ^ c[j+(16*(i-1))];
                printf(" %2x", X[j]);
            }
        }
        printf("\n");
        KeySchedule_enc_192(key);
        encrypt_192(X,Y);
        printf(" Output O%d \t = ", i);
        for(j=0; j<BLOCK_LENGTH; ++j)
        {
            printf(" %2x", Y[j]);
        }
        printf("\n");

        printf(" Ciphertext C%d \t = ", i);
        for(j=0; j<BLOCK_LENGTH; ++j)
        {
            c[j+ (16 * i)] = Y[j];
            printf(" %2x", c[j+(16*i)]);
        }
        printf("\n\n\n");
    }
}
void CBC_dec_192(unsigned char* m, unsigned char* p, int mLength, unsigned char* key, unsigned char* iv)
{
    int i=0, j=0;
    int bNum = mLength/BLOCK_LENGTH;
    unsigned char* X = (unsigned char*)malloc(sizeof(unsigned char)*BLOCK_LENGTH);
    unsigned char* Y = (unsigned char*)malloc(sizeof(unsigned char)*BLOCK_LENGTH);
    unsigned char* C0 = (unsigned char*)malloc(sizeof(unsigned char)*BLOCK_LENGTH);

    printf(" ##############################  CBC Decrypt ##################################\n\n");
    for(i=0; i<BLOCK_LENGTH; ++i)
    {
        C0[i] = iv[i];
    }
    for(i=0; i<bNum; ++i)
    {
        printf(" ===============================  BLOCK %d ===============================\n", i);
		printf(" Ciphertext C%d \t = ",i);
        for(j=0; j<BLOCK_LENGTH;++j)
        {
            printf(" %2x", m[j+(16*i)]);
        }
        printf("\n");
        printf(" Input I%d \t = ", i);
        for(j=0; j<BLOCK_LENGTH; ++j)
        {
            X[j] = m[j+(16*i)];
            printf(" %2x", X[j]);
        }
        printf("\n");

		KeySchedule_dec_192(key);
		decrypt_192(X,Y);
		printf(" Output O%d \t = ",i);
		for(j=0; j<BLOCK_LENGTH; ++j)
		{
			printf(" %2x",Y[j]);
		}
		printf("\n");
        printf(" Plaintext C%d \t = ", i);
        for(j=0; j<BLOCK_LENGTH; ++j)
        {
            if(i==0)
            {
                p[j+(16*i)] = Y[j] ^ C0[j];
                printf(" %2x", p[j+(16*i)]);
            }
            else
            {
                p[j+(16*i)] = Y[j] ^ m[j+(16*(i-1))];
                printf(" %2x", p[j+(16*i)]);
            }
        }
        printf("\n\n\n");
    }
}

void CBC_enc_256(unsigned char* m, unsigned char* c, int mLength, unsigned char* key, unsigned char* iv)
{
    int i=0, j=0;
    int bNum = mLength/BLOCK_LENGTH;
    unsigned char* X = (unsigned char*)malloc(sizeof(unsigned char*)*BLOCK_LENGTH);
    unsigned char* Y = (unsigned char*)malloc(sizeof(unsigned char*)*BLOCK_LENGTH);
    unsigned char* C0 = (unsigned char*)malloc(sizeof(unsigned char*)*BLOCK_LENGTH);

    printf(" ##############################  CBC Encrypt ##################################\n\n");

    for(i=0; i<BLOCK_LENGTH; ++i)
    {
        C0[i] = iv[i];
    }

    for(i=0; i<bNum; ++i)
    {
        printf(" ===============================  BLOCK %d ===============================\n", i);
        printf("Plaintext P%d \t = ", i);
        for(j=0; j<BLOCK_LENGTH; ++j)
        {
            printf( "%2x", m[j+(16*i)]);
        }
        printf("\n");
        printf(" Input I%d \t = ", i);
        for(j=0; j<BLOCK_LENGTH; ++j)
        {
            if(i==0)
            {
                X[j] = m[j+(16*i)] ^ C0[j];
                printf(" %2x", X[j]);
            }else
            {
                X[j] = m[j+(16*i)] ^ c[j+(16*(i-1))];
                printf(" %2x", X[j]);
            }
        }
        printf("\n");
        KeySchedule_enc_256(key);
        encrypt_256(X,Y);
        printf(" Output O%d \t = ", i);
        for(j=0; j<BLOCK_LENGTH; ++j)
        {
            printf(" %2x", Y[j]);
        }
        printf("\n");

        printf(" Ciphertext C%d \t = ", i);
        for(j=0; j<BLOCK_LENGTH; ++j)
        {
            c[j+ (16 * i)] = Y[j];
            printf(" %2x", c[j+(16*i)]);
        }
        printf("\n\n\n");
    }
}

void CBC_dec_256(unsigned char* m, unsigned char* p, int mLength, unsigned char* key, unsigned char* iv)
{
    int i=0, j=0;
    int bNum = mLength/BLOCK_LENGTH;
    unsigned char* X = (unsigned char*)malloc(sizeof(unsigned char)*BLOCK_LENGTH);
    unsigned char* Y = (unsigned char*)malloc(sizeof(unsigned char)*BLOCK_LENGTH);
    unsigned char* C0 = (unsigned char*)malloc(sizeof(unsigned char)*BLOCK_LENGTH);

    printf(" ##############################  CBC Decrypt ##################################\n\n");
    for(i=0; i<BLOCK_LENGTH; ++i)
    {
        C0[i] = iv[i];
    }
    for(i=0; i<bNum; ++i)
    {
        printf(" ===============================  BLOCK %d ===============================\n", i);
		printf(" Ciphertext C%d \t = ",i);
        for(j=0; j<BLOCK_LENGTH;++j)
        {
            printf(" %2x", m[j+(16*i)]);
        }
        printf("\n");
        printf(" Input I%d \t = ", i);
        for(j=0; j<BLOCK_LENGTH; ++j)
        {
            X[j] = m[j+(16*i)];
            printf(" %2x", X[j]);
        }
        printf("\n");

		KeySchedule_dec_256(key);
		decrypt_256(X,Y);
		printf(" Output O%d \t = ",i);
		for(j=0; j<BLOCK_LENGTH; ++j)
		{
			printf(" %2x",Y[j]);
		}
		printf("\n");
        printf(" Plaintext C%d \t = ", i);
        for(j=0; j<BLOCK_LENGTH; ++j)
        {
            if(i==0)
            {
                p[j+(16*i)] = Y[j] ^ C0[j];
                printf(" %2x", p[j+(16*i)]);
            }
            else
            {
                p[j+(16*i)] = Y[j] ^ m[j+(16*(i-1))];
                printf(" %2x", p[j+(16*i)]);
            }
        }
        printf("\n\n\n");
    }
}

void CTR_enc_128(unsigned char* m, unsigned char* c, int mLength, unsigned char* key, unsigned char* init_ctr)
{
	unsigned char X[BLOCK_LENGTH];
	unsigned char Y[BLOCK_LENGTH];
	int i,j;
	int bNum = mLength/BLOCK_LENGTH;

	unsigned char CTR_Cur[BLOCK_LENGTH]; // 8bit * 16 
	unsigned int* wordCtrCur;
	wordCtrCur = (unsigned int*)CTR_Cur;
	
	printf(" ##############################  CTR Encrypt ##################################\n\n"); 
	KeySchedule_enc_128(key);

	for(i=0; i<BLOCK_LENGTH; ++i)
	{
		CTR_Cur[i] = init_ctr[i];
//		printf("%x ",CTR_Cur[i]);
	}

	for(i=0; i< bNum-1; ++i)
	{
		printf(" Plaintext P%d \t = ",i);
		for(j=0; j<BLOCK_LENGTH; ++j)
		{
			printf(" %2x",m[j+(16*i)]);
		}
		printf("\n");
		printf(" Input I%d \t = ",i);
		for(j=0; j<BLOCK_LENGTH; ++j)
		{
			printf(" %2x",CTR_Cur[j]);
		}
		printf("\n");
		
		encrypt_128(CTR_Cur,Y);
		printf(" Output O%d \t = ",i);
		for(j=0; j<BLOCK_LENGTH; ++j)
		{
			printf(" %2x",Y[j]);
		}
		printf("\n");

		for(j=0; j< BLOCK_LENGTH; ++j)
		{
			c[j+(16*i)] = m[j+(16*i)] ^ Y[j];
		}
		printf(" Ciphertext C%d \t = ",i);
		for(j=0; j<BLOCK_LENGTH; ++j)
		{
			printf(" %2x",c[j+(16*i)]);
		}
		printf("\n");

		Counter(CTR_Cur);
//		printf("\n%x %x %x %x\n",(*(wordCtrCur)),(*(wordCtrCur+1)),(*(wordCtrCur+2)),(*(wordCtrCur+3)));
	}
	printf(" Plaintext P%d \t = ",i);
	for(j=0; j<BLOCK_LENGTH; ++j)
	{
		printf(" %2x",m[j+(16*i)]);
	}
	printf("\n");
	printf(" Input I%d \t = ",i);
	for(j=0; j<BLOCK_LENGTH; ++j)
	{
		printf(" %2x",CTR_Cur[j]);
	}
	printf("\n");

	encrypt_128(CTR_Cur,Y);
	
	printf(" Output O%d \t = ",i);
	for(j=0; j<BLOCK_LENGTH; ++j)
	{
		printf(" %2x",Y[j]);
	}
	printf("\n");

	printf(" Ciphertext C%d \t = ",i);

	for(j=0; j< BLOCK_LENGTH; ++j)
	{
		c[j+(16*i)] = m[j+(16*i)] ^ Y[j];
		printf(" %2x",c[j+(16*i)]);
	}
	printf("\n");
}

void CTR_dec_128(unsigned char* m, unsigned char* p, int mLength, unsigned char* key, unsigned char* init_ctr)
{
	unsigned char X[BLOCK_LENGTH];
	unsigned char Y[BLOCK_LENGTH];
	int i,j;
	int bNum = mLength/BLOCK_LENGTH;

	unsigned char CTR_Cur[BLOCK_LENGTH]; // 8bit * 16 
	unsigned int* wordCtrCur;
	wordCtrCur = (unsigned int*)CTR_Cur;
	
	printf(" ##############################  CTR Decrypt ##################################\n\n"); 

	KeySchedule_enc_128(key);


	for(i=0; i<BLOCK_LENGTH; ++i)
	{
		CTR_Cur[i] = init_ctr[i];
//		printf("%x ",CTR_Cur[i]);
	}
	
	for(i=0; i< bNum-1; ++i)
	{
		printf(" Ciphertext C%d \t = ",i);
		for(j=0; j<BLOCK_LENGTH; ++j)
		{
			printf(" %2x",m[j+(16*i)]);
			
		}
		printf("\n");
		printf(" Input I%d \t = ",i);
		for(j=0; j<BLOCK_LENGTH; ++j)
		{
			printf(" %2x",CTR_Cur[j]);
		}
		printf("\n");

		encrypt_128(CTR_Cur,Y);
		printf(" Output O%d \t = ",i);
		for(j=0; j<BLOCK_LENGTH; ++j)
		{
			printf(" %2x",Y[j]);
		}
		printf("\n");

		for(j=0; j< BLOCK_LENGTH; ++j)
		{
			p[j+(16*i)] = m[j+(16*i)] ^ Y[j];
		}
		printf(" Plaintext C%d \t = ",i);
		for(j=0; j<BLOCK_LENGTH; ++j)
		{
			printf(" %2x",p[j+(16*i)]);
		}
		printf("\n");

		Counter(CTR_Cur);
	}

	printf(" Ciphertext P%d \t = ",i);
	for(j=0; j<BLOCK_LENGTH; ++j)
	{
		printf(" %2x",m[j+(16*i)]);
	}
	printf("\n");
	printf(" Input I%d \t = ",i);
	for(j=0; j<BLOCK_LENGTH; ++j)
	{
		printf(" %2x",CTR_Cur[j]);
	}
	printf("\n");

	encrypt_128(CTR_Cur,Y);
	
	printf(" Output O%d \t = ",i);
	for(j=0; j<BLOCK_LENGTH; ++j)
	{
		printf(" %2x",Y[j]);
	}
	printf("\n");

	printf(" Plaintext C%d \t = ",i);

	for(j=0; j< BLOCK_LENGTH; ++j)
	{
		p[j+(16*i)] = m[j+(16*i)] ^ Y[j];
		printf(" %2x",p[j+(16*i)]);
	}
	printf("\n");
}

void CTR_enc_192(unsigned char* m, unsigned char* c, int mLength, unsigned char* key, unsigned char* init_ctr)
{
	unsigned char X[BLOCK_LENGTH];
	unsigned char Y[BLOCK_LENGTH];
	int i,j;
	int bNum = mLength/BLOCK_LENGTH;

	unsigned char CTR_Cur[BLOCK_LENGTH]; // 8bit * 16 
	unsigned int* wordCtrCur;
	wordCtrCur = (unsigned int*)CTR_Cur;
	
	printf(" ##############################  CTR Encrypt ##################################\n\n"); 
	KeySchedule_enc_192(key);

	for(i=0; i<BLOCK_LENGTH; ++i)
	{
		CTR_Cur[i] = init_ctr[i];
//		printf("%x ",CTR_Cur[i]);
	}

	for(i=0; i< bNum-1; ++i)
	{
		printf(" Plaintext P%d \t = ",i);
		for(j=0; j<BLOCK_LENGTH; ++j)
		{
			printf(" %2x",m[j+(16*i)]);
		}
		printf("\n");
		printf(" Input I%d \t = ",i);
		for(j=0; j<BLOCK_LENGTH; ++j)
		{
			printf(" %2x",CTR_Cur[j]);
		}
		printf("\n");
		
		encrypt_192(CTR_Cur,Y);
		printf(" Output O%d \t = ",i);
		for(j=0; j<BLOCK_LENGTH; ++j)
		{
			printf(" %2x",Y[j]);
		}
		printf("\n");

		for(j=0; j< BLOCK_LENGTH; ++j)
		{
			c[j+(16*i)] = m[j+(16*i)] ^ Y[j];
		}
		printf(" Ciphertext C%d \t = ",i);
		for(j=0; j<BLOCK_LENGTH; ++j)
		{
			printf(" %2x",c[j+(16*i)]);
		}
		printf("\n");

		Counter(CTR_Cur);
//		printf("\n%x %x %x %x\n",(*(wordCtrCur)),(*(wordCtrCur+1)),(*(wordCtrCur+2)),(*(wordCtrCur+3)));
	}
	printf(" Plaintext P%d \t = ",i);
	for(j=0; j<BLOCK_LENGTH; ++j)
	{
		printf(" %2x",m[j+(16*i)]);
	}
	printf("\n");
	printf(" Input I%d \t = ",i);
	for(j=0; j<BLOCK_LENGTH; ++j)
	{
		printf(" %2x",CTR_Cur[j]);
	}
	printf("\n");

	encrypt_192(CTR_Cur,Y);
	
	printf(" Output O%d \t = ",i);
	for(j=0; j<BLOCK_LENGTH; ++j)
	{
		printf(" %2x",Y[j]);
	}
	printf("\n");

	printf(" Ciphertext C%d \t = ",i);

	for(j=0; j< BLOCK_LENGTH; ++j)
	{
		c[j+(16*i)] = m[j+(16*i)] ^ Y[j];
		printf(" %2x",c[j+(16*i)]);
	}
	printf("\n");
}

void CTR_dec_192(unsigned char* m, unsigned char* p, int mLength, unsigned char* key, unsigned char* init_ctr)
{
	unsigned char X[BLOCK_LENGTH];
	unsigned char Y[BLOCK_LENGTH];
	int i,j;
	int bNum = mLength/BLOCK_LENGTH;

	unsigned char CTR_Cur[BLOCK_LENGTH]; // 8bit * 16 
	unsigned int* wordCtrCur;
	wordCtrCur = (unsigned int*)CTR_Cur;
	
	printf(" ##############################  CTR Decrypt ##################################\n\n"); 

	KeySchedule_enc_192(key);


	for(i=0; i<BLOCK_LENGTH; ++i)
	{
		CTR_Cur[i] = init_ctr[i];
//		printf("%x ",CTR_Cur[i]);
	}
	
	for(i=0; i< bNum-1; ++i)
	{
		printf(" Ciphertext C%d \t = ",i);
		for(j=0; j<BLOCK_LENGTH; ++j)
		{
			printf(" %2x",m[j+(16*i)]);
			
		}
		printf("\n");
		printf(" Input I%d \t = ",i);
		for(j=0; j<BLOCK_LENGTH; ++j)
		{
			printf(" %2x",CTR_Cur[j]);
		}
		printf("\n");

		encrypt_128(CTR_Cur,Y);
		printf(" Output O%d \t = ",i);
		for(j=0; j<BLOCK_LENGTH; ++j)
		{
			printf(" %2x",Y[j]);
		}
		printf("\n");

		for(j=0; j< BLOCK_LENGTH; ++j)
		{
			p[j+(16*i)] = m[j+(16*i)] ^ Y[j];
		}
		printf(" Plaintext C%d \t = ",i);
		for(j=0; j<BLOCK_LENGTH; ++j)
		{
			printf(" %2x",p[j+(16*i)]);
		}
		printf("\n");

		Counter(CTR_Cur);
	}

	printf(" Ciphertext P%d \t = ",i);
	for(j=0; j<BLOCK_LENGTH; ++j)
	{
		printf(" %2x",m[j+(16*i)]);
	}
	printf("\n");
	printf(" Input I%d \t = ",i);
	for(j=0; j<BLOCK_LENGTH; ++j)
	{
		printf(" %2x",CTR_Cur[j]);
	}
	printf("\n");

	encrypt_192(CTR_Cur,Y);
	
	printf(" Output O%d \t = ",i);
	for(j=0; j<BLOCK_LENGTH; ++j)
	{
		printf(" %2x",Y[j]);
	}
	printf("\n");

	printf(" Plaintext C%d \t = ",i);

	for(j=0; j< BLOCK_LENGTH; ++j)
	{
		p[j+(16*i)] = m[j+(16*i)] ^ Y[j];
		printf(" %2x",p[j+(16*i)]);
	}
	printf("\n");
}

void CTR_enc_256(unsigned char* m, unsigned char* c, int mLength, unsigned char* key, unsigned char* init_ctr)
{
	unsigned char X[BLOCK_LENGTH];
	unsigned char Y[BLOCK_LENGTH];
	int i,j;
	int bNum = mLength/BLOCK_LENGTH;

	unsigned char CTR_Cur[BLOCK_LENGTH]; // 8bit * 16 
	unsigned int* wordCtrCur;
	wordCtrCur = (unsigned int*)CTR_Cur;
	
	printf(" ##############################  CTR Encrypt ##################################\n\n"); 
	KeySchedule_enc_256(key);

	for(i=0; i<BLOCK_LENGTH; ++i)
	{
		CTR_Cur[i] = init_ctr[i];
//		printf("%x ",CTR_Cur[i]);
	}

	for(i=0; i< bNum-1; ++i)
	{
		printf(" Plaintext P%d \t = ",i);
		for(j=0; j<BLOCK_LENGTH; ++j)
		{
			printf(" %2x",m[j+(16*i)]);
		}
		printf("\n");
		printf(" Input I%d \t = ",i);
		for(j=0; j<BLOCK_LENGTH; ++j)
		{
			printf(" %2x",CTR_Cur[j]);
		}
		printf("\n");
		
		encrypt_256(CTR_Cur,Y);
		printf(" Output O%d \t = ",i);
		for(j=0; j<BLOCK_LENGTH; ++j)
		{
			printf(" %2x",Y[j]);
		}
		printf("\n");

		for(j=0; j< BLOCK_LENGTH; ++j)
		{
			c[j+(16*i)] = m[j+(16*i)] ^ Y[j];
		}
		printf(" Ciphertext C%d \t = ",i);
		for(j=0; j<BLOCK_LENGTH; ++j)
		{
			printf(" %2x",c[j+(16*i)]);
		}
		printf("\n");

		Counter(CTR_Cur);
//		printf("\n%x %x %x %x\n",(*(wordCtrCur)),(*(wordCtrCur+1)),(*(wordCtrCur+2)),(*(wordCtrCur+3)));
	}
	printf(" Plaintext P%d \t = ",i);
	for(j=0; j<BLOCK_LENGTH; ++j)
	{
		printf(" %2x",m[j+(16*i)]);
	}
	printf("\n");
	printf(" Input I%d \t = ",i);
	for(j=0; j<BLOCK_LENGTH; ++j)
	{
		printf(" %2x",CTR_Cur[j]);
	}
	printf("\n");

	encrypt_256(CTR_Cur,Y);
	
	printf(" Output O%d \t = ",i);
	for(j=0; j<BLOCK_LENGTH; ++j)
	{
		printf(" %2x",Y[j]);
	}
	printf("\n");

	printf(" Ciphertext C%d \t = ",i);

	for(j=0; j< BLOCK_LENGTH; ++j)
	{
		c[j+(16*i)] = m[j+(16*i)] ^ Y[j];
		printf(" %2x",c[j+(16*i)]);
	}
	printf("\n");
}

void CTR_dec_256(unsigned char* m, unsigned char* p, int mLength, unsigned char* key, unsigned char* init_ctr)
{
	unsigned char X[BLOCK_LENGTH];
	unsigned char Y[BLOCK_LENGTH];
	int i,j;
	int bNum = mLength/BLOCK_LENGTH;

	unsigned char CTR_Cur[BLOCK_LENGTH]; // 8bit * 16 
	unsigned int* wordCtrCur;
	wordCtrCur = (unsigned int*)CTR_Cur;
	
	printf(" ##############################  CTR Decrypt ##################################\n\n"); 

	KeySchedule_enc_256(key);


	for(i=0; i<BLOCK_LENGTH; ++i)
	{
		CTR_Cur[i] = init_ctr[i];
//		printf("%x ",CTR_Cur[i]);
	}
	
	for(i=0; i< bNum-1; ++i)
	{
		printf(" Ciphertext C%d \t = ",i);
		for(j=0; j<BLOCK_LENGTH; ++j)
		{
			printf(" %2x",m[j+(16*i)]);
			
		}
		printf("\n");
		printf(" Input I%d \t = ",i);
		for(j=0; j<BLOCK_LENGTH; ++j)
		{
			printf(" %2x",CTR_Cur[j]);
		}
		printf("\n");

		encrypt_256(CTR_Cur,Y);
		printf(" Output O%d \t = ",i);
		for(j=0; j<BLOCK_LENGTH; ++j)
		{
			printf(" %2x",Y[j]);
		}
		printf("\n");

		for(j=0; j< BLOCK_LENGTH; ++j)
		{
			p[j+(16*i)] = m[j+(16*i)] ^ Y[j];
		}
		printf(" Plaintext C%d \t = ",i);
		for(j=0; j<BLOCK_LENGTH; ++j)
		{
			printf(" %2x",p[j+(16*i)]);
		}
		printf("\n");

		Counter(CTR_Cur);
	}

	printf(" Ciphertext P%d \t = ",i);
	for(j=0; j<BLOCK_LENGTH; ++j)
	{
		printf(" %2x",m[j+(16*i)]);
	}
	printf("\n");
	printf(" Input I%d \t = ",i);
	for(j=0; j<BLOCK_LENGTH; ++j)
	{
		printf(" %2x",CTR_Cur[j]);
	}
	printf("\n");

	encrypt_256(CTR_Cur,Y);
	
	printf(" Output O%d \t = ",i);
	for(j=0; j<BLOCK_LENGTH; ++j)
	{
		printf(" %2x",Y[j]);
	}
	printf("\n");

	printf(" Plaintext C%d \t = ",i);

	for(j=0; j< BLOCK_LENGTH; ++j)
	{
		p[j+(16*i)] = m[j+(16*i)] ^ Y[j];
		printf(" %2x",p[j+(16*i)]);
	}
	printf("\n");
}