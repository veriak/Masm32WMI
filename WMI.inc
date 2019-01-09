;----------------------------------------------------------------------------------------
; WMI Masm32 Library
;
; Copyright 2007 Veria Kalantary
; veria.kalantary@gmail.com
; https://github.com/veriak
;
;----------------------------------------------------------------------------------------

_vtIWbemLocator macro CastName:REQ
	_vtIUnknown CastName	
    &CastName&_ConnectServer				comethod9	?
endm

IWbemLocator struct
	_vtIWbemLocator							IWbemLocator	
IWbemLocator ends

_vtIWbemServices macro CastName:REQ
	_vtIUnknown CastName	
	&CastName&_OpenNamespace				comethod6	?         
	&CastName&_CancelAsyncCall				comethod2	?        
	&CastName&_QueryObjectSink				comethod3	?         
	&CastName&_GetObject					comethod6	?       
	&CastName&_GetObjectAsync				comethod5	?        
	&CastName&_PutClass						comethod5	?        
	&CastName&_PutClassAsync				comethod5	?        
	&CastName&_DeleteClass					comethod5	?        
	&CastName&_DeleteClassAsync				comethod5	?        
	&CastName&_CreateClassEnum				comethod5	?        
	&CastName&_CreateClassEnumAsync			comethod5	?         
	&CastName&_PutInstance					comethod5	?
	&CastName&_PutInstanceAsync				comethod5	?         
	&CastName&_DeleteInstance				comethod5	?        
	&CastName&_DeleteInstanceAsync			comethod5	?        
	&CastName&_CreateInstanceEnum			comethod5	?        
	&CastName&_CreateInstanceEnumAsync		comethod5	?        
	&CastName&_ExecQuery					comethod6	?
	&CastName&_ExecQueryAsync				comethod6	?         
	&CastName&_ExecNotificationQuery		comethod6	?        
	&CastName&_ExecNotificationQueryAsync	comethod6	?        
	&CastName&_ExecMethod					comethod8	?        
	&CastName&_ExecMethodAsync				comethod7	?
endm

IWbemServices struc
	_vtIWbemServices						IWbemServices	
IWbemServices ends

_vtIEnumWbemClassObject	macro CastName:REQ
	_vtIUnknown CastName	
	&CastName&_Reset						comethod1	?        
	&CastName&_Next							comethod5	?                     
	&CastName&_NextAsync					comethod3	?         
	&CastName&_Clone						comethod2	?         
	&CastName&_Skip							comethod3	? 	
endm

IEnumWbemClassObject struct
	_vtIEnumWbemClassObject					IEnumWbemClassObject
IEnumWbemClassObject ends

_vtIWbemClassObject	macro CastName:REQ
	_vtIUnknown CastName
	&CastName&_GetQualifierSet				comethod2	?        
	&CastName&_Get							comethod6	?
	&CastName&_Put							comethod5	?
	&CastName&_Delete						comethod2	?
	&CastName&_GetNames						comethod5	?        
	&CastName&_BeginEnumeration				comethod2	?
	&CastName&_Next							comethod6	?        
	&CastName&_EndEnumeration				comethod1	?        
	&CastName&_GetPropertyQualifierSet		comethod3	?
	&CastName&_Clone						comethod2	?
	&CastName&_GetObjectText				comethod3	?
	&CastName&_SpawnDerivedClass			comethod3	?
	&CastName&_SpawnInstance				comethod3	?
	&CastName&_CompareTo					comethod3	?
	&CastName&_GetPropertyOrigin			comethod3	?
	&CastName&_InheritsFrom					comethod2	?
	&CastName&_GetMethod					comethod5	?
	&CastName&_PutMethod					comethod5	?
	&CastName&_DeleteMethod					comethod2	?
	&CastName&_BeginMethodEnumeration		comethod2	?
	&CastName&_NextMethod					comethod5	?
	&CastName&_EndMethodEnumeration			comethod1	?        
	&CastName&_GetMethodQualifierSet		comethod3	?
	&CastName&_GetMethodOrigin				comethod3	?
endm

