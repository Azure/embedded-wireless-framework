/***********************************************************************************************************************
 * Copyright [2020-2022] Renesas Electronics Corporation and/or its affiliates.  All Rights Reserved.
 *
 * This software and documentation are supplied by Renesas Electronics America Inc. and may only be used with products
 * of Renesas Electronics Corp. and its affiliates ("Renesas").  No other uses are authorized.  Renesas products are
 * sold pursuant to Renesas terms and conditions of sale.  Purchasers are solely responsible for the selection and use
 * of Renesas products and Renesas assumes no liability.  No license, express or implied, to any intellectual property
 * right is granted by Renesas. This software is protected under all applicable laws, including copyright laws. Renesas
 * reserves the right to change or discontinue this software and/or this documentation. THE SOFTWARE AND DOCUMENTATION
 * IS DELIVERED TO YOU "AS IS," AND RENESAS MAKES NO REPRESENTATIONS OR WARRANTIES, AND TO THE FULLEST EXTENT
 * PERMISSIBLE UNDER APPLICABLE LAW, DISCLAIMS ALL WARRANTIES, WHETHER EXPLICITLY OR IMPLICITLY, INCLUDING WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT, WITH RESPECT TO THE SOFTWARE OR
 * DOCUMENTATION.  RENESAS SHALL HAVE NO LIABILITY ARISING OUT OF ANY SECURITY VULNERABILITY OR BREACH.  TO THE MAXIMUM
 * EXTENT PERMITTED BY LAW, IN NO EVENT WILL RENESAS BE LIABLE TO YOU IN CONNECTION WITH THE SOFTWARE OR DOCUMENTATION
 * (OR ANY PERSON OR ENTITY CLAIMING RIGHTS DERIVED FROM YOU) FOR ANY LOSS, DAMAGES, OR CLAIMS WHATSOEVER, INCLUDING,
 * WITHOUT LIMITATION, ANY DIRECT, CONSEQUENTIAL, SPECIAL, INDIRECT, PUNITIVE, OR INCIDENTAL DAMAGES; ANY LOST PROFITS,
 * OTHER ECONOMIC DAMAGE, PROPERTY DAMAGE, OR PERSONAL INJURY; AND EVEN IF RENESAS HAS BEEN ADVISED OF THE POSSIBILITY
 * OF SUCH LOSS, DAMAGES, CLAIMS OR COSTS.
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * File Name    : nx_crypto_cbc_alt_process.c
 * Description  : Functions interfacing with SCE
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

#include "rm_netx_secure_crypto_cfg.h"
#if (1U == NETX_SECURE_CRYPTO_NX_CRYPTO_METHODS_AES_ALT)
 #include "rm_netx_secure_crypto.h"
 #include "nx_crypto_aes.h"
 #include "nx_crypto_cbc.h"
 #include "hw_sce_aes_private.h"
 #include "hw_sce_private.h"

/*******************************************************************************************************************//**
 * @addtogroup RM_NETX_SECURE_CRYPTO
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * AES CBC Encryption
 * @retval NX_CRYPTO_SUCCESS              AES encryption using SCE was successful.
 * @retval NX_CRYPTO_NOT_SUCCESSFUL       AES encryption using SCE failed.
 **********************************************************************************************************************/
