;----------------------------------------------------------------------------------------
; WMI Client Library
;
; Copyright 2008 Veria Kalantary
; veria.kalantary@gmail.com
; https://github.com/veriak
;
;----------------------------------------------------------------------------------------

include Com.inc
include WMI.inc

WMIGetHardDriveSerialNumber		PROTO	:LPVOID
WMIGetMacAddress				PROTO	:LPVOID
	
.code

WMIGetHardDriveSerialNumber proc uses ecx edx lpBuff:LPVOID 
	LOCAL pWbemLocator: PIWbemLocator
	LOCAL pWbemServices: PIWbemServices	
	LOCAL pEnumWbemObject: PIEnumWbemClassObject
	LOCAL pWbemClassObject: PIWbemClassObject 	 
	LOCAL bstrServer: BSTR
	LOCAL bstrQuery: BSTR
	LOCAL bstrWQL: BSTR
	LOCAL bstrClassProp: BSTR
	LOCAL dwReturned: DWORD			
	LOCAL var: VARIANT	
	
	invoke StrToBstr, StrM("root\cimv2")
	mov bstrServer, eax	
	invoke StrToBstr, StrM("WQL")
	mov bstrWQL, eax		
	
	invoke CoInitializeEx, NULL, COINIT_MULTITHREADED 
	invoke CoInitializeSecurity, NULL, -1, NULL, NULL, RPC_C_AUTHN_LEVEL_PKT,\
					RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE, NULL
					
	invoke CoCreateInstance, addr CLSID_WbemAdministrativeLocator, NULL, CLSCTX_INPROC_SERVER or CLSCTX_LOCAL_SERVER, \
							addr IID_IWbemLocator, addr pWbemLocator																							
	coinvoke pWbemLocator, IWbemLocator, ConnectServer, bstrServer, NULL, NULL, NULL, 0, NULL, NULL, addr pWbemServices	
	
	invoke StrToBstr, StrM("SELECT * FROM Win32_PhysicalMedia")
	mov bstrQuery, eax
    coinvoke pWbemServices, IWbemServices, ExecQuery, bstrWQL, bstrQuery, WBEM_FLAG_RETURN_IMMEDIATELY,\
    						NULL, addr pEnumWbemObject    						
								
	coinvoke pEnumWbemObject, IEnumWbemClassObject, Reset
	coinvoke pEnumWbemObject, IEnumWbemClassObject, Next, WBEM_INFINITE, 1, addr pWbemClassObject, addr dwReturned
			
	invoke StrToBstr, StrM("SerialNumber")
	mov bstrClassProp, eax
	
	coinvoke pWbemClassObject, IWbemClassObject, Get, bstrClassProp, 0, addr var, 0, 0		
	.if eax == S_OK
		invoke BstrToStr, var.bstrVal
		push eax
		invoke lstrcpy, lpBuff, eax
		call GlobalFree
	.endif	 
	invoke VariantClear, addr var
			 
    coinvoke pWbemClassObject, IWbemClassObject, Release
    coinvoke pEnumWbemObject, IEnumWbemClassObject, Release    							 									 	
	coinvoke pWbemLocator, IWbemLocator, Release
	coinvoke pWbemServices, IWbemServices, Release														
	invoke CoUninitialize
	
	invoke FreeBstr, addr bstrClassProp
	invoke FreeBstr, addr bstrQuery							
	invoke FreeBstr, addr bstrWQL	
	invoke FreeBstr, addr bstrServer
	ret
WMIGetHardDriveSerialNumber endp

WMIGetMacAddress proc uses ecx edx lpBuff:LPVOID 
	LOCAL pWbemLocator: PIWbemLocator
	LOCAL pWbemServices: PIWbemServices	
	LOCAL pEnumWbemObject: PIEnumWbemClassObject
	LOCAL pWbemClassObject: PIWbemClassObject 	 
	LOCAL bstrServer: BSTR
	LOCAL bstrQuery: BSTR
	LOCAL bstrWQL: BSTR
	LOCAL bstrClassProp: BSTR
	LOCAL dwReturned: DWORD			
	LOCAL var: VARIANT	
	
	invoke StrToBstr, StrM("root\cimv2")
	mov bstrServer, eax	
	invoke StrToBstr, StrM("WQL")
	mov bstrWQL, eax		
	
	invoke CoInitializeEx, NULL, COINIT_MULTITHREADED 
	invoke CoInitializeSecurity, NULL, -1, NULL, NULL, RPC_C_AUTHN_LEVEL_PKT,\
					RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE, NULL
					
	invoke CoCreateInstance, addr CLSID_WbemAdministrativeLocator, NULL, CLSCTX_INPROC_SERVER or CLSCTX_LOCAL_SERVER, \
							addr IID_IWbemLocator, addr pWbemLocator																							
	coinvoke pWbemLocator, IWbemLocator, ConnectServer, bstrServer, NULL, NULL, NULL, 0, NULL, NULL, addr pWbemServices	
	
	invoke StrToBstr, StrM("SELECT * FROM Win32_NetworkAdapterConfiguration WHERE IPEnabled=1")
	mov bstrQuery, eax
    coinvoke pWbemServices, IWbemServices, ExecQuery, bstrWQL, bstrQuery, WBEM_FLAG_RETURN_IMMEDIATELY,\
    						NULL, addr pEnumWbemObject    						
								
	coinvoke pEnumWbemObject, IEnumWbemClassObject, Reset
	coinvoke pEnumWbemObject, IEnumWbemClassObject, Next, WBEM_INFINITE, 1, addr pWbemClassObject, addr dwReturned
			
	invoke StrToBstr, StrM("MACAddress")
	mov bstrClassProp, eax
	
	coinvoke pWbemClassObject, IWbemClassObject, Get, bstrClassProp, 0, addr var, 0, 0		
	.if eax == S_OK
		invoke BstrToStr, var.bstrVal
		push eax
		invoke lstrcpy, lpBuff, eax
		call GlobalFree
	.endif	 
	invoke VariantClear, addr var
			 
    coinvoke pWbemClassObject, IWbemClassObject, Release
    coinvoke pEnumWbemObject, IEnumWbemClassObject, Release    							 									 	
	coinvoke pWbemLocator, IWbemLocator, Release
	coinvoke pWbemServices, IWbemServices, Release														
	invoke CoUninitialize
	
	invoke FreeBstr, addr bstrClassProp
	invoke FreeBstr, addr bstrQuery							
	invoke FreeBstr, addr bstrWQL	
	invoke FreeBstr, addr bstrServer
	ret
WMIGetMacAddress endp