IWbemClassObject struct
	_vtIWbemClassObject						IWbemClassObject
IWbemClassObject ends        

_vtIWbemObjectSink 	macro CastName:REQ
	_vtIUnknown CastName
	&CastName&_Indicate						comethod3	?        
	&CastName&_SetStatus					comethod5	?
endm
	
IWbemObjectSink struct
	_vtIWbemObjectSink						IWbemObjectSink
IWbemObjectSink ends
	
_vtIUnsecuredApartment	macro CastName:REQ
	_vtIUnknown CastName			
	&CastName&_CreateObjectStub				comethod3	?				 
endm

IUnsecuredApartment struct
	_vtIUnsecuredApartment					IUnsecuredApartment
IUnsecuredApartment ends 
    
PIWbemLocator								typedef	ptr IWbemLocator
PIWbemServices								typedef	ptr IWbemServices
PIEnumWbemClassObject						typedef	ptr IEnumWbemClassObject
PIWbemClassObject							typedef	ptr IWbemClassObject
PIWbemObjectSink							typedef	ptr IWbemObjectSink
PIUnsecuredApartment						typedef	ptr IUnsecuredApartment

PPIWbemClassObject							typedef	ptr PIWbemClassObject

.const
	WBEM_FLAG_CONNECT_REPOSITORY_ONLY		equ	40h
	WBEM_FLAG_CONNECT_USE_MAX_WAIT			equ	80h
	
	WBEM_FLAG_RETURN_IMMEDIATELY			equ	10h
	WBEM_FLAG_RETURN_WBEM_COMPLETE			equ	0
	WBEM_FLAG_BIDIRECTIONAL					equ	0
	WBEM_FLAG_FORWARD_ONLY					equ	20
	WBEM_FLAG_NO_ERROR_OBJECT				equ	40
	WBEM_FLAG_RETURN_ERROR_OBJECT			equ	0
	WBEM_FLAG_SEND_STATUS					equ	80h
	WBEM_FLAG_DONT_SEND_STATUS				equ	0
	WBEM_FLAG_ENSURE_LOCATABLE				equ	100h
	WBEM_FLAG_DIRECT_READ					equ	200h
	WBEM_FLAG_SEND_ONLY_SELECTED			equ	0
	WBEM_RETURN_WHEN_COMPLETE				equ	0
	WBEM_RETURN_IMMEDIATELY					equ	10h
	WBEM_MASK_RESERVED_FLAGS				equ	1F000h
	WBEM_FLAG_USE_AMENDED_QUALIFIERS		equ	20000h
	WBEM_FLAG_STRONG_VALIDATION				equ	100000h
	
	WBEM_NO_WAIT							equ	0
	WBEM_INFINITE							equ	0FFFFFFFFh

	WBEM_S_NO_ERROR							equ	0
	WBEM_S_SAME								equ	0
	WBEM_S_FALSE							equ	1
	WBEM_S_ALREADY_EXISTS					equ	40001h
	WBEM_S_RESET_TO_DEFAULT					equ	40002h
	WBEM_S_DIFFERENT						equ	40003h
	WBEM_S_TIMEDOUT							equ	40004h
	WBEM_S_NO_MORE_DATA						equ	40005h
	WBEM_S_OPERATION_CANCELLED				equ	40006h
	WBEM_S_PENDING							equ	40007h
	WBEM_S_DUPLICATE_OBJECTS				equ	40008h
	WBEM_S_ACCESS_DENIED					equ	40009h
	WBEM_S_PARTIAL_RESULTS					equ	40010h
	WBEM_S_SOURCE_NOT_AVAILABLE				equ	40017h
	WBEM_E_FAILED							equ	80041001h
	WBEM_E_NOT_FOUND						equ	80041002h
	WBEM_E_ACCESS_DENIED					equ	80041003h
	WBEM_E_PROVIDER_FAILURE					equ	80041004h
	WBEM_E_TYPE_MISMATCH					equ	80041005h
	WBEM_E_OUT_OF_MEMORY					equ	80041006h
	WBEM_E_INVALID_CONTEXT					equ	80041007h
	WBEM_E_INVALID_PARAMETER				equ	80041008h
	WBEM_E_NOT_AVAILABLE					equ	80041009h
	WBEM_E_CRITICAL_ERROR					equ	8004100ah
	WBEM_E_INVALID_STREAM					equ	8004100bh
	WBEM_E_NOT_SUPPORTED					equ	8004100ch
	WBEM_E_INVALID_SUPERCLASS				equ	8004100dh
	WBEM_E_INVALID_NAMESPACE				equ	8004100eh
	WBEM_E_INVALID_OBJECT					equ	8004100fh
	WBEM_E_INVALID_CLASS					equ	80041010h
	WBEM_E_PROVIDER_NOT_FOUND				equ	80041011h
	WBEM_E_INVALID_PROVIDER_REGISTRATION	equ	80041012h
	WBEM_E_PROVIDER_LOAD_FAILURE			equ	80041013h
	WBEM_E_INITIALIZATION_FAILURE			equ	80041014h
	WBEM_E_TRANSPORT_FAILURE				equ	80041015h
	WBEM_E_INVALID_OPERATION				equ	80041016h
	WBEM_E_INVALID_QUERY					equ	80041017h
	WBEM_E_INVALID_QUERY_TYPE				equ	80041018h
	WBEM_E_ALREADY_EXISTS					equ	80041019h
	WBEM_E_OVERRIDE_NOT_ALLOWED				equ	8004101ah
	WBEM_E_PROPAGATED_QUALIFIER				equ	8004101bh
	WBEM_E_PROPAGATED_PROPERTY				equ	8004101ch
	WBEM_E_UNEXPECTED						equ	8004101dh
	WBEM_E_ILLEGAL_OPERATION				equ	8004101eh
	WBEM_E_CANNOT_BE_KEY					equ	8004101fh
	WBEM_E_INCOMPLETE_CLASS					equ	80041020h
	WBEM_E_INVALID_SYNTAX					equ	80041021h
	WBEM_E_NONDECORATED_OBJECT				equ	80041022h
	WBEM_E_READ_ONLY						equ	80041023h
	WBEM_E_PROVIDER_NOT_CAPABLE				equ	80041024h
	WBEM_E_CLASS_HAS_CHILDREN				equ	80041025h
	WBEM_E_CLASS_HAS_INSTANCES				equ	80041026h
	WBEM_E_QUERY_NOT_IMPLEMENTED			equ	80041027h
	WBEM_E_ILLEGAL_NULL						equ	80041028h
	WBEM_E_INVALID_QUALIFIER_TYPE			equ	80041029h
	WBEM_E_INVALID_PROPERTY_TYPE			equ	8004102ah
	WBEM_E_VALUE_OUT_OF_RANGE				equ	8004102bh
	WBEM_E_CANNOT_BE_SINGLETON				equ	8004102ch
	WBEM_E_INVALID_CIM_TYPE					equ	8004102dh
	WBEM_E_INVALID_METHOD					equ	8004102eh
	WBEM_E_INVALID_METHOD_PARAMETERS		equ	8004102fh
	WBEM_E_SYSTEM_PROPERTY					equ	80041030h
	WBEM_E_INVALID_PROPERTY					equ	80041031h
	WBEM_E_CALL_CANCELLED					equ	80041032h
	WBEM_E_SHUTTING_DOWN					equ	80041033h
	WBEM_E_PROPAGATED_METHOD				equ	80041034h
	WBEM_E_UNSUPPORTED_PARAMETER			equ	80041035h
	WBEM_E_MISSING_PARAMETER_ID				equ	80041036h
	WBEM_E_INVALID_PARAMETER_ID				equ	80041037h
	WBEM_E_NONCONSECUTIVE_PARAMETER_IDS		equ	80041038h
	WBEM_E_PARAMETER_ID_ON_RETVAL			equ	80041039h
	WBEM_E_INVALID_OBJECT_PATH				equ	8004103ah
	WBEM_E_OUT_OF_DISK_SPACE				equ	8004103bh
	WBEM_E_BUFFER_TOO_SMALL					equ	8004103ch
	WBEM_E_UNSUPPORTED_PUT_EXTENSION		equ	8004103dh
	WBEM_E_UNKNOWN_OBJECT_TYPE				equ	8004103eh
	WBEM_E_UNKNOWN_PACKET_TYPE				equ	8004103fh
	WBEM_E_MARSHAL_VERSION_MISMATCH			equ	80041040h
	WBEM_E_MARSHAL_INVALID_SIGNATURE		equ	80041041h
	WBEM_E_INVALID_QUALIFIER				equ	80041042h
	WBEM_E_INVALID_DUPLICATE_PARAMETER		equ	80041043h
	WBEM_E_TOO_MUCH_DATA					equ	80041044h
	WBEM_E_SERVER_TOO_BUSY					equ	80041045h
	WBEM_E_INVALID_FLAVOR					equ	80041046h
	WBEM_E_CIRCULAR_REFERENCE				equ	80041047h
	WBEM_E_UNSUPPORTED_CLASS_UPDATE			equ	80041048h
	WBEM_E_CANNOT_CHANGE_KEY_INHERITANCE	equ	80041049h
	WBEM_E_CANNOT_CHANGE_INDEX_INHERITANCE	equ	80041050h
	WBEM_E_TOO_MANY_PROPERTIES				equ	80041051h
	WBEM_E_UPDATE_TYPE_MISMATCH				equ	80041052h
	WBEM_E_UPDATE_OVERRIDE_NOT_ALLOWED		equ	80041053h
	WBEM_E_UPDATE_PROPAGATED_METHOD			equ	80041054h
	WBEM_E_METHOD_NOT_IMPLEMENTED			equ	80041055h
	WBEM_E_METHOD_DISABLED					equ	80041056h
	WBEM_E_REFRESHER_BUSY					equ	80041057h
	WBEM_E_UNPARSABLE_QUERY					equ	80041058h
	WBEM_E_NOT_EVENT_CLASS					equ	80041059h
	WBEM_E_MISSING_GROUP_WITHIN				equ	8004105ah
	WBEM_E_MISSING_AGGREGATION_LIST			equ	8004105bh
	WBEM_E_PROPERTY_NOT_AN_OBJECT			equ	8004105ch
	WBEM_E_AGGREGATING_BY_OBJECT			equ	8004105dh
	WBEM_E_UNINTERPRETABLE_PROVIDER_QUERY	equ	8004105fh
	WBEM_E_BACKUP_RESTORE_WINMGMT_RUNNING	equ	80041060h
	WBEM_E_QUEUE_OVERFLOW					equ	80041061h
	WBEM_E_PRIVILEGE_NOT_HELD				equ	80041062h
	WBEM_E_INVALID_OPERATOR					equ	80041063h
	WBEM_E_LOCAL_CREDENTIALS				equ	80041064h
	WBEM_E_CANNOT_BE_ABSTRACT				equ	80041065h
	WBEM_E_AMENDED_OBJECT					equ	80041066h
	WBEM_E_CLIENT_TOO_SLOW					equ	80041067h
	WBEM_E_NULL_SECURITY_DESCRIPTOR			equ	80041068h
	WBEM_E_TIMED_OUT						equ	80041069h
	WBEM_E_INVALID_ASSOCIATION				equ	8004106ah
	WBEM_E_AMBIGUOUS_OPERATION				equ	8004106bh
	WBEM_E_QUOTA_VIOLATION					equ	8004106ch
	WBEM_E_RESERVED_001						equ	8004106dh
	WBEM_E_RESERVED_002						equ	8004106eh
	WBEM_E_UNSUPPORTED_LOCALE				equ	8004106fh
	WBEM_E_HANDLE_OUT_OF_DATE				equ	80041070h
	WBEM_E_CONNECTION_FAILED				equ	80041071h
	WBEM_E_INVALID_HANDLE_REQUEST			equ	80041072h
	WBEM_E_PROPERTY_NAME_TOO_WIDE			equ	80041073h
	WBEM_E_CLASS_NAME_TOO_WIDE				equ	80041074h
	WBEM_E_METHOD_NAME_TOO_WIDE				equ	80041075h
	WBEM_E_QUALIFIER_NAME_TOO_WIDE			equ	80041076h
	WBEM_E_RERUN_COMMAND					equ	80041077h
	WBEM_E_DATABASE_VER_MISMATCH			equ	80041078h
	WBEM_E_VETO_DELETE						equ	80041079h
	WBEM_E_VETO_PUT							equ	8004107ah
	WBEM_E_INVALID_LOCALE					equ	80041080h
	WBEM_E_PROVIDER_SUSPENDED				equ	80041081h
	WBEM_E_SYNCHRONIZATION_REQUIRED			equ	80041082h
	WBEM_E_NO_SCHEMA						equ	80041083h
	WBEM_E_PROVIDER_ALREADY_REGISTERED		equ	80041084h
	WBEM_E_PROVIDER_NOT_REGISTERED			equ	80041085h
	WBEM_E_FATAL_TRANSPORT_ERROR			equ	80041086h
	WBEM_E_ENCRYPTED_CONNECTION_REQUIRED	equ	80041087h
	WBEM_E_PROVIDER_TIMED_OUT				equ	80041088h
	WBEM_E_NO_KEY							equ	80041089h
	WBEM_E_PROVIDER_DISABLED				equ	8004108ah
	WBEMESS_E_REGISTRATION_TOO_BROAD		equ	80042001h
	WBEMESS_E_REGISTRATION_TOO_PRECISE		equ	80042002h
	WBEMMOF_E_EXPECTED_QUALIFIER_NAME		equ	80044001h
	WBEMMOF_E_EXPECTED_SEMI					equ	80044002h
	WBEMMOF_E_EXPECTED_OPEN_BRACE			equ	80044003h
	WBEMMOF_E_EXPECTED_CLOSE_BRACE			equ	80044004h
	WBEMMOF_E_EXPECTED_CLOSE_BRACKET		equ	80044005h
	WBEMMOF_E_EXPECTED_CLOSE_PAREN			equ	80044006h
	WBEMMOF_E_ILLEGAL_CONSTANT_VALUE		equ	80044007h
	WBEMMOF_E_EXPECTED_TYPE_IDENTIFIER		equ	80044008h
	WBEMMOF_E_EXPECTED_OPEN_PAREN			equ	80044009h
	WBEMMOF_E_UNRECOGNIZED_TOKEN			equ	8004400ah
	WBEMMOF_E_UNRECOGNIZED_TYPE				equ	8004400bh
	WBEMMOF_E_EXPECTED_PROPERTY_NAME		equ	8004400ch
	WBEMMOF_E_TYPEDEF_NOT_SUPPORTED			equ	8004400dh
	WBEMMOF_E_UNEXPECTED_ALIAS				equ	8004400eh
	WBEMMOF_E_UNEXPECTED_ARRAY_INIT			equ	8004400fh
	WBEMMOF_E_INVALID_AMENDMENT_SYNTAX		equ	80044010h
	WBEMMOF_E_INVALID_DUPLICATE_AMENDMENT	equ	80044011h
	WBEMMOF_E_INVALID_PRAGMA				equ	80044012h
	WBEMMOF_E_INVALID_NAMESPACE_SYNTAX		equ	80044013h
	WBEMMOF_E_EXPECTED_CLASS_NAME			equ	80044014h
	WBEMMOF_E_TYPE_MISMATCH					equ	80044015h
	WBEMMOF_E_EXPECTED_ALIAS_NAME			equ	80044016h
	WBEMMOF_E_INVALID_CLASS_DECLARATION		equ	80044017h
	WBEMMOF_E_INVALID_INSTANCE_DECLARATION	equ	80044018h
	WBEMMOF_E_EXPECTED_DOLLAR				equ	80044019h
	WBEMMOF_E_CIMTYPE_QUALIFIER				equ	8004401ah
	WBEMMOF_E_DUPLICATE_PROPERTY			equ	8004401bh
	WBEMMOF_E_INVALID_NAMESPACE_SPECIFICATION	equ	8004401ch
	WBEMMOF_E_OUT_OF_RANGE					equ	8004401dh
	WBEMMOF_E_INVALID_FILE					equ	8004401eh
	WBEMMOF_E_ALIASES_IN_EMBEDDED			equ	8004401fh
	WBEMMOF_E_NULL_ARRAY_ELEM				equ	80044020h
	WBEMMOF_E_DUPLICATE_QUALIFIER			equ	80044021h
	WBEMMOF_E_EXPECTED_FLAVOR_TYPE			equ	80044022h
	WBEMMOF_E_INCOMPATIBLE_FLAVOR_TYPES		equ	80044023h
	WBEMMOF_E_MULTIPLE_ALIASES				equ	80044024h
	WBEMMOF_E_INCOMPATIBLE_FLAVOR_TYPES2	equ	80044025h
	WBEMMOF_E_NO_ARRAYS_RETURNED			equ	80044026h
	WBEMMOF_E_MUST_BE_IN_OR_OUT				equ	80044027h
	WBEMMOF_E_INVALID_FLAGS_SYNTAX			equ	80044028h
	WBEMMOF_E_EXPECTED_BRACE_OR_BAD_TYPE	equ	80044029h
	WBEMMOF_E_UNSUPPORTED_CIMV22_QUAL_VALUE	equ	8004402ah
	WBEMMOF_E_UNSUPPORTED_CIMV22_DATA_TYPE	equ	8004402bh
	WBEMMOF_E_INVALID_DELETEINSTANCE_SYNTAX	equ	8004402ch
	WBEMMOF_E_INVALID_QUALIFIER_SYNTAX		equ	8004402dh
	WBEMMOF_E_QUALIFIER_USED_OUTSIDE_SCOPE	equ	8004402eh
	WBEMMOF_E_ERROR_CREATING_TEMP_FILE		equ	8004402fh
	WBEMMOF_E_ERROR_INVALID_INCLUDE_FILE	equ	80044030h
	WBEMMOF_E_INVALID_DELETECLASS_SYNTAX	equ	80044031h
	
	RPC_C_AUTHZ_NONE						equ	0
	RPC_C_AUTHZ_NAME						equ	1
	RPC_C_AUTHZ_DCE							equ	2
	RPC_C_AUTHZ_DEFAULT						equ	0FFFFFFFFh

	RPC_C_AUTHN_LEVEL_DEFAULT				equ	0
	RPC_C_AUTHN_LEVEL_NONE					equ	1
	RPC_C_AUTHN_LEVEL_CONNECT				equ	2
	RPC_C_AUTHN_LEVEL_CALL					equ	3
	RPC_C_AUTHN_LEVEL_PKT					equ	4
	RPC_C_AUTHN_LEVEL_PKT_INTEGRITY			equ	5
	RPC_C_AUTHN_LEVEL_PKT_PRIVACY			equ	6

	RPC_C_IMP_LEVEL_DEFAULT					equ	0
	RPC_C_IMP_LEVEL_ANONYMOUS				equ	1
	RPC_C_IMP_LEVEL_IDENTIFY				equ	2
	RPC_C_IMP_LEVEL_IMPERSONATE				equ	3
	RPC_C_IMP_LEVEL_DELEGATE				equ	4
	
	RPC_C_QOS_IDENTITY_STATIC				equ	0
	RPC_C_QOS_IDENTITY_DYNAMIC				equ	1

	RPC_C_QOS_CAPABILITIES_DEFAULT			equ	0
	RPC_C_QOS_CAPABILITIES_MUTUAL_AUTH		equ	1
	RPC_C_QOS_CAPABILITIES_MAKE_FULLSIC		equ	2
	RPC_C_QOS_CAPABILITIES_ANY_AUTHORITY	equ	4
	RPC_C_QOS_CAPABILITIES_IGNORE_DELEGATE_FAILURE	equ	8
	RPC_C_QOS_CAPABILITIES_LOCAL_MA_HINT	equ	10

	RPC_C_PROTECT_LEVEL_DEFAULT				equ	RPC_C_AUTHN_LEVEL_DEFAULT
	RPC_C_PROTECT_LEVEL_NONE				equ	RPC_C_AUTHN_LEVEL_NONE
	RPC_C_PROTECT_LEVEL_CONNECT				equ	RPC_C_AUTHN_LEVEL_CONNECT
	RPC_C_PROTECT_LEVEL_CALL				equ	RPC_C_AUTHN_LEVEL_CALL
	RPC_C_PROTECT_LEVEL_PKT					equ	RPC_C_AUTHN_LEVEL_PKT
	RPC_C_PROTECT_LEVEL_PKT_INTEGRITY		equ	RPC_C_AUTHN_LEVEL_PKT_INTEGRITY
	RPC_C_PROTECT_LEVEL_PKT_PRIVACY			equ	RPC_C_AUTHN_LEVEL_PKT_PRIVACY

	RPC_C_AUTHN_NONE						equ	0
	RPC_C_AUTHN_DCE_PRIVATE					equ	1
	RPC_C_AUTHN_DCE_PUBLIC					equ	2
	RPC_C_AUTHN_DEC_PUBLIC					equ	4
	RPC_C_AUTHN_GSS_NEGOTIATE				equ	9
	RPC_C_AUTHN_WINNT						equ	10
	RPC_C_AUTHN_GSS_SCHANNEL				equ	14
	RPC_C_AUTHN_GSS_KERBEROS				equ	16
	RPC_C_AUTHN_DPA							equ	17
	RPC_C_AUTHN_MSN							equ	18
	RPC_C_AUTHN_DIGEST						equ	21
	RPC_C_AUTHN_MQ							equ	100
	RPC_C_AUTHN_DEFAULT						equ	0FFFFFFFFh	
	
	EOAC_NONE								equ	0000h
	EOAC_MUTUAL_AUTH						equ	0001h
	EOAC_STATIC_CLOAKING					equ	0020h
	EOAC_DYNAMIC_CLOAKING					equ	0040h
	EOAC_ANY_AUTHORITY						equ	0080h
	EOAC_MAKE_FULLSIC						equ	0100h
	EOAC_DEFAULT							equ	0800h
	EOAC_SECURE_REFS						equ	0002h
	EOAC_ACCESS_CONTROL						equ	0004h	
	EOAC_APPID								equ	0008h
	EOAC_DYNAMIC							equ	0010h
	EOAC_REQUIRE_FULLSIC					equ	0200h
	EOAC_AUTO_IMPERSONATE					equ	0400h
	EOAC_NO_CUSTOM_MARSHAL					equ	2000h
	EOAC_DISABLE_AAA						equ	1000h
	
	CLSID_WbemAdministrativeLocator			GUID	<0cb8555cch, 9128h, 11d1h, <0adh, 9bh, 00h, 0c0h, 4fh, 0d8h, 0fdh, 0ffh>>
	CLSID_UnsecuredApartment				GUID	<49bd2028h, 1523h, 11d1h, <0adh, 79h, 00h, 0c0h, 4fh, 0d8h, 0fdh, 0ffh>>

	IID_IWbemLocator						GUID	<0dc12a687h, 737fh, 11cfh, <88h, 4dh, 00h, 0aah, 00h, 04bh, 2eh, 24h>>
	IID_IWbemServices						GUID	<9556dc99h, 828ch, 11cfh, <0a3h, 7eh, 00h, 0aah, 00h, 32h, 40h, 0c7h>>
	IID_IEnumWbemClassObject				GUID	<027947e1h,	0d731h, 11ceh, <0a3h, 57h, 00h, 00h, 00h, 00h, 00h, 01h>>
	IID_IWbemClassObject					GUID	<0dc12a681h, 737fh, 11cfh, <88h, 4dh, 00h, 0aah, 00h, 4bh, 2eh, 24h>>
	IID_IWbemObjectSink						GUID	<7c857801h, 7381h, 11cfh, <88h, 4dh, 00h, 0aah, 00h, 4bh, 2eh, 24h>>
	IID_IUnsecuredApartment					GUID	<1cfaba8ch, 1523h, 11d1h, <0adh, 79h, 00h, 0c0h, 4fh, 0d8h, 0fdh, 0ffh>>	