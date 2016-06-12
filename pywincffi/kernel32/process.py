"""
Process
-------

Provides functions, constants and utilities that wrap the Windows
functions associated with process management and interaction.  This
module also provides several constants as well, see Microsoft's
documentation for the constant names and their purpose:

    * **Process Security and Access Rights** -
      https://msdn.microsoft.com/en-us/library/windows/desktop/ms684880

.. note::

    Not all constants may be defined
"""

from six import integer_types, text_type

from pywincffi.core import dist
from pywincffi.core.checks import NoneType, Enums, input_check, error_check
from pywincffi.exceptions import (
    WindowsAPIError, PyWinCFFINotImplementedError, InputError)
from pywincffi.kernel32.handle import CloseHandle
from pywincffi.kernel32.synchronization import WaitForSingleObject
from pywincffi.wintypes import (
    HANDLE, SECURITY_ATTRIBUTES, STARTUPINFO, wintype_to_cdata)

RESERVED_PIDS = set([0, 4])


def pid_exists(pid, wait=0):
    """
    Returns True if there's a process associated with ``pid``.

    :param int pid:
        The id of the process to check for.

    :keyword int wait:
        An optional keyword that controls how long we tell
        :func:`WaitForSingleObject` to wait on the process.

    :raises ValidationError:
        Raised if there's a problem with the value provided for ``pid``.
    """
    input_check("pid", pid, integer_types)

    # Process IDs which always exist shouldn't need to continue
    # further.
    if pid in RESERVED_PIDS:
        return True

    _, library = dist.load()

    try:
        hProcess = OpenProcess(
            library.PROCESS_QUERY_INFORMATION | library.SYNCHRONIZE,
            False, pid)

    except WindowsAPIError as error:
        # If we can't access the process then it must exist
        # otherwise there would be nothing to access.  We
        # reach this bit of code if the pid in question
        # is owned by another user or the system and
        # the process running this code does not have the
        # rights to query the other process's information.
        if error.errno == library.ERROR_ACCESS_DENIED:
            return True

        # Sometimes the PID we're asking about no longer exists
        # in the stack anywhere so we'll get ERROR_INVALID_PARAMETER
        # so there's not any reason to continue further.
        if error.errno == library.ERROR_INVALID_PARAMETER:
            return False

        raise

    try:
        process_exit_code = GetExitCodeProcess(hProcess)

        # Process may or may not still be running.  If process_exit_code
        # seem to indicate the process is still alive then run one
        # last check to be certain.
        if process_exit_code == library.STILL_ACTIVE:
            wait_result = WaitForSingleObject(hProcess, wait)

            # The process was still running.
            if wait_result == library.WAIT_TIMEOUT:
                return True

            # The process exited while we were waiting
            # on it so it no longer exists.
            elif wait_result == library.WAIT_OBJECT_0:
                return False

            elif wait_result == library.WAIT_ABANDONED:
                raise PyWinCFFINotImplementedError(
                    "An unknown error occurred while running "
                    "pid_exists(%r).  It appears that the call to "
                    "WaitForSingleObject may be been terminated." % pid)

            else:
                raise PyWinCFFINotImplementedError(
                    "Unhandled result from "
                    "WaitForSingleObject(): %r" % wait_result)

        return False

    finally:
        CloseHandle(hProcess)


def GetExitCodeProcess(hProcess):
    """
    Retrieves the exit code of the given process handle.  To retrieve
    a process handle use :func:`OpenProcess`.

    .. warning::

        You may want to use :func:`process_exit_code` instead of this
        function if you're just checking to see if a process has
        exited at all.

    .. seealso::

        https://msdn.microsoft.com/en-us/library/ms683189

    :param pywincffi.wintypes.HANDLE hProcess:
        The handle of the process to retrieve the exit code for.

    :returns:
        Returns the exit code of the requested process if one
        can be found.
    """
    input_check("hProcess", hProcess, HANDLE)

    ffi, library = dist.load()
    lpExitCode = ffi.new("LPDWORD")
    code = library.GetExitCodeProcess(wintype_to_cdata(hProcess), lpExitCode)
    error_check("GetExitCodeProcess", code=code, expected=Enums.NON_ZERO)
    return lpExitCode[0]


def OpenProcess(dwDesiredAccess, bInheritHandle, dwProcessId):
    """
    Opens an existing local process object.

    .. seealso::

        https://msdn.microsoft.com/en-us/library/ms684320

    :param int dwDesiredAccess:
        The required access to the process object.

    :param bool bInheritHandle:
        Enables or disable handle inheritance for child processes.

    :param int dwProcessId:
        The id of the local process to be opened.

    :returns:
        Returns a :class:`pywincffi.wintypes.HANDLE` to the opened process.
        This value can be used by other functions such as
        :func:`TerminateProcess`.
    """
    input_check("dwDesiredAccess", dwDesiredAccess, integer_types)
    input_check("bInheritHandle", bInheritHandle, bool)
    input_check("dwProcessId", dwProcessId, integer_types)
    ffi, library = dist.load()

    handle = library.OpenProcess(
        ffi.cast("DWORD", dwDesiredAccess),
        ffi.cast("BOOL", bInheritHandle),
        ffi.cast("DWORD", dwProcessId)
    )
    error_check("OpenProcess")
    return HANDLE(handle)


def GetCurrentProcess():
    """
    Returns a handle to the current thread.

    .. seealso::

        https://msdn.microsoft.com/en-us/library/ms683179

    .. note::

        Calling :func:`pywincffi.kernel32.handle.CloseHandle` on the handle
        produced by this function will produce an exception.

    :returns:
        The :class:`pywincffi.wintypes.HANDLE` to the current process.
    """
    _, library = dist.load()
    return HANDLE(library.GetCurrentProcess())


