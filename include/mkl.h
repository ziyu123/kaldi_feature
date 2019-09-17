/*******************************************************************************
!   Copyright(C) 1999-2015 Intel Corporation. All Rights Reserved.
!
!   The source code, information  and  material ("Material") contained herein is
!   owned  by Intel Corporation or its suppliers or licensors, and title to such
!   Material remains  with Intel Corporation  or its suppliers or licensors. The
!   Material  contains proprietary information  of  Intel or  its  suppliers and
!   licensors. The  Material is protected by worldwide copyright laws and treaty
!   provisions. No  part  of  the  Material  may  be  used,  copied, reproduced,
!   modified, published, uploaded, posted, transmitted, distributed or disclosed
!   in any way  without Intel's  prior  express written  permission. No  license
!   under  any patent, copyright  or  other intellectual property rights  in the
!   Material  is  granted  to  or  conferred  upon  you,  either  expressly,  by
!   implication, inducement,  estoppel or  otherwise.  Any  license  under  such
!   intellectual  property  rights must  be express  and  approved  by  Intel in
!   writing.
!
!   *Third Party trademarks are the property of their respective owners.
!
!   Unless otherwise  agreed  by Intel  in writing, you may not remove  or alter
!   this  notice or  any other notice embedded  in Materials by Intel or Intel's
!   suppliers or licensors in any way.
!
!*******************************************************************************
!  Content:
!      Intel(R) Math Kernel Library (MKL) interface
!******************************************************************************/

#ifndef _MKL_H_
#define _MKL_H_

#define __INTEL_MKL_BUILD_DATE 20150409

#define __INTEL_MKL__ 11
#define __INTEL_MKL_MINOR__ 2
#define __INTEL_MKL_UPDATE__ 3

#define INTEL_MKL_VERSION (__INTEL_MKL__ * 10000 + \
        __INTEL_MKL_MINOR__ * 100 + __INTEL_MKL_UPDATE__)

#define _Mkl_Api(rtype,name,arg) extern rtype name    arg;
#define _mkl_api(rtype,name,arg) extern rtype name##_ arg;
#define _MKL_API(rtype,name,arg) extern rtype name##_ arg;

#include "mkl_types.h"
#include "mkl_blas.h"
#include "mkl_trans.h"
#include "mkl_cblas.h"
#include "mkl_spblas.h"
#include "mkl_lapack.h"
#include "mkl_lapacke.h"
#include "mkl_solver.h"
#include "mkl_pardiso.h"
#include "mkl_sparse_handle.h"
#include "mkl_dss.h"
#include "mkl_rci.h"
#include "mkl_vml.h"
#include "mkl_vsl.h"
#include "mkl_df.h"
#include "mkl_service.h"
#include "mkl_dfti.h"
#include "mkl_trig_transforms.h"
#include "mkl_poisson.h"
#include "mkl_solvers_ee.h"
#include "mkl_direct_call.h"

#endif /* _MKL_H_ */
