#ifndef _TRSDK_H
#define _TRSDK_H

// Totally TRSDK OFF default header file
#pragma message("[TRSDK] ++++++++++++++ TR/TREXE macro is totally turned OFF ++++++++++++++")

// IVIScramble
#define iviTR_CHECKSUM(val, start_addr, end_addr, seed) {}
#define iviTR_SCRAMBLE(start_addr, end_addr, seed) {}
#define iviTR_DESCRAMBLE(start_addr, end_addr, seed) {}

// Extended checksum routines.
#define CHECKSUM_INSERT1(val, REG1, REG2) 
#define CHECKSUM_INSERT2(val, REG1, REG2) 
#define CHECKSUM_INSERT3(val, REG1, REG2) 
#define CHECKSUM_INSERT4(val, REG1, REG2) 

#define iviTR_CHECKSUM_EXPRESS1(val) \
	CHECKSUM_INSERT1(val, ebx, esi)

#define iviTR_CHECKSUM1(val, start_addr, end_addr, seed) {}

#define iviTR_CHECKSUM_EXPRESS2(val) \
	CHECKSUM_INSERT2(val, eax, edi)

#define iviTR_CHECKSUM2(val, start_addr, end_addr, seed) {}

#define iviTR_CHECKSUM_EXPRESS3(val) \
	CHECKSUM_INSERT3(val, ebx, esi)

#define iviTR_CHECKSUM3(val, start_addr, end_addr, seed) {}

#define iviTR_CHECKSUM_EXPRESS4(val) \
	CHECKSUM_INSERT4(val, eax, edi)

#define iviTR_CHECKSUM4(val, start_addr, end_addr, seed) {}

#define iviTR_USE_CTR_MACRO_VERSION

#define iviTR_ChecksumRegion(start_addr, end_addr, seed, pval, pwTable) {}
#define iviTR_ChecksumRegion1(start_addr, end_addr, seed, pval, pwTable) {}
#define iviTR_ChecksumRegion2(start_addr, end_addr, seed, pval, pwTable) {}
#define iviTR_ChecksumRegion3(start_addr, end_addr, seed, pval, pwTable) {}
#define iviTR_ChecksumRegion4(start_addr, end_addr, seed, pval, pwTable) {}
#define iviTR_ScrambleRegion(start_addr, end_addr, seed, pwTable) {}
#define iviTR_DescrambleRegion(start_addr, end_addr, seed, pwTable) {}

#define iviTR_Lightweight_ScrambleRegion(start_addr, end_addr, seed, pwTable, pwScrambleEIPTable, scrambleEIPTableSize) {}
#define iviTR_Lightweight_DescrambleRegion(start_addr, end_addr, seed, pwTable, pwScrambleEIPTable, scrambleEIPTableSize) {}

#define DO_GETNEXTADDR(bSkipAddr,dwBase, pwTable) {}

#define DO_GETUNDOOFFSET  

#define DO_ISRELOCATED	1

#define DO_RELOCATECODE(start_addr, pwTable, bUndo) {}

#define DO_CHECKSUM(start_addr, end_addr, seed, pval, pwTable) {}
#define DO_CHECKSUM1(start_addr, end_addr, seed, pval, pwTable) {}
#define DO_CHECKSUM2(start_addr, end_addr, seed, pval, pwTable) {}
#define DO_CHECKSUM3(start_addr, end_addr, seed, pval, pwTable) {}
#define DO_CHECKSUM4(start_addr, end_addr, seed, pval, pwTable) {}

#define DO_DESCRAMBLE(start_addr, end_addr, seed, pwTable) {}
#define DO_SCRAMBLE(start_addr, end_addr, seed, pwTable) {}

#define iviTR_TREXE2_REGION_PFX ""
#define iviTR_TREXE2_REGION_DECLARE(GROUP, REGION) 
#define iviTR_TREXE2_REGION_DECLARE_BY_ORDER(GROUP, REGION, ORDER) 

#define iviTR_TREXE2_SPECIFY_LIB
#define iviTR_TREXE2_RUN_REGION_PFX ""
#define iviTR_TREXE2_DECLARE(GROUP, REGION, dword_relocate) 

#define iviTR_TREXE2_EXTERN(GROUP, REGION, dword_relocate) 
#define iviTR_TREXE2_DECLARE_CHECKSUMONLY(GROUP, REGION, dword_relocate) 
#define iviTR_TREXE2_EXTERN_CHECKSUMONLY(GROUP, REGION, dword_relocate)	

