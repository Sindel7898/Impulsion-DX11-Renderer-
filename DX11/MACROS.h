#pragma once
#include <comdef.h> 
#include <d3d11.h> 

#define CHECK_HRESULT(hr) \
   if (FAILED(hr)) { \
        _com_error err(hr); \
        std::wcerr << L"Error: " << err.ErrorMessage() << L" (HRESULT: " << std::hex << hr << L")" << std::endl; \
    }