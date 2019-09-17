/*******************************************************************************
!  Copyright(C) 2005-2015 Intel Corporation. All Rights Reserved.
!
!  The source code, information and material ("Material") contained herein is
!  owned by Intel Corporation or its suppliers or licensors, and title to such
!  Material remains with Intel Corporation or its suppliers or licensors. The
!  Material contains proprietary information of Intel or its suppliers and
!  licensors. The Material is protected by worldwide copyright laws and treaty
!  provisions. No part of the Material may be used, copied, reproduced,
!  modified, published, uploaded, posted, transmitted, distributed or disclosed
!  in any way without Intel's prior express written permission. No license
!  under any patent, copyright or other intellectual property rights in the
!  Material is granted to or conferred upon you, either expressly, by
!  implication, inducement, estoppel or otherwise. Any license under such
!  intellectual property rights must be express and approved by Intel in
!  writing.
!
!  *Third Party trademarks are the property of their respective owners.
!
!  Unless otherwise agreed by Intel in writing, you may not remove or alter
!  this notice or any other notice embedded in Materials by Intel or Intel's
!  suppliers or licensors in any way.
!
!*******************************************************************************
! Content:
!  Intel(R) Math Kernel Library (MKL) interface for Sparse BLAS level 2,3 routines
!******************************************************************************/

#ifndef _MKL_SPBLAS_H_
#define _MKL_SPBLAS_H_

#include "mkl_types.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Float */
/* Sparse BLAS Level2 lower case */
void mkl_scsrmv(const char *transa, const MKL_INT *m, const MKL_INT *k, const float *alpha, const char *matdescra, const float *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const float *x, const float *beta, float *y);
void mkl_scsrsv(const char *transa, const MKL_INT *m, const float *alpha, const char *matdescra, const float *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const float *x, float *y);
void mkl_scsrgemv(const char *transa, const MKL_INT *m, const float *a, const MKL_INT *ia, const MKL_INT *ja, const float *x, float *y);
void mkl_cspblas_scsrgemv(const char *transa, const MKL_INT *m, const float *a, const MKL_INT *ia, const MKL_INT *ja, const float *x, float *y);
void mkl_scsrsymv(const char *uplo, const MKL_INT *m, const float *a, const MKL_INT *ia, const MKL_INT *ja, const float *x, float *y);
void mkl_cspblas_scsrsymv(const char *uplo, const MKL_INT *m, const float *a, const MKL_INT *ia, const MKL_INT *ja, const float *x, float *y);
void mkl_scsrtrsv(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const float *a, const MKL_INT *ia, const MKL_INT *ja, const float *x, float *y);
void mkl_cspblas_scsrtrsv(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const float *a, const MKL_INT *ia, const MKL_INT *ja, const float *x, float *y);

void mkl_scscmv(const char *transa, const MKL_INT *m, const MKL_INT *k, const float *alpha, const char *matdescra, const float *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const float *x, const float *beta, float *y);
void mkl_scscsv(const char *transa, const MKL_INT *m, const float *alpha, const char *matdescra, const float *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const float *x, float *y);

void mkl_scoomv(const char *transa, const MKL_INT *m, const MKL_INT *k, const float *alpha, const char *matdescra, const float *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const float *x, const float *beta, float *y);
void mkl_scoosv(const char *transa, const MKL_INT *m, const float *alpha, const char *matdescra, const float *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const float *x, float *y);
void mkl_scoogemv(const char *transa, const MKL_INT *m, const float *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const float *x, float *y);
void mkl_cspblas_scoogemv(const char *transa, const MKL_INT *m, const float *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const float *x, float *y);
void mkl_scoosymv(const char *uplo, const MKL_INT *m, const float *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const float *x, float *y);
void mkl_cspblas_scoosymv(const char *uplo, const MKL_INT *m, const float *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const float *x, float *y);
void mkl_scootrsv(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const float *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const float *x, float *y);
void mkl_cspblas_scootrsv(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const float *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const float *x, float *y);

void mkl_sdiamv (const char *transa, const MKL_INT *m, const MKL_INT *k, const float *alpha, const char *matdescra, const float *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const float *x, const float *beta, float *y);
void mkl_sdiasv (const char *transa, const MKL_INT *m, const float *alpha, const char *matdescra, const float *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const float *x, float *y);
void mkl_sdiagemv(const char *transa, const MKL_INT *m, const float *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const float *x, float *y);
void mkl_sdiasymv(const char *uplo, const MKL_INT *m, const float *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const float *x, float *y);
void mkl_sdiatrsv(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const float *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const float *x, float *y);

void mkl_sskymv (const char *transa, const MKL_INT *m, const MKL_INT *k, const float *alpha, const char *matdescra, const float *val, const MKL_INT *pntr, const float *x, const float *beta, float *y);
void mkl_sskysv(const char *transa, const MKL_INT *m, const float *alpha, const char *matdescra, const float *val, const MKL_INT *pntr, const float *x, float *y);

void mkl_sbsrmv (const char *transa, const MKL_INT *m, const MKL_INT *k, const MKL_INT *lb, const float *alpha, const char *matdescra, const float *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const float *x, const float *beta, float *y);
void mkl_sbsrsv(const char *transa, const MKL_INT *m, const MKL_INT *lb, const float *alpha, const char *matdescra, const float *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const float *x, float *y);
void mkl_sbsrgemv(const char *transa, const MKL_INT *m, const MKL_INT *lb, const float *a, const MKL_INT *ia, const MKL_INT *ja, const float *x, float *y);
void mkl_cspblas_sbsrgemv(const char *transa, const MKL_INT *m, const MKL_INT *lb, const float *a, const MKL_INT *ia, const MKL_INT *ja, const float *x, float *y);
void mkl_sbsrsymv(const char *uplo, const MKL_INT *m, const MKL_INT *lb, const float *a, const MKL_INT *ia, const MKL_INT *ja, const float *x, float *y);
void mkl_cspblas_sbsrsymv(const char *uplo, const MKL_INT *m, const MKL_INT *lb, const float *a, const MKL_INT *ia, const MKL_INT *ja, const float *x, float *y);
void mkl_sbsrtrsv(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_INT *lb, const float *a, const MKL_INT *ia, const MKL_INT *ja, const float *x, float *y);
void mkl_cspblas_sbsrtrsv(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_INT *lb, const float *a, const MKL_INT *ia, const MKL_INT *ja, const float *x, float *y);

/* Sparse BLAS Level3 lower case */
void mkl_scsrmm(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const float *alpha, const char *matdescra, const float *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const float *b, const MKL_INT *ldb, const float *beta, float *c, const MKL_INT *ldc);
void mkl_scsrsm(const char *transa, const MKL_INT *m, const MKL_INT *n, const float *alpha, const char *matdescra, const float *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const float *b, const MKL_INT *ldb, float *c, const MKL_INT *ldc);

void mkl_scscmm(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const float *alpha, const char *matdescra, const float *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const float *b, const MKL_INT *ldb, const float *beta, float *c, const MKL_INT *ldc);
void mkl_scscsm(const char *transa, const MKL_INT *m, const MKL_INT *n, const float *alpha, const char *matdescra, const float *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const float *b, const MKL_INT *ldb, float *c, const MKL_INT *ldc);

void mkl_scoomm(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const float *alpha, const char *matdescra, const float *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const float *b, const MKL_INT *ldb, const float *beta, float *c, const MKL_INT *ldc);
void mkl_scoosm(const char *transa, const MKL_INT *m, const MKL_INT *n, const float *alpha, const char *matdescra, const float *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const float *b, const MKL_INT *ldb, float *c, const MKL_INT *ldc);

void mkl_sdiamm (const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const float *alpha, const char *matdescra, const float *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const float *b, const MKL_INT *ldb, const float *beta, float *c, const MKL_INT *ldc);
void mkl_sdiasm (const char *transa, const MKL_INT *m, const MKL_INT *n, const float *alpha, const char *matdescra, const float *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const float *b, const MKL_INT *ldb, float *c, const MKL_INT *ldc);

void mkl_sskysm (const char *transa, const MKL_INT *m, const MKL_INT *n, const float *alpha, const char *matdescra, const float *val, const MKL_INT *pntr, const float *b, const MKL_INT *ldb, float *c, const MKL_INT *ldc);
void mkl_sskymm (const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const float *alpha, const char *matdescra, const float *val, const MKL_INT *pntr, const float *b, const MKL_INT *ldb, const float *beta, float *c, const MKL_INT *ldc);

void mkl_sbsrmm(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_INT *lb, const float *alpha, const char *matdescra, const float *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const float *b, const MKL_INT *ldb, const float *beta, float *c, const MKL_INT *ldc);
void mkl_sbsrsm(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *lb, const float *alpha, const char *matdescra, const float *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const float *b, const MKL_INT *ldb, float *c, const MKL_INT *ldc);

/* Upper case declaration */
/* Sparse BLAS Level2 upper case */
void MKL_SCSRMV (const char *transa, const MKL_INT *m, const MKL_INT *k, const float *alpha, const char *matdescra, const float *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const float *x, const float *beta, float *y);
void MKL_SCSRSV(const char *transa, const MKL_INT *m, const float *alpha, const char *matdescra, const float *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const float *x, float *y);
void MKL_SCSRGEMV(const char *transa, const MKL_INT *m, const float *a, const MKL_INT *ia, const MKL_INT *ja, const float *x, float *y);
void MKL_CSPBLAS_SCSRGEMV(const char *transa, const MKL_INT *m, const float *a, const MKL_INT *ia, const MKL_INT *ja, const float *x, float *y);
void MKL_SCSRSYMV(const char *uplo, const MKL_INT *m, const float *a, const MKL_INT *ia, const MKL_INT *ja, const float *x, float *y);
void MKL_CSPBLAS_SCSRSYMV(const char *uplo, const MKL_INT *m, const float *a, const MKL_INT *ia, const MKL_INT *ja, const float *x, float *y);
void MKL_SCSRTRSV(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const float *a, const MKL_INT *ia, const MKL_INT *ja, const float *x, float *y);
void MKL_CSPBLAS_SCSRTRSV(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const float *a, const MKL_INT *ia, const MKL_INT *ja, const float *x, float *y);

void MKL_SCSCMV(const char *transa, const MKL_INT *m, const MKL_INT *k, const float *alpha, const char *matdescra, const float *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const float *x, const float *beta, float *y);
void MKL_SCSCSV(const char *transa, const MKL_INT *m, const float *alpha, const char *matdescra, const float *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const float *x, float *y);

