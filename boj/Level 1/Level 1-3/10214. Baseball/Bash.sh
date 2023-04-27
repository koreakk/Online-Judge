main() {
    local t i j n y k
    read -r t

    i=0
    while [ $i -lt "$t" ]; do
        n=0

        j=0
        while [ $j -lt 9 ]; do
            read -r y k
            n=$((n+y-k))
            j=$((j+1))
        done

        if   [ $n -gt 0 ]; then echo "Yonsei"
        elif [ $n -lt 0 ]; then echo "Korea"
        else                    echo "Draw"
        fi

        i=$((i+1))
    done
}

main
