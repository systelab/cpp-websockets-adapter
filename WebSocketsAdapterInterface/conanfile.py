from conans import ConanFile


class WebSocketsAdapterInterfaceConan(ConanFile):
    name = "WebSocketsAdapterInterface"
    description = "Interface of library-agnostic API for C++ to work with a web sockets"
    url = "https://github.com/systelab/cpp-websockets-adapter"
    homepage = "https://github.com/systelab/cpp-websockets-adapter"
    author = "CSW <csw@werfen.com>"
    topics = ("conan", "websockets", "ws", "adapter", "wrapper")
    license = "MIT"
    generators = "cmake_find_package"
    # No settings/options are necessary, this is header only

    def package(self):
        self.copy("*.h", dst="include/WebSocketsAdapterInterface")
        self.copy("*.inl", dst="include/WebSocketsAdapterInterface")

    def package_info(self):
        self.info.header_only()
