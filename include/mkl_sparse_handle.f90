!*******************************************************************************
!   Copyright(C) 2004-2015 Intel Corporation. All Rights Reserved.
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
!   Content : MKL DSS Fortran header file
!
!           Contains more detailed information on internal datatypes and
!           constants used by DSS interface to PARDISO.
!
!*******************************************************************************

      MODULE MKL_SPARSE_CHECK

      USE, INTRINSIC :: ISO_C_BINDING, ONLY : C_INTPTR_T
      
      ENUM, BIND(C)
          ENUMERATOR :: MKL_ZERO_BASED, MKL_ONE_BASED
      END ENUM

      ENUM, BIND(C)
          ENUMERATOR :: MKL_C_STYLE, MKL_FORTRAN_STYLE
      END ENUM

      ENUM, BIND(C)
          ENUMERATOR :: MKL_NO_PRINT, MKL_PRINT
      END ENUM

      ENUM, BIND(C)
          ENUMERATOR :: MKL_GENERAL_STRUCTURE, MKL_UPPER_TRIANGULAR, MKL_LOWER_TRIANGULAR, MKL_STRUCTURAL_SYMMETRIC
      END ENUM
      
      ENUM, BIND(C)
          ENUMERATOR :: MKL_CSR
      END ENUM

      TYPE, BIND(C) :: SPARSE_STRUCT
          INTEGER N
          INTEGER (C_INTPTR_T) :: CSR_IA
          INTEGER (C_INTPTR_T) :: CSR_JA
          INTEGER CHECK_RESULT(3)
          INTEGER(KIND=4) INDEXING
          INTEGER(KIND=4) MATRIX_STRUCTURE
          INTEGER(KIND=4) MATRIX_FORMAT
          INTEGER(KIND=4) MESSAGE_LEVEL
          INTEGER(KIND=4) PRINT_STYLE
      END TYPE SPARSE_STRUCT

      INTERFACE

          FUNCTION sparse_matrix_checker(PT)
              IMPORT SPARSE_STRUCT
              TYPE(SPARSE_STRUCT), INTENT(INOUT) :: PT
              INTEGER sparse_matrix_checker
          END

          SUBROUTINE sparse_matrix_checker_init(PT)
              IMPORT SPARSE_STRUCT
              TYPE(SPARSE_STRUCT), INTENT(INOUT) :: PT
          END

      END INTERFACE

      END MODULE MKL_SPARSE_CHECK