void MKL_SCOOMV(const char *transa, const MKL_INT *m, const MKL_INT *k, const float *alpha, const char *matdescra, const float *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const float *x, const float *beta, float *y);
void MKL_SCOOSV(const char *transa, const MKL_INT *m, const float *alpha, const char *matdescra, const float *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const float *x, float *y);
void MKL_SCOOGEMV(const char *transa, const MKL_INT *m, const float *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const float *x, float *y);
void MKL_CSPBLAS_SCOOGEMV(const char *transa, const MKL_INT *m, const float *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const float *x, float *y);
void MKL_SCOOSYMV(const char *uplo, const MKL_INT *m, const float *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const float *x, float *y);
void MKL_CSPBLAS_SCOOSYMV(const char *uplo, const MKL_INT *m, const float *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const float *x, float *y);
void MKL_SCOOTRSV(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const float *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const float *x, float *y);
void MKL_CSPBLAS_SCOOTRSV(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const float *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const float *x, float *y);

void MKL_SDIAMV (const char *transa, const MKL_INT *m, const MKL_INT *k, const float *alpha, const char *matdescra, const float *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const float *x, const float *beta, float *y);
void MKL_SDIASV (const char *transa, const MKL_INT *m, const float *alpha, const char *matdescra, const float *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const float *x, float *y);
void MKL_SDIAGEMV(const char *transa, const MKL_INT *m, const float *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const float *x, float *y);
void MKL_SDIASYMV(const char *uplo, const MKL_INT *m, const float *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const float *x, float *y);
void MKL_SDIATRSV(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const float *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const float *x, float *y);

void MKL_SSKYMV (const char *transa, const MKL_INT *m, const MKL_INT *k, const float *alpha, const char *matdescra, const float *val, const MKL_INT *pntr, const float *x, const float *beta, float *y);
void MKL_SSKYSV(const char *transa, const MKL_INT *m, const float *alpha, const char *matdescra, const float *val, const MKL_INT *pntr, const float *x, float *y);

void MKL_SBSRMV (const char *transa, const MKL_INT *m, const MKL_INT *k, const MKL_INT *lb, const float *alpha, const char *matdescra, const float *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const float *x, const float *beta, float *y);
void MKL_SBSRSV(const char *transa, const MKL_INT *m, const MKL_INT *lb, const float *alpha, const char *matdescra, const float *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const float *x, float *y);
void MKL_SBSRGEMV(const char *transa, const MKL_INT *m, const MKL_INT *lb, const float *a, const MKL_INT *ia, const MKL_INT *ja, const float *x, float *y);
void MKL_CSPBLAS_SBSRGEMV(const char *transa, const MKL_INT *m, const MKL_INT *lb, const float *a, const MKL_INT *ia, const MKL_INT *ja, const float *x, float *y);
void MKL_SBSRSYMV(const char *uplo, const MKL_INT *m, const MKL_INT *lb, const float *a, const MKL_INT *ia, const MKL_INT *ja, const float *x, float *y);
void MKL_CSPBLAS_SBSRSYMV(const char *uplo, const MKL_INT *m, const MKL_INT *lb, const float *a, const MKL_INT *ia, const MKL_INT *ja, const float *x, float *y);
void MKL_SBSRTRSV(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_INT *lb, const float *a, const MKL_INT *ia, const MKL_INT *ja, const float *x, float *y);
void MKL_CSPBLAS_SBSRTRSV(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_INT *lb, const float *a, const MKL_INT *ia, const MKL_INT *ja, const float *x, float *y);

/* Sparse BLAS Level3 upper case */
void MKL_SCSRMM(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const float *alpha, const char *matdescra, const float *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const float *b, const MKL_INT *ldb, const float *beta, float *c, const MKL_INT *ldc);
void MKL_SCSRSM(const char *transa, const MKL_INT *m, const MKL_INT *n, const float *alpha, const char *matdescra, const float *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const float *b, const MKL_INT *ldb, float *c, const MKL_INT *ldc);

void MKL_SCSCMM(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const float *alpha, const char *matdescra, const float *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const float *b, const MKL_INT *ldb, const float *beta, float *c, const MKL_INT *ldc);
void MKL_SCSCSM(const char *transa, const MKL_INT *m, const MKL_INT *n, const float *alpha, const char *matdescra, const float *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const float *b, const MKL_INT *ldb, float *c, const MKL_INT *ldc);

void MKL_SCOOMM(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const float *alpha, const char *matdescra, const float *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const float *b, const MKL_INT *ldb, const float *beta, float *c, const MKL_INT *ldc);
void MKL_SCOOSM(const char *transa, const MKL_INT *m, const MKL_INT *n, const float *alpha, const char *matdescra, const float *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const float *b, const MKL_INT *ldb, float *c, const MKL_INT *ldc);

void MKL_SDIAMM (const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const float *alpha, const char *matdescra, const float *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const float *b, const MKL_INT *ldb, const float *beta, float *c, const MKL_INT *ldc);
void MKL_SDIASM (const char *transa, const MKL_INT *m, const MKL_INT *n, const float *alpha, const char *matdescra, const float *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const float *b, const MKL_INT *ldb, float *c, const MKL_INT *ldc);

void MKL_SSKYSM (const char *transa, const MKL_INT *m, const MKL_INT *n, const float *alpha, const char *matdescra, const float *val, const MKL_INT *pntr, const float *b, const MKL_INT *ldb, float *c, const MKL_INT *ldc);
void MKL_SSKYMM (const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const float *alpha, const char *matdescra, const float *val, const MKL_INT *pntr, const float *b, const MKL_INT *ldb, const float *beta, float *c, const MKL_INT *ldc);

void MKL_SBSRMM(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_INT *lb, const float *alpha, const char *matdescra, const float *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const float *b, const MKL_INT *ldb, const float *beta, float *c, const MKL_INT *ldc);
void MKL_SBSRSM(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *lb, const float *alpha, const char *matdescra, const float *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const float *b, const MKL_INT *ldb, float *c, const MKL_INT *ldc);

/* Double */
/* Sparse BLAS Level2 lower case */
void mkl_dcsrmv(const char *transa, const MKL_INT *m, const MKL_INT *k, const double *alpha, const char *matdescra, const double *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const double *x, const double *beta, double *y);
void mkl_dcsrsv(const char *transa, const MKL_INT *m, const double *alpha, const char *matdescra, const double *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const double *x, double *y);
void mkl_dcsrgemv(const char *transa, const MKL_INT *m, const double *a, const MKL_INT *ia, const MKL_INT *ja, const double *x, double *y);
void mkl_cspblas_dcsrgemv(const char *transa, const MKL_INT *m, const double *a, const MKL_INT *ia, const MKL_INT *ja, const double *x, double *y);
void mkl_dcsrsymv(const char *uplo, const MKL_INT *m, const double *a, const MKL_INT *ia, const MKL_INT *ja, const double *x, double *y);
void mkl_cspblas_dcsrsymv(const char *uplo, const MKL_INT *m, const double *a, const MKL_INT *ia, const MKL_INT *ja, const double *x, double *y);
void mkl_dcsrtrsv(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const double *a, const MKL_INT *ia, const MKL_INT *ja, const double *x, double *y);
void mkl_cspblas_dcsrtrsv(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const double *a, const MKL_INT *ia, const MKL_INT *ja, const double *x, double *y);

void mkl_dcscmv(const char *transa, const MKL_INT *m, const MKL_INT *k, const double *alpha, const char *matdescra, const double *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const double *x, const double *beta, double *y);
void mkl_dcscsv(const char *transa, const MKL_INT *m, const double *alpha, const char *matdescra, const double *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const double *x, double *y);

void mkl_dcoomv(const char *transa, const MKL_INT *m, const MKL_INT *k, const double *alpha, const char *matdescra, const double *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const double *x, const double *beta, double *y);
void mkl_dcoosv(const char *transa, const MKL_INT *m, const double *alpha, const char *matdescra, const double *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const double *x, double *y);
void mkl_dcoogemv(const char *transa, const MKL_INT *m, const double *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const double *x, double *y);
void mkl_cspblas_dcoogemv(const char *transa, const MKL_INT *m, const double *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const double *x, double *y);
void mkl_dcoosymv(const char *uplo, const MKL_INT *m, const double *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const double *x, double *y);
void mkl_cspblas_dcoosymv(const char *uplo, const MKL_INT *m, const double *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const double *x, double *y);
void mkl_dcootrsv(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const double *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const double *x, double *y);
void mkl_cspblas_dcootrsv(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const double *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const double *x, double *y);

void mkl_ddiamv (const char *transa, const MKL_INT *m, const MKL_INT *k, const double *alpha, const char *matdescra, const double *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const double *x, const double *beta, double *y);
void mkl_ddiasv (const char *transa, const MKL_INT *m, const double *alpha, const char *matdescra, const double *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const double *x, double *y);
void mkl_ddiagemv(const char *transa, const MKL_INT *m, const double *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const double *x, double *y);
void mkl_ddiasymv(const char *uplo, const MKL_INT *m, const double *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const double *x, double *y);
void mkl_ddiatrsv(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const double *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const double *x, double *y);

void mkl_dskymv (const char *transa, const MKL_INT *m, const MKL_INT *k, const double *alpha, const char *matdescra, const double *val, const MKL_INT *pntr, const double *x, const double *beta, double *y);
void mkl_dskysv(const char *transa, const MKL_INT *m, const double *alpha, const char *matdescra, const double *val, const MKL_INT *pntr, const double *x, double *y);

void mkl_dbsrmv (const char *transa, const MKL_INT *m, const MKL_INT *k, const MKL_INT *lb, const double *alpha, const char *matdescra, const double *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const double *x, const double *beta, double *y);
void mkl_dbsrsv(const char *transa, const MKL_INT *m, const MKL_INT *lb, const double *alpha, const char *matdescra, const double *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const double *x, double *y);
void mkl_dbsrgemv(const char *transa, const MKL_INT *m, const MKL_INT *lb, const double *a, const MKL_INT *ia, const MKL_INT *ja, const double *x, double *y);
void mkl_cspblas_dbsrgemv(const char *transa, const MKL_INT *m, const MKL_INT *lb, const double *a, const MKL_INT *ia, const MKL_INT *ja, const double *x, double *y);
void mkl_dbsrsymv(const char *uplo, const MKL_INT *m, const MKL_INT *lb, const double *a, const MKL_INT *ia, const MKL_INT *ja, const double *x, double *y);
void mkl_cspblas_dbsrsymv(const char *uplo, const MKL_INT *m, const MKL_INT *lb, const double *a, const MKL_INT *ia, const MKL_INT *ja, const double *x, double *y);
void mkl_dbsrtrsv(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_INT *lb, const double *a, const MKL_INT *ia, const MKL_INT *ja, const double *x, double *y);
void mkl_cspblas_dbsrtrsv(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_INT *lb, const double *a, const MKL_INT *ia, const MKL_INT *ja, const double *x, double *y);

