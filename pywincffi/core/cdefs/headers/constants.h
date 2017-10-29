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
#define STILL_ACTIVE ...

// TH32CS
#define TH32CS_INHERIT ...
#define TH32CS_SNAPALL ...
#define TH32CS_SNAPHEAPLIST ...
#define TH32CS_SNAPMODULE ...
#define TH32CS_SNAPMODULE32 ...
#define TH32CS_SNAPPROCESS ...
#define TH32CS_SNAPTHREAD ...

// Process creation flags
// https://msdn.microsoft.com/en-us/library/ms684863
#define CREATE_BREAKAWAY_FROM_JOB ...
#define CREATE_DEFAULT_ERROR_MODE ...
#define CREATE_NEW_CONSOLE ...
#define CREATE_NEW_PROCESS_GROUP ...
#define CREATE_NO_WINDOW ...
#define CREATE_PROTECTED_PROCESS ...
#define CREATE_PRESERVE_CODE_AUTHZ_LEVEL ...
#define CREATE_SEPARATE_WOW_VDM ...
#define CREATE_SHARED_WOW_VDM ...
#define CREATE_SUSPENDED ...
#define CREATE_UNICODE_ENVIRONMENT ...
#define DEBUG_ONLY_THIS_PROCESS ...
#define DEBUG_PROCESS ...
#define DETACHED_PROCESS ...
#define EXTENDED_STARTUPINFO_PRESENT ...
#define INHERIT_PARENT_AFFINITY ...

// Process creation flags for priority
// https://msdn.microsoft.com/en-us/library/ms683211
#define ABOVE_NORMAL_PRIORITY_CLASS ...
#define BELOW_NORMAL_PRIORITY_CLASS ...
#define HIGH_PRIORITY_CLASS ...
#define IDLE_PRIORITY_CLASS ...
#define NORMAL_PRIORITY_CLASS ...
#define REALTIME_PRIORITY_CLASS ...

// Return values of WaitForSingleObject
// https://msdn.microsoft.com/en-us/library/ms687032
#define WAIT_ABANDONED ...
#define WAIT_ABANDONED_0 ...
#define WAIT_OBJECT_0 ...
#define WAIT_TIMEOUT ...
#define WAIT_FAILED ...
#define INFINITE ...

// Flags for pywincffi.kernel32.io (may be shared with other modules too)
#define SYNCHRONIZE ...
#define FILE_GENERIC_READ ...
#define FILE_GENERIC_WRITE ...
#define FILE_GENERIC_EXECUTE ...
#define FILE_ADD_FILE ...
#define FILE_ADD_SUBDIRECTORY ...
#define FILE_ALL_ACCESS ...
#define FILE_APPEND_DATA ...
#define FILE_CREATE_PIPE_INSTANCE ...
#define FILE_DELETE_CHILD ...
#define FILE_EXECUTE ...
#define FILE_LIST_DIRECTORY ...
#define FILE_READ_ATTRIBUTES ...
#define FILE_READ_DATA ...
#define FILE_READ_EA ...
#define FILE_TRAVERSE ...
#define FILE_WRITE_ATTRIBUTES ...
#define FILE_WRITE_DATA ...
#define FILE_WRITE_EA ...
#define FILE_SHARE_DELETE ...
#define FILE_SHARE_READ ...
#define FILE_SHARE_WRITE ...
#define FILE_ATTRIBUTE_ARCHIVE ...
#define FILE_ATTRIBUTE_ENCRYPTED ...
#define FILE_ATTRIBUTE_HIDDEN ...
#define FILE_ATTRIBUTE_NORMAL ...
#define FILE_ATTRIBUTE_OFFLINE ...
#define FILE_ATTRIBUTE_READONLY ...
#define FILE_ATTRIBUTE_SYSTEM ...
#define FILE_ATTRIBUTE_TEMPORARY ...
#define FILE_FLAG_BACKUP_SEMANTICS ...
#define FILE_FLAG_DELETE_ON_CLOSE ...
#define FILE_FLAG_NO_BUFFERING ...
#define FILE_FLAG_OPEN_NO_RECALL ...
#define FILE_FLAG_OPEN_REPARSE_POINT ...
#define FILE_FLAG_OVERLAPPED ...
#define FILE_FLAG_POSIX_SEMANTICS ...
#define FILE_FLAG_RANDOM_ACCESS ...
#define FILE_FLAG_SESSION_AWARE ...
#define FILE_FLAG_SEQUENTIAL_SCAN ...
#define FILE_FLAG_WRITE_THROUGH ...
#define CREATE_ALWAYS ...
#define CREATE_NEW ...
#define OPEN_ALWAYS ...
#define OPEN_EXISTING ...
#define TRUNCATE_EXISTING ...

