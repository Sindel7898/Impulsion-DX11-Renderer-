# Install script for directory: C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/directxtk/src/jun2024-41841b3d9b.clean

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/pkgs/directxtk_x64-windows")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "OFF")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/directxtk/x64-windows-rel/lib/DirectXTK.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/directxtk/DirectXTK-targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/directxtk/DirectXTK-targets.cmake"
         "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/directxtk/x64-windows-rel/CMakeFiles/Export/a11a99d19d8d3c8432b0fa94ef825414/DirectXTK-targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/directxtk/DirectXTK-targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/directxtk/DirectXTK-targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/directxtk" TYPE FILE FILES "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/directxtk/x64-windows-rel/CMakeFiles/Export/a11a99d19d8d3c8432b0fa94ef825414/DirectXTK-targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/directxtk" TYPE FILE FILES "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/directxtk/x64-windows-rel/CMakeFiles/Export/a11a99d19d8d3c8432b0fa94ef825414/DirectXTK-targets-release.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/directxtk" TYPE FILE FILES
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/directxtk/src/jun2024-41841b3d9b.clean/Inc/BufferHelpers.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/directxtk/src/jun2024-41841b3d9b.clean/Inc/CommonStates.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/directxtk/src/jun2024-41841b3d9b.clean/Inc/DDSTextureLoader.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/directxtk/src/jun2024-41841b3d9b.clean/Inc/DirectXHelpers.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/directxtk/src/jun2024-41841b3d9b.clean/Inc/Effects.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/directxtk/src/jun2024-41841b3d9b.clean/Inc/GeometricPrimitive.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/directxtk/src/jun2024-41841b3d9b.clean/Inc/GraphicsMemory.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/directxtk/src/jun2024-41841b3d9b.clean/Inc/Model.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/directxtk/src/jun2024-41841b3d9b.clean/Inc/PostProcess.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/directxtk/src/jun2024-41841b3d9b.clean/Inc/PrimitiveBatch.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/directxtk/src/jun2024-41841b3d9b.clean/Inc/ScreenGrab.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/directxtk/src/jun2024-41841b3d9b.clean/Inc/SpriteBatch.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/directxtk/src/jun2024-41841b3d9b.clean/Inc/SpriteFont.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/directxtk/src/jun2024-41841b3d9b.clean/Inc/VertexTypes.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/directxtk/src/jun2024-41841b3d9b.clean/Inc/WICTextureLoader.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/directxtk/src/jun2024-41841b3d9b.clean/Inc/GamePad.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/directxtk/src/jun2024-41841b3d9b.clean/Inc/Keyboard.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/directxtk/src/jun2024-41841b3d9b.clean/Inc/Mouse.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/directxtk/src/jun2024-41841b3d9b.clean/Inc/SimpleMath.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/directxtk/src/jun2024-41841b3d9b.clean/Inc/SimpleMath.inl"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/directxtk" TYPE FILE FILES
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/directxtk/x64-windows-rel/directxtk-config.cmake"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/directxtk/x64-windows-rel/directxtk-config-version.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/directxtk/x64-windows-rel/DirectXTK.pc")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/directxtk/x64-windows-rel/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
