// swift-tools-version: 6.0
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "LvglSwift",
    products: [
        // Products define the executables and libraries a package produces, making them visible to other packages.
        .library(
            name: "LvglSwift",
            targets: ["LvglSwift"]),
    ],
    targets: [
        .target(
          name: "LvglSwift",
          dependencies: [],
          cSettings: [
            .headerSearchPath("lv_drivers"),
            .headerSearchPath("lvgl"),
            .headerSearchPath("."),
            .unsafeFlags(["-I/opt/homebrew/include", "-DLV_CONF_INCLUDE_SIMPLE", "-DLV_LVGL_H_INCLUDE_SIMPLE"]),
          ],
          linkerSettings: [.unsafeFlags(["-L/opt/homebrew/lib", "-lSDL2"])]
        ),
        .testTarget(
            name: "LvglSwiftTests",
            dependencies: ["LvglSwift"]
        ),
    ]
)
