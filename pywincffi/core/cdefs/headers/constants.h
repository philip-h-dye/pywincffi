//
// This file contains constants which can be used either internally or
// by users of pywincffi.
//
// NOTE: The tests for this file, tests/test_core/test_cdefs/test_constants.py
//       depend on a constant's names to follow this format:
//           #define NAME ...
//

// General or system wide constants
#define MAX_PATH ...
#define STD_INPUT_HANDLE ...
#define STD_OUTPUT_HANDLE ...
#define STD_ERROR_HANDLE ...

// Flags for pywincffi.kernel32.process (may be shared with other modules too)
#define PROCESS_CREATE_PROCESS ...
#define PROCESS_CREATE_THREAD ...
#define PROCESS_DUP_HANDLE ...
#define PROCESS_QUERY_INFORMATION ...
#define PROCESS_QUERY_LIMITED_INFORMATION ...
#define PROCESS_SET_INFORMATION ...
#define PROCESS_SET_QUOTA ...
#define PROCESS_SUSPEND_RESUME ...
#define PROCESS_TERMINATE ...
#define PROCESS_VM_OPERATION ...
#define PROCESS_VM_READ ...
#define PROCESS_VM_WRITE ...

// Flags for pywincffi.kernel32.io (may be shared with other modules too)
#define SYNCHRONIZE ...
#define PIPE_TYPE_MESSAGE ...
#define PIPE_READMODE_BYTE ...
#define PIPE_READMODE_MESSAGE ...
#define PIPE_WAIT ...
#define PIPE_NOWAIT ...

// Errors
#define ERROR_INVALID_PARAMETER ...
#define ERROR_ACCESS_DENIED ...

// For the moment, we can't define this here.  When cffi
// parses the header this returns -1 and cffi seems to
// only handle positive integers right now.
//#define INVALID_HANDLE_VALUE ...
