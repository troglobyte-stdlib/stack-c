miok_stack_lib = static_library('miok-stack',
    'package.c',
    include_directories: inc_dir,
    gnu_symbol_visibility: 'hidden',
    install: true)

miok_stack_dep = declare_dependency(
    link_with: miok_stack_lib,
    include_directories: inc_dir)
