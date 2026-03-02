load("@build_bazel_rules_swift//swift:swift.bzl", "swift_library")

swift_library(
    name = "SGAPIWebSettings",
    module_name = "SGAPIWebSettings",
    srcs = glob([
        "Sources/**/*.swift",
    ]),
    copts = [
        "-warnings-as-errors",
    ],
    deps = [
        "//VexGram/SGAPI:SGAPI",
        "//VexGram/SGAPIToken:SGAPIToken",
        "//VexGram/SGLogging:SGLogging",
        "//VexGram/SGSimpleSettings:SGSimpleSettings",
        "//submodules/AccountContext:AccountContext",
        "//submodules/TelegramCore:TelegramCore",
    ],
    visibility = [
        "//visibility:public",
    ],
)