/* Sparse BLAS Level3 lower case */
void mkl_dcsrmm(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const double *alpha, const char *matdescra, const double *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const double *b, const MKL_INT *ldb, const double *beta, double *c, const MKL_INT *ldc);
void mkl_dcsrsm(const char *transa, const MKL_INT *m, const MKL_INT *n, const double *alpha, const char *matdescra, const double *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const double *b, const MKL_INT *ldb, double *c, const MKL_INT *ldc);

void mkl_dcscmm(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const double *alpha, const char *matdescra, const double *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const double *b, const MKL_INT *ldb, const double *beta, double *c, const MKL_INT *ldc);
void mkl_dcscsm(const char *transa, const MKL_INT *m, const MKL_INT *n, const double *alpha, const char *matdescra, const double *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const double *b, const MKL_INT *ldb, double *c, const MKL_INT *ldc);

void mkl_dcoomm(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const double *alpha, const char *matdescra, const double *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const double *b, const MKL_INT *ldb, const double *beta, double *c, const MKL_INT *ldc);
void mkl_dcoosm(const char *transa, const MKL_INT *m, const MKL_INT *n, const double *alpha, const char *matdescra, const double *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const double *b, const MKL_INT *ldb, double *c, const MKL_INT *ldc);

void mkl_ddiamm (const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const double *alpha, const char *matdescra, const double *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const double *b, const MKL_INT *ldb, const double *beta, double *c, const MKL_INT *ldc);
void mkl_ddiasm (const char *transa, const MKL_INT *m, const MKL_INT *n, const double *alpha, const char *matdescra, const double *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const double *b, const MKL_INT *ldb, double *c, const MKL_INT *ldc);

void mkl_dskysm (const char *transa, const MKL_INT *m, const MKL_INT *n, const double *alpha, const char *matdescra, const double *val, const MKL_INT *pntr, const double *b, const MKL_INT *ldb, double *c, const MKL_INT *ldc);
void mkl_dskymm (const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const double *alpha, const char *matdescra, const double *val, const MKL_INT *pntr, const double *b, const MKL_INT *ldb, const double *beta, double *c, const MKL_INT *ldc);

void mkl_dbsrmm(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_INT *lb, const double *alpha, const char *matdescra, const double *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const double *b, const MKL_INT *ldb, const double *beta, double *c, const MKL_INT *ldc);
void mkl_dbsrsm(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *lb, const double *alpha, const char *matdescra, const double *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const double *b, const MKL_INT *ldb, double *c, const MKL_INT *ldc);

/* Upper case declaration */
/* Sparse BLAS Level2 upper case */
void MKL_DCSRMV (const char *transa, const MKL_INT *m, const MKL_INT *k, const double *alpha, const char *matdescra, const double *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const double *x, const double *beta, double *y);
void MKL_DCSRSV(const char *transa, const MKL_INT *m, const double *alpha, const char *matdescra, const double *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const double *x, double *y);
void MKL_DCSRGEMV(const char *transa, const MKL_INT *m, const double *a, const MKL_INT *ia, const MKL_INT *ja, const double *x, double *y);
void MKL_CSPBLAS_DCSRGEMV(const char *transa, const MKL_INT *m, const double *a, const MKL_INT *ia, const MKL_INT *ja, const double *x, double *y);
void MKL_DCSRSYMV(const char *uplo, const MKL_INT *m, const double *a, const MKL_INT *ia, const MKL_INT *ja, const double *x, double *y);
void MKL_CSPBLAS_DCSRSYMV(const char *uplo, const MKL_INT *m, const double *a, const MKL_INT *ia, const MKL_INT *ja, const double *x, double *y);
void MKL_DCSRTRSV(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const double *a, const MKL_INT *ia, const MKL_INT *ja, const double *x, double *y);
void MKL_CSPBLAS_DCSRTRSV(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const double *a, const MKL_INT *ia, const MKL_INT *ja, const double *x, double *y);

void MKL_DCSCMV(const char *transa, const MKL_INT *m, const MKL_INT *k, const double *alpha, const char *matdescra, const double *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const double *x, const double *beta, double *y);
void MKL_DCSCSV(const char *transa, const MKL_INT *m, const double *alpha, const char *matdescra, const double *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const double *x, double *y);

void MKL_DCOOMV(const char *transa, const MKL_INT *m, const MKL_INT *k, const double *alpha, const char *matdescra, const double *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const double *x, const double *beta, double *y);
void MKL_DCOOSV(const char *transa, const MKL_INT *m, const double *alpha, const char *matdescra, const double *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const double *x, double *y);
void MKL_DCOOGEMV(const char *transa, const MKL_INT *m, const double *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const double *x, double *y);
void MKL_CSPBLAS_DCOOGEMV(const char *transa, const MKL_INT *m, const double *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const double *x, double *y);
void MKL_DCOOSYMV(const char *uplo, const MKL_INT *m, const double *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const double *x, double *y);
void MKL_CSPBLAS_DCOOSYMV(const char *uplo, const MKL_INT *m, const double *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const double *x, double *y);
void MKL_DCOOTRSV(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const double *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const double *x, double *y);
void MKL_CSPBLAS_DCOOTRSV(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const double *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const double *x, double *y);

void MKL_DDIAMV (const char *transa, const MKL_INT *m, const MKL_INT *k, const double *alpha, const char *matdescra, const double *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const double *x, const double *beta, double *y);
void MKL_DDIASV (const char *transa, const MKL_INT *m, const double *alpha, const char *matdescra, const double *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const double *x, double *y);
void MKL_DDIAGEMV(const char *transa, const MKL_INT *m, const double *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const double *x, double *y);
void MKL_DDIASYMV(const char *uplo, const MKL_INT *m, const double *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const double *x, double *y);
void MKL_DDIATRSV(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const double *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const double *x, double *y);

void MKL_DSKYMV (const char *transa, const MKL_INT *m, const MKL_INT *k, const double *alpha, const char *matdescra, const double *val, const MKL_INT *pntr, const double *x, const double *beta, double *y);
void MKL_DSKYSV(const char *transa, const MKL_INT *m, const double *alpha, const char *matdescra, const double *val, const MKL_INT *pntr, const double *x, double *y);

void MKL_DBSRMV (const char *transa, const MKL_INT *m, const MKL_INT *k, const MKL_INT *lb, const double *alpha, const char *matdescra, const double *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const double *x, const double *beta, double *y);
void MKL_DBSRSV(const char *transa, const MKL_INT *m, const MKL_INT *lb, const double *alpha, const char *matdescra, const double *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const double *x, double *y);
void MKL_DBSRGEMV(const char *transa, const MKL_INT *m, const MKL_INT *lb, const double *a, const MKL_INT *ia, const MKL_INT *ja, const double *x, double *y);
void MKL_CSPBLAS_DBSRGEMV(const char *transa, const MKL_INT *m, const MKL_INT *lb, const double *a, const MKL_INT *ia, const MKL_INT *ja, const double *x, double *y);
void MKL_DBSRSYMV(const char *uplo, const MKL_INT *m, const MKL_INT *lb, const double *a, const MKL_INT *ia, const MKL_INT *ja, const double *x, double *y);
void MKL_CSPBLAS_DBSRSYMV(const char *uplo, const MKL_INT *m, const MKL_INT *lb, const double *a, const MKL_INT *ia, const MKL_INT *ja, const double *x, double *y);
void MKL_DBSRTRSV(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_INT *lb, const double *a, const MKL_INT *ia, const MKL_INT *ja, const double *x, double *y);
void MKL_CSPBLAS_DBSRTRSV(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_INT *lb, const double *a, const MKL_INT *ia, const MKL_INT *ja, const double *x, double *y);

/* Sparse BLAS Level3 upper case */
void MKL_DCSRMM(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const double *alpha, const char *matdescra, const double *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const double *b, const MKL_INT *ldb, const double *beta, double *c, const MKL_INT *ldc);
void MKL_DCSRSM(const char *transa, const MKL_INT *m, const MKL_INT *n, const double *alpha, const char *matdescra, const double *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const double *b, const MKL_INT *ldb, double *c, const MKL_INT *ldc);

void MKL_DCSCMM(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const double *alpha, const char *matdescra, const double *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const double *b, const MKL_INT *ldb, const double *beta, double *c, const MKL_INT *ldc);
void MKL_DCSCSM(const char *transa, const MKL_INT *m, const MKL_INT *n, const double *alpha, const char *matdescra, const double *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const double *b, const MKL_INT *ldb, double *c, const MKL_INT *ldc);

void MKL_DCOOMM(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const double *alpha, const char *matdescra, const double *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const double *b, const MKL_INT *ldb, const double *beta, double *c, const MKL_INT *ldc);
void MKL_DCOOSM(const char *transa, const MKL_INT *m, const MKL_INT *n, const double *alpha, const char *matdescra, const double *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const double *b, const MKL_INT *ldb, double *c, const MKL_INT *ldc);

void MKL_DDIAMM (const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const double *alpha, const char *matdescra, const double *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const double *b, const MKL_INT *ldb, const double *beta, double *c, const MKL_INT *ldc);
void MKL_DDIASM (const char *transa, const MKL_INT *m, const MKL_INT *n, const double *alpha, const char *matdescra, const double *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const double *b, const MKL_INT *ldb, double *c, const MKL_INT *ldc);

void MKL_DSKYSM (const char *transa, const MKL_INT *m, const MKL_INT *n, const double *alpha, const char *matdescra, const double *val, const MKL_INT *pntr, const double *b, const MKL_INT *ldb, double *c, const MKL_INT *ldc);
void MKL_DSKYMM (const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const double *alpha, const char *matdescra, const double *val, const MKL_INT *pntr, const double *b, const MKL_INT *ldb, const double *beta, double *c, const MKL_INT *ldc);

void MKL_DBSRMM(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_INT *lb, const double *alpha, const char *matdescra, const double *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const double *b, const MKL_INT *ldb, const double *beta, double *c, const MKL_INT *ldc);
void MKL_DBSRSM(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *lb, const double *alpha, const char *matdescra, const double *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const double *b, const MKL_INT *ldb, double *c, const MKL_INT *ldc);

/* MKL_Complex8 */
/* Sparse BLAS Level2 lower case */
void mkl_ccsrmv(const char *transa, const MKL_INT *m, const MKL_INT *k, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex8 *x, const MKL_Complex8 *beta, MKL_Complex8 *y);
void mkl_ccsrsv(const char *transa, const MKL_INT *m, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex8 *x, MKL_Complex8 *y);
void mkl_ccsrgemv(const char *transa, const MKL_INT *m, const MKL_Complex8 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex8 *x, MKL_Complex8 *y);
void mkl_cspblas_ccsrgemv(const char *transa, const MKL_INT *m, const MKL_Complex8 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex8 *x, MKL_Complex8 *y);
void mkl_ccsrsymv(const char *uplo, const MKL_INT *m, const MKL_Complex8 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex8 *x, MKL_Complex8 *y);
void mkl_cspblas_ccsrsymv(const char *uplo, const MKL_INT *m, const MKL_Complex8 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex8 *x, MKL_Complex8 *y);
void mkl_ccsrtrsv(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_Complex8 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex8 *x, MKL_Complex8 *y);
void mkl_cspblas_ccsrtrsv(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_Complex8 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex8 *x, MKL_Complex8 *y);

