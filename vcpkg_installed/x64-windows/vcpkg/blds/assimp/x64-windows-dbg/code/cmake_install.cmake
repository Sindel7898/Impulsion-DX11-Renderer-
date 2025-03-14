# Install script for directory: C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/pkgs/assimp_x64-windows/debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
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

if(CMAKE_INSTALL_COMPONENT STREQUAL "libassimp5.4.0-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/x64-windows-dbg/lib/assimp-vc143-mtd.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libassimp5.4.0" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/x64-windows-dbg/bin/assimp-vc143-mtd.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/anim.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/aabb.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/ai_assert.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/camera.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/color4.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/color4.inl"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/x64-windows-dbg/code/../include/assimp/config.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/ColladaMetaData.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/commonMetaData.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/defs.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/cfileio.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/light.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/material.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/material.inl"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/matrix3x3.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/matrix3x3.inl"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/matrix4x4.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/matrix4x4.inl"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/mesh.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/ObjMaterial.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/pbrmaterial.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/GltfMaterial.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/postprocess.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/quaternion.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/quaternion.inl"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/scene.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/metadata.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/texture.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/types.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/vector2.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/vector2.inl"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/vector3.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/vector3.inl"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/version.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/cimport.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/AssertHandler.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/importerdesc.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/Importer.hpp"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/DefaultLogger.hpp"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/ProgressHandler.hpp"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/IOStream.hpp"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/IOSystem.hpp"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/Logger.hpp"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/LogStream.hpp"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/NullLogger.hpp"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/cexport.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/Exporter.hpp"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/DefaultIOStream.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/DefaultIOSystem.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/ZipArchiveIOSystem.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/SceneCombiner.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/fast_atof.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/qnan.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/BaseImporter.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/Hash.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/MemoryIOWrapper.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/ParsingUtils.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/StreamReader.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/StreamWriter.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/StringComparison.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/StringUtils.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/SGSpatialSort.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/GenericProperty.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/SpatialSort.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/SkeletonMeshBuilder.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/SmallVector.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/SmoothingGroups.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/SmoothingGroups.inl"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/StandardShapes.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/RemoveComments.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/Subdivision.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/Vertex.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/LineSplitter.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/TinyFormatter.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/Profiler.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/LogAux.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/Bitmap.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/XMLTools.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/IOStreamBuffer.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/CreateAnimMesh.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/XmlParser.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/BlobIOSystem.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/MathFunctions.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/Exceptional.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/ByteSwapper.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/Base64.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/Compiler/pushpack1.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/Compiler/poppack1.h"
    "C:/Users/Amir sanni/source/repos/DX11/LearnDX/vcpkg_installed/x64-windows/vcpkg/blds/assimp/src/v5.4.0-df40e53144.clean/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

