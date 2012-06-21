!/***********************************************************************
!*                                                                      *
!*  Dummy mpif.h for occasional standalone compilations of MPL-lib only *
!*                                                                      *
!*  Modified from the original F77-version by Sami Saarinen, ECMWF      *
!*                                                                      *
!*  Date: 25-Jan-2001                                                   *
!*                                                                      *
!*                                                                      *
!/***********************************************************************
!

!/***********************************************************************
!*                                                                      *
!*   mpif.h                                                             *
!*   mpi for Win32                                                      *
!*   current version: 0.9                                               *
!*                                                                      *
!*   Jose Manuel Meireles Marinho                                       *
!*                                                                      *
!*   Instituto Superior de Engenharia de Coimbra (Portugal)             *
!*   University of Coimbra (Portugal) - Department of Computer Science  *
!*                                                                      *
!*   This is an MPI implementation for Win32                            *
!*   It is based on the MPICH implementation from Argonne               *
!*   National Laboratory and Mississippi State University,              *
!*   version 1.0.13. Note their COPYRIGHT.                              *
!*                                                                      *
!***********************************************************************/
!/* user include file for MPI programs, with no dependencies */
!
!/* return codes */
       integer MPI_SUCCESS,MPI_ERR_BUFFER,MPI_ERR_COUNT,MPI_ERR_TYPE, &
     & MPI_ERR_TAG,MPI_ERR_COMM,MPI_ERR_RANK,MPI_ERR_ROOT,MPI_ERR_GROUP, &
     & MPI_ERR_OP,MPI_ERR_TOPOLOGY,MPI_ERR_DIMS,MPI_ERR_ARG, &
     & MPI_ERR_UNKNOWN,MPI_ERR_TRUNCATE,MPI_ERR_OTHER,MPI_ERR_INTERN, &
     & MPI_ERR_IN_STATUS,MPI_ERR_PENDING,MPI_ERR_REQUEST, &
     & MPI_ERR_LASTCODE
       parameter (MPI_SUCCESS=0,MPI_ERR_BUFFER=1,MPI_ERR_COUNT=2, &
     & MPI_ERR_TYPE=3,MPI_ERR_TAG=4,MPI_ERR_COMM=5,MPI_ERR_RANK=6, &
     & MPI_ERR_ROOT=7,MPI_ERR_GROUP=8,MPI_ERR_OP=9,MPI_ERR_TOPOLOGY=10, &
     & MPI_ERR_DIMS=11,MPI_ERR_ARG=12,MPI_ERR_UNKNOWN=13, &
     & MPI_ERR_TRUNCATE=14,MPI_ERR_OTHER=15,MPI_ERR_INTERN=16, &
     & MPI_ERR_IN_STATUS=17,MPI_ERR_PENDING=18,MPI_ERR_REQUEST=19, &
     & MPI_ERR_LASTCODE=4114)
!
       integer MPI_UNDEFINED
       parameter (MPI_UNDEFINED = (-32766))
!
       INTEGER MPI_GRAPH, MPI_CART
       PARAMETER (MPI_GRAPH = 1, MPI_CART = 2)
       INTEGER  MPI_PROC_NULL
       PARAMETER ( MPI_PROC_NULL = (-1) )
!
       INTEGER MPI_BSEND_OVERHEAD
       PARAMETER ( MPI_BSEND_OVERHEAD = 512 )

      INTEGER MPI_SOURCE, MPI_TAG, MPI_ERROR
      PARAMETER(MPI_SOURCE=2, MPI_TAG=3, MPI_ERROR=4)
      INTEGER MPI_STATUS_SIZE
      PARAMETER (MPI_STATUS_SIZE=4)
      INTEGER MPI_MAX_PROCESSOR_NAME, MPI_MAX_ERROR_STRING
      PARAMETER (MPI_MAX_PROCESSOR_NAME=256, &
     &           MPI_MAX_ERROR_STRING=256)
!
      INTEGER MPI_COMM_NULL
      PARAMETER (MPI_COMM_NULL=0)
!
      INTEGER MPI_DATATYPE_NULL
      PARAMETER (MPI_DATATYPE_NULL = 0)

      INTEGER MPI_ERRHANDLER_NULL
      PARAMETER (MPI_ERRHANDLER_NULL = 0)

      INTEGER MPI_GROUP_NULL
      PARAMETER (MPI_GROUP_NULL = 0)

      INTEGER MPI_KEYVAL_INVALID
      PARAMETER (MPI_KEYVAL_INVALID = 0)

      INTEGER MPI_REQUEST_NULL
      PARAMETER (MPI_REQUEST_NULL = 0)
