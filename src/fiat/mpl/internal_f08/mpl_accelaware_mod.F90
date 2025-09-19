! (C) Copyright 2025- ECMWF.
! (C) Copyright 2025- Meteo-France.
! 
! This software is licensed under the terms of the Apache Licence Version 2.0
! which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
! In applying this licence, ECMWF does not waive the privileges and immunities
! granted to it by virtue of its status as an intergovernmental organisation
! nor does it submit to any jurisdiction.
!

MODULE MPL_ACCELAWARE_MOD

USE MPL_DATA_MODULE, ONLY : LMPL_ARGS_ON_DEVICE

IMPLICIT NONE

PUBLIC :: MPL_ASSUME_ARGS_ON_DEVICE, MPL_ASSUME_ARGS_ON_HOST, MPL_QUERY_ON_DEVICE_DEFAULT

CONTAINS 

SUBROUTINE MPL_ASSUME_ARGS_ON_DEVICE()
  LMPL_ARGS_ON_DEVICE = .TRUE.
END SUBROUTINE MPL_ASSUME_ARGS_ON_DEVICE

SUBROUTINE MPL_ASSUME_ARGS_ON_HOST()
  LMPL_ARGS_ON_DEVICE = .FALSE.
END SUBROUTINE MPL_ASSUME_ARGS_ON_HOST

LOGICAL FUNCTION MPL_QUERY_ON_DEVICE_DEFAULT()
  MPL_QUERY_ON_DEVICE_DEFAULT = LMPL_ARGS_ON_DEVICE
END FUNCTION MPL_QUERY_ON_DEVICE_DEFAULT

END MODULE MPL_ACCELAWARE_MOD