#define iviTR_TREXE2_CallDescramble(GROUP, REGION, dword_uniquenum) {}
#define iviTR_TREXE2_CallScramble(GROUP, REGION, dword_uniquenum) {}
#define iviTR_TREXE2_CallChecksum(GROUP, REGION, dword_uniquenum, bool_return) {}

#define iviTR_TREXE2_CallChecksum1(GROUP, REGION, dword_uniquenum, bool_return)	{}
#define iviTR_TREXE2_CallChecksum2(GROUP, REGION, dword_uniquenum, bool_return)	{}
#define iviTR_TREXE2_CallChecksum3(GROUP, REGION, dword_uniquenum, bool_return)	{}
#define iviTR_TREXE2_CallChecksum4(GROUP, REGION, dword_uniquenum, bool_return)	{}

#define iviTR_TREXE_REGION_BOUNDARY(region_num)	

#define iviTR_TREXE_DECLARE_CHECKSUMONLY(region_num, dword_relocate) 
#define iviTR_TREXE_EXTERN_CHECKSUMONLY(region_num, dword_relocate) 

#define iviTR_TREXE_DECLARE_SCRAMBLEONLY(region_num, dword_relocate) 
#define iviTR_TREXE_EXTERN_SCRAMBLEONLY(region_num, dword_relocate) 

#define iviTR_TREXE_DECLARE(region_num, dword_relocate)	
#define iviTR_TREXE_EXTERN(region_num, dword_relocate) 

#define iviTR_TREXE_CHECK_CHECKSUM(region_num, bool_return) 
#define iviTR_TREXE_CHECK_CHECKSUM1(region_num, bool_return) 
#define iviTR_TREXE_CHECK_CHECKSUM2(region_num, bool_return) 
#define iviTR_TREXE_CHECK_CHECKSUM3(region_num, bool_return) 
#define iviTR_TREXE_CHECK_CHECKSUM4(region_num, bool_return) 

#define iviTR_TREXE_DESCRAMBLE(region_num) 
#define iviTR_TREXE_SCRAMBLE(region_num) 

#define iviTR_WRAPAPI_REGION_BEGIN     
#define iviTR_WRAPAPI_REGION_ADDITEM   
#define iviTR_WRAPAPI_REGION_END  

#define iviTR_WRAPAPI_REGION_ADD_10_ITEM   
#define iviTR_WRAPAPI_REGION_ADD_500_ITEM   

// code morphing
#define iviTR_MORPH_BEGIN_0 {}
#define iviTR_MORPH_BEGIN_1 {}
#define iviTR_MORPH_BEGIN_2 {}
#define iviTR_MORPH_BEGIN_3 {}
#define iviTR_MORPH_BEGIN_4 {}
#define iviTR_MORPH_BEGIN_5 {}
#define iviTR_MORPH_BEGIN_6 {}
#define iviTR_MORPH_BEGIN_7 {}
#define iviTR_MORPH_BEGIN_8 {}
#define iviTR_MORPH_BEGIN_9 {}

#define iviTR_MORPH_END_0 {}
#define iviTR_MORPH_END_1 {}
#define iviTR_MORPH_END_2 {}
#define iviTR_MORPH_END_3 {}
#define iviTR_MORPH_END_4 {}
#define iviTR_MORPH_END_5 {}
#define iviTR_MORPH_END_6 {}
#define iviTR_MORPH_END_7 {}
#define iviTR_MORPH_END_8 {}
#define iviTR_MORPH_END_9 {}

#define iviTR_VIRTUAL_MACHINE_BEGIN {}
#define iviTR_VIRTUAL_MACHINE_END {}

// anti-disassembly

#define iviTR_NULL_PAD {}
#define iviTR_MISALIGNMENT(ll, reg, pad) {}
#define iviTR_MISALIGNMENT_1(ll) {}
#define iviTR_MISALIGNMENT_2(ll) {}
#define iviTR_FALSE_RETURN(ll, reg, pad) {}
#define iviTR_FALSE_RETURN_1(ll) {}
#define iviTR_FALSE_RETURN_2(ll) {}
#define iviTR_FALSE_CALL(ll, reg, pad) {}
#define iviTR_FALSE_CALL_1(ll) {}

