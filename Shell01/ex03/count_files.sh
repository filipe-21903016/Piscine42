find . -type f -or -type d | awk 'END{print NR}'