// Flags for pywincffi.kernel32.pipe (may be shared with other modules too)
#define PIPE_TYPE_MESSAGE ...
#define PIPE_READMODE_BYTE ...
#define PIPE_READMODE_MESSAGE ...
#define PIPE_WAIT ...
#define PIPE_NOWAIT ...
#define PIPE_CLIENT_END ...
#define PIPE_SERVER_END ...
#define PIPE_TYPE_BYTE ...
#define PIPE_TYPE_MESSAGE ...

// Flags for pywincffi.kernel32.handle
#define HANDLE_FLAG_INHERIT ...
#define HANDLE_FLAG_PROTECT_FROM_CLOSE ...
#define DUPLICATE_CLOSE_SOURCE ...
#define DUPLICATE_SAME_ACCESS ...

// Flags for MoveFileEx
#define MOVEFILE_COPY_ALLOWED ...
#define MOVEFILE_CREATE_HARDLINK ...
#define MOVEFILE_DELAY_UNTIL_REBOOT ...
#define MOVEFILE_FAIL_IF_NOT_TRACKABLE ...
#define MOVEFILE_REPLACE_EXISTING ...
#define MOVEFILE_WRITE_THROUGH ...

// Flags for LockFileEx
#define LOCKFILE_EXCLUSIVE_LOCK ...
#define LOCKFILE_FAIL_IMMEDIATELY ...

// General security
#define SECURITY_ANONYMOUS ...
#define SECURITY_CONTEXT_TRACKING ...
#define SECURITY_DELEGATION ...
#define SECURITY_EFFECTIVE_ONLY ...
#define SECURITY_IDENTIFICATION ...
#define SECURITY_IMPERSONATION ...
#define STANDARD_RIGHTS_READ ...
#define STANDARD_RIGHTS_WRITE ...
#define GENERIC_ALL ...
#define GENERIC_READ ...
#define GENERIC_WRITE ...

// Errors
#define ERROR_INVALID_HANDLE ...
#define ERROR_INVALID_PARAMETER ...
#define ERROR_ACCESS_DENIED ...
#define ERROR_ALREADY_EXISTS ...
#define ERROR_NOT_SAME_DEVICE ...
#define ERROR_SHARING_VIOLATION ...
#define ERROR_FILE_EXISTS ...
#define ERROR_FILE_NOT_FOUND ...
#define ERROR_PATH_NOT_FOUND ...
#define ERROR_IO_PENDING ...

// Events
#define DELETE ...
#define READ_CONTROL ...
#define WRITE_DAC ...
#define WRITE_OWNER ...
#define EVENT_ALL_ACCESS ...
#define EVENT_MODIFY_STATE ...
#define MUTEX_ALL_ACCESS ...
#define MUTEX_MODIFY_STATE ...
#define SEMAPHORE_ALL_ACCESS ...
#define SEMAPHORE_MODIFY_STATE ...
#define TIMER_ALL_ACCESS ...
#define TIMER_MODIFY_STATE ...
#define TIMER_QUERY_STATE ...