UINT sce_nx_crypto_cbc_encrypt (VOID          * crypto_metadata,
                                NX_CRYPTO_CBC * cbc_metadata,
                                UCHAR         * input,
                                UCHAR         * output,
                                UINT            length)
{
    NX_CRYPTO_AES * aes_ptr          = (NX_CRYPTO_AES *) crypto_metadata;
    UINT            num_rounds       = aes_ptr->nx_crypto_aes_rounds;
    UINT          * w                = aes_ptr->nx_crypto_aes_key_schedule;
    fsp_err_t       ret              = FSP_ERR_ASSERTION;
    uint32_t      * p_aligned_input  = NULL;
    uint32_t      * p_aligned_output = NULL;
    uint8_t       * p_local_input    = input;
    uint8_t       * p_local_output   = output;
    uint32_t        aligned_input_buffer[RM_NETX_SECURE_CRYPTO_BYTES_TO_WORDS(NX_CRYPTO_AES_BLOCK_SIZE)]  = {0};
    uint32_t        aligned_output_buffer[RM_NETX_SECURE_CRYPTO_BYTES_TO_WORDS(NX_CRYPTO_AES_BLOCK_SIZE)] = {0};
    uint32_t        total_length   = RM_NETX_SECURE_CRYPTO_BYTES_TO_WORDS(length);
    uint32_t        process_length = total_length;
    bool            misaligned     = false;

    /* Alignment Check */
    if (RM_NETX_SECURE_CRYPTO_NONALIGNMENT_CHECK(input) || RM_NETX_SECURE_CRYPTO_NONALIGNMENT_CHECK(output))
    {
        p_aligned_input  = aligned_input_buffer;
        p_aligned_output = aligned_output_buffer;
        process_length   = RM_NETX_SECURE_CRYPTO_BYTES_TO_WORDS(NX_CRYPTO_AES_BLOCK_SIZE);

        /* Setup the first block */
        NX_CRYPTO_MEMCPY((uint8_t *) p_aligned_input, p_local_input, NX_CRYPTO_AES_BLOCK_SIZE);
        misaligned = true;
    }
    else
    {
        p_aligned_input  = (uint32_t *) input;
        p_aligned_output = (uint32_t *) output;
    }

    /* total_length is a multiple of block size, ensured by caller */
    while (total_length != 0U)
    {
        switch (num_rounds)
        {
            case 10:
            {
                if (aes_ptr->nx_crypto_aes_key_size == (UCHAR) SCE_NX_CRYPTO_AES_KEY_SIZE_128_WRAPPED_WORDS)
                {
                    ret = HW_SCE_AES_128CbcEncryptUsingEncryptedKey((uint32_t *) w,
                                                                    (uint32_t *) cbc_metadata->nx_crypto_cbc_last_block,
                                                                    process_length,
                                                                    p_aligned_input,
                                                                    p_aligned_output,
                                                                    (uint32_t *) cbc_metadata->nx_crypto_cbc_last_block);
                }

 #if (BSP_FEATURE_CRYPTO_HAS_SCE9 == 0)
                else
                {
                    ret = HW_SCE_AES_128CbcEncrypt((uint32_t *) w,
                                                   (uint32_t *) cbc_metadata->nx_crypto_cbc_last_block,
                                                   process_length,
                                                   p_aligned_input,
                                                   p_aligned_output,
                                                   (uint32_t *) cbc_metadata->nx_crypto_cbc_last_block);
                }
 #endif
                break;
            }

 #if (BSP_FEATURE_CRYPTO_HAS_SCE9 == 1)
            case 12:
            {
                ret = HW_SCE_AES_192CbcEncryptUsingEncryptedKey((uint32_t *) w,
                                                                (uint32_t *) cbc_metadata->nx_crypto_cbc_last_block,
                                                                process_length,
                                                                p_aligned_input,
                                                                p_aligned_output,
                                                                (uint32_t *) cbc_metadata->nx_crypto_cbc_last_block);
                break;
            }
 #endif
            case 14:
            {
                if (aes_ptr->nx_crypto_aes_key_size == (UCHAR) SCE_NX_CRYPTO_AES_KEY_SIZE_256_WRAPPED_WORDS)
                {
                    ret = HW_SCE_AES_256CbcEncryptUsingEncryptedKey((uint32_t *) w,
                                                                    (uint32_t *) cbc_metadata->nx_crypto_cbc_last_block,
                                                                    process_length,
                                                                    p_aligned_input,
                                                                    p_aligned_output,
                                                                    (uint32_t *) cbc_metadata->nx_crypto_cbc_last_block);
                }

 #if (BSP_FEATURE_CRYPTO_HAS_SCE9 == 0)
                else
                {
                    ret = HW_SCE_AES_256CbcEncrypt((uint32_t *) w,
                                                   (uint32_t *) cbc_metadata->nx_crypto_cbc_last_block,
                                                   process_length,
                                                   p_aligned_input,
                                                   p_aligned_output,
                                                   (uint32_t *) cbc_metadata->nx_crypto_cbc_last_block);
                }
 #endif
                break;
            }

            default:
            {
                break;                 /* Will never get here due to the num_rounds check above. */
            }
        }

        /* Return immediately in case of error */
        FSP_ERROR_RETURN((FSP_SUCCESS == ret), NX_CRYPTO_NOT_SUCCESSFUL);
        if (misaligned)
        {
            NX_CRYPTO_MEMCPY(p_local_output, (uint8_t *) p_aligned_output, NX_CRYPTO_AES_BLOCK_SIZE);

            /* Clear out local buffers */
            NX_CRYPTO_MEMSET((uint8_t *) p_aligned_output, 0, NX_CRYPTO_AES_BLOCK_SIZE);
            NX_CRYPTO_MEMSET((uint8_t *) p_aligned_input, 0, NX_CRYPTO_AES_BLOCK_SIZE);
            total_length -= RM_NETX_SECURE_CRYPTO_BYTES_TO_WORDS(NX_CRYPTO_AES_BLOCK_SIZE);
            if (0 != total_length)
            {
                p_local_output += NX_CRYPTO_AES_BLOCK_SIZE;
                p_local_input  += NX_CRYPTO_AES_BLOCK_SIZE;

                /* Setup the next block */
                NX_CRYPTO_MEMCPY((uint8_t *) p_aligned_input, p_local_input, NX_CRYPTO_AES_BLOCK_SIZE);
            }
        }
        else
        {
            break;                     /* Buffers were aligned, all the encryption was done in a single call. */
        }
    }

    return NX_CRYPTO_SUCCESS;
}

