add_subdirectory(Categories)
add_subdirectory(Modules)

target_sources(EchoClient PRIVATE 
    "Client.cpp"
)