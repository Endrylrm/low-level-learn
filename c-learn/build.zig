const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const exe = b.addExecutable(.{
        .name = "main",
        .root_module = b.createModule(.{
            .target = target,
            .optimize = optimize,
            .link_libc = true,
        }),
    });

    exe.root_module.addIncludePath(b.path("include"));

    exe.root_module.addCSourceFiles(.{
        .files = &[_][]const u8{
            "src/main.c",
            "src/logging.c",
            "src/person.c",
            "src/car.c",
            "src/linkedlist.c",
        },
        .flags = &[_][]const u8{ "-O3", "-Wall", "-Wextra" },
    });

    b.installArtifact(exe);

    const run_cmd = b.addRunArtifact(exe);
    run_cmd.step.dependOn(b.getInstallStep());

    // Create a "run" step to easily execute the binary via 'zig build run'
    const run_step = b.step("run", "Run the app");
    run_step.dependOn(&run_cmd.step);
}
