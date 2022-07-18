project('uparse', 'cpp',
    license: 'MIT',
    default_options: [
        'cpp_std=c++17',
        'warning_level=3'])

headers = [
    'include/uparse/uparse.hpp'
]

incdirs = include_directories('./include')

ufmt = declare_dependency(
    include_directories: incdirs,
    sources: headers
)

subdir('test')
