add_subdirectory(Client)
add_subdirectory(Math)
add_subdirectory(Memory)
add_subdirectory(Utils)

target_sources(EchoClient PRIVATE 
    "dllmain.cpp"
)