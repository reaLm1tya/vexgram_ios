load("@build_bazel_rules_swift//swift:swift.bzl", "swift_library")

swift_library(
    name = "SGAPI",
    module_name = "SGAPI",
    srcs = glob([
		"Sources/**/*.swift",
    ]),
    copts = [
        "-warnings-as-errors",
    ],
    deps = [
        "//submodules/SSignalKit/SwiftSignalKit:SwiftSignalKit",
        "//VexGram/SGLogging:SGLogging",
        "//VexGram/SGWebAppExtensions:SGWebAppExtensions",
        "//VexGram/SGSimpleSettings:SGSimpleSettings",
        "//VexGram/SGWebSettingsScheme:SGWebSettingsScheme",
        "//VexGram/SGRegDateScheme:SGRegDateScheme",
        "//VexGram/SGRequests:SGRequests",
        "//VexGram/SGConfig:SGConfig"
    ],
    visibility = [
        "//visibility:public",
    ],
)
