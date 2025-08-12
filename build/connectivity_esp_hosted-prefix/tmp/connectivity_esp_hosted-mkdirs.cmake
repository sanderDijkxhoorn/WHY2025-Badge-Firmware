# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file LICENSE.rst or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/Users/zyki/Work/firmware/connectivity_esp_hosted/slave")
  file(MAKE_DIRECTORY "/Users/zyki/Work/firmware/connectivity_esp_hosted/slave")
endif()
file(MAKE_DIRECTORY
  "/Users/zyki/Work/firmware/connectivity_esp_hosted/slave"
  "/Users/zyki/Work/firmware/build/connectivity_esp_hosted-prefix"
  "/Users/zyki/Work/firmware/build/connectivity_esp_hosted-prefix/tmp"
  "/Users/zyki/Work/firmware/build/connectivity_esp_hosted-prefix/src/connectivity_esp_hosted-stamp"
  "/Users/zyki/Work/firmware/build/connectivity_esp_hosted-prefix/src"
  "/Users/zyki/Work/firmware/build/connectivity_esp_hosted-prefix/src/connectivity_esp_hosted-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/zyki/Work/firmware/build/connectivity_esp_hosted-prefix/src/connectivity_esp_hosted-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/zyki/Work/firmware/build/connectivity_esp_hosted-prefix/src/connectivity_esp_hosted-stamp${cfgdir}") # cfgdir has leading slash
endif()