void mkl_ccscmv(const char *transa, const MKL_INT *m, const MKL_INT *k, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex8 *x, const MKL_Complex8 *beta, MKL_Complex8 *y);
void mkl_ccscsv(const char *transa, const MKL_INT *m, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex8 *x, MKL_Complex8 *y);

void mkl_ccoomv(const char *transa, const MKL_INT *m, const MKL_INT *k, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex8 *x, const MKL_Complex8 *beta, MKL_Complex8 *y);
void mkl_ccoosv(const char *transa, const MKL_INT *m, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex8 *x, MKL_Complex8 *y);
void mkl_ccoogemv(const char *transa, const MKL_INT *m, const MKL_Complex8 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex8 *x, MKL_Complex8 *y);
void mkl_cspblas_ccoogemv(const char *transa, const MKL_INT *m, const MKL_Complex8 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex8 *x, MKL_Complex8 *y);
void mkl_ccoosymv(const char *uplo, const MKL_INT *m, const MKL_Complex8 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex8 *x, MKL_Complex8 *y);
void mkl_cspblas_ccoosymv(const char *uplo, const MKL_INT *m, const MKL_Complex8 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex8 *x, MKL_Complex8 *y);
void mkl_ccootrsv(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_Complex8 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex8 *x, MKL_Complex8 *y);
void mkl_cspblas_ccootrsv(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_Complex8 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex8 *x, MKL_Complex8 *y);

void mkl_cdiamv (const char *transa, const MKL_INT *m, const MKL_INT *k, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const MKL_Complex8 *x, const MKL_Complex8 *beta, MKL_Complex8 *y);
void mkl_cdiasv (const char *transa, const MKL_INT *m, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const MKL_Complex8 *x, MKL_Complex8 *y);
void mkl_cdiagemv(const char *transa, const MKL_INT *m, const MKL_Complex8 *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const MKL_Complex8 *x, MKL_Complex8 *y);
void mkl_cdiasymv(const char *uplo, const MKL_INT *m, const MKL_Complex8 *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const MKL_Complex8 *x, MKL_Complex8 *y);
void mkl_cdiatrsv(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_Complex8 *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const MKL_Complex8 *x, MKL_Complex8 *y);

void mkl_cskymv (const char *transa, const MKL_INT *m, const MKL_INT *k, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *pntr, const MKL_Complex8 *x, const MKL_Complex8 *beta, MKL_Complex8 *y);
void mkl_cskysv(const char *transa, const MKL_INT *m, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *pntr, const MKL_Complex8 *x, MKL_Complex8 *y);

void mkl_cbsrmv (const char *transa, const MKL_INT *m, const MKL_INT *k, const MKL_INT *lb, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex8 *x, const MKL_Complex8 *beta, MKL_Complex8 *y);
void mkl_cbsrsv(const char *transa, const MKL_INT *m, const MKL_INT *lb, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex8 *x, MKL_Complex8 *y);
void mkl_cbsrgemv(const char *transa, const MKL_INT *m, const MKL_INT *lb, const MKL_Complex8 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex8 *x, MKL_Complex8 *y);
void mkl_cspblas_cbsrgemv(const char *transa, const MKL_INT *m, const MKL_INT *lb, const MKL_Complex8 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex8 *x, MKL_Complex8 *y);
void mkl_cbsrsymv(const char *uplo, const MKL_INT *m, const MKL_INT *lb, const MKL_Complex8 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex8 *x, MKL_Complex8 *y);
void mkl_cspblas_cbsrsymv(const char *uplo, const MKL_INT *m, const MKL_INT *lb, const MKL_Complex8 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex8 *x, MKL_Complex8 *y);
void mkl_cbsrtrsv(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_INT *lb, const MKL_Complex8 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex8 *x, MKL_Complex8 *y);
void mkl_cspblas_cbsrtrsv(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_INT *lb, const MKL_Complex8 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex8 *x, MKL_Complex8 *y);

/* Sparse BLAS Level3 lower case */
void mkl_ccsrmm(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex8 *b, const MKL_INT *ldb, const MKL_Complex8 *beta, MKL_Complex8 *c, const MKL_INT *ldc);
void mkl_ccsrsm(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex8 *b, const MKL_INT *ldb, MKL_Complex8 *c, const MKL_INT *ldc);

void mkl_ccscmm(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex8 *b, const MKL_INT *ldb, const MKL_Complex8 *beta, MKL_Complex8 *c, const MKL_INT *ldc);
void mkl_ccscsm(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex8 *b, const MKL_INT *ldb, MKL_Complex8 *c, const MKL_INT *ldc);

void mkl_ccoomm(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex8 *b, const MKL_INT *ldb, const MKL_Complex8 *beta, MKL_Complex8 *c, const MKL_INT *ldc);
void mkl_ccoosm(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex8 *b, const MKL_INT *ldb, MKL_Complex8 *c, const MKL_INT *ldc);

void mkl_cdiamm (const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const MKL_Complex8 *b, const MKL_INT *ldb, const MKL_Complex8 *beta, MKL_Complex8 *c, const MKL_INT *ldc);
void mkl_cdiasm (const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const MKL_Complex8 *b, const MKL_INT *ldb, MKL_Complex8 *c, const MKL_INT *ldc);

void mkl_cskysm (const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *pntr, const MKL_Complex8 *b, const MKL_INT *ldb, MKL_Complex8 *c, const MKL_INT *ldc);
void mkl_cskymm (const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *pntr, const MKL_Complex8 *b, const MKL_INT *ldb, const MKL_Complex8 *beta, MKL_Complex8 *c, const MKL_INT *ldc);

void mkl_cbsrmm(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_INT *lb, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex8 *b, const MKL_INT *ldb, const MKL_Complex8 *beta, MKL_Complex8 *c, const MKL_INT *ldc);
void mkl_cbsrsm(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *lb, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex8 *b, const MKL_INT *ldb, MKL_Complex8 *c, const MKL_INT *ldc);

/* Upper case declaration */
/* Sparse BLAS Level2 upper case */
void MKL_CCSRMV (const char *transa, const MKL_INT *m, const MKL_INT *k, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex8 *x, const MKL_Complex8 *beta, MKL_Complex8 *y);
void MKL_CCSRSV(const char *transa, const MKL_INT *m, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex8 *x, MKL_Complex8 *y);
void MKL_CCSRGEMV(const char *transa, const MKL_INT *m, const MKL_Complex8 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex8 *x, MKL_Complex8 *y);
void MKL_CSPBLAS_CCSRGEMV(const char *transa, const MKL_INT *m, const MKL_Complex8 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex8 *x, MKL_Complex8 *y);
void MKL_CCSRSYMV(const char *uplo, const MKL_INT *m, const MKL_Complex8 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex8 *x, MKL_Complex8 *y);
void MKL_CSPBLAS_CCSRSYMV(const char *uplo, const MKL_INT *m, const MKL_Complex8 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex8 *x, MKL_Complex8 *y);
void MKL_CCSRTRSV(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_Complex8 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex8 *x, MKL_Complex8 *y);
void MKL_CSPBLAS_CCSRTRSV(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_Complex8 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex8 *x, MKL_Complex8 *y);

void MKL_CCSCMV(const char *transa, const MKL_INT *m, const MKL_INT *k, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex8 *x, const MKL_Complex8 *beta, MKL_Complex8 *y);
void MKL_CCSCSV(const char *transa, const MKL_INT *m, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex8 *x, MKL_Complex8 *y);

void MKL_CCOOMV(const char *transa, const MKL_INT *m, const MKL_INT *k, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex8 *x, const MKL_Complex8 *beta, MKL_Complex8 *y);
void MKL_CCOOSV(const char *transa, const MKL_INT *m, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex8 *x, MKL_Complex8 *y);
void MKL_CCOOGEMV(const char *transa, const MKL_INT *m, const MKL_Complex8 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex8 *x, MKL_Complex8 *y);
void MKL_CSPBLAS_CCOOGEMV(const char *transa, const MKL_INT *m, const MKL_Complex8 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex8 *x, MKL_Complex8 *y);
void MKL_CCOOSYMV(const char *uplo, const MKL_INT *m, const MKL_Complex8 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex8 *x, MKL_Complex8 *y);
void MKL_CSPBLAS_CCOOSYMV(const char *uplo, const MKL_INT *m, const MKL_Complex8 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex8 *x, MKL_Complex8 *y);
void MKL_CCOOTRSV(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_Complex8 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex8 *x, MKL_Complex8 *y);
void MKL_CSPBLAS_CCOOTRSV(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_Complex8 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex8 *x, MKL_Complex8 *y);

void MKL_CDIAMV (const char *transa, const MKL_INT *m, const MKL_INT *k, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const MKL_Complex8 *x, const MKL_Complex8 *beta, MKL_Complex8 *y);
void MKL_CDIASV (const char *transa, const MKL_INT *m, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const MKL_Complex8 *x, MKL_Complex8 *y);
void MKL_CDIAGEMV(const char *transa, const MKL_INT *m, const MKL_Complex8 *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const MKL_Complex8 *x, MKL_Complex8 *y);
void MKL_CDIASYMV(const char *uplo, const MKL_INT *m, const MKL_Complex8 *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const MKL_Complex8 *x, MKL_Complex8 *y);
void MKL_CDIATRSV(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_Complex8 *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const MKL_Complex8 *x, MKL_Complex8 *y);

void MKL_CSKYMV (const char *transa, const MKL_INT *m, const MKL_INT *k, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *pntr, const MKL_Complex8 *x, const MKL_Complex8 *beta, MKL_Complex8 *y);
void MKL_CSKYSV(const char *transa, const MKL_INT *m, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *pntr, const MKL_Complex8 *x, MKL_Complex8 *y);