!
      INTEGER MPI_IDENT, MPI_CONGRUENT, MPI_SIMILAR, MPI_UNEQUAL
      PARAMETER (MPI_IDENT=0, MPI_CONGRUENT=1, MPI_SIMILAR=2, &
     &          MPI_UNEQUAL=3)
!
!     We handle datatypes by putting the variables that hold them into
!     common.  This way, a Fortran program can directly use the various
!     datatypes and can even give them to C programs.
!
!     MPI_BOTTOM needs to be a known address; here we put it at the
!     beginning of the common block.  The point-to-point and collective
!     routines know about MPI_BOTTOM, but MPI_TYPE_STRUCT as yet does not.
!
!     The types MPI_INTEGER1,2,4 and MPI_REAL4,8 are OPTIONAL.
!     Their values are zero if they are not available.  Note that
!     using these reduces the portability of code (though may enhance
!     portability between Crays and other systems)
!
      integer MPI_TAG_UB, MPI_HOST, MPI_IO
      integer MPI_BOTTOM, MPI_INTEGER, MPI_REAL, MPI_DOUBLE_PRECISION, &
     &        MPI_COMPLEX, MPI_DOUBLE_COMPLEX, &
     &        MPI_LOGICAL, MPI_CHARACTER, MPI_BYTE, &
     &        MPI_2INTEGER, MPI_2REAL, MPI_2DOUBLE_PRECISION, &
     &        MPI_2COMPLEX, MPI_2DOUBLE_COMPLEX, &
     &        MPI_INTEGER1, MPI_INTEGER2, MPI_INTEGER4, &
     &        MPI_REAL2, MPI_REAL4, MPI_REAL8, MPI_UB, MPI_LB, &
     &        MPI_PACKED, MPI_WTIME_IS_GLOBAL
      integer MPI_COMM_WORLD, MPI_COMM_SELF, MPI_GROUP_EMPTY
      integer MPI_SUM, MPI_MAX, MPI_MIN, MPI_PROD, MPI_LAND, MPI_BAND, &
     &     MPI_LOR, MPI_BOR, MPI_LXOR, MPI_BXOR, MPI_MINLOC, MPI_MAXLOC, &
     &     MPI_OP_NULL
      integer MPI_ERRORS_ARE_FATAL, MPI_ERRORS_RETURN
      common /mpipriv/ MPI_BOTTOM, MPI_INTEGER, MPI_REAL, &
     &     MPI_DOUBLE_PRECISION, &
     &     MPI_COMPLEX, MPI_DOUBLE_COMPLEX, &
     &     MPI_LOGICAL, MPI_CHARACTER, MPI_BYTE, &
     &     MPI_2INTEGER, MPI_2REAL, MPI_2DOUBLE_PRECISION, &
     &     MPI_2COMPLEX, MPI_2DOUBLE_COMPLEX, &
     &     MPI_INTEGER1, MPI_INTEGER2, MPI_INTEGER4, &
     &     MPI_REAL2, MPI_REAL4, MPI_REAL8, &
     &     MPI_UB, MPI_LB, &
     &     MPI_COMM_WORLD, MPI_COMM_SELF, MPI_GROUP_EMPTY, &
     &     MPI_SUM, MPI_MAX, MPI_MIN, MPI_PROD, MPI_LAND, MPI_BAND, &
     &     MPI_LOR, MPI_BOR, MPI_LXOR, MPI_BXOR, MPI_MINLOC, MPI_MAXLOC, &
     &     MPI_OP_NULL, &
     &     MPI_TAG_UB, MPI_HOST, MPI_IO, MPI_ERRORS_ARE_FATAL, &
     &     MPI_ERRORS_RETURN, MPI_PACKED, MPI_WTIME_IS_GLOBAL
!
!     Without this save, some Fortran implementations may make the common
!     dynamic!
!
      save /mpipriv/
!
      integer MPI_ANY_SOURCE
      parameter (MPI_ANY_SOURCE = (-2))
      integer MPI_ANY_TAG
      parameter (MPI_ANY_TAG = (-1))
!
!     All other MPI routines are subroutines
      double precision MPI_WTIME, MPI_WTICK
      external MPI_WTIME, MPI_WTICK
!
!     The attribute copy/delete functions are symbols that can be passed
!     to MPI routines
      external MPI_NULL_COPY_FN, MPI_NULL_DELETE_FN, MPI_DUP_FN
!
