/* 
****************************************************************
LEA-128
****************************************************************
*/

void encrypt_128(unsigned char* p, unsigned char* c);
void decrypt_128(unsigned char* c, unsigned char* p);
void KeySchedule_enc_128(unsigned char* key);
void KeySchedule_dec_128(unsigned char* key);
void round_enc_128(int i, unsigned int* x1);
void round_dec_128(int i, unsigned int* x1);

/* 
****************************************************************
LEA-192
****************************************************************
*/

void encrypt_192(unsigned char* p, unsigned char* c);
void decrypt_192(unsigned char* c, unsigned char* p);
void KeySchedule_enc_192(unsigned char* key);
void KeySchedule_dec_192(unsigned char* key);
void round_enc_192(int i, unsigned int* x1);
void round_dec_192(int i, unsigned int* x1);

/* 
****************************************************************
LEA-256
****************************************************************
*/

void encrypt_256(unsigned char* p, unsigned char* c);
void decrypt_256(unsigned char* c, unsigned char* p);
void KeySchedule_enc_256(unsigned char* key);
void KeySchedule_dec_256(unsigned char* key);
void round_enc_256(int i, unsigned int* x1);
void round_dec_256(int i, unsigned int* x1);

/* 
****************************************************************
Rotation
****************************************************************
*/
unsigned int rol_i(int i, unsigned int x);
unsigned int ror_i(int i, unsigned int x);