// STARTUPINFO
// https://msdn.microsoft.com/en-us/library/ms686331
#define STARTF_FORCEONFEEDBACK ...
#define STARTF_FORCEOFFFEEDBACK ...
#define STARTF_PREVENTPINNING ...
#define STARTF_RUNFULLSCREEN ...
#define STARTF_TITLEISAPPID ...
#define STARTF_TITLEISLINKNAME ...
#define STARTF_UNTRUSTEDSOURCE ...
#define STARTF_USECOUNTCHARS ...
#define STARTF_USEFILLATTRIBUTE ...
#define STARTF_USEHOTKEY ...
#define STARTF_USEPOSITION ...
#define STARTF_USESHOWWINDOW ...
#define STARTF_USESIZE ...
#define STARTF_USESTDHANDLES ...

// ClearCommError
#define CE_BREAK ...
#define CE_FRAME ...
#define CE_OVERRUN ...
#define CE_RXOVER ...
#define CE_RXPARITY ...
#define CE_DNS ...
#define CE_IOE ...
#define CE_MODE ...
#define CE_OOP ...
#define CE_PTO ...
#define CE_TXFULL ...

// MsgWaitForMultipleObjects
#define MAXIMUM_WAIT_OBJECTS ...
#define QS_ALLEVENTS ...
#define QS_ALLINPUT ...
#define QS_ALLPOSTMESSAGE ...
#define QS_HOTKEY ...
#define QS_INPUT ...
#define QS_KEY ...
#define QS_MOUSE ...
#define QS_MOUSEBUTTON ...
#define QS_MOUSEMOVE ...
#define QS_PAINT ...
#define QS_POSTMESSAGE ...
#define QS_RAWINPUT ...
#define QS_SENDMESSAGE ...
#define QS_TIMER ...

// WSAEventSelect
// https://msdn.microsoft.com/en-us/library/ms741576
#define SOCKET_ERROR ...
#define FD_READ ...
#define FD_WRITE ...
#define FD_OOB ...
#define FD_ACCEPT ...
#define FD_CONNECT ...
#define FD_CLOSE ...
#define FD_QOS ...
#define FD_GROUP_QOS ...
#define FD_ROUTING_INTERFACE_CHANGE ...
#define FD_ADDRESS_LIST_CHANGE ...
#define FD_MAX_EVENTS ...