#define iviTR_FIND_INT_3H_UNHANDLEDEXCEPTIONFILTER(dword_variable) {dword_variable = 0;}
#define iviTR_DETECT_TRACER_TRAP_FLAG(dword_variable) {dword_variable = 1;}
#define iviTR_INT3_EAX_CHECK(dword_variable) {dword_variable = 4;}
#define iviTR_DAEMON_FINDER(bool_variable) {bool_variable = false;}
#define iviTR_LOCK_CMPXCHG8B() {}

//Hibernate Detection Macros
#define iviTR_REGISTER_HIBERNATE_MONITOR(pfn) {}
#define iviTR_UNREGISTER_HIBERNATE_MONITOR(pfn) {}

//Anti Print Screen Macros
#define iviTR_DISABLE_PRINT_SCREEN() {}
#define iviTR_ENABLE_PRINT_SCREEN() {}

//Breakpoint detection macro
#define iviTR_MEMORY_ADDRESS_BREAKPOINT_DETECT(bool_variable, dword_variable) {bool_variable = false;}

//Anti Virtual Machine (vmware, virtualpc)
#define iviTR_INSIDEVMWARE_CHECK(bool_variable) {bool_variable = false;}
#define iviTR_INSIDEVIRTUALPC_CHECK(bool_variable) {bool_variable = false;}

// {Process Name | Window Name | Module Name} Checking
#define iviTR_CHECK_WINDOW_NAMES(match, call1, call2, parg) {}
#define iviTR_CHECK_PROCESS_NAMES(match, call1, call2, type, parg) {}
#define iviTR_CHECK_PROCESS_MODULES(match, call1, call2, type, parg) {}
#define iviTR_CHECK_ALL_PROCESS_NAMES(call1, call2, parg) {}
#define iviTR_CHECK_ALL_MODULE_NAMES(call1, call2, parg) {}
#define iviTR_CHECK_ALL_WINDOW_NAMES(call1, call2, parg) {}

// IVICheckProcessMemory, memory checksumming
#define iviTR_MEM_CHECKSUM {}
#define iviTR_CREATE_CHECK_PROCESS_MEMORY_THREAD(timer, s_addr, e_addr, call1, call2, parg, event) {}
#define iviTR_DELETE_CHECK_PROCESS_MEMORY_THREAD(pmt) {}

//Debug Register checks
#define iviTR_DEBUG_REGISTER_CHECK(bool_variable) {bool_variable = false;}

// IVIAntiDebug
#define iviTR_VERIFY_SOFTICE(proc) {}
#define iviTR_VERIFY_ATTACHED_DEBUGGER(proc) {}
#define iviTR_VERIFY_VTUNE_30(proc) {}
#define iviTR_HALT_THIS_PROCESS(x) ExitProcess(0)
#define iviTR_CHECK_MICROSOFT_PIN(testpin, flag) {(flag)=0;}
#define iviTR_CHECK_THREAD_TIMER(timeout_sec,proc) {}

#define iviTR_GETRDTSC(dword_variable) {dword_variable=0;}

#define iviTR_SOFTWARE_NUMEGA_SOFTICE_REGISTRY_CHECK(bool_variable) {bool_variable = false;}
#define iviTR_SOFTWARE_SYSERSOFT_SYSER_REGISTRY_CHECK1(bool_variable) {bool_variable = false;}
#define iviTR_SOFTWARE_SYSERSOFT_SYSER_REGISTRY_CHECK2(bool_variable) {bool_variable = false;}
#define iviTR_SOFTWARE_SYSERSOFT_SYSER_REGISTRY_CHECK3(bool_variable) {bool_variable = false;}
#define iviTR_SOFTWARE_SYSERSOFT_SYSER_REGISTRY_CHECK4(bool_variable) {bool_variable = false;}
#define iviTR_SOFTWARE_SYSERSOFT_SYSER_REGISTRY_CHECK5(bool_variable) {bool_variable = false;}
#define iviTR_DEBUGBREAK_CHECK(bool_variable) {bool_variable = false;}

#define iviTR_INT1H_CHECK(bool_variable) {bool_variable = false;}
#define iviTR_ICEBP_CHECK(bool_variable) {bool_variable = false;}
#define iviTR_API_ISDEBUGGERPRESENT_CHECK(bool_variable) {bool_variable = false;}

// IVIAntiDebug2
#define iviTR_VERIFY_SOFTICE_SIWVIDSTART_A(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SOFTICE_SIWVIDSTART_DD_A(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SOFTICE_SICE_A(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SOFTICE_SICE_DD_A(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SOFTICE_NTICE_A(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SOFTICE_NTICE_DD_A(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SOFTICE_SIWVID_A(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SOFTICE_SIWVID_DD_A(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SOFTICE_SIWDEBUG_A(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SOFTICE_SIWDEBUG_DD_A(bool_variable){bool_variable = false;}

