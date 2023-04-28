main() {
    local t c_s c_l s l n
    read -r t

    while [ "$t" -gt 0 ]; do
        c_s=''; c_l=0
        read -r n

        while [ "$n" -gt 0 ]; do
            read -r s l

            if [ "$l" -gt "$c_l" ]; then
                c_l=$l
                c_s=$s
            fi

            n=$((n-1))
        done

        echo "$c_s"

        t=$((t-1))
    done
}

main
