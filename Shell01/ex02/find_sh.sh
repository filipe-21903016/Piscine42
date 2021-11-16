find . -name "*.sh" | awk -F/ '{print $NF}' | awk -F. '{print $1}'