#define iviTR_VERIFY_SOFTICE_SIWVIDSTART_A_INV(bool_variable){bool_variable = true;}
#define iviTR_VERIFY_SOFTICE_SIWVIDSTART_DD_A_INV(bool_variable){bool_variable = true;}
#define iviTR_VERIFY_SOFTICE_SICE_A_INV(bool_variable){bool_variable = true;}
#define iviTR_VERIFY_SOFTICE_SICE_DD_A_INV(bool_variable){bool_variable = true;}
#define iviTR_VERIFY_SOFTICE_NTICE_A_INV(bool_variable){bool_variable = true;}
#define iviTR_VERIFY_SOFTICE_NTICE_DD_A_INV(bool_variable){bool_variable = true;}
#define iviTR_VERIFY_SOFTICE_SIWVID_A_INV(bool_variable){bool_variable = true;}
#define iviTR_VERIFY_SOFTICE_SIWVID_DD_A_INV(bool_variable){bool_variable = true;}
#define iviTR_VERIFY_SOFTICE_SIWDEBUG_A_INV(bool_variable){bool_variable = true;}
#define iviTR_VERIFY_SOFTICE_SIWDEBUG_DD_A_INV(bool_variable){bool_variable = true;}

#define iviTR_VERIFY_SOFTICE_SIWVIDSTART_W(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SOFTICE_SIWVIDSTART_DD_W(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SOFTICE_SICE_W(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SOFTICE_SICE_DD_W(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SOFTICE_NTICE_W(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SOFTICE_NTICE_DD_W(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SOFTICE_SIWVID_W(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SOFTICE_SIWVID_DD_W(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SOFTICE_SIWDEBUG_W(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SOFTICE_SIWDEBUG_DD_W(bool_variable){bool_variable = false;}

#define iviTR_VERIFY_SOFTICE_SIWVIDSTART_W_INV(bool_variable){bool_variable = true;}
#define iviTR_VERIFY_SOFTICE_SIWVIDSTART_DD_W_INV(bool_variable){bool_variable = true;}
#define iviTR_VERIFY_SOFTICE_SICE_W_INV(bool_variable){bool_variable = true;}
#define iviTR_VERIFY_SOFTICE_SICE_DD_W_INV(bool_variable){bool_variable = true;}
#define iviTR_VERIFY_SOFTICE_NTICE_W_INV(bool_variable){bool_variable = true;}
#define iviTR_VERIFY_SOFTICE_NTICE_DD_W_INV(bool_variable){bool_variable = true;}
#define iviTR_VERIFY_SOFTICE_SIWVID_W_INV(bool_variable){bool_variable = true;}
#define iviTR_VERIFY_SOFTICE_SIWVID_DD_W_INV(bool_variable){bool_variable = true;}
#define iviTR_VERIFY_SOFTICE_SIWDEBUG_W_INV(bool_variable){bool_variable = true;}
#define iviTR_VERIFY_SOFTICE_SIWDEBUG_DD_W_INV(bool_variable){bool_variable = true;}

#define iviTR_VERIFY_SOFTICE_LCREAT(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SOFTICE_LCREAT1(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SOFTICE_LCREAT2(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SOFTICE_LCREAT3(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SOFTICE_LCREAT4(bool_variable){bool_variable = false;}

#define iviTR_VERIFY_SOFTICE_LCREAT_INV(bool_variable){bool_variable = true;}
#define iviTR_VERIFY_SOFTICE_LCREAT1_INV(bool_variable){bool_variable = true;}
#define iviTR_VERIFY_SOFTICE_LCREAT2_INV(bool_variable){bool_variable = true;}
#define iviTR_VERIFY_SOFTICE_LCREAT3_INV(bool_variable){bool_variable = true;}
#define iviTR_VERIFY_SOFTICE_LCREAT4_INV(bool_variable){bool_variable = true;}

#define iviTR_VERIFY_SOFTICE_LOPEN(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SOFTICE_LOPEN1(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SOFTICE_LOPEN2(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SOFTICE_LOPEN3(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SOFTICE_LOPEN4(bool_variable){bool_variable = false;}