void MKL_CBSRMV (const char *transa, const MKL_INT *m, const MKL_INT *k, const MKL_INT *lb, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex8 *x, const MKL_Complex8 *beta, MKL_Complex8 *y);
void MKL_CBSRSV(const char *transa, const MKL_INT *m, const MKL_INT *lb, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex8 *x, MKL_Complex8 *y);
void MKL_CBSRGEMV(const char *transa, const MKL_INT *m, const MKL_INT *lb, const MKL_Complex8 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex8 *x, MKL_Complex8 *y);
void MKL_CSPBLAS_CBSRGEMV(const char *transa, const MKL_INT *m, const MKL_INT *lb, const MKL_Complex8 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex8 *x, MKL_Complex8 *y);
void MKL_CBSRSYMV(const char *uplo, const MKL_INT *m, const MKL_INT *lb, const MKL_Complex8 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex8 *x, MKL_Complex8 *y);
void MKL_CSPBLAS_CBSRSYMV(const char *uplo, const MKL_INT *m, const MKL_INT *lb, const MKL_Complex8 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex8 *x, MKL_Complex8 *y);
void MKL_CBSRTRSV(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_INT *lb, const MKL_Complex8 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex8 *x, MKL_Complex8 *y);
void MKL_CSPBLAS_CBSRTRSV(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_INT *lb, const MKL_Complex8 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex8 *x, MKL_Complex8 *y);

/* Sparse BLAS Level3 upper case */
void MKL_CCSRMM(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex8 *b, const MKL_INT *ldb, const MKL_Complex8 *beta, MKL_Complex8 *c, const MKL_INT *ldc);
void MKL_CCSRSM(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex8 *b, const MKL_INT *ldb, MKL_Complex8 *c, const MKL_INT *ldc);

void MKL_CCSCMM(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex8 *b, const MKL_INT *ldb, const MKL_Complex8 *beta, MKL_Complex8 *c, const MKL_INT *ldc);
void MKL_CCSCSM(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex8 *b, const MKL_INT *ldb, MKL_Complex8 *c, const MKL_INT *ldc);

void MKL_CCOOMM(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex8 *b, const MKL_INT *ldb, const MKL_Complex8 *beta, MKL_Complex8 *c, const MKL_INT *ldc);
void MKL_CCOOSM(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex8 *b, const MKL_INT *ldb, MKL_Complex8 *c, const MKL_INT *ldc);

void MKL_CDIAMM (const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const MKL_Complex8 *b, const MKL_INT *ldb, const MKL_Complex8 *beta, MKL_Complex8 *c, const MKL_INT *ldc);
void MKL_CDIASM (const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const MKL_Complex8 *b, const MKL_INT *ldb, MKL_Complex8 *c, const MKL_INT *ldc);

void MKL_CSKYSM (const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *pntr, const MKL_Complex8 *b, const MKL_INT *ldb, MKL_Complex8 *c, const MKL_INT *ldc);
void MKL_CSKYMM (const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *pntr, const MKL_Complex8 *b, const MKL_INT *ldb, const MKL_Complex8 *beta, MKL_Complex8 *c, const MKL_INT *ldc);

void MKL_CBSRMM(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_INT *lb, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex8 *b, const MKL_INT *ldb, const MKL_Complex8 *beta, MKL_Complex8 *c, const MKL_INT *ldc);
void MKL_CBSRSM(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *lb, const MKL_Complex8 *alpha, const char *matdescra, const MKL_Complex8 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex8 *b, const MKL_INT *ldb, MKL_Complex8 *c, const MKL_INT *ldc);

/* MKL_Complex16 */
/* Sparse BLAS Level2 lower case */
void mkl_zcsrmv(const char *transa, const MKL_INT *m, const MKL_INT *k, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex16 *x, const MKL_Complex16 *beta, MKL_Complex16 *y);
void mkl_zcsrsv(const char *transa, const MKL_INT *m, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex16 *x, MKL_Complex16 *y);
void mkl_zcsrgemv(const char *transa, const MKL_INT *m, const MKL_Complex16 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex16 *x, MKL_Complex16 *y);
void mkl_cspblas_zcsrgemv(const char *transa, const MKL_INT *m, const MKL_Complex16 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex16 *x, MKL_Complex16 *y);
void mkl_zcsrsymv(const char *uplo, const MKL_INT *m, const MKL_Complex16 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex16 *x, MKL_Complex16 *y);
void mkl_cspblas_zcsrsymv(const char *uplo, const MKL_INT *m, const MKL_Complex16 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex16 *x, MKL_Complex16 *y);
void mkl_zcsrtrsv(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_Complex16 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex16 *x, MKL_Complex16 *y);
void mkl_cspblas_zcsrtrsv(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_Complex16 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex16 *x, MKL_Complex16 *y);

void mkl_zcscmv(const char *transa, const MKL_INT *m, const MKL_INT *k, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex16 *x, const MKL_Complex16 *beta, MKL_Complex16 *y);
void mkl_zcscsv(const char *transa, const MKL_INT *m, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex16 *x, MKL_Complex16 *y);

void mkl_zcoomv(const char *transa, const MKL_INT *m, const MKL_INT *k, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex16 *x, const MKL_Complex16 *beta, MKL_Complex16 *y);
void mkl_zcoosv(const char *transa, const MKL_INT *m, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex16 *x, MKL_Complex16 *y);
void mkl_zcoogemv(const char *transa, const MKL_INT *m, const MKL_Complex16 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex16 *x, MKL_Complex16 *y);
void mkl_cspblas_zcoogemv(const char *transa, const MKL_INT *m, const MKL_Complex16 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex16 *x, MKL_Complex16 *y);
void mkl_zcoosymv(const char *uplo, const MKL_INT *m, const MKL_Complex16 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex16 *x, MKL_Complex16 *y);
void mkl_cspblas_zcoosymv(const char *uplo, const MKL_INT *m, const MKL_Complex16 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex16 *x, MKL_Complex16 *y);
void mkl_zcootrsv(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_Complex16 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex16 *x, MKL_Complex16 *y);
void mkl_cspblas_zcootrsv(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_Complex16 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex16 *x, MKL_Complex16 *y);

void mkl_zdiamv (const char *transa, const MKL_INT *m, const MKL_INT *k, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const MKL_Complex16 *x, const MKL_Complex16 *beta, MKL_Complex16 *y);
void mkl_zdiasv (const char *transa, const MKL_INT *m, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const MKL_Complex16 *x, MKL_Complex16 *y);
void mkl_zdiagemv(const char *transa, const MKL_INT *m, const MKL_Complex16 *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const MKL_Complex16 *x, MKL_Complex16 *y);
void mkl_zdiasymv(const char *uplo, const MKL_INT *m, const MKL_Complex16 *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const MKL_Complex16 *x, MKL_Complex16 *y);
void mkl_zdiatrsv(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_Complex16 *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const MKL_Complex16 *x, MKL_Complex16 *y);

void mkl_zskymv (const char *transa, const MKL_INT *m, const MKL_INT *k, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *pntr, const MKL_Complex16 *x, const MKL_Complex16 *beta, MKL_Complex16 *y);
void mkl_zskysv(const char *transa, const MKL_INT *m, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *pntr, const MKL_Complex16 *x, MKL_Complex16 *y);

void mkl_zbsrmv (const char *transa, const MKL_INT *m, const MKL_INT *k, const MKL_INT *lb, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex16 *x, const MKL_Complex16 *beta, MKL_Complex16 *y);
void mkl_zbsrsv(const char *transa, const MKL_INT *m, const MKL_INT *lb, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex16 *x, MKL_Complex16 *y);
void mkl_zbsrgemv(const char *transa, const MKL_INT *m, const MKL_INT *lb, const MKL_Complex16 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex16 *x, MKL_Complex16 *y);
void mkl_cspblas_zbsrgemv(const char *transa, const MKL_INT *m, const MKL_INT *lb, const MKL_Complex16 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex16 *x, MKL_Complex16 *y);
void mkl_zbsrsymv(const char *uplo, const MKL_INT *m, const MKL_INT *lb, const MKL_Complex16 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex16 *x, MKL_Complex16 *y);
void mkl_cspblas_zbsrsymv(const char *uplo, const MKL_INT *m, const MKL_INT *lb, const MKL_Complex16 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex16 *x, MKL_Complex16 *y);
void mkl_zbsrtrsv(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_INT *lb, const MKL_Complex16 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex16 *x, MKL_Complex16 *y);
void mkl_cspblas_zbsrtrsv(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_INT *lb, const MKL_Complex16 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex16 *x, MKL_Complex16 *y);

/* Sparse BLAS Level3 lower case */
void mkl_zcsrmm(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex16 *b, const MKL_INT *ldb, const MKL_Complex16 *beta, MKL_Complex16 *c, const MKL_INT *ldc);
void mkl_zcsrsm(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex16 *b, const MKL_INT *ldb, MKL_Complex16 *c, const MKL_INT *ldc);

void mkl_zcscmm(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex16 *b, const MKL_INT *ldb, const MKL_Complex16 *beta, MKL_Complex16 *c, const MKL_INT *ldc);
void mkl_zcscsm(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex16 *b, const MKL_INT *ldb, MKL_Complex16 *c, const MKL_INT *ldc);

void mkl_zcoomm(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex16 *b, const MKL_INT *ldb, const MKL_Complex16 *beta, MKL_Complex16 *c, const MKL_INT *ldc);
void mkl_zcoosm(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex16 *b, const MKL_INT *ldb, MKL_Complex16 *c, const MKL_INT *ldc);

void mkl_zdiamm (const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const MKL_Complex16 *b, const MKL_INT *ldb, const MKL_Complex16 *beta, MKL_Complex16 *c, const MKL_INT *ldc);
void mkl_zdiasm (const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const MKL_Complex16 *b, const MKL_INT *ldb, MKL_Complex16 *c, const MKL_INT *ldc);

void mkl_zskysm (const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *pntr, const MKL_Complex16 *b, const MKL_INT *ldb, MKL_Complex16 *c, const MKL_INT *ldc);
void mkl_zskymm (const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *pntr, const MKL_Complex16 *b, const MKL_INT *ldb, const MKL_Complex16 *beta, MKL_Complex16 *c, const MKL_INT *ldc);

void mkl_zbsrmm(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_INT *lb, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex16 *b, const MKL_INT *ldb, const MKL_Complex16 *beta, MKL_Complex16 *c, const MKL_INT *ldc);
void mkl_zbsrsm(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *lb, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex16 *b, const MKL_INT *ldb, MKL_Complex16 *c, const MKL_INT *ldc);

/* Upper case declaration */
/* Sparse BLAS Level2 upper case */
void MKL_ZCSRMV (const char *transa, const MKL_INT *m, const MKL_INT *k, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex16 *x, const MKL_Complex16 *beta, MKL_Complex16 *y);
void MKL_ZCSRSV(const char *transa, const MKL_INT *m, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex16 *x, MKL_Complex16 *y);
void MKL_ZCSRGEMV(const char *transa, const MKL_INT *m, const MKL_Complex16 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex16 *x, MKL_Complex16 *y);
void MKL_CSPBLAS_ZCSRGEMV(const char *transa, const MKL_INT *m, const MKL_Complex16 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex16 *x, MKL_Complex16 *y);
void MKL_ZCSRSYMV(const char *uplo, const MKL_INT *m, const MKL_Complex16 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex16 *x, MKL_Complex16 *y);
void MKL_CSPBLAS_ZCSRSYMV(const char *uplo, const MKL_INT *m, const MKL_Complex16 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex16 *x, MKL_Complex16 *y);
void MKL_ZCSRTRSV(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_Complex16 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex16 *x, MKL_Complex16 *y);
void MKL_CSPBLAS_ZCSRTRSV(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_Complex16 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex16 *x, MKL_Complex16 *y);

