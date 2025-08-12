
function(generate_md5_file input_file)
    file(MD5 ${input_file} file_md5)
    file(WRITE ${input_file}.md5 "${file_md5}")
endfunction()

generate_md5_file(${INPUT_FILE})
