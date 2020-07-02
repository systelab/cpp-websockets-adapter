from conans import ConanFile, CMake

class WebSocketsAdapterTestUtilitiesTestConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake_find_package"
    options = {"gtest": ["1.7.0", "1.8.1", "1.10.0"]}
    default_options = "gtest=1.10.0"

    def configure(self):
        self.options["WebSocketsAdapterTestUtilities"].gtest = self.options.gtest

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib*", dst="bin", src="lib")
        self.copy('*.so*', dst='bin', src='lib')

    def test(self):
        cmake = CMake(self)
        cmake.test()
