load("@build_bazel_rules_swift//swift:swift.bzl", "swift_library")

swift_library(
    name = "SGRegDate",
    module_name = "SGRegDate",
    srcs = glob([
        "Sources/**/*.swift",
    ]),
    copts = [
        "-warnings-as-errors",
    ],
    deps = [
        "//VexGram/SGRegDateScheme:SGRegDateScheme",
        "//VexGram/SGSimpleSettings:SGSimpleSettings",
        "//VexGram/SGAPI:SGAPI",
        "//VexGram/SGAPIToken:SGAPIToken",
        "//VexGram/SGDeviceToken:SGDeviceToken",
        "//VexGram/SGStrings:SGStrings",

        "//submodules/AccountContext:AccountContext",
        "//submodules/SSignalKit/SwiftSignalKit:SwiftSignalKit",
        "//submodules/TelegramPresentationData:TelegramPresentationData",
    ],
    visibility = [
        "//visibility:public",
    ],
)