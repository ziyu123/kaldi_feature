!*******************************************************************************
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
!      Intel(R) Math Kernel Library (Intel(R) MKL) Fortran 90 interface for
!	   Cluster Sparse Solver
!*******************************************************************************

!DEC$ IF .NOT. DEFINED( __MKL_CLUSTER_SPARSE_SOLVER_F90 )

!DEC$ DEFINE __MKL_CLUSTER_SPARSE_SOLVER_F90

      MODULE MKL_CLUSTER_SPARSE_SOLVER_PRIVATE
        TYPE MKL_CLUSTER_SPARSE_SOLVER_HANDLE; INTEGER(KIND=8) DUMMY; END TYPE
      END MODULE MKL_CLUSTER_SPARSE_SOLVER_PRIVATE

      MODULE MKL_CLUSTER_SPARSE_SOLVER
        USE MKL_CLUSTER_SPARSE_SOLVER_PRIVATE

!
! Subroutine prototype for CLUSTER_SPARSE_SOLVER
!

      INTERFACE
        SUBROUTINE CLUSTER_SPARSE_SOLVER(PT,MAXFCT,MNUM,MTYPE,PHASE,N,A,IA,JA,PERM,NRHS,IPARM,MSGLVL,B,X,COMM,ERROR)
          USE MKL_CLUSTER_SPARSE_SOLVER_PRIVATE
          TYPE(MKL_CLUSTER_SPARSE_SOLVER_HANDLE), INTENT(INOUT) :: PT(*)
          INTEGER,          INTENT(IN)    :: MAXFCT
          INTEGER,          INTENT(IN)    :: MNUM
          INTEGER,          INTENT(IN)    :: MTYPE
          INTEGER,          INTENT(IN)    :: PHASE
          INTEGER,          INTENT(IN)    :: N
          INTEGER,          INTENT(IN)    :: IA(*)
          INTEGER,          INTENT(IN)    :: JA(*)
          INTEGER,          INTENT(IN)    :: PERM(*)
          INTEGER,          INTENT(IN)    :: NRHS
          INTEGER,          INTENT(INOUT) :: IPARM(*)
          INTEGER,          INTENT(IN)    :: MSGLVL
          INTEGER,          INTENT(OUT)   :: ERROR
          REAL(KIND=8),     INTENT(IN)    :: A(*)
          REAL(KIND=8),     INTENT(INOUT) :: B(*)
          REAL(KIND=8),     INTENT(OUT)   :: X(*)
          INTEGER*4,          INTENT(IN)    :: COMM
        END SUBROUTINE CLUSTER_SPARSE_SOLVER
      END INTERFACE

      END MODULE MKL_CLUSTER_SPARSE_SOLVER

!DEC$ ENDIF
