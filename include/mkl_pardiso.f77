********************************************************************************
*   Copyright(C) 2004-2015 Intel Corporation. All Rights Reserved.
*
*   The source code, information  and  material ("Material") contained herein is
*   owned  by Intel Corporation or its suppliers or licensors, and title to such
*   Material remains  with Intel Corporation  or its suppliers or licensors. The
*   Material  contains proprietary information  of  Intel or  its  suppliers and
*   licensors. The  Material is protected by worldwide copyright laws and treaty
*   provisions. No  part  of  the  Material  may  be  used,  copied, reproduced,
*   modified, published, uploaded, posted, transmitted, distributed or disclosed
*   in any way  without Intel's  prior  express written  permission. No  license
*   under  any patent, copyright  or  other intellectual property rights  in the
*   Material  is  granted  to  or  conferred  upon  you,  either  expressly,  by
*   implication, inducement,  estoppel or  otherwise.  Any  license  under  such
*   intellectual  property  rights must  be express  and  approved  by  Intel in
*   writing.
*
*   *Third Party trademarks are the property of their respective owners.
*
*   Unless otherwise  agreed  by Intel  in writing, you may not remove  or alter
*   this  notice or  any other notice embedded  in Materials by Intel or Intel's
*   suppliers or licensors in any way.
*
********************************************************************************
*   Content : MKL PARDISO Fortran-77 header file.
*             This header file is obsolete. Use mkl_pardiso.f90 instead.
*
*           Contains PARDISO routine definition
*
********************************************************************************
      
      EXTERNAL PARDISO_GETENV
      INTEGER  PARDISO_GETENV
      
      EXTERNAL PARDISO_SETENV
      INTEGER  PARDISO_SETENV

      EXTERNAL PARDISO_HANDLE_DELETE
      EXTERNAL PARDISO_HANDLE_DELETE_64
      EXTERNAL PARDISO_HANDLE_STORE
      EXTERNAL PARDISO_HANDLE_STORE_64
      EXTERNAL PARDISO_HANDLE_RESTORE
      EXTERNAL PARDISO_HANDLE_RESTORE_64
      
      INTEGER PARDISO_OOC_FILE_NAME
      PARAMETER ( PARDISO_OOC_FILE_NAME = 1 )