#define iviTR_VERIFY_SOFTICE_LOPEN_INV(bool_variable){bool_variable = true;}
#define iviTR_VERIFY_SOFTICE_LOPEN1_INV(bool_variable){bool_variable = true;}
#define iviTR_VERIFY_SOFTICE_LOPEN2_INV(bool_variable){bool_variable = true;}
#define iviTR_VERIFY_SOFTICE_LOPEN3_INV(bool_variable){bool_variable = true;}
#define iviTR_VERIFY_SOFTICE_LOPEN4_INV(bool_variable){bool_variable = true;}

#define iviTR_VERIFY_SOFTICE_NTICE_SERVICE(bool_variable) {bool_variable = false;}
#define iviTR_VERIFY_SOFTICE_NTICE_SERVICE_INV(bool_variable) {bool_variable = true;}

#define iviTR_VERIFY_SYSER_A(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SYSER_DD_A(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SYSER_W(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SYSER_DD_W(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SYSER_LCREAT(bool_variable){bool_variable = false;}
#define iviTR_VERIFY_SYSER_LOPEN(bool_variable){bool_variable = false;}

#define iviTR_SYSTEM_DEBUG_REGISTRY_CHECK(bool_variable) {bool_variable = false;}
#define iviTR_VERIFY_SYSER_ENGINE(bool_variable) {bool_variable = false;}
#define iviTR_VERIFY_SYSER_SYSERBOOT(bool_variable) {bool_variable = false;}
#define iviTR_DETECT_PRINTEXCEPTION(bool_variable) {bool_variable = false;}
#define iviTR_INT2D_CHECK(bool_variable) {bool_variable = false;}

#define iviTR_SOFTICE_ICEEXT_REGISTRY_CHECK(bool_variable) {bool_variable = false;}
#define iviTR_SOFTICE_ICEEXT_REGISTRY_CHECK_INV(bool_variable) {bool_variable = true;}

// IVIKernelUserDebuggerCofusion
#define iviTR_BLOCK_USER_INPUT(BOOLEAN_VAL) true
#define iviTR_CHECK_MULTIPLE_RUNNING_INSTANCE() true

// IVIOsFunctionCallHackingDetect
#define iviTR_GET_IAT_CRC32(rdwChecksum, bool_variable){bool_variable = true;}
#define iviTR_GET_IAT_CRC32_BY_MODULE_HANDLE(hModule, rdwChecksum, bool_variable){bool_variable = true;}

// IVIVirtualMachineDetect
#define iviTR_INSIDEVIRTUALPC_CHECK(bool_variable) {bool_variable = false;}
#define iviTR_INSIDEVMWARE_CHECK(bool_variable) {bool_variable = false;}

// IVICheckReturnAddr
#define iviTR_SAVE_RETURN_ADDR {}
#define iviTR_RACHECK_BEGIN(FNUM)
#define iviTR_RACHECK_END(FNUM)
#define iviTR_CHECK_RETURN_ADDR(FNUM, bool_variable) {bool_variable = true;}

// IVICallStackVerify
#define iviTR_VERIFY_CALLER_FRAMEPOINTER(pFuncAddrs, cbNumFuncAddrs, bResult) {bResult = true;}
#define iviTR_VERIFY_CALLER_PARAM(firstparam, pFuncAddrs, cbNumFuncAddrs, bResult) {bResult = true;}
#define iviTR_VERIFY_CALLER_REGISTER(GUID, INDEX) {}
#define iviTR_VERIFY_CALLER(bReturn, GUID) {}

//IVIVerifyCheckSumRegion
#define iviTR_CREATE_VERIFY_CHECKSUM_REGION(pfnStart, pfnEnd, trRelocatTable, trChecksumValue,trChecksumSeed, trChecksumValueSeed, trChecksumEnable, trChecksumEnableSeed, pfnChangeCallback, parg) 0
#define iviTR_DELETE_VERIFY_CHECKSUM_REGION(pVCT) {}
#define iviTR_CREATE_VERIFY_CHECKSUM_REGION_EX(region_num, pfnChangeCallback, parg) 0

//IVIDetectHookCOM - RegisterCallerHandle/DetectHookCOM(Need SQPlus)
#define iviTR_REGISTER_CALLER_HANDLE(sz_value, h_handle, byte_pattern) {}
#define iviTR_DETECT_HOOK_COM(sz_clsid, sz_path, byte_pattern, bool_return){bool_return = false;}

//IVIDetectHookCOM - Validation detection by hand-shaking(irrelevant to SQPlus)
#define iviTR_INIT_DETECT_CALLER_VALIDATION(sz_clsid) {}
#define iviTR_DETECT_CALLER_VALIDATION(bool_return, sz_clsid) {bool_return = false;}