def GetProcessId(Process):  # pylint: disable=invalid-name
    """
    Returns the pid of the process handle provided in ``Process``.

    .. seealso::

        https://msdn.microsoft.com/en-us/library/ms683215

    :param pywincffi.wintypes.HANDLE Process:
        The handle of the process.

    :return:
        Returns an integer which represents the pid of the given
        process handle.
    """
    input_check("Process", Process, HANDLE)
    _, library = dist.load()
    pid = library.GetProcessId(wintype_to_cdata(Process))
    error_check("GetProcessId")
    return pid


def TerminateProcess(hProcess, uExitCode):
    """
    Terminates the specified process and all of its threads.

    .. seealso::

        https://msdn.microsoft.com/en-us/library/ms686714

    :param pywincffi.wintypes.HANDLE hProcess:
        A handle to the process to be terminated.

    :param int uExitCode:
        The exit code of the processes and threads as a result of calling
        this function.
    """
    input_check("hProcess", hProcess, HANDLE)
    input_check("uExitCode", uExitCode, integer_types)
    ffi, library = dist.load()
    code = library.TerminateProcess(
        wintype_to_cdata(hProcess),
        ffi.cast("UINT", uExitCode)
    )
    error_check("TerminateProcess", code=code, expected=Enums.NON_ZERO)


def CreateProcess(  # pylint: disable=too-many-arguments
        lpCommandLine, lpApplicationName=None, lpProcessAttributes=None,
        lpThreadAttributes=None, bInheritHandles=True, dwCreationFlags=None,
        lpEnvironment=None, lpCurrentDirectory=None, lpStartupInfo=None):
    """
    Creates a new process and its primary thread.  The process will be
    created in the same security context as the original process.

    .. seealso::

        https://msdn.microsoft.com/en-us/library/ms682425

    :param str lpCommandLine:
        The command line to be executed.  The maximum length of this parameter
        is 32768.

    :param pywincffi.wintypes.STARTUPINFO lpStartupInfo:
        A :class:`pywincffi.wintypes.STARTUPINFO` instance.  See Microsoft's
        documentation for additional information.

    :keyword str lpApplicationName:
        The name of the module or application to be executed.  This can be
        either the fully qualified path name or a partial name.  The system
        path will not be searched.  If no value is provided for this keyword
        then the input to ``lpCommandLine`` will be used by Windows instead.

    :keyword pywincffi.wintypes.SECUREITY_ATTRIBUTES lpProcessAttributes:
        Determines whether the returned handle to the new process object
        can be inherited by child processes.  By default, the handle cannot be
        inherited.

    :keyword pywincffi.wintypes.SECUREITY_ATTRIBUTES lpThreadAttributes:
        Determines if the returned handle to the new thread object can
        be inherited by child processes.  By default, the thread cannot be
        inherited.

    :keyword bool bInheritHandles:
        If True (the default) the handles inherited by the calling process
        are inherited by the new process.

    :keyword int dwCreationFlags:
        Controls the priority class and creation of the process.  By default
        the process will flag will default to ``NORMAL_PRIORITY_CLASS``

    :keyword dict lpEnvironment:
        The environment for the new process.  By default the the process
        will be created with the same environment as the parent process.

    :keyword str lpCurrentDirectory:
        The full path to the current directory for the process.  If not
         provided then the process will have the same working directory
         as the parent process.

    :raises InputError:
        Raised if ``lpCommandLine`` is longer than 32768 characters or there
        are other input issues.

    """
    ffi, library = dist.load()

    # The command line length cannot exceed this value according
    # to Microsoft's documentation.
    if len(lpCommandLine) > 32768:
        raise InputError(
            "lpCommandLine", lpCommandLine, text_type,
            message="lpCommandLine's length cannot exceed 32768")

    input_check(
        "lpApplicationName", lpApplicationName,
        allowed_types=(NoneType, text_type))
    input_check(
        "lpStartupInfo", lpStartupInfo,
        allowed_types=(NoneType, STARTUPINFO))
    input_check(
        "lpProcessAttributes", lpProcessAttributes,
        allowed_types=(NoneType, SECURITY_ATTRIBUTES))
    input_check(
        "lpThreadAttributes", lpThreadAttributes,
        allowed_types=(NoneType, SECURITY_ATTRIBUTES))
    input_check(
        "bInheritHandles", bInheritHandles,
        allowed_values=(True, False))
    input_check(
        "dwCreationFlags", dwCreationFlags,
        allowed_types=(NoneType, integer_types))
    input_check(
        "lpEnvironment", lpEnvironment,
        allowed_types=(NoneType, dict))
    input_check(
        "lpCurrentDirectory", lpCurrentDirectory,
        allowed_types=(NoneType, text_type))

    if lpApplicationName is None:
        lpApplicationName = ffi.NULL

    if lpProcessAttributes is None:
        lpProcessAttributes = ffi.NULL
    else:
        lpProcessAttributes = wintype_to_cdata(lpThreadAttributes)

    if lpThreadAttributes is None:
        lpThreadAttributes = ffi.NULL
    else:
        lpThreadAttributes = wintype_to_cdata(lpThreadAttributes)

    if dwCreationFlags is None:
        dwCreationFlags = library.NORMAL_PRIORITY_CLASS

    if lpEnvironment is None:
        lpEnvironment = ffi.NULL

    # TODO: conversion to Microsoft's format
    if isinstance(lpEnvironment, dict):
        pass

    if lpCurrentDirectory is None:
        lpCurrentDirectory = ffi.NULL

    # bInheritHandles = ffi.cast("BOOL", bInheritHandles)
    # dwCreationFlags = ffi.cast("DWORD", dwCreationFlags)
