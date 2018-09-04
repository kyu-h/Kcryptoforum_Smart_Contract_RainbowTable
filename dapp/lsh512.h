/*
 * Copyright (c) 2016 NSR (National Security Research Institute)
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy 
 * of this software and associated documentation files (the "Software"), to deal 
 * in the Software without restriction, including without limitation the rights 
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
 * copies of the Software, and to permit persons to whom the Software is 
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in 
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN 
 * THE SOFTWARE.
 */

#ifndef _REF_LSH512_H_
#define _REF_LSH512_H_

#include "lsh_def.h"
#include "lsh.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * LSH512 �빐�떆 �궡遺� �긽�깭瑜� 珥덇린�솕�븳�떎.
 *
 * @param [in] ctx �빐�떆 �궡遺� �긽�깭 援ъ“泥�
 * @param [in] algtype LSH �븣怨좊━利� 紐낆꽭
 *
 * @return LSH_SUCCESS �궡遺� �긽�깭 珥덇린�솕 �꽦怨�
 * @return LSH_ERR_NULL_PTR ctx�굹 hashval�씠 NULL�씤 寃쎌슦 
 * @return LSH_ERR_INVALID_STATE �빐�떆 �궡遺� �긽�깭媛믪뿉 �삤瑜섍� �엳�뒗 寃쎌슦
 * @return LSH_ERR_INVALID_DATABITLEN �씠�쟾�뿉 �엯�젰�맂 �뜲�씠�꽣�쓽 湲몄씠媛� 8�쓽 諛곗닔媛� �븘�땶 寃쎌슦
 */
lsh_err lsh512_init(struct LSH512_Context * ctx, const lsh_type algtype);

/**
 * LSH512 �빐�떆 �궡遺� �긽�깭瑜� �뾽�뜲�씠�듃�븳�떎.
 *
 * @param [in/out] ctx �빐�떆 �궡遺� �긽�깭 援ъ“泥�
 * @param [in] data �빐�떆瑜� 怨꾩궛�븷 �뜲�씠�꽣
 * @param [in] databitlen �뜲�씠�꽣 湲몄씠 (鍮꾪듃�떒�쐞)
 *
 * @return LSH_SUCCESS �뾽�뜲�씠�듃 �꽦怨�
 * @return LSH_ERR_NULL_PTR ctx�굹 hashval�씠 NULL�씤 寃쎌슦 
 * @return LSH_ERR_INVALID_STATE �빐�떆 �궡遺� �긽�깭媛믪뿉 �삤瑜섍� �엳�뒗 寃쎌슦
 * @return LSH_ERR_INVALID_DATABITLEN �씠�쟾�뿉 �엯�젰�맂 �뜲�씠�꽣�쓽 湲몄씠媛� 8�쓽 諛곗닔媛� �븘�땶 寃쎌슦
 */
lsh_err lsh512_update(struct LSH512_Context * ctx, const lsh_u8 * data, size_t databitlen);

/**
 * LSH512 �빐�떆瑜� 怨꾩궛�븳�떎.
 *
 * @param [in] ctx �빐�떆 �궡遺� �긽�깭 援ъ“泥�
 * @param [out] hashval �빐�떆媛� ���옣�맆 踰꾪띁, alignment媛� 留욎븘�빞�븳�떎.
 *
 * @return LSH_SUCCESS �빐�떆 怨꾩궛 �꽦怨�
 * @return LSH_ERR_NULL_PTR ctx�굹 hashval�씠 NULL�씤 寃쎌슦
 * @return LSH_ERR_INVALID_STATE �빐�떆 �궡遺� �긽�깭媛믪뿉 �삤瑜섍� �엳�뒗 寃쎌슦
 */
lsh_err lsh512_final(struct LSH512_Context * ctx, lsh_u8 * hashval);

/**
 * LSH512 �빐�떆瑜� 怨꾩궛�븳�떎.
 *
 * @param [in] algtype �븣怨좊━利� 紐낆꽭
 * @param [in] data �뜲�씠�꽣
 * @param [in] databitlen �뜲�씠�꽣 湲몄씠 (鍮꾪듃�떒�쐞)
 * @param [out] hashval �빐�떆媛� ���옣�맆 踰꾪띁, alignment媛� 留욎븘�빞�븳�떎.
 *
 * @return LSH_SUCCESS �빐�떆 怨꾩궛 �꽦怨�
 */
lsh_err lsh512_digest(const lsh_type algtype, const lsh_u8 * data, size_t databitlen, lsh_u8 * hashval);

#ifdef __cplusplus
}
#endif

#endif