void MKL_ZCSCMV(const char *transa, const MKL_INT *m, const MKL_INT *k, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex16 *x, const MKL_Complex16 *beta, MKL_Complex16 *y);
void MKL_ZCSCSV(const char *transa, const MKL_INT *m, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex16 *x, MKL_Complex16 *y);

void MKL_ZCOOMV(const char *transa, const MKL_INT *m, const MKL_INT *k, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex16 *x, const MKL_Complex16 *beta, MKL_Complex16 *y);
void MKL_ZCOOSV(const char *transa, const MKL_INT *m, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex16 *x, MKL_Complex16 *y);
void MKL_ZCOOGEMV(const char *transa, const MKL_INT *m, const MKL_Complex16 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex16 *x, MKL_Complex16 *y);
void MKL_CSPBLAS_ZCOOGEMV(const char *transa, const MKL_INT *m, const MKL_Complex16 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex16 *x, MKL_Complex16 *y);
void MKL_ZCOOSYMV(const char *uplo, const MKL_INT *m, const MKL_Complex16 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex16 *x, MKL_Complex16 *y);
void MKL_CSPBLAS_ZCOOSYMV(const char *uplo, const MKL_INT *m, const MKL_Complex16 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex16 *x, MKL_Complex16 *y);
void MKL_ZCOOTRSV(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_Complex16 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex16 *x, MKL_Complex16 *y);
void MKL_CSPBLAS_ZCOOTRSV(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_Complex16 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex16 *x, MKL_Complex16 *y);

void MKL_ZDIAMV (const char *transa, const MKL_INT *m, const MKL_INT *k, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const MKL_Complex16 *x, const MKL_Complex16 *beta, MKL_Complex16 *y);
void MKL_ZDIASV (const char *transa, const MKL_INT *m, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const MKL_Complex16 *x, MKL_Complex16 *y);
void MKL_ZDIAGEMV(const char *transa, const MKL_INT *m, const MKL_Complex16 *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const MKL_Complex16 *x, MKL_Complex16 *y);
void MKL_ZDIASYMV(const char *uplo, const MKL_INT *m, const MKL_Complex16 *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const MKL_Complex16 *x, MKL_Complex16 *y);
void MKL_ZDIATRSV(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_Complex16 *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const MKL_Complex16 *x, MKL_Complex16 *y);

void MKL_ZSKYMV (const char *transa, const MKL_INT *m, const MKL_INT *k, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *pntr, const MKL_Complex16 *x, const MKL_Complex16 *beta, MKL_Complex16 *y);
void MKL_ZSKYSV(const char *transa, const MKL_INT *m, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *pntr, const MKL_Complex16 *x, MKL_Complex16 *y);

void MKL_ZBSRMV (const char *transa, const MKL_INT *m, const MKL_INT *k, const MKL_INT *lb, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex16 *x, const MKL_Complex16 *beta, MKL_Complex16 *y);
void MKL_ZBSRSV(const char *transa, const MKL_INT *m, const MKL_INT *lb, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex16 *x, MKL_Complex16 *y);
void MKL_ZBSRGEMV(const char *transa, const MKL_INT *m, const MKL_INT *lb, const MKL_Complex16 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex16 *x, MKL_Complex16 *y);
void MKL_CSPBLAS_ZBSRGEMV(const char *transa, const MKL_INT *m, const MKL_INT *lb, const MKL_Complex16 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex16 *x, MKL_Complex16 *y);
void MKL_ZBSRSYMV(const char *uplo, const MKL_INT *m, const MKL_INT *lb, const MKL_Complex16 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex16 *x, MKL_Complex16 *y);
void MKL_CSPBLAS_ZBSRSYMV(const char *uplo, const MKL_INT *m, const MKL_INT *lb, const MKL_Complex16 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex16 *x, MKL_Complex16 *y);
void MKL_ZBSRTRSV(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_INT *lb, const MKL_Complex16 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex16 *x, MKL_Complex16 *y);
void MKL_CSPBLAS_ZBSRTRSV(const char *uplo, const char *transa, const char *diag, const MKL_INT *m, const MKL_INT *lb, const MKL_Complex16 *a, const MKL_INT *ia, const MKL_INT *ja, const MKL_Complex16 *x, MKL_Complex16 *y);

/* Sparse BLAS Level3 upper case */
void MKL_ZCSRMM(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex16 *b, const MKL_INT *ldb, const MKL_Complex16 *beta, MKL_Complex16 *c, const MKL_INT *ldc);
void MKL_ZCSRSM(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex16 *b, const MKL_INT *ldb, MKL_Complex16 *c, const MKL_INT *ldc);

void MKL_ZCSCMM(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex16 *b, const MKL_INT *ldb, const MKL_Complex16 *beta, MKL_Complex16 *c, const MKL_INT *ldc);
void MKL_ZCSCSM(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex16 *b, const MKL_INT *ldb, MKL_Complex16 *c, const MKL_INT *ldc);

void MKL_ZCOOMM(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex16 *b, const MKL_INT *ldb, const MKL_Complex16 *beta, MKL_Complex16 *c, const MKL_INT *ldc);
void MKL_ZCOOSM(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *rowind, const MKL_INT *colind, const MKL_INT *nnz, const MKL_Complex16 *b, const MKL_INT *ldb, MKL_Complex16 *c, const MKL_INT *ldc);

void MKL_ZDIAMM (const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const MKL_Complex16 *b, const MKL_INT *ldb, const MKL_Complex16 *beta, MKL_Complex16 *c, const MKL_INT *ldc);
void MKL_ZDIASM (const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *lval, const MKL_INT *idiag, const MKL_INT *ndiag, const MKL_Complex16 *b, const MKL_INT *ldb, MKL_Complex16 *c, const MKL_INT *ldc);

void MKL_ZSKYSM (const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *pntr, const MKL_Complex16 *b, const MKL_INT *ldb, MKL_Complex16 *c, const MKL_INT *ldc);
void MKL_ZSKYMM (const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *pntr, const MKL_Complex16 *b, const MKL_INT *ldb, const MKL_Complex16 *beta, MKL_Complex16 *c, const MKL_INT *ldc);

void MKL_ZBSRMM(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k, const MKL_INT *lb, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex16 *b, const MKL_INT *ldb, const MKL_Complex16 *beta, MKL_Complex16 *c, const MKL_INT *ldc);
void MKL_ZBSRSM(const char *transa, const MKL_INT *m, const MKL_INT *n, const MKL_INT *lb, const MKL_Complex16 *alpha, const char *matdescra, const MKL_Complex16 *val, const MKL_INT *indx, const MKL_INT *pntrb, const MKL_INT *pntre, const MKL_Complex16 *b, const MKL_INT *ldb, MKL_Complex16 *c, const MKL_INT *ldc);

/*Converters lower case*/
void mkl_dcsrbsr(const MKL_INT *job, const MKL_INT *m, const MKL_INT *mblk, const MKL_INT *ldAbsr, double *Acsr, MKL_INT *AJ, MKL_INT *AI, double *Absr,  MKL_INT *AJB,  MKL_INT *AIB,  MKL_INT *info);
void mkl_dcsrcoo(const MKL_INT *job, const MKL_INT *n, double *Acsr, MKL_INT *AJR, MKL_INT *AIR, MKL_INT *nnz, double *Acoo,  MKL_INT *ir,  MKL_INT *jc,  MKL_INT *info);
void mkl_ddnscsr(const MKL_INT *job, const MKL_INT *m, const MKL_INT *n, double *Adns, const MKL_INT *lda, double *Acsr, MKL_INT *AJ, MKL_INT *AI, MKL_INT *info);
void mkl_dcsrcsc(const MKL_INT *job, const MKL_INT *n, double *Acsr, MKL_INT *AJ0, MKL_INT *AI0, double *Acsc, MKL_INT *AJ1, MKL_INT *AI1, MKL_INT *info);
void mkl_dcsrdia(const MKL_INT *job, const MKL_INT *n, double *Acsr, MKL_INT *AJ0, MKL_INT *AI0, double *Adia, const MKL_INT *ndiag, MKL_INT *distance, MKL_INT *idiag, double *Acsr_rem, MKL_INT *AJ0_rem, MKL_INT *AI0_rem, MKL_INT *info);
void mkl_dcsrsky(const MKL_INT *job, const MKL_INT *n, double *Acsr, MKL_INT *AJ0, MKL_INT *AI0,  double *Asky, MKL_INT *pointers, MKL_INT *info);

void mkl_scsrbsr(const MKL_INT *job, const MKL_INT *m, const MKL_INT *mblk, const MKL_INT *ldAbsr, float *Acsr, MKL_INT *AJ, MKL_INT *AI, float *Absr,  MKL_INT *AJB,  MKL_INT *AIB,  MKL_INT *info);
void mkl_scsrcoo(const MKL_INT *job, const MKL_INT *n, float *Acsr, MKL_INT *AJR, MKL_INT *AIR, MKL_INT *nnz, float *Acoo,  MKL_INT *ir,  MKL_INT *jc,  MKL_INT *info);
void mkl_sdnscsr(const MKL_INT *job, const MKL_INT *m, const MKL_INT *n, float *Adns, const MKL_INT *lda, float *Acsr, MKL_INT *AJ, MKL_INT *AI, MKL_INT *info);
void mkl_scsrcsc(const MKL_INT *job, const MKL_INT *n, float *Acsr, MKL_INT *AJ0, MKL_INT *AI0, float *Acsc, MKL_INT *AJ1, MKL_INT *AI1, MKL_INT *info);
void mkl_scsrdia(const MKL_INT *job, const MKL_INT *n, float *Acsr, MKL_INT *AJ0, MKL_INT *AI0, float *Adia, const MKL_INT *ndiag, MKL_INT *distance, MKL_INT *idiag, float *Acsr_rem, MKL_INT *AJ0_rem, MKL_INT *AI0_rem, MKL_INT *info);
void mkl_scsrsky(const MKL_INT *job, const MKL_INT *n, float *Acsr, MKL_INT *AJ0, MKL_INT *AI0,  float *Asky, MKL_INT *pointers, MKL_INT *info);