/***********************************************************************************************************************
 * AES CBC Decryption
 * @retval NX_CRYPTO_SUCCESS              AES decryption using SCE was successful.
 * @retval NX_CRYPTO_NOT_SUCCESSFUL       AES decryption using SCE failed.
 **********************************************************************************************************************/
UINT sce_nx_crypto_cbc_decrypt (VOID          * crypto_metadata,
                                NX_CRYPTO_CBC * cbc_metadata,
                                UCHAR         * input,
                                UCHAR         * output,
                                UINT            length)
{
    NX_CRYPTO_AES * aes_ptr          = (NX_CRYPTO_AES *) crypto_metadata;
    UINT            num_rounds       = aes_ptr->nx_crypto_aes_rounds;
    UINT          * w                = aes_ptr->nx_crypto_aes_key_schedule;
    fsp_err_t       ret              = FSP_ERR_ASSERTION;
    uint32_t      * p_aligned_input  = NULL;
    uint32_t      * p_aligned_output = NULL;
    uint8_t       * p_local_input    = input;
    uint8_t       * p_local_output   = output;
    uint32_t        aligned_input_buffer[RM_NETX_SECURE_CRYPTO_BYTES_TO_WORDS(NX_CRYPTO_AES_BLOCK_SIZE)]  = {0};
    uint32_t        aligned_output_buffer[RM_NETX_SECURE_CRYPTO_BYTES_TO_WORDS(NX_CRYPTO_AES_BLOCK_SIZE)] = {0};
    uint32_t        total_length   = RM_NETX_SECURE_CRYPTO_BYTES_TO_WORDS(length);
    uint32_t        process_length = total_length;
    bool            misaligned     = false;

    /* Alignment Check */
    if (RM_NETX_SECURE_CRYPTO_NONALIGNMENT_CHECK(input) || RM_NETX_SECURE_CRYPTO_NONALIGNMENT_CHECK(output))
    {
        p_aligned_input  = aligned_input_buffer;
        p_aligned_output = aligned_output_buffer;
        process_length   = RM_NETX_SECURE_CRYPTO_BYTES_TO_WORDS(NX_CRYPTO_AES_BLOCK_SIZE);

        /* Setup the first block */
        NX_CRYPTO_MEMCPY((uint8_t *) p_aligned_input, p_local_input, NX_CRYPTO_AES_BLOCK_SIZE);
        misaligned = true;
    }
    else
    {
        p_aligned_input  = (uint32_t *) input;
        p_aligned_output = (uint32_t *) output;
    }

    /* total_length is a multiple of block size, ensured by caller */
    while (total_length != 0U)
    {
        switch (num_rounds)
        {
            case 10:
            {
                if (aes_ptr->nx_crypto_aes_key_size == (UCHAR) SCE_NX_CRYPTO_AES_KEY_SIZE_128_WRAPPED_WORDS)
                {
                    ret = HW_SCE_AES_128CbcDecryptUsingEncryptedKey((uint32_t *) w,
                                                                    (uint32_t *) cbc_metadata->nx_crypto_cbc_last_block,
                                                                    process_length,
                                                                    p_aligned_input,
                                                                    p_aligned_output,
                                                                    (uint32_t *) cbc_metadata->nx_crypto_cbc_last_block);
                }
                else
                {
                    ret = HW_SCE_AES_128CbcDecrypt((uint32_t *) w,
                                                   (uint32_t *) cbc_metadata->nx_crypto_cbc_last_block,
                                                   process_length,
                                                   p_aligned_input,
                                                   p_aligned_output,
                                                   (uint32_t *) cbc_metadata->nx_crypto_cbc_last_block);
                }

                break;
            }

 #if (BSP_FEATURE_CRYPTO_HAS_SCE9 == 1)
            case 12:
            {
                ret = HW_SCE_AES_192CbcDecryptUsingEncryptedKey((uint32_t *) w,
                                                                (uint32_t *) cbc_metadata->nx_crypto_cbc_last_block,
                                                                process_length,
                                                                p_aligned_input,
                                                                p_aligned_output,
                                                                (uint32_t *) cbc_metadata->nx_crypto_cbc_last_block);
                break;
            }
 #endif
            case 14:
            {
                if (aes_ptr->nx_crypto_aes_key_size == (UCHAR) SCE_NX_CRYPTO_AES_KEY_SIZE_128_WRAPPED_WORDS)
                {
                    ret = HW_SCE_AES_256CbcDecryptUsingEncryptedKey((uint32_t *) w,
                                                                    (uint32_t *) cbc_metadata->nx_crypto_cbc_last_block,
                                                                    process_length,
                                                                    p_aligned_input,
                                                                    p_aligned_output,
                                                                    (uint32_t *) cbc_metadata->nx_crypto_cbc_last_block);
                }
                else
                {
                    ret = HW_SCE_AES_256CbcDecrypt((uint32_t *) w,
                                                   (uint32_t *) cbc_metadata->nx_crypto_cbc_last_block,
                                                   process_length,
                                                   p_aligned_input,
                                                   p_aligned_output,
                                                   (uint32_t *) cbc_metadata->nx_crypto_cbc_last_block);
                }

                break;
            }

            default:
            {
                break;                 /* Will never get here due to the num_rounds check above. */
            }
        }

        /* Return immediately in case of error */
        FSP_ERROR_RETURN((FSP_SUCCESS == ret), NX_CRYPTO_NOT_SUCCESSFUL);
        if (misaligned)
        {
            NX_CRYPTO_MEMCPY(p_local_output, (uint8_t *) p_aligned_output, NX_CRYPTO_AES_BLOCK_SIZE);

            /* Clear out local buffers */
            NX_CRYPTO_MEMSET((uint8_t *) p_aligned_output, 0, NX_CRYPTO_AES_BLOCK_SIZE);
            NX_CRYPTO_MEMSET((uint8_t *) p_aligned_input, 0, NX_CRYPTO_AES_BLOCK_SIZE);
            total_length -= RM_NETX_SECURE_CRYPTO_BYTES_TO_WORDS(NX_CRYPTO_AES_BLOCK_SIZE);
            if (0 != total_length)
            {
                p_local_output += NX_CRYPTO_AES_BLOCK_SIZE;
                p_local_input  += NX_CRYPTO_AES_BLOCK_SIZE;

                /* Setup the next block */
                NX_CRYPTO_MEMCPY((uint8_t *) p_aligned_input, p_local_input, NX_CRYPTO_AES_BLOCK_SIZE);
            }
        }
        else
        {
            break;                     /* Buffers were aligned, all the encryption was done in a single call. */
        }
    }

    return NX_CRYPTO_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup RM_NETX_SECURE_CRYPTO)
 **********************************************************************************************************************/

#endif
