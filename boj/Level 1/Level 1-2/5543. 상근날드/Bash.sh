min() {
    local a b
    a="$1"
    b="$2"

    if [ "$a" -lt "$b" ]; then
        echo "$a"
    else
        echo "$b"
    fi
}

main() {
    local a b c d e
    read -r a; read -r b; read -r c
    read -r d; read -r e

    local m1 m2
    m1=$(min "$a" "$b")
    m1=$(min "$c" "$m1")
    m2=$(min "$d" "$e")

    echo $(("$m1" + "$m2" - 50))
}

main