void mkl_ccsrbsr(const MKL_INT *job, const MKL_INT *m, const MKL_INT *mblk, const MKL_INT *ldAbsr, MKL_Complex8 *Acsr, MKL_INT *AJ, MKL_INT *AI, MKL_Complex8 *Absr,  MKL_INT *AJB,  MKL_INT *AIB,  MKL_INT *info);
void mkl_ccsrcoo(const MKL_INT *job, const MKL_INT *n, MKL_Complex8 *Acsr, MKL_INT *AJR, MKL_INT *AIR, MKL_INT *nnz, MKL_Complex8 *Acoo,  MKL_INT *ir,  MKL_INT *jc,  MKL_INT *info);
void mkl_cdnscsr(const MKL_INT *job, const MKL_INT *m, const MKL_INT *n, MKL_Complex8 *Adns, const MKL_INT *lda, MKL_Complex8 *Acsr, MKL_INT *AJ, MKL_INT *AI, MKL_INT *info);
void mkl_ccsrcsc(const MKL_INT *job, const MKL_INT *n, MKL_Complex8 *Acsr, MKL_INT *AJ0, MKL_INT *AI0, MKL_Complex8 *Acsc, MKL_INT *AJ1, MKL_INT *AI1, MKL_INT *info);
void mkl_ccsrdia(const MKL_INT *job, const MKL_INT *n, MKL_Complex8 *Acsr, MKL_INT *AJ0, MKL_INT *AI0, MKL_Complex8 *Adia, const MKL_INT *ndiag, MKL_INT *distance, MKL_INT *idiag, MKL_Complex8 *Acsr_rem, MKL_INT *AJ0_rem, MKL_INT *AI0_rem, MKL_INT *info);
void mkl_ccsrsky(const MKL_INT *job, const MKL_INT *n, MKL_Complex8 *Acsr, MKL_INT *AJ0, MKL_INT *AI0,  MKL_Complex8 *Asky, MKL_INT *pointers, MKL_INT *info);

void mkl_zcsrbsr(const MKL_INT *job, const MKL_INT *m, const MKL_INT *mblk, const MKL_INT *ldAbsr, MKL_Complex16 *Acsr, MKL_INT *AJ, MKL_INT *AI, MKL_Complex16 *Absr,  MKL_INT *AJB,  MKL_INT *AIB,  MKL_INT *info);
void mkl_zcsrcoo(const MKL_INT *job, const MKL_INT *n, MKL_Complex16 *Acsr, MKL_INT *AJR, MKL_INT *AIR, MKL_INT *nnz, MKL_Complex16 *Acoo,  MKL_INT *ir,  MKL_INT *jc,  MKL_INT *info);
void mkl_zdnscsr(const MKL_INT *job, const MKL_INT *m, const MKL_INT *n, MKL_Complex16 *Adns, const MKL_INT *lda, MKL_Complex16 *Acsr, MKL_INT *AJ, MKL_INT *AI, MKL_INT *info);
void mkl_zcsrcsc(const MKL_INT *job, const MKL_INT *n, MKL_Complex16 *Acsr, MKL_INT *AJ0, MKL_INT *AI0, MKL_Complex16 *Acsc, MKL_INT *AJ1, MKL_INT *AI1, MKL_INT *info);
void mkl_zcsrdia(const MKL_INT *job, const MKL_INT *n, MKL_Complex16 *Acsr, MKL_INT *AJ0, MKL_INT *AI0, MKL_Complex16 *Adia, const MKL_INT *ndiag, MKL_INT *distance, MKL_INT *idiag, MKL_Complex16 *Acsr_rem, MKL_INT *AJ0_rem, MKL_INT *AI0_rem, MKL_INT *info);
void mkl_zcsrsky(const MKL_INT *job, const MKL_INT *n, MKL_Complex16 *Acsr, MKL_INT *AJ0, MKL_INT *AI0,  MKL_Complex16 *Asky, MKL_INT *pointers, MKL_INT *info);

/*Converters upper case*/
void MKL_DCSRBSR(const MKL_INT *job, const MKL_INT *m, const MKL_INT *mblk, const MKL_INT *ldAbsr, double *Acsr, MKL_INT *AJ, MKL_INT *AI, double *Absr,  MKL_INT *AJB,  MKL_INT *AIB,  MKL_INT *info);
void MKL_DCSRCOO(const MKL_INT *job, const MKL_INT *n, double *Acsr, MKL_INT *AJR, MKL_INT *AIR, MKL_INT *nnz, double *Acoo,  MKL_INT *ir,  MKL_INT *jc,  MKL_INT *info);
void MKL_DDNSCSR(const MKL_INT *job, const MKL_INT *m, const MKL_INT *n, double *Adns, const MKL_INT *lda, double *Acsr, MKL_INT *AJ, MKL_INT *AI, MKL_INT *info);
void MKL_DCSRCSC(const MKL_INT *job, const MKL_INT *n, double *Acsr, MKL_INT *AJ0, MKL_INT *AI0, double *Acsc, MKL_INT *AJ1, MKL_INT *AI1, MKL_INT *info);
void MKL_DCSRDIA(const MKL_INT *job, const MKL_INT *n, double *Acsr, MKL_INT *AJ0, MKL_INT *AI0, double *Adia, const MKL_INT *ndiag, MKL_INT *distance, MKL_INT *idiag, double *Acsr_rem, MKL_INT *AJ0_rem, MKL_INT *AI0_rem, MKL_INT *info);
void MKL_DCSRSKY(const MKL_INT *job, const MKL_INT *n, double *Acsr, MKL_INT *AJ0, MKL_INT *AI0,  double *Asky, MKL_INT *pointers, MKL_INT *info);

void MKL_SCSRBSR(const MKL_INT *job, const MKL_INT *m, const MKL_INT *mblk, const MKL_INT *ldAbsr, float *Acsr, MKL_INT *AJ, MKL_INT *AI, float *Absr,  MKL_INT *AJB,  MKL_INT *AIB,  MKL_INT *info);
void MKL_SCSRCOO(const MKL_INT *job, const MKL_INT *n, float *Acsr, MKL_INT *AJR, MKL_INT *AIR, MKL_INT *nnz, float *Acoo,  MKL_INT *ir,  MKL_INT *jc,  MKL_INT *info);
void MKL_SDNSCSR(const MKL_INT *job, const MKL_INT *m, const MKL_INT *n, float *Adns, const MKL_INT *lda, float *Acsr, MKL_INT *AJ, MKL_INT *AI, MKL_INT *info);
void MKL_SCSRCSC(const MKL_INT *job, const MKL_INT *n, float *Acsr, MKL_INT *AJ0, MKL_INT *AI0, float *Acsc, MKL_INT *AJ1, MKL_INT *AI1, MKL_INT *info);
void MKL_SCSRDIA(const MKL_INT *job, const MKL_INT *n, float *Acsr, MKL_INT *AJ0, MKL_INT *AI0, float *Adia, const MKL_INT *ndiag, MKL_INT *distance, MKL_INT *idiag, float *Acsr_rem, MKL_INT *AJ0_rem, MKL_INT *AI0_rem, MKL_INT *info);
void MKL_SCSRSKY(const MKL_INT *job, const MKL_INT *n, float *Acsr, MKL_INT *AJ0, MKL_INT *AI0,  float *Asky, MKL_INT *pointers, MKL_INT *info);

void MKL_CCSRBSR(const MKL_INT *job, const MKL_INT *m, const MKL_INT *mblk, const MKL_INT *ldAbsr, MKL_Complex8 *Acsr, MKL_INT *AJ, MKL_INT *AI, MKL_Complex8 *Absr,  MKL_INT *AJB,  MKL_INT *AIB,  MKL_INT *info);
void MKL_CCSRCOO(const MKL_INT *job, const MKL_INT *n, MKL_Complex8 *Acsr, MKL_INT *AJR, MKL_INT *AIR, MKL_INT *nnz, MKL_Complex8 *Acoo,  MKL_INT *ir,  MKL_INT *jc,  MKL_INT *info);
void MKL_CDNSCSR(const MKL_INT *job, const MKL_INT *m, const MKL_INT *n, MKL_Complex8 *Adns, const MKL_INT *lda, MKL_Complex8 *Acsr, MKL_INT *AJ, MKL_INT *AI, MKL_INT *info);
void MKL_CCSRCSC(const MKL_INT *job, const MKL_INT *n, MKL_Complex8 *Acsr, MKL_INT *AJ0, MKL_INT *AI0, MKL_Complex8 *Acsc, MKL_INT *AJ1, MKL_INT *AI1, MKL_INT *info);
void MKL_CCSRDIA(const MKL_INT *job, const MKL_INT *n, MKL_Complex8 *Acsr, MKL_INT *AJ0, MKL_INT *AI0, MKL_Complex8 *Adia, const MKL_INT *ndiag, MKL_INT *distance, MKL_INT *idiag, MKL_Complex8 *Acsr_rem, MKL_INT *AJ0_rem, MKL_INT *AI0_rem, MKL_INT *info);
void MKL_CCSRSKY(const MKL_INT *job, const MKL_INT *n, MKL_Complex8 *Acsr, MKL_INT *AJ0, MKL_INT *AI0,  MKL_Complex8 *Asky, MKL_INT *pointers, MKL_INT *info);

void MKL_ZCSRBSR(const MKL_INT *job, const MKL_INT *m, const MKL_INT *mblk, const MKL_INT *ldAbsr, MKL_Complex16 *Acsr, MKL_INT *AJ, MKL_INT *AI, MKL_Complex16 *Absr,  MKL_INT *AJB,  MKL_INT *AIB,  MKL_INT *info);
void MKL_ZCSRCOO(const MKL_INT *job, const MKL_INT *n, MKL_Complex16 *Acsr, MKL_INT *AJR, MKL_INT *AIR, MKL_INT *nnz, MKL_Complex16 *Acoo,  MKL_INT *ir,  MKL_INT *jc,  MKL_INT *info);
void MKL_ZDNSCSR(const MKL_INT *job, const MKL_INT *m, const MKL_INT *n, MKL_Complex16 *Adns, const MKL_INT *lda, MKL_Complex16 *Acsr, MKL_INT *AJ, MKL_INT *AI, MKL_INT *info);
void MKL_ZCSRCSC(const MKL_INT *job, const MKL_INT *n, MKL_Complex16 *Acsr, MKL_INT *AJ0, MKL_INT *AI0, MKL_Complex16 *Acsc, MKL_INT *AJ1, MKL_INT *AI1, MKL_INT *info);
void MKL_ZCSRDIA(const MKL_INT *job, const MKL_INT *n, MKL_Complex16 *Acsr, MKL_INT *AJ0, MKL_INT *AI0, MKL_Complex16 *Adia, const MKL_INT *ndiag, MKL_INT *distance, MKL_INT *idiag, MKL_Complex16 *Acsr_rem, MKL_INT *AJ0_rem, MKL_INT *AI0_rem, MKL_INT *info);
void MKL_ZCSRSKY(const MKL_INT *job, const MKL_INT *n, MKL_Complex16 *Acsr, MKL_INT *AJ0, MKL_INT *AI0,  MKL_Complex16 *Asky, MKL_INT *pointers, MKL_INT *info);