// Windows socket error codes
// https://msdn.microsoft.com/en-us/library/ms740668
#define WSA_INVALID_HANDLE ...
#define WSA_NOT_ENOUGH_MEMORY ...
#define WSA_INVALID_PARAMETER ...
#define WSA_OPERATION_ABORTED ...
#define WSA_IO_INCOMPLETE ...
#define WSA_IO_PENDING ...
#define WSAEINTR ...
#define WSAEBADF ...
#define WSAEACCES ...
#define WSAEFAULT ...
#define WSAEINVAL ...
#define WSAEMFILE ...
#define WSAEWOULDBLOCK ...
#define WSAEINPROGRESS ...
#define WSAEALREADY ...
#define WSAENOTSOCK ...
#define WSAEDESTADDRREQ ...
#define WSAEMSGSIZE ...
#define WSAEPROTOTYPE ...
#define WSAENOPROTOOPT ...
#define WSAEPROTONOSUPPORT ...
#define WSAESOCKTNOSUPPORT ...
#define WSAEOPNOTSUPP ...
#define WSAEPFNOSUPPORT ...
#define WSAEAFNOSUPPORT ...
#define WSAEADDRINUSE ...
#define WSAEADDRNOTAVAIL ...
#define WSAENETDOWN ...
#define WSAENETUNREACH ...
#define WSAENETRESET ...
#define WSAECONNABORTED ...
#define WSAECONNRESET ...
#define WSAENOBUFS ...
#define WSAEISCONN ...
#define WSAENOTCONN ...
#define WSAESHUTDOWN ...
#define WSAETOOMANYREFS ...
#define WSAETIMEDOUT ...
#define WSAECONNREFUSED ...
#define WSAELOOP ...
#define WSAENAMETOOLONG ...
#define WSAEHOSTDOWN ...
#define WSAEHOSTUNREACH ...
#define WSAENOTEMPTY ...
#define WSAEPROCLIM ...
#define WSAEUSERS ...
#define WSAEDQUOT ...
#define WSAESTALE ...
#define WSAEREMOTE ...
#define WSASYSNOTREADY ...
#define WSAVERNOTSUPPORTED ...
#define WSANOTINITIALISED ...
#define WSAEDISCON ...
#define WSAENOMORE ...
#define WSAECANCELLED ...
#define WSAEINVALIDPROCTABLE ...
#define WSAEINVALIDPROVIDER ...
#define WSAEPROVIDERFAILEDINIT ...
#define WSASYSCALLFAILURE ...
#define WSASERVICE_NOT_FOUND ...
#define WSATYPE_NOT_FOUND ...
#define WSA_E_NO_MORE ...
#define WSA_E_CANCELLED ...
#define WSAEREFUSED ...
#define WSAHOST_NOT_FOUND ...
#define WSATRY_AGAIN ...
#define WSANO_RECOVERY ...
#define WSANO_DATA ...
#define WSA_QOS_RECEIVERS ...
#define WSA_QOS_SENDERS ...
#define WSA_QOS_NO_SENDERS ...
#define WSA_QOS_NO_RECEIVERS ...
#define WSA_QOS_REQUEST_CONFIRMED ...
#define WSA_QOS_ADMISSION_FAILURE ...
#define WSA_QOS_POLICY_FAILURE ...
#define WSA_QOS_BAD_STYLE ...
#define WSA_QOS_BAD_OBJECT ...
#define WSA_QOS_TRAFFIC_CTRL_ERROR ...
#define WSA_QOS_GENERIC_ERROR ...
#define WSA_QOS_ESERVICETYPE ...
#define WSA_QOS_EFLOWSPEC ...
#define WSA_QOS_EPROVSPECBUF ...
#define WSA_QOS_EFILTERSTYLE ...
#define WSA_QOS_EFILTERTYPE ...
#define WSA_QOS_EFILTERCOUNT ...
#define WSA_QOS_EOBJLENGTH ...
#define WSA_QOS_EFLOWCOUNT ...
#define WSA_QOS_EUNKOWNPSOBJ ...
#define WSA_QOS_EPOLICYOBJ ...
#define WSA_QOS_EFLOWDESC ...
#define WSA_QOS_EPSFLOWSPEC ...
#define WSA_QOS_EPSFILTERSPEC ...
#define WSA_QOS_ESDMODEOBJ ...
#define WSA_QOS_ESHAPERATEOBJ ...
#define WSA_QOS_RESERVED_PETYPE ...

// Console
#define CONSOLE_TEXTMODE_BUFFER ...

// see https://docs.microsoft.com/en-us/windows/console/console-screen-buffers#_win32_font_attributes
#define FOREGROUND_RED ...
#define FOREGROUND_GREEN ...
#define FOREGROUND_BLUE ...
#define BACKGROUND_RED ...
#define BACKGROUND_GREEN ...
#define BACKGROUND_BLUE ...
#define FOREGROUND_INTENSITY ...
#define BACKGROUND_INTENSITY ...
#define COMMON_LVB_LEADING_BYTE ...
#define COMMON_LVB_TRAILING_BYTE ...
#define COMMON_LVB_GRID_HORIZONTAL ...
#define COMMON_LVB_GRID_LVERTICAL ...
#define COMMON_LVB_GRID_RVERTICAL ...
#define COMMON_LVB_REVERSE_VIDEO ...
#define COMMON_LVB_UNDERSCORE ...

// For the moment, we can't define this here.  When cffi
// parses the header this returns -1 and cffi seems to
// only handle positive integers right now.
//#define INVALID_HANDLE_VALUE ...
