/* 
============================================================================================
CBC Mode
============================================================================================
 */

void CBC_enc_128(unsigned char* m, unsigned char* c, int mLength, unsigned char* key, unsigned char* iv);
void CBC_dec_128(unsigned char* m, unsigned char* p, int mLength, unsigned char* key, unsigned char* iv);

void CBC_enc_192(unsigned char* m, unsigned char* c, int mLength, unsigned char* key, unsigned char* iv);
void CBC_dec_192(unsigned char* m, unsigned char* p, int mLength, unsigned char* key, unsigned char* iv);

void CBC_enc_256(unsigned char* m, unsigned char* c, int mLength, unsigned char* key, unsigned char* iv);
void CBC_dec_256(unsigned char* m, unsigned char* p, int mLength, unsigned char* key, unsigned char* iv);
/* 
============================================================================================
CTR Mode
============================================================================================
 */

void CTR_enc_128(unsigned char* m, unsigned char* c, int mLength, unsigned char* key, unsigned char* init_ctr);
void CTR_dec_128(unsigned char* m, unsigned char* p, int mLength, unsigned char* key, unsigned char* init_ctr);

void CTR_enc_192(unsigned char* m, unsigned char* c, int mLength, unsigned char* key, unsigned char* init_ctr);
void CTR_dec_192(unsigned char* m, unsigned char* p, int mLength, unsigned char* key, unsigned char* init_ctr);

void CTR_enc_256(unsigned char* m, unsigned char* c, int mLength, unsigned char* key, unsigned char* init_ctr);
void CTR_dec_256(unsigned char* m, unsigned char* p, int mLength, unsigned char* key, unsigned char* init_ctr);


/* 
============================================================================================
etc....
============================================================================================
 */

void Counter(unsigned char* ctr);