/*Sparse BLAS Level2 (CSR-CSR or CSR-DNS) lower case */
void mkl_dcsrmultcsr(const char *transa,  const MKL_INT *job,  const MKL_INT *sort,  const MKL_INT *m,  const MKL_INT *n,  const MKL_INT *k, double *a,  MKL_INT *ja, MKL_INT *ia, double *b, MKL_INT *jb, MKL_INT *ib,  double *c,  MKL_INT *jc,  MKL_INT *ic,  const MKL_INT *nnzmax,  MKL_INT *ierr);
void mkl_dcsrmultd(const char *transa,   const MKL_INT *m,  const MKL_INT *n,  const MKL_INT *k, double *a, MKL_INT *ja, MKL_INT *ia, double *b, MKL_INT *jb, MKL_INT *ib,  double *c,  MKL_INT *ldc);
void mkl_dcsradd(const char *transa,  const MKL_INT *job,  const MKL_INT *sort,  const MKL_INT *m,  const MKL_INT *n, double *a, MKL_INT *ja, MKL_INT *ia,  const double *beta, double *b, MKL_INT *jb, MKL_INT *ib,  double *c,  MKL_INT *jc,  MKL_INT *ic,  const MKL_INT *nnzmax,  MKL_INT *ierr);

void mkl_scsrmultcsr(const char *transa,  const MKL_INT *job,  const MKL_INT *sort,  const MKL_INT *m,  const MKL_INT *n,  const MKL_INT *k, float *a, MKL_INT *ja, MKL_INT *ia, float *b, MKL_INT *jb, MKL_INT *ib,  float *c,  MKL_INT *jc,  MKL_INT *ic,  const MKL_INT *nnzmax,  MKL_INT *ierr);
void mkl_scsrmultd(const char *transa,   const MKL_INT *m,  const MKL_INT *n,  const MKL_INT *k, float *a, MKL_INT *ja, MKL_INT *ia, float *b, MKL_INT *jb,  MKL_INT *ib, float *c,  MKL_INT *ldc);
void mkl_scsradd(const char *transa,  const MKL_INT *job,  const MKL_INT *sort,  const MKL_INT *m,  const MKL_INT *n, float *a, MKL_INT *ja, MKL_INT *ia,  const float *beta, float *b, MKL_INT *jb, MKL_INT *ib, float *c,  MKL_INT *jc,  MKL_INT *ic,  const MKL_INT *nnzmax,  MKL_INT *ierr);

void mkl_ccsrmultcsr(const char *transa,  const MKL_INT *job,  const MKL_INT *sort,  const MKL_INT *m,  const MKL_INT *n, const MKL_INT *k, MKL_Complex8 *a, MKL_INT *ja, MKL_INT *ia, MKL_Complex8 *b, MKL_INT *jb, MKL_INT *ib, MKL_Complex8 *c, MKL_INT *jc, MKL_INT *ic, const MKL_INT *nnzmax, MKL_INT *ierr);
void mkl_ccsrmultd(const char *transa,   const MKL_INT *m, const MKL_INT *n,  const MKL_INT *k, MKL_Complex8 *a, MKL_INT *ja, MKL_INT *ia, MKL_Complex8 *b, MKL_INT *jb, MKL_INT *ib, MKL_Complex8 *c, MKL_INT *ldc);
void mkl_ccsradd(const char *transa,  const MKL_INT *job, const MKL_INT *sort,  const MKL_INT *m,  const MKL_INT *n, MKL_Complex8 *a, MKL_INT *ja, MKL_INT *ia, const MKL_Complex8 *beta, MKL_Complex8 *b, MKL_INT *jb, MKL_INT *ib,  MKL_Complex8 *c,  MKL_INT *jc,  MKL_INT *ic,  const MKL_INT *nnzmax,  MKL_INT *ierr);

void mkl_zcsrmultcsr(const char *transa,  const MKL_INT *job,  const MKL_INT *sort,  const MKL_INT *m,  const MKL_INT *n,  const MKL_INT *k, MKL_Complex16 *a, MKL_INT *ja,  MKL_INT *ia, MKL_Complex16 *b, MKL_INT *jb, MKL_INT *ib,  MKL_Complex16 *c,  MKL_INT *jc,  MKL_INT *ic,  const MKL_INT *nnzmax,  MKL_INT *ierr);
void mkl_zcsrmultd(const char *transa,   const MKL_INT *m,  const MKL_INT *n,  const MKL_INT *k, MKL_Complex16 *a, MKL_INT *ja, MKL_INT *ia, MKL_Complex16 *b, MKL_INT *jb, MKL_INT *ib,  MKL_Complex16 *c,  MKL_INT *ldc);
void mkl_zcsradd(const char *transa,  const MKL_INT *job,  const MKL_INT *sort,  const MKL_INT *m,  const MKL_INT *n, MKL_Complex16 *a, MKL_INT *ja, MKL_INT *ia,  const MKL_Complex16 *beta, MKL_Complex16 *b, MKL_INT *jb, MKL_INT *ib,  MKL_Complex16 *c,  MKL_INT *jc,  MKL_INT *ic,  const MKL_INT *nnzmax,  MKL_INT *ierr);


/*Sparse BLAS Level2 (CSR-CSR or CSR-DNS) upper case */
void MKL_DCSRMULTCSR(const char *transa,  const MKL_INT *job,  const MKL_INT *sort,  const MKL_INT *m,  const MKL_INT *n,  const MKL_INT *k, double *a, MKL_INT *ja, MKL_INT *ia, double *b, MKL_INT *jb, MKL_INT *ib,  double *c,  MKL_INT *jc,  MKL_INT *ic,  const MKL_INT *nnzmax,  MKL_INT *ierr);
void MKL_DCSRMULTD(const char *transa,   const MKL_INT *m,  const MKL_INT *n,  const MKL_INT *k, double *a, MKL_INT *ja, MKL_INT *ia, double *b, MKL_INT *jb, MKL_INT *ib,  double *c,  MKL_INT *ldc);
void MKL_DCSRADD(const char *transa,  const MKL_INT *job,  const MKL_INT *sort,  const MKL_INT *m,  const MKL_INT *n, double *a, MKL_INT *ja, MKL_INT *ia, const double *beta, double *b, MKL_INT *jb, MKL_INT *ib,  double *c,  MKL_INT *jc,  MKL_INT *ic,  const MKL_INT *nnzmax,  MKL_INT *ierr);

void MKL_SCSRMULTCSR(const char *transa,  const MKL_INT *job,  const MKL_INT *sort,  const MKL_INT *m,  const MKL_INT *n,  const MKL_INT *k, float *a, MKL_INT *ja, MKL_INT *ia, float *b, MKL_INT *jb, MKL_INT *ib,  float *c,  MKL_INT *jc,  MKL_INT *ic,  const MKL_INT *nnzmax,  MKL_INT *ierr);
void MKL_SCSRMULTD(const char *transa,   const MKL_INT *m,  const MKL_INT *n,  const MKL_INT *k, float *a, MKL_INT *ja, MKL_INT *ia, float *b, MKL_INT *jb, MKL_INT *ib,  float *c,  MKL_INT *ldc);
void MKL_SCSRADD(const char *transa,  const MKL_INT *job,  const MKL_INT *sort,  const MKL_INT *m,  const MKL_INT *n, float *a, MKL_INT *ja, MKL_INT *ia,  const float *beta, float *b, MKL_INT *jb, MKL_INT *ib,  float *c,  MKL_INT *jc,  MKL_INT *ic,  const MKL_INT *nnzmax,  MKL_INT *ierr);

void MKL_CCSRMULTCSR(const char *transa,  const MKL_INT *job,  const MKL_INT *sort,  const MKL_INT *m,  const MKL_INT *n,  const MKL_INT *k, MKL_Complex8 *a, MKL_INT *ja, MKL_INT *ia, MKL_Complex8 *b, MKL_INT *jb, MKL_INT *ib,  MKL_Complex8 *c,  MKL_INT *jc,  MKL_INT *ic,  const MKL_INT *nnzmax,  MKL_INT *ierr);
void MKL_CCSRMULTD(const char *transa,   const MKL_INT *m,  const MKL_INT *n,  const MKL_INT *k, MKL_Complex8 *a, MKL_INT *ja, MKL_INT *ia, MKL_Complex8 *b, MKL_INT *jb, MKL_INT *ib,  MKL_Complex8 *c,  MKL_INT *ldc);
void MKL_CCSRADD(const char *transa,  const MKL_INT *job,  const MKL_INT *sort,  const MKL_INT *m,  const MKL_INT *n, MKL_Complex8 *a, MKL_INT *ja, MKL_INT *ia,  const MKL_Complex8 *beta, MKL_Complex8 *b, MKL_INT *jb, MKL_INT *ib,  MKL_Complex8 *c,  MKL_INT *jc,  MKL_INT *ic,  const MKL_INT *nnzmax,  MKL_INT *ierr);

void MKL_ZCSRMULTCSR(const char *transa,  const MKL_INT *job,  const MKL_INT *sort,  const MKL_INT *m,  const MKL_INT *n,  const MKL_INT *k, MKL_Complex16 *a, MKL_INT *ja, MKL_INT *ia, MKL_Complex16 *b, MKL_INT *jb, MKL_INT *ib,  MKL_Complex16 *c,  MKL_INT *jc,  MKL_INT *ic,  const MKL_INT *nnzmax,  MKL_INT *ierr);
void MKL_ZCSRMULTD(const char *transa,   const MKL_INT *m,  const MKL_INT *n,  const MKL_INT *k, MKL_Complex16 *a, MKL_INT *ja, MKL_INT *ia, MKL_Complex16 *b, MKL_INT *jb, MKL_INT *ib,  MKL_Complex16 *c,  MKL_INT *ldc);
void MKL_ZCSRADD(const char *transa,  const MKL_INT *job,  const MKL_INT *sort,  const MKL_INT *m,  const MKL_INT *n, MKL_Complex16 *a, MKL_INT *ja, MKL_INT *ia,  const MKL_Complex16 *beta, MKL_Complex16 *b, MKL_INT *jb, MKL_INT *ib,  MKL_Complex16 *c,  MKL_INT *jc,  MKL_INT *ic,  const MKL_INT *nnzmax,  MKL_INT *ierr);

#ifdef __cplusplus
}
#endif /*__cplusplus */

#endif /*_MKL_SPBLAS_H_ */