//IVICheckVtableHook
#define iviTR_CHECK_VTABLE_HOOK_ON_CALLBACK(ptr_interface, int_index, int_count, bool_variable) {bool_variable = false;}

// TimingMacros
#define iviTR_SET_TIMEOUT_COUNT(int_variable) {}
#define iviTR_SET_INITIAL_TIMESTAMP(t1) {}
#define iviTR_SET_FINAL_TIMESTAMP(t2) {}
#define iviTR_TIMESTAMP_CHECK(t1, t2, dword_variable, bool_variable) {bool_variable = false;}

// DelayedInstability
#define iviTR_CRASH() {}
#define iviTR_EXIT_PROCESS() {}


//IVIDetectDebuggerAttach
#define iviTR_DETECT_DEBUGGER_ATTACH() {}

// DebugDetectExcept
#define iviTR_DEBUG_DETECT_INIT {}
#define iviTR_DEBUG_DETECT_START {}
#define iviTR_DEBUG_DETECT_WAIT {}
#define iviTR_DEBUG_DETECT_RES FALSE
#define iviTR_DEBUG_DETECT_END {}

// IVIDummyAccess
#define iviTR_START_DUMMY_WRITE(nBlockSize, nTotalBlockPerThread, nTotalThread, nSleepTimePerCycle, pszHeadPattern, pszMidPattern, pszTailPattern) {}
#define iviTR_END_DUMMY_WRITE() {}

// IVIAntiMemoryDump
#define iviTR_REGISTER_IMAGESIZE(hModule) {}
#define iviTR_UNREGISTER_IMAGESIZE(hModule) {}
#define iviTR_START_IMAGESIZE_CHECKER {}
#define iviTR_STOP_IMAGESIZE_CHECKER {}
#define iviTR_MODULE_HIDING(hModule) {}

// IVIDummyCall
#define iviTR_DUMMY_CALL_1(Num) {}
#define iviTR_DUMMY_CALL_2(Num) {}
#define iviTR_DUMMY_CALL_3(Num) {}
#define iviTR_DUMMY_CALL_4(Num) {}
#define iviTR_DUMMY_CALL_5(Num) {}
#define iviTR_DUMMY_CALL_6(Num) {}
#define iviTR_DUMMY_CALL_7(Num) {}
#define iviTR_DUMMY_CALL_8(Num) {}
#define iviTR_DUMMY_CALL_9(Num) {}
#define iviTR_DUMMY_CALL_10(Num) {}

//checksum
#define iviTR_DUMP_CHECKSUM_LOG(val, seed) {}

//IVITRUtil
#define iviTR_ENCRYPT_CONTENT_EX(sz_value, int_buffsize, byte_pattern, int_encrypttype) {}
#define iviTR_ENCRYPT_CONTENT(sz_value, byte_pattern, int_encrypttype) {}
#define iviTR_DECRYPT_CONTENT(sz_value, byte_pattern, int_decrypttype) {}

#define iviTR_CONST_REVERSE_STR(sz_NORMAL, sz_REVERSED) sz_NORMAL

#define iviTR_ALLOCATE_ENCRYPTED_TCHAR(name, sz_encrypted, int_pattern, sz_original)	\
	TCHAR name[] = sz_original

#define iviTR_RE_ENCRYPT_ALLOCATED_TCHAR(name, int_pattern) {}

//detect tr enable
#define iviTR_CHECK_ENGINE_TR_ENABLE_APPLIED()
#define iviTR_CHECK_UI_TR_ENABLE_APPLIED()

#define iviTR_IS_TR_ENABLE_APPLIED_FOR_ENGINE(pbTR_ENABLE, pbTR_ENABLE_NEWMACROS) { (*pbTR_ENABLE) = (*pbTR_ENABLE_NEWMACROS) = false; }

// call this macro to check if TR_ENABLE/TR_ENABLE_NEWMACROS is applied for UI part
#define iviTR_IS_TR_ENABLE_APPLIED_FOR_UI(pbTR_ENABLE, pbTR_ENABLE_NEWMACROS) { (*pbTR_ENABLE) = (*pbTR_ENABLE_NEWMACROS) = false; }

//detect trexe enable
#define iviTR_CHECK_TREXE_APPLIED()
#define TR_IS_TREXE_APPLIED(pbTR_ENABLE) { (*pbTR_ENABLE) = false; }

#endif