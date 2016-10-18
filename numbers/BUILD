cc_library (
  name = "prime_lib",
  srcs = [
    "prime.cc",
  ],
  hdrs = [
    "prime.h",
  ],
  visibility = ["//solutions:__pkg__"],
)

cc_binary (
  name = "prime_test",
  srcs = [
    "prime_test.cc",
  ],
  deps = [
    ":prime_lib",
  ],
)

cc_library (
  name = "modular_lib",
  srcs = [
    "modular.cc",
  ],
  hdrs = [
    "modular.h",
  ],
  visibility = ["//solutions:__pkg__"],
)

cc_binary (
  name = "modular_test",
  srcs = [
    "modular_test.cc",
  ],
  deps = [
    ":modular_lib",
  ],
)

