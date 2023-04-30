count() {
    local S=$1
    local V=$2
    local T=$3

    local i=0 r=0
    while [ "$i" -lt "$V" ]; do
        if [ "${S:$i:${#T}}" = "$T" ]; then
            r=$((r+1))
        fi

        i=$((i+1))
    done

    echo "$r"
}

main() {
    local v s
    read -r v
    read -r s

    local A B
    A=$(count "$s" "$v" 'A')
    B=$(count "$s" "$v" 'B')

    if [ "$A" -gt "$B" ]; then
        echo 'A'
    elif [ "$A" -lt "$B" ]; then
        echo 'B'
    else
        echo 'Tie'
    fi
}